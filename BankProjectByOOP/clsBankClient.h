#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode{EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line, string Separator = "#//#")
	{
		vector <string> vClientDate = clsString::Split(Line, Separator);

		return clsBankClient(	enMode::UpdateMode, 
							vClientDate[0], vClientDate[1],
							vClientDate[2], vClientDate[3], 
							vClientDate[4], vClientDate[5],		
							stod(vClientDate[6]));

	}


	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string AccountNumber,
		string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	bool IsEmpty()
	{
		return ( _Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n__________________________";
		cout << "\nFirstName    : " << FirstName;
		cout << "\nLastName     : "<< LastName;
		cout << "\nFull Name    : " << FirstName + " " + LastName;
		cout << "\nEmail        : " << Email;
		cout << "\nPhone        : " << Phone;
		cout << "\nAcc. Number  : " << _AccountNumber;
		cout << "\nPassword     : " << _PinCode;
		cout << "\nBalance      : " << _AccountBalance;
		cout << "\n__________________________";
	}

	static clsBankClient Find(string AccountNumber)
	{

		vector <clsBankClient> vClients;

		fstream MyFile; 

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();

	}


	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

};

