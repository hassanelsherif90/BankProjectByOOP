#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenuScreen.h"
#include "clsManageUsersScreen.h"

using namespace std;


class clsMainScreen : protected clsScreen 
{
private :

	enum enMainMenueOptions
	{
		eListClients = 1, eAddNewClient = 2,
		eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8

	};

	static short _ReadMainMenuOption()
	{
		cout << setw(37) << left << "" << "What do you want to do ? [1 to 8] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Please choice Between 1 to 8 ? ");
		return Choice;
	}

	static void _GoToBackMenu()
	{
		cout << setw(37) << left << "" << "Press any key to go back to Main Menu...\n ";
		system("pause>0");
		ShowMainMenu();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "Client List Screen Will be here.........\n";

		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		//cout << "Add New Client Screen Will be here.........\n";
		clsAddNewClientScreen::ShowAddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "Delete Client Screen Will be here.........\n";
		clsDeleteClientScreen::ShowDeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "Update Client Screen Will be here.........\n";
		clsUpdateClientScreen::ShowUpdateClient();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find Client Screen Will be here.........\n";
		clsFindClientScreen::ShowFindClient();
	}

	static void _ShowTransactionsMenuScreen()
	{
		//cout << "Transactions Menu Screen Will be here.........\n";
		clsTransactionsMenuScreen::ShowTransactionsMenu();
	}

	static void _ShowManageUsersMenu()
	{
		//cout << "Manage Users Screen Will be here.........\n";
		clsManageUsersScreen::ShowManageUsersMenu();
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen Will be here...\n";

	}

	static void _PerFormMainMenuOptions(enMainMenueOptions MainMenuOptions)
	{
		
		switch (MainMenuOptions)
		{
			case enMainMenueOptions::eListClients:
				{
					system("cls");
					_ShowAllClientsScreen();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eAddNewClient:
				{
					system("cls");
					_ShowAddNewClientScreen();
					_GoToBackMenu();
					break;

				}
			case enMainMenueOptions::eDeleteClient:
				{
					system("cls");
					_ShowDeleteClientScreen();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eUpdateClient:
				{
					system("cls");
					_ShowUpdateClientScreen();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eFindClient:
				{
					system("cls");
					_ShowFindClientScreen();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eShowTransactionsMenue:
				{
					system("cls");
					_ShowTransactionsMenuScreen();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eManageUsers:
				{
					system("cls");
					_ShowManageUsersMenu();
					_GoToBackMenu();
					break;
				}
			case enMainMenueOptions::eExit:
				{
					system("cls");
					_ShowEndScreen();
					break;
				}
		}

	}

public :

	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[ 1 ] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[ 2 ] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[ 3 ] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[ 4 ] Update Client.\n";
		cout << setw(37) << left << "" << "\t[ 5 ] Find Client.\n";
		cout << setw(37) << left << "" << "\t[ 6 ] Transaction.\n";
		cout << setw(37) << left << "" << "\t[ 7 ] Mange Users.\n";
		cout << setw(37) << left << "" << "\t[ 8 ] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";
		
		_PerFormMainMenuOptions((enMainMenueOptions)_ReadMainMenuOption());
	}
};

