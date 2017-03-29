// ConsoleApplication10.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include <ctime>
#include <stdio.h>

class BankAccount
{
protected:
	int AccountNumber;
	double balance;
	double interest;
	int term;


public:
	BankAccount() {};
	BankAccount(int a, int b)
	{
		// a - account
		// b - balance
		balance = b;
		AccountNumber = a;
	}
	virtual void withdraw() = 0;
	virtual void deposit() = 0;
	virtual void display() = 0;
	virtual void UserInput() = 0;
	virtual void sbalance() = 0;
	virtual void cdbalance() = 0;
	virtual void checks() = 0;
	virtual void monthly() = 0;
	string response;

};

class Savings : public BankAccount
{
public:
	Savings() {};
	Savings(int a, int b) : BankAccount(a,b)
	{	
		
	}
	int AccountQ;
	virtual void UserInput();
	virtual void sbalance();
	virtual void withdraw();
	virtual void deposit();
	virtual void monthly();
	virtual void display();
	virtual void cdbalance();
	virtual void checks();
};

class Checking : public BankAccount
{
public:
	Checking() {};
	Checking(int a, int b) : BankAccount(a,b)
	{
		balance = 600;
	}
	int AccountQ;
	virtual void UserInput();
	virtual void withdraw();
	virtual void deposit();
	virtual void checks();
	virtual void display();
	virtual void monthly();
	virtual void sbalance();
	virtual void cdbalance();

};
class CD : public BankAccount
{
public:
	CD() {};
	CD(int a, int b) : BankAccount(a, b)
	{
		balance = 10000;
		term = 3;
	}
	int AccountQ;
	virtual void UserInput();
	virtual void cdbalance();
	virtual void display();
	virtual void withdraw();
	virtual void deposit();
	virtual void sbalance();
	virtual void monthly();
	virtual void checks();
};

void Savings::cdbalance()
{}
void Savings::checks()
{}
void Savings::UserInput()
{
	cout << "Do you want to 1-deposit or 2-withdraw?" << endl;
	cin >> AccountQ;
}
void Savings::sbalance()
{
	double beforebal;
	if (balance < 10000)
	{
		interest = .01;
	}
	else
	{
		interest = .02;
	}
	beforebal = balance * interest;
	balance = balance + beforebal;
}
void Savings::withdraw()
{
		balance = balance - 2;
		int amount;
		cout << "Please enter the amount you wish to withdrawl" << endl;
		cin >> amount;
		if (amount >= 0)
			balance = balance - amount;
}
void Savings::deposit()
{
	int amount;
	cout << "Enter amount you wish to deposit" << endl;
	cin >> amount;
	if (amount >= 0)
		balance = balance + amount;
}
void Savings::monthly()
{
	balance = balance + (balance * (interest / 100) / 12);

}
void Savings::display()
{
	cout << "Account Number:" << AccountNumber << endl;
	cout << "Interest:" << interest << endl;
	cout << "Balance:" << balance << endl;

}


void Checking::UserInput()
	{
		cout << "Do you want to 1-deposit or 2-withdraw?" << endl;
		cin >> AccountQ;
	}
void Checking::withdraw()
{
	{
		int amount;
		cout << "Please enter the amount you wish to withdrawl" << endl;
		cin >> amount;
		if (balance < 600)
			balance = balance - 5;
	}
}
void Checking::deposit()
		{
			int amount;
			cout << "Enter amount you wish to deposit" << endl;
			cin >> amount;
			if (amount >= 0)
				balance = balance + amount;
		}
void Checking::checks()
		{
			cout << "Would you like to order checks? Please enter Y if yes" << endl;
			cin >> response;
			if (response == "Y" || response == "y")
				balance = balance - 15;
		}
void Checking::display()
		{
			cout << "Account Number:" << AccountNumber << endl;
			cout << "Balance:" << balance << endl;

		}
void Checking::sbalance()
{}
void Checking::cdbalance()
{}
void Checking::monthly()
{}

void CD::UserInput()
{
	cout << "Do you want to 1-deposit or 2-withdraw?" << endl;
	cin >> AccountQ;
}
void CD::cdbalance()
{
	double before;
	if (term >= 5)
	{
		interest = .1;
		before = balance * .1;
		balance = balance + before;
	}
	else if (term < 5)
	{
		interest = .05;
		before = balance * .05;
		balance = balance + before;
	}
}
void CD::monthly()
{
	balance = balance + (balance * (interest / 100) / 12);
}
void CD::deposit()
{
	int amount;
	cout << "Enter amount you wish to deposit" << endl;
	cin >> amount;
	if (amount >= 0)
		balance = balance + amount;
}
void CD::withdraw()
{
	int amount;
	cout << "Please enter the amount you wish to withdrawl" << endl;
	cin >> amount;
	if (amount < term)
		balance = balance * .1;
	else
	{
		balance = balance - amount;
	}
}
void CD::display()
{
	cout << "Account Number:" << AccountNumber << endl;
	cout << "Interest:" << interest << endl;
	cout << "Balance:" << balance << endl;
}
void CD::sbalance()
{}

void CD::checks()
{}

int main()
		{
			BankAccount*BankAccount[100];
			int account;
			int Get_Account;
			int AccountNumber;
			int Type = 3;
			cout << "Please enter your account number" << endl;
			cin >> AccountNumber;
			cin.ignore();
			cin.clear();
			
				cout << "What type of account do you wish to open today? Please only enter 1-Savings, 2-Checking, or 3-CD." << endl;
				cin >> account;
				

				if (account == 1)
				{
					cin.ignore();
					cin.clear();
					BankAccount[AccountNumber] = new Savings(AccountNumber,10000);
					cout << "Do you want to 1-Deposit or 2-Withdraw" << endl;
					cin >> Get_Account;
					
				if (Get_Account == 1)
				{ 
					BankAccount[AccountNumber]->deposit();
				}
				else if (Get_Account == 2)
				{
					BankAccount[AccountNumber]->withdraw();
				}
				else {}
				cin.ignore();
				cin.clear();
				BankAccount[AccountNumber]->sbalance();
				BankAccount[AccountNumber]->monthly();
				BankAccount[AccountNumber]->display();

				}
				else if (account == 2)
				{
					cin.ignore();
					cin.clear();
					BankAccount[AccountNumber] = new Checking(AccountNumber, 10000);
					cout << "Do you want to 1-Deposit or 2-Withdraw" << endl;
					cin >> Get_Account;
				if (Get_Account == 1)
				{
					BankAccount[AccountNumber]->deposit();
				}
				else if (Get_Account == 2)
				{
					BankAccount[AccountNumber]->withdraw();
				}
				else {}
				cin.ignore();
				cin.clear();
				BankAccount[AccountNumber]->checks(); 
				BankAccount[AccountNumber]->display();

}
				else if (account == 3)
				{
					cin.ignore();
					cin.clear();
					BankAccount[AccountNumber] = new CD(AccountNumber, 10000);
					cout << "Do you want to 1-Deposit or 2-Withdraw" << endl;
					cin >> Get_Account;
				if (Get_Account == 1)
				{
					BankAccount[AccountNumber]->deposit();
				}
				else if (Get_Account == 2)
				{
					BankAccount[AccountNumber]->withdraw();
				}
				else {}
				cin.ignore();
				cin.clear();
				BankAccount[AccountNumber]->display();
				BankAccount[AccountNumber]->monthly();
				BankAccount[AccountNumber]->cdbalance();
}
				else
				{
				}

				char s[50];
				time_t  t = time(NULL);
				int e;
				e = ctime_s(s, 50, &t);
				if (e) puts("Time");
				else puts(s);
				//I found this on google, it works but it doesn't stamp it in the right format. Every time I tried to do it dd/mm/yyyy, it would give me an error that it was unsafe? Not sure why, I tried to investigate but google gave me the output that I included. I included it here mainly for my reference to learn more about later. 
				
			return 0;

		}