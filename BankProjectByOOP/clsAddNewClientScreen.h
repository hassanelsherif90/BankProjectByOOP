#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsAddNewClientScreen : protected clsScreen
{

private :
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
    static void ShowAddNewClient()
    {
        _DrawScreenHeader("\t  Add New Client\n");
        string AccountNumber;

        cout << "\nPlease Enter client Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is alraedy Used, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        cout << "\n\nAdd Client :\n";
        cout << "_____________________";

        _ReadClientInfo(NewClient);
        cout << "_____________________";

        clsBankClient::enSaveResults SaveResults;

        SaveResults = NewClient.Save();

        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Added Successfully :) \n";
            _PrintClient(NewClient);
            break;
        }

        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account was not saved bescouse it�s Empty :( \n";
            break;
        }
        case  clsBankClient::enSaveResults::svFaildAccountNumberExsit:
        {
            cout << "\nAccount number is alraedy Used";
            break;
        }
        }

        cout << endl;
    }
};

