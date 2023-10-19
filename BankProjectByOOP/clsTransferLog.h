#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsDate.h"

using namespace std;

class clsTransferLog : clsScreen
{
private:

	static void _PrintLoginRecord(clsBankClient::stLoginBankClient TransferLoginLog)
	{

		cout << setw(8) << left << "" << "| " << setw(25) << left << TransferLoginLog.DateTime;
		cout << "| " << setw(12) << left << TransferLoginLog.surAcct;
		cout << "| " << setw(12) << left << TransferLoginLog.desAcct;
		cout << "| " << setw(12) << left << to_string(TransferLoginLog.Amount);
		cout << "| " << setw(15) << left << to_string(TransferLoginLog.surBalance);
		cout << "| " << setw(15) << left << to_string(TransferLoginLog.desBalance);
		cout << "| " << setw(12) << left << TransferLoginLog.UserName;
	}

public:

	static void ShowTransferLog()
	{
		vector <clsBankClient::stLoginBankClient> vLoginRegisterRecord = clsBankClient::GetLoadTransferLog();


		string Title = "\t Transfer Log";
		string SubTitle = "\t (" + to_string(vLoginRegisterRecord.size()) + ") Clients ";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t================================================";
		cout << "==============================================================================\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(25) << left << "DateTime";
		cout << "| " << setw(12) << left << "s.Acct";
		cout << "| " << setw(12) << left << "d.Acct";
		cout << "| " << setw(12) << left << "Amount";
		cout << "| " << setw(15) << left << "s.Balance";
		cout << "| " << setw(15) << left << "d.Balance";
		cout << "| " << setw(12) << left << "User Name";
		cout << setw(8) << left << "" << "\n\t================================================";
		cout << "==============================================================================\n" << endl;


		if (vLoginRegisterRecord.size() == 0)
			cout << "\n\t\t\tNo LoginRegisterRecord Available In the System!";

		for (clsBankClient::stLoginBankClient C : vLoginRegisterRecord)
		{
			_PrintLoginRecord(C);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t================================================";
		cout << "==============================================================================\n" << endl;

	
	}

};

