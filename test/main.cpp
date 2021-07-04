// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "DBManager.h"
using namespace std;




int main(int argc, char* argv[]){
	MySQLInterface UsrCtrl;
	MySQLInterface MySQLInterface;
	char hst[] = "cs348-project.c56bjewfihhr.us-east-2.rds.amazonaws.com"; //host name
	char db[] = "DB1"; //database
	char uc[] = "UsrCtrl"; //the user control
	char uc_pw[] = "123456"; //the password for user control admin
	char* usr = new char[24]; //user
	char* pw = new char[10]; //password
	int choice;
	UsrCtrl.SetMySQLConInfo(hst, uc, uc_pw, db, 3306);

	//login section

	choice = pnf(0);


	

	cin >> usr;
	cout << "Please enter your password:" << endl; //idk how to hide the password from screen
	cin >> pw;


	MySQLInterface.SetMySQLConInfo(hst, usr, pw, db, 3306);

	if (!MySQLInterface.Open()){
		cout << MySQLInterface.ErrorNum << " : " << MySQLInterface.ErrorInfo << endl;
		exit(1);
	}

	//menu
	int choice = 0;
	while (true) {
		cout << "\nYou are in database " << db << ".\nPlease choose an operation:" << endl;
		cout << "1. Display items\n"
			<< "2. Display select query\n"
			<< "3. Enter query\n"
			<< "4. Search by category\n"
			<< "5. Search by name\n"
			<< "0. Quit" << endl;

		cin >> choice;
		cin.clear();
		cin.ignore();

		if (choice == 0) break;

		string sqlstr, qname;
		vector<vector<string>> data;

		switch (choice) {
		case 1:
			// simple query

			sqlstr = "SELECT * FROM `DB1`.`test`;";
			errSelect(data, sqlstr, MySQLInterface);

			break;

		case 2:

			// simple query
			cout << "\nPlease enter your query:" << endl;
			getline(cin, sqlstr);
			errSelect(data, sqlstr, MySQLInterface);

			break;

		case 3:
			//do the query
			cout << "\nPlease enter your query:" << endl;
			getline(cin, sqlstr);
			if (sqlstr.substr(0, 2) == "--") break;
			errQuery(sqlstr, MySQLInterface);
			break;

		case 4:
			//search by category
			cout << "Enter the name of the category: " << endl;
			cin >> qname;
			cout << endl;
			sqlstr = "select * from items inner join ( select iid from isMemberOf inner join ( select cid from categories where categories.name = '" + qname + "' ) as query_cid on isMemberOf.cid = query_cid.cid) as query_table on items.iid = query_table.iid";
			errSelect(data, sqlstr, MySQLInterface);
			break;

		case 5:
			//search by name
			cout << "Enter the name of search: " << endl;
			cin >> qname;
			cout << endl;
			sqlstr = "select * from items where name like '%" + qname + "%'";
			errSelect(data, sqlstr, MySQLInterface);
			break;
		default:
			break;
		}

		choice = 0;
	}




	MySQLInterface.Close();




	return 0;

}