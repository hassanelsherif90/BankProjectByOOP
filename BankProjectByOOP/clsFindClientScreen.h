#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

public :

    static void ShowFindClient()
    {
        _DrawScreenHeader("\tFind Client\n");

        string Account_Number;

        cout << "\nPlease Enter client Account Number : ";
        Account_Number = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(Account_Number))
        {
            cout << "\nAccount number is not found, choose another one: ";
            Account_Number = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(Account_Number);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :)\n";
        }
        else
        {
            cout << "\nClient Not Found :(\n";
        }
        _PrintClient(Client1);
    }
};

