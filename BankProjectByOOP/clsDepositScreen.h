#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsDepositScreen : protected clsScreen
{

private :

	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n__________________________";
		cout << "\nFirstName    : " << Client.FirstName;
		cout << "\nLastName     : " << Client.LastName;
		cout << "\nFull Name    : " << Client.FullName();
		cout << "\nEmail        : " << Client.Email;
		cout << "\nPhone        : " << Client.Phone;
		cout << "\nAcc. Number  : " << Client.AccountNumber();
		cout << "\nPassword     : " << Client.PinCode;
		cout << "\nBalance      : " << Client.AccountBalance;
		cout << "\n__________________________";
	}
public:
	static void ShowTransactionsDeposit()
	{

		_DrawScreenHeader("\tDeposit Screen\n");

		cout << "\nPlease Enter client Account Number : ";

		string AccountNumber = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease Enter Deposit amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure want perform this transaction? y / n ? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Client.Deposit(Amount);

			cout << "\nAmount Deposit Successfully :) \n";
			cout << "\nNew Balances : " << Client.AccountBalance << endl;

		}
		else
		{
			cout << "\nOperation Canceled !\n\n";
		}

	}
};

