#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsUser.h"

class clsLoginScreen : protected clsScreen
{
private :

	static bool _Login()
	{
		bool LoginFailed = false;
		string UserName, PassWord;

		int AccountLogin = 0;

		do
		{
			if (LoginFailed)
			{
				AccountLogin++;
				cout << "\nInvalided UserName OR PassWord ? \n";
				cout << "\nYou have " << 3 - AccountLogin << " Trials to login \n";

				if (AccountLogin == 3)
				{
					cout << "\nYour are Locked after 3 failed trials\n\n";
					return false;
				}

			}
			cout << "\nEnter User Name : ";
			cin >> UserName;
			
			cout << "\nEnter PassWord : ";
			cin >> PassWord;

			CurrentUser = clsUser::Find(UserName, PassWord);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);


		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();

		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Log In");
		return _Login();
	}
};

