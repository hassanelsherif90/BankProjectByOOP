#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsTransferScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nCard Client\n";
		cout << "_______________________";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
	}

	static string _ReadAccountNumber()
	{
		string Account_Number = "";
		Account_Number = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(Account_Number))
		{
			cout << "\nAccount number is not found, choose another one: ";
			Account_Number = clsInputValidate::ReadString();
		}
		return Account_Number;
	}

public :

	static void ShowTransferScreen()
	{
		cout << "\nPlease Enter client Account Number Transfer From : ";
		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(Client1);

		cout << "\nPlease Enter client Account Number Transfer To : ";
		clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(Client2);

		cout << "\nPlease Enter Transfer amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure want perform this transaction? y / n ? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Client1.Withdraw(Amount);
			Client2.Deposit(Amount);
			cout << "\nAmount Transfer Successfully :) \n\n";
			_PrintClient(Client1);
			_PrintClient(Client1);
		}
		else
		{
			cout << "\nOperation Canceled !\n\n";
		}

	}


};

