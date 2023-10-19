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
		cout << "\n_______________________\n\n";
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
		_DrawScreenHeader("\t Transfer Amount\n");
		cout << "\nPlease Enter client Account Number Transfer From : ";
		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(Client1);

		cout << "\nPlease Enter client Account Number Transfer To : ";
		clsBankClient Client2 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(Client2);

		cout << "\nPlease Enter Transfer amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure want perform this Operation? y / n ? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Transfer(Amount, Client2, CurrentUser.UserName))
			{
				cout << "\nThe amount has been transferred successfully :) \n\n";
				
			}
			else
			{
				cout << "\nOperation Canceled !\n\n";
			}
			
		}
		
		_PrintClient(Client1);
		_PrintClient(Client2);

	}


};

