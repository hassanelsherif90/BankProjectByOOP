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


}

int main()
{
    UpdateClient();
    system("pause>0");
}

