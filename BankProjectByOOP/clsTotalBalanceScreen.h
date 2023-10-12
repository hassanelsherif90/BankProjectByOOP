#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
private:

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(15) << left << "" << "| " << left << setw(30) << Client.AccountNumber();
        cout << "| " << left << setw(30) << Client.FullName();
        cout << "| " << left << setw(20) << Client.AccountBalance;
    }                            

public:
    static void ShowTotalbalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Total balances";
        string SubTitle = "\t (" + to_string(vClients.size()) + ") Clients ";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(15) << left << "" << "\n\t=======================================================================================\n";

        cout << setw(15) << left << "" << "| " << left << setw(30) << "Account Number";
        cout << "| " << left << setw(30) <<  "Client Name";
        cout << "| " << left << setw(20) << "Balance";

        
      
        cout << setw(15) << left << "" << "\n\t=======================================================================================\n";
        double TotalBalances = clsBankClient::GetTotalBalances();


        if (vClients.size() == 0)
            cout << "\n\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient C : vClients)
            {
                PrintClientRecordLine(C);
                cout << endl;
            }

        cout << setw(15) << left << "" << "\n\t=======================================================================================\n";
        cout << "\t\t\t\t\tTotal Balances : " << TotalBalances << endl;
        cout << setw(15) << left << "" << "(" << clsUtil::NumberToText(TotalBalances) << ")\n";
        
    }
};

