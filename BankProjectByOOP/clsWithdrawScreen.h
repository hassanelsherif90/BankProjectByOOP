#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsWithdrawScreen : protected clsScreen
{

private:

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
	static void ShowTransactionsWithdraw()
	{

		_DrawScreenHeader("\tWithdraw Screen\n");

		cout << "\nPlease Enter client Account Number : ";

		string AccountNumber = clsInputValidate::ReadString();

		if (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease Enter Withdraw amount ? ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "\nAre you sure want perform this transaction? y / n ? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (!Client.Withdraw(Amount))
			{
				cout << "\nCannot withdraw, Insufficient Balance ! \n";
				cout << "\nAmount to withdraw amount ? " << Amount << endl;
				cout << "\nYour Balance is : " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "\nAmount Withdraw Successfully :) \n";
				cout << "\nNew Balances : " << Client.AccountBalance << endl;
			}
		}
		else
		{
			cout << "\nOperation Canceled !\n\n";
		}

	}
};
