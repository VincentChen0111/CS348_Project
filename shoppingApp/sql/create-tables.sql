CREATE TABLE Items
(iid DECIMAL(4, 0) NOT NULL PRIMARY KEY,
 name VARCHAR(50) NOT NULL,
 price DECIMAL(4, 2) NOT NULL CHECK(price >= 0),
 stock DECIMAL(3, 0) NOT NULL CHECK(stock >= 0)
);

CREATE TABLE Categories
(cid DECIMAL(2, 0) NOT NULL PRIMARY KEY,
 cname VARCHAR(50) NOT NULL
);

CREATE TABLE SubCategories
(scid DECIMAL(3, 0) NOT NULL PRIMARY KEY,
 scname VARCHAR(50) NOT NULL
);

CREATE TABLE Users
(uid DECIMAL(8, 0) NOT NULL PRIMARY KEY
);

CREATE TABLE IsMemberOf
(iid DECIMAL(4, 0) NOT NULL,
 scid DECIMAL(3, 0) NOT NULL,
 PRIMARY KEY(iid, scid),
 FOREIGN KEY(iid) REFERENCES Items(iid),
 FOREIGN KEY(scid) REFERENCES SubCategories(scid)
);

CREATE TABLE IsSubsetOf
(cid DECIMAL(2, 0) NOT NULL,
 scid DECIMAL(3, 0) NOT NULL,
 PRIMARY KEY(cid, scid),
 FOREIGN KEY(cid) REFERENCES Categories(cid),
 FOREIGN KEY(scid) REFERENCES SubCategories(scid)
);

CREATE TABLE IsInCart
(iid DECIMAL(4, 0) NOT NULL,
 uid DECIMAL(8, 0) NOT NULL,
 quantity DECIMAL(3, 0) NOT NULL CHECK(quantity >= 0),
 PRIMARY KEY(iid, uid),
 FOREIGN KEY(iid) REFERENCES Items(iid),
 FOREIGN KEY(uid) REFERENCES Users(uid)
);

CREATE TABLE ItemsOnSale
(iid DECIMAL(4, 0) NOT NULL,
 percentOff DECIMAL(2, 0) NOT NULL CHECK(percentOff < 100 and percentOff > 0),
 expirationDate DATE,
 PRIMARY KEY(iid),
 FOREIGN KEY(iid) REFERENCES Items(iid)
);

CREATE TABLE RegisteredUsers
(uid DECIMAL(8, 0) NOT NULL,
 username VARCHAR(50) NOT NULL UNIQUE,
 password VARCHAR(50) NOT NULL,
 isAdmin BOOL NOT NULL,
 PRIMARY KEY(uid),
 FOREIGN KEY(uid) REFERENCES Users(uid)
);
