#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private :

	enum enUsersMenuOptions
	{
		enListUsers = 1,
		enAddNewUser = 2,
		enDeleteUser = 3,
		enUpdateUser = 4,
		enFindUser = 5,
		enMainMenu = 6
	};

	static short ReadManageUsersMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

    static void _GoBackToManageUsersMenu()
    {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>0");
        ShowManageUsersMenu();
    }

    static void _ShowListUsersScreen()
    {
        //cout << "\nList Users Screen Will Be Here.\n";
        clsUserListScreen::ShowUserList();

    }

    static void _ShowAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::ShowAddNewUser();
    }

    static void _ShowDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will Be Here.\n";
        clsDeleteUserScreen::ShowDeleteUser();

    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will Be Here.\n";
        clsUpdateUserScreen::ShowUpdateUser();
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }

    static void _PerformManageUsersMenuOption(enUsersMenuOptions ManageUsersMenuOption)
    {

        switch (ManageUsersMenuOption)
        {
        case enUsersMenuOptions::enListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enUsersMenuOptions::enAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enUsersMenuOptions::enDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enUsersMenuOptions::enUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enUsersMenuOptions::enFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }

        case enUsersMenuOptions::enMainMenu:
        {
            //do nothing here the main screen will handle it :-) ;
        }

        }

    }

public:

    static void ShowManageUsersMenu()
    {

        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageUsersMenuOption((enUsersMenuOptions)ReadManageUsersMenuOption());
    }

};

