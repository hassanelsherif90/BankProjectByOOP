#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
{

private:
    static void _ReadClientInfo(clsBankClient& Client)
    {

        cout << "\nFirstName      : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nLastName       : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEmail          : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPhone          : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nPinCode        : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nAccountBalance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();

    }

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


public : 
	static void ShowUpdateClient()
{
        _DrawScreenHeader("\tUpdate Client\n");
    string Account_Number ;

    cout << "\nPlease Enter client Account Number : ";
    Account_Number = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(Account_Number))
    {
        cout << "\nAccount number is not found, choose another one: ";
        Account_Number = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(Account_Number);
   _PrintClient(Client1);


    cout << "\n\nUpadate Client :\n";
    cout << "_____________________";

    _ReadClientInfo(Client1);
    cout << "_____________________";

    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client1.Save();

    switch (SaveResults)
    {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Updated Successfully :) \n";
            _PrintClient(Client1);
            break;
        }
        
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account was not saved bescouse it�s Empty :( \n";
            break;
        }
    }
}

};

