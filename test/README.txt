1. To create and load the dataset into database, we use navicat. First, we get the excel form of data. Then we import them
	into the mysql database via navicat.
2. To run the command line program, first we enter our user name and password, then we can choose to display the tables or
	perform other queries following the instruction.
3. The application currently support a) display item table b) display data from query c) perform other queries.

Notice: The application only support local database. By default, the host is "localhost" with port 3306,
	and the database's name is "testDB". To change them, change the string in main.cpp then recompile.
Compile Note: Before compiling, the "ws2_32.lib" and "libmysql.lib" should be loaded first.