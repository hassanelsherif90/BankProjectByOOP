#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsDeleteClientScreen : protected clsScreen
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
   static void  ShowDeleteClient()
    {
       _DrawScreenHeader("\t  Delete Client\n");
        string AccountNumber;

        cout << "\nPlease Enter client Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\nAre you Want to delete Account Number ? y / n ? ";

        char Answer = 'N';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (Client1.Delete())
            {
                cout << "\nClient Deleted Successfully :) .";
                _PrintClient(Client1);
            }
            else
            {
                cout << "\nError Client Was not Deleted .";
            }
        }
        else
        {
            cout << "\nClient Was not Deleted .";
        }

    }
};

