#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsUser.h"

class clsLoginScreen : protected clsScreen
{
private :

	static void _Login()
	{
		bool LoginFailed = false;
		string UserName, PassWord;

		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalided UserName OR PassWord ? \n";
			}
			cout << "\nEnter User Name : ";
			cin >> UserName;
			
			cout << "\nEnter PassWord : ";
			cin >> PassWord;

			CurrentUser = clsUser::Find(UserName, PassWord);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();

	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Log In");
		_Login();
	}
};

