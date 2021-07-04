--From store owner's end:
-- add new item into DB  
insert into Items
	values (new_iid, new_name, new_price, new_stock);

-- classify item as X category
insert into IsMemberOf
	values (new_iid, new_cid);

-- de-classify item A as B category
delete from IsMemberOf
	where iid = cur_iid
	and cid = cur_cid;

-- update category
update IsMemberOf
	set cid = new_cid
	where iid = cur_iid;

-- update item price
update Items
	set price=new_price
	where iid=cur_iid;

-- update item stock
update Items
	set stock=new_stock
	where iid=cur_iid;

-- delete item from DB by iid
delete from Items
	where iid = cur_iid;

-- mark item for sale 
-- must input cur_iid, new_sale_percentage, new_hours, new_days
insert into ItemsOnSale
	values(
		cur_iid,
		new_sale_percentage, 
		DATE_ADD(DATE_ADD(SYSDATE(), INTERVAL new_days DAY), INTERVAL new_hours HOUR)
	);

-- check for expired sales
-- datediff produces the difference in hours between the expiry date and current date
-- if negative, the sale is over
delete from ItemsOnSale
	where iid = cur_iid
	and DATEDIFF(expirationDate, SYSDATE()) < 0;

-- query item-name (generic name search)
-- the query name has to be built with % on each end from the outside before SQL
select * from Items
where name like '%query_name%'

-- query Items that are on sale
select * from Items 
inner join ItemsOnSale
on ItemsOnSale.iid = Items.iid

-- query by category
select Items.iid, name, price, stock from Items
inner join (
	select iid from IsMemberOf
	inner join (
		select cid from Categories
		where Categories.name = query_name
		) as query_cid
	on IsMemberOf.cid = query_cid.cid
	) as query_table
on Items.iid = query_table.iid