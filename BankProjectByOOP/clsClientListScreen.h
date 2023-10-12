#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen
{
private :

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;
    }

public:
	static void ShowClientsList()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Client List";
        string SubTitle = "\t (" + to_string(vClients.size()) + ") Clients ";
        
        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t___________________________________________";
        cout << "____________________________________________________________\n" << endl;
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t___________________________________________";
        cout << "____________________________________________________________\n" << endl;

        double TotalBalances = clsBankClient::GetTotalBalances();


        if (vClients.size() == 0)
            cout << "\n\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient C : vClients)
            {
                PrintClientRecordLine(C);
                cout << endl;
            }

        cout << setw(8) << left << "\n\t___________________________________________";
        cout << "____________________________________________________________\n" << endl;

        
        

    }
};

