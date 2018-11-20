// ass4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string data_container[5];


fstream clientsdata("data.txt", ios::in | ios::out | ios::app);


class BankApplication
{

private:

	string name;
	string ID;
	string indicator = "1";


public:
	BankApplication(string name, string ID) {
		this->name = name;
		this->ID = ID;

	}
	string getting() { return ID; }


	BankApplication()
	{

		name = "NULL";
		ID = "NULL";
		indicator = "NULL";
	}

	void inputs(string indicator)
	{

		if (indicator == "1")
		{

			cout << "adding new client" << endl;



		}
		else
		{


		}



	}


	string getName() {



		return name;
	}

};


class BankAccount
{

protected:
	string ID;

	float balance;
	BankApplication b1;
public:
	BankAccount() {}
	BankAccount(float x, BankApplication bank1) :balance(x), b1(bank1) {}
	
	void setBalance(float balance) { (*this).balance = balance; }
	float  getBalance() { return balance; }


	//process in money
	void withdraw(float x) { balance = balance - x; }
	void deposit(float x) { balance = balance + x; }

};



class SavingsBankAccount :public BankAccount {
private:
	float minimumBalance=0;

public:
	
	
	void setBalance(float minimumBalance) {

		if (minimumBalance >= 100)
		{
			
			
			(*this).minimumBalance = minimumBalance;
			balance = minimumBalance; 
			
		}
		else
		{
			cout << "you have to set balance at least with 100$" << endl;

		}
	
	}
	
	
	void withdraw(float x)
	{

		if (balance - x >= minimumBalance)
		{
			cout << "please wait wile transaction is processing" << endl;
			balance = balance - x;
		}
		else
		{

			cout << "account have it's minimum balance" << endl;
		}

	}
	void deposit(float x) {

		if (x >= 100)
		{
			cout << "please wait wile transaction is processing" << endl;
			balance = balance + x;
			
		}
		else
		{

			cout << "field process you have to add more than 100$" << endl;

		}
		
	}


};

class Client {

private:

	string clientAdree;
	string phoneNumber;
	BankAccount type1bank;
	SavingsBankAccount type2bank;
	BankApplication using1;

public:

	Client() { ; clientAdree = "NULL"; phoneNumber = "NULL"; }
	Client(string y, string z, BankAccount dayday, BankApplication us1) : clientAdree(y), phoneNumber(z), type1bank(dayday), using1(us1) {}
	Client(string y, string z, SavingsBankAccount daydayy, BankApplication us1) : clientAdree(y), phoneNumber(z), type2bank(daydayy),using1(us1) {}


	void withdraw1(int x)
	{
		type1bank.withdraw(x);
		getClientData();
	}
	
	void withdraw2(int x)
	{
		
		type2bank.withdraw(x);
		getClientData2(); 
	}

	 void deposit33(int x)
	{
		type1bank.deposit(x);
		getClientData();

	}

	 void deposit2(int x)
	 {
		 type2bank.deposit(x);
		 getClientData2();
	 }

	 void getClientData2() {

		 data_container[0] = using1.getName();
		 data_container[1] = clientAdree;
		 data_container[2] = phoneNumber;
		 data_container[3] = using1.getting();
		 data_container[4] = to_string(type2bank.getBalance());
		// clientsdata << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' <<"saving"<< endl;
		 for (int i = 0; i < 5; i++)
		 {
			 
			 cout << data_container[i] << " ";
		 }
		 cout << endl;
		 


	 }

	void getClientData() {



		data_container[0] = using1.getName();
		data_container[1] = clientAdree;
		data_container[2] = phoneNumber;
		data_container[3] = using1.getting();
		data_container[4] = to_string(type1bank.getBalance());
		
		//clientsdata << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' <<"checkking" <<endl;
		for (int i = 0; i < 5; i++)
		{
			
			cout << data_container[i] << " ";
		}
		cout << endl;
		

	}

	void getClientDataforcheckking() {

		data_container[0] = using1.getName();
		data_container[1] = clientAdree;
		data_container[2] = phoneNumber;
		data_container[3] = using1.getting();
		data_container[4] = to_string(type1bank.getBalance());
		clientsdata<< data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' <<"checkking" <<endl;
		
	}

	void getClientDataforsaving() {

		data_container[0] = using1.getName();
		data_container[1] = clientAdree;
		data_container[2] = phoneNumber;
		data_container[3] = using1.getting();
		data_container[4] = to_string(type2bank.getBalance());
		 clientsdata << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' <<"saving"<< endl;
		


	}

	//***********************










	//*************************
};





class dataa  {
private:
	string insertedID; 
	string data[6];
	string injection; 
	string choice;
	int p; 
	string testing[4];
	string tes[6];

public:
	string bankingSytemIndicator;

	void settingid() {

		ifstream IDS2("IDS.txt");
		IDS2 >> p;
		cout << "p : " <<p<< endl;
		IDS2.close();
		ofstream IDS;
		IDS.open("IDs.txt");
		p++; 
		string x = to_string(p);
		IDS << x ;
		IDS.close();
	}
	void start() {
		cout << R"( "WELCOM TO FCI SEMI BANKING MANAGEMENT SYSTEM"

							1. PRESS '1' TO ADD NEW ACCOUNT 
							2. PRESS '2' TO DEPOSIT IN ACCOUNT 
							3. PRESS '3' TO WITTHDRAW FROM ACCOUNT 
							4. PRESS '4' TO LIST ALL ACCOUNTS
							5. PRESS '5' TO EXIST 


 )";

		

		getline(cin, choice);

		if (choice == "1")
		{

			addnewacount();
		}
		if (choice == "2")
		{
			float ammount; 
			cout << "Enter an Ammount of Money" << endl;
			cin >> ammount; 
			deposit(ammount);

		}
		if(choice=="3")
		{
			float ammount;
			cout << "Enter an Ammount of Money" << endl;
			cin >> ammount;
			wizdaraw(ammount);
			
		}
		if (choice == "4")
		{

			listingallclients();

		}
		if (choice == "5")
		{
			cout << "CLOSING . . ." << endl;
			Existsystem();

		}

	}
	void deposit(float ammount){
		fstream clientsdata1000("newdata.txt", ios::in | ios::out | ios::app);

		
		string x;
		string m;

		cout << "please enter your ID number"; 
		cin >> x;
		
		while (getline(clientsdata,m))

		{
			
			cout << "m is : " << m << endl;

			
			
			
			
			
			
			texthandling(m);

			if (x == tes[0])
			{
				

				cout << "your accout has been founded succseefully" << endl; 
				
				for (int i = 0; i < 6; i++)
				{
					cout << tes[i]<<" "; 
				}
				cout << endl;

				

				if (tes[5] == "checkking")
				{

					cout << "your account is checkking" << endl;
					BankApplication a(tes[1],tes[0]);
					BankAccount account1;
					account1.setBalance(stoi(tes[4]));
					Client cl(tes[2], tes[3], account1, a);
					cl.deposit33(ammount); 
					clientsdata1000<< data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' << "checkking" << endl;


				}
				else
				{


					cout << "your account is saving" << endl;
					BankApplication a(tes[1], tes[0]);
					SavingsBankAccount account2;
					account2.setBalance(stoi(tes[4]));
					Client cl(tes[2], tes[3], account2, a);
					cl.deposit2(ammount);
					clientsdata1000 << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' << "saving" << endl;



				}



			}
			else
			{
				
				cout << "copy" << endl;

				clientsdata1000 << tes[0] << ',' << tes[1] << ',' << tes[2] << ',' << tes[3] << ',' << tes[4] << ',' << tes[5] << endl;


				
			}

		}

		
		clientsdata1000.close();
		clientsdata.close();
		remove("data.txt");
		rename("newdata.txt", "data.txt");
		
	
	}
	void wizdaraw(float ammount) {
		fstream clientsdata1000("newdata.txt", ios::in | ios::out | ios::app);


		string x;
		string m;

		cout << "please enter your ID number";
		cin >> x;

		while (getline(clientsdata, m))
		{
			texthandling(m);

			if (x == tes[0])
			{

				cout << "your accout has been founded succseefully" << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << tes[i] << " ";
				}
				cout << endl;
				if (tes[5] == "checkking")
				{

					cout << "your account is checkking" << endl;
					BankApplication a(tes[1], tes[0]);
					BankAccount account1;
					account1.setBalance(stoi(tes[4]));
					Client cl(tes[2], tes[3], account1, a);
					cl.withdraw1(ammount);
					clientsdata1000 << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' << "checkking" << endl;


				}
				else
				{


					cout << "your account is saving" << endl;
					BankApplication a(tes[1], tes[0]);
					SavingsBankAccount account2;
					account2.setBalance(stoi(tes[4]));
					Client cl(tes[2], tes[3], account2, a);
					cl.withdraw2(ammount);
					clientsdata1000 << data_container[3] << ',' << data_container[0] << ',' << data_container[1] << ',' << data_container[2] << ',' << data_container[4] << ',' << "saving" << endl;


				}

			}
			else
			{
				clientsdata1000 << tes[0] << ',' << tes[1] << ',' << tes[2] << ',' << tes[3] << ',' << tes[4] << ',' << tes[5] << endl;

			}

		}

		
		clientsdata1000.close();
		clientsdata.close();
		remove("data.txt");
		rename("newdata.txt", "data.txt");

	}
	void addnewacount() {

		cout << "Please enter your name: " << " ";
		getline(cin, injection);
		data[0] = injection;
		cout << "Please enter your adress: " << " ";
		getline(cin, injection);
		data[1] = injection;
		cout << "Please enter your phone: " << " ";
		getline(cin, injection);
		data[2] = injection;
		cout << "Please enter your bank account type (checkking,savaing): " <<" ";
		getline(cin, injection);
		data[3] = injection;
		
		if (data[3] == "checkking")
		{
			setbasicaccount();
		}
		else
		{
			setNONbasicaccount();

		}
		

		

	}
	void setbasicaccount()    {
	

		settingid(); 


		BankApplication b1(data[0], to_string(p));
		BankAccount ac1;
		//------------------------
		cout << "Please insertr ammount of money: " << " ";
		getline(cin, injection);
		data[4] = injection;
		//------------------------

		
		ac1.setBalance(stoi(data[4]));
		Client cl(data[1], data[2], ac1, b1);
		cl.getClientDataforcheckking();


		
	
	}
	void setNONbasicaccount() {	
		settingid();
		BankApplication b2(data[0], to_string(p));
		SavingsBankAccount ac2;
		here:
		cout << "Please insertr ammount of money: " << " ";
	
		getline(cin, injection);
		data[4] = injection;

		if (stoi(data[4]) < 100)
		{

			ac2.setBalance(stoi(data[4]));
			goto here;

		}
		else
		{
			
			ac2.setBalance(stoi(data[4]));
			Client cl(data[1], data[2], ac2, b2);
			cl.getClientDataforsaving();

		}

		
		
	}
	void texthandling(string x) {


		cout << "iam called" << endl;
		string raw;
		string temp;
		int f = 0;

		for (int i = 0; i < x.size(); i++)
		{

			if (x[i] != ',')
			{
				raw += x[i];

			}

			else
			{
				tes[f] = raw;
				f++;

				raw = "";


			}

		}

		raw = "";
		for (int i = x.size() - 1; i > 0; i--)
		{

			if (x[i] != ',')
			{
				raw += x[i];

			}
			else
			{
				for (int j = raw.size() - 1; j >= 0; j--)
					temp += raw[j];
				tes[5] = temp;
				break;

			}
		}








	}
	void listingallclients(){
		string m; 
		while (getline(clientsdata, m))
		{
			cout << m << endl;

		}
	}
	void Existsystem(){
	
		bankingSytemIndicator = "yes";
	
	}
		
};



void getgraphics() {


	cout << R"(
     __          ________ _      _____ ____  __  __ ______   _______ ____    ______ _____ _____    _______     _______ _______ ______ __  __  _____ 
     \ \        / /  ____| |    / ____/ __ \|  \/  |  ____| |__   __/ __ \  |  ____/ ____|_   _|  / ____\ \   / / ____|__   __|  ____|  \/  |/ ____|
      \ \  /\  / /| |__  | |   | |   | |  | | \  / | |__       | | | |  | | | |__ | |      | |   | (___  \ \_/ / (___    | |  | |__  | \  / | (___  
       \ \/  \/ / |  __| | |   | |   | |  | | |\/| |  __|      | | | |  | | |  __|| |      | |    \___ \  \   / \___ \   | |  |  __| | |\/| |\___ \ 
        \  /\  /  | |____| |___| |___| |__| | |  | | |____     | | | |__| | | |   | |____ _| |_   ____) |  | |  ____) |  | |  | |____| |  | |____) |
         \/  \/   |______|______\_____\____/|_|  |_|______|    |_|  \____/  |_|    \_____|_____| |_____/   |_| |_____/   |_|  |______|_|  |_|_____/ 
                                                                                                                                                
                                                                                                                                                                                                                                                  
                                                                                                                                         
     )";


}


int main()
{
	string choicesystem; 
	while (true)
	{

		getgraphics();
		cout << "                                                   ENTER 1 TO USE BANKING MANAGEMENT SYSTEM  "; 
		here:
		getline(cin, choicesystem);
		if (choicesystem == "1")
		{
			while (true) {


				dataa d1;
				d1.start();
				if (d1.bankingSytemIndicator=="yes")
				{
					cout << "done" << endl;
					break; 
				}


			}
			


		}
		

	}
	

}