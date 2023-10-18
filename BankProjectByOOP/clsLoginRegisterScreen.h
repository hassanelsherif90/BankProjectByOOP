#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"


using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintLoginRecord(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(12) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterRecordScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegisterRecord))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoadRegisterUser();


		string Title = "\t Login Register Record";
		string SubTitle = "\t (" + to_string(vLoginRegisterRecord.size()) + ") Clients ";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "PassWord";
		cout << "| " << left << setw(20) << "Permission";
		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;


		if (vLoginRegisterRecord.size() == 0)
			cout << "\n\t\t\tNo LoginRegisterRecord Available In the System!";

		for (clsUser::stLoginRegisterRecord C : vLoginRegisterRecord)
		{
			_PrintLoginRecord(C);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;

	}
};

