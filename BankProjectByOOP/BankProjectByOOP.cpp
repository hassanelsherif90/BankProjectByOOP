#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient()
{
    string Account_Number ;

    cout << "\nPlease Enter client Account Number : ";
    Account_Number = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(Account_Number))
    {
        cout << "\nAccount number is not found, choose another one: ";
        Account_Number = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(Account_Number);
    Client1.Print();


    cout << "\n\nUpadate Client :\n";
    cout << "_____________________";

    ReadClientInfo(Client1);
    cout << "_____________________";

    clsBankClient::enSaveResults SaveResults;

    SaveResults = Client1.Save();

    switch (SaveResults)
    {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Updated Successfully :) \n";
            Client1.Print();
            break;
        }
        
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account was not saved bescouse it�s Empty :( \n";
            break;
        }
    }
}

void AddNewClient()
{
    string Account_Number;

    cout << "\nPlease Enter client Account Number : ";
    Account_Number = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(Account_Number))
    {
        cout << "\nAccount number is alraedy Used, choose another one: ";
        Account_Number = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(Account_Number);
 
    cout << "\n\nAdd Client :\n";
    cout << "_____________________";

    ReadClientInfo(NewClient);
    cout << "_____________________";

    clsBankClient::enSaveResults SaveResults;

    SaveResults = NewClient.Save();

    switch (SaveResults)
    {
        case clsBankClient::enSaveResults::svSucceded:
        {
            cout << "\nAccount Added Successfully :) \n";
            NewClient.Print();
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



int main()
{
    //UpdateClient();
    //AddNewClient();
    clsBankClient Client = clsBankClient::Find("A104000");
    Client.Print();

    system("pause>0");
}

