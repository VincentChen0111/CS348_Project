--From store owner's end:
-- add new item into DB  
insert into items values (new_iid, new_name, new_price, new_stock)

-- update item price
update items set price=new_price where iid=cur_iid

-- update item stock
update items set stock=new_stock where iid=cur_iid

-- delete item from DB by iid
delete from itemsonsale where iid = cur_iid

-- mark item for sale 
-- must input cur_iid, new_sale_percentage, new_hours, new_days
insert into itemsonsale values( cur_iid, new_sale_percentage,  DATEADD(hour, new_hours, DATEADD(day, new_days, GETDATE())) )

-- check for expired sales
-- datediff produces the difference in hours between the expiry date and current date
-- if negative, the sale is over
delete from itemsonsale where iid = cur_iid and DATEDIFF(hour, expires, GETDATE()) < 0

--From user's end: 
-- query item-name (generic name search)
-- the query name has to be built with % on each end from the outside before SQL
select * from items where name like '%query_name%'
-- query items that are on sale
select * from items  inner join itemsonsale on itemsonsale.iid = items.iid

-- query by category
select * from items inner join ( select iid from isMemberOf inner join ( select cid from categories where categories.name = query_name ) as query_cid on isMemberOf.cid = query_cid.cid on items.iid = query_table.iid