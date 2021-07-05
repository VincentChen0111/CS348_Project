# CS348_Project
## Database Related
* The RDS we choose is MySQL, since it is well-developed and easy to use.

* Because of convience, we choose to use Amazon AWS cloud service to store our database
    - The endpoint is *cs348-project.c56bjewfihhr.us-east-2.rds.amazonaws.com*
    - There are three main users operating the data base
        1. admin: the adminstrator of the database
        2. customer: the customer account, right now all the customers will log in to this account
            + behavior for different users(like shopping cart) will be controlled by the client app.
        3. UsrCtrl: the account controlling all the user behavior, including sign up, log in and etc.
    - The database using is named "DB1". Admin has the full control on it, customers can view the data and 
    modify shopping cart related tables(the later one has not implemented yet), and UsrCtrl has the privelidge on all user related tables.

* To initialize the database, run create_table.sql in the code.zip.

* Method to pop data into the database:
    1.  Download the .xlsx file from website <https://www.kaggle.com/jeffryjames/groceries-data?select=Product_Details_Extract.xlsx>
    2.  Open the .xlsx file with Microsoft Excel
    3.  Add needed columns like ids and stock
        - for the creation of id, use the vlookup function
    4.  Import the data to the database
        - various methods can be used, I used the import wizzard from navicat to do the trick

* Notice: on sale items are not supported right now, stocks are initialized to 10 due to the lack of info from the source
    

## Application design
* the application supports Windows environment
* sql_api.h to wrap up mysql interface
* DBManager.h to provide manangement for the mart db
* main.cpp for the client program
* For details, see the conresponding files


## Compiling application
* The user interface application is developed through visual studio on Windows. Thus the code is to be compiled with vc++. The github project <https://github.com/VincentChen0111/CS348_Project> is a visual studio project.

* Dependencies
    - Additional include path: SOME_PATH\MySQL\MySQL Server 8.0\include; 
    - Additional library path:C:\Program Files %28x86%29\Windows Kits\10\Lib;SOME_PATH\MySQL\MySQL Server 8.0\lib;
    - Additional dependencies for the linker: libmysql.lib;Ws2_32.lib;

## Running application
* You MUST put the libmysql.dll on the appropriate folder(e.g. the folder having the executable)
* There will be couple vc++ dll files needed for the executable to run, so you should have vc++ in your windows
* Add other dependencies if required
* Follow the instructions specified in the command line to proceed
    - Note that some featrues are not supported right now


## Features
* Login as admin or customer account
    - allow users to create registered accounts
    + temporary users are not supported right now
* As admin:
    - view items
    - add items
    + modifying categories, relationships are not supported
    + on sale items are not supported
* As customer:
    - search by category
    - search by name
    + shopping cart related are not supported

