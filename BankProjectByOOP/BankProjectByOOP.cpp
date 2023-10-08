#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include  <iomanip>
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;



//void UpdateClient()
//{
//    string Account_Number ;
//
//    cout << "\nPlease Enter client Account Number : ";
//    Account_Number = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(Account_Number))
//    {
//        cout << "\nAccount number is not found, choose another one: ";
//        Account_Number = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client1 = clsBankClient::Find(Account_Number);
//    Client1.Print();
//
//
//    cout << "\n\nUpadate Client :\n";
//    cout << "_____________________";
//
//    ReadClientInfo(Client1);
//    cout << "_____________________";
//
//    clsBankClient::enSaveResults SaveResults;
//
//    SaveResults = Client1.Save();
//
//    switch (SaveResults)
//    {
//        case clsBankClient::enSaveResults::svSucceded:
//        {
//            cout << "\nAccount Updated Successfully :) \n";
//            Client1.Print();
//            break;
//        }
//        
//        case clsBankClient::enSaveResults::svFaildEmptyObject:
//        {
//            cout << "\nError Account was not saved bescouse it�s Empty :( \n";
//            break;
//        }
//    }
//}



//void DeleteClient()
//{
//    string AccountNumber;
//
//    cout << "\nPlease Enter client Account Number : ";
//    AccountNumber = clsInputValidate::ReadString();
//
//    while (!clsBankClient::IsClientExist(AccountNumber))
//    {
//        cout << "\nAccount number is not found, choose another one: ";
//        AccountNumber = clsInputValidate::ReadString();
//    }
//
//    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//    Client1.Print();
//
//    cout << "\nAre you Want to delete Account Number ? y / n ? ";
//
//    char Answer = 'N';
//    cin >> Answer;
//
//    if (Answer == 'y' || Answer == 'Y')
//    {
//        if (Client1.Delete())
//        {
//            cout << "\nClient Deleted Successfully :) .";
//            Client1.Print();
//        }
//        else
//        {
//            cout << "\nError Client Was not Deleted .";
//    }
//    } else
//    {
//        cout << "\nClient Was not Deleted .";
//    }
//
//}

                             




int main()
{
    clsMainScreen::ShowMainMenue();
    system("pause>0");
}

