// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "sql_api.h"
using namespace std;

//display data
void display(vector<vector<string>>& data) {
	for (unsigned int i = 0; i < data.size(); ++i) {
		for (unsigned int j = 0; j < data[0].size(); ++j)
			cout << data[i][j] << "\t\t\t";
		cout << endl;
	}
}

//display selected items with error testing
void errSelect(vector<vector<string>>& data, string sqlstr, MySQLInterface& MySQLInterface) {
	if (!MySQLInterface.Select(sqlstr, data))
		cout << MySQLInterface.ErrorNum << " : " << MySQLInterface.ErrorInfo << endl;

	// display data
	cout << endl;
	display(data);
}

//do the query displaying error testing
void errQuery(string sqlstr, MySQLInterface& MySQLInterface) {
	if (!MySQLInterface.Query(sqlstr))
		cout << MySQLInterface.ErrorNum << " : " << MySQLInterface.ErrorInfo << endl;
}


int main(int argc, char* argv[]){
	MySQLInterface MySQLInterface;
	char hst[] = "localhost"; //host name
	char db[] = "testDB"; //database
	char* usr = new char[24]; //user
	char* pw = new char[10]; //password

	//login section

	cout << "Welcome to the <name> database system.\nPlease enter you user name:" << endl;
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

			sqlstr = "SELECT * FROM `testDB`.`Items`;";
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