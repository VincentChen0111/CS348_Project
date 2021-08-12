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
    - The database using is named "shoppingApp". Admin has the full control on it, customers can view the data and 
    modify shopping cart related tables, and UsrCtrl has the privelidge on all user related tables.

* To initialize the database, run create_table.sql in the code.zip.

* Method to pop data into the database:
    1.  Download the .xlsx file from website <https://www.kaggle.com/jeffryjames/groceries-data?select=Product_Details_Extract.xlsx>
    2.  Open the .xlsx file with Microsoft Excel
    3.  Add needed columns like ids and stock
        - for the creation of id, use the vlookup function
        - see the .xlsx file in the code.zip
    4.  Import the data to the database
        - various methods can be used, I used the import wizzard from navicat to do the trick

* Notice: stocks are initialized to 10 due to the lack of info from the source
    

## Application design
* the application supports Windows environment
* use C++ as programming language
    - C++ is powerful, and every member in the group is familiar with it
* use Qt to build a user interface
    - As a desktop interface designer, qt is extremly powerful and easy to use


## Compiling application
* Users do not need to compile the code to run application, just in case for code inspection
* The executable is compiled with Qt 5.12.11
    - to complile the code, a mysql driver for qt must be included. The driver used in this project is compiled with MySQL 5.7.

* Dependencies
    - require "libmysql.dll" in the running environment from mysql's provided include folder
    - All dynamic libraries, including the one above are packed up in the exec folder.

## Running application
* Download the exec folder, click shoppingApp.exe to run.


## Features and Instructions
* Login as admin or customer or guest account
    - allow users to create registered accounts. 
    - allow temporary user to login as guest.
        + guest uid will be clear after the application close
    - allow admin login.
        + admin account cannot be registered through the app, it must be added directly to the database
* As admin: the options in the application should be self-explanatory
    - view items
    - update items/categories/subcategories
    - add items/categories/subcategories (add and update must be commited by clicking the button)
        + when add button is clicked, an empty record will appear at the bottom. 
    - delete items/categories/subcategories (delete operation cannot be canceled so need not to commit)
        + after deletion, corresponding relationships in the table will also be deleted
        + delete category : delete itself, all its sub category, all relationship to its sub categories
        + delete subcategory: delete itself, delete all relationship between it and its items, delete relationship between it and its parent
        + delete item: delete itself, delete its relationship to some subcategory
    - modifying categories, subcategories relationships
        + multiple children can be selected, but only one parent should be selected to proceed. Otherwise the application will return an error.
    - tag items as on sale
        + this fuction is only available when viewing the items table
    - managing on sale items
        + update information
        + remove all expired on sale items
* As customer (registered user or guest): the options in the application should be self-explanatory
    - search by category
        + choose category, subcategory in the combo box then click view.
        + after choosing main category, only subcategories that belongs to the main category will be shown in the second combo box.
    - search by name
        + after seaching, return to tab "view and add" to add items shown to the cart
    - show all items on sale
        + clicked the corresponding button
    - add items to cart
        + select appropriate quantity in the spin box, then clicked the button
        + the spin box and the button will only be available when items are shown on the right side
    - view cart by clicking the button on "cart" tab
    - update items quantity in cart by inputting id, desired quantity then click the button on "cart" tab
    - check out
        + if some quantity of item exceed the stock in database, an error message with show that
        + this button clears all items in cart, decrease appropriate amount of unit for the items' stock in the database



