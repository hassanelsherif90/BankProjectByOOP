#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"

using namespace std;

class clsTransactionsMenuScreen : protected clsScreen 
{
private :

	enum enTransactionsMenuOptions
	{
		enDeposit = 1,
		enWithdraw = 2,
		enTotalBalance = 3,
		eShowMainMenu = 4
	};


	static short _ReadTransactionsMenuOption()
	{
		cout << setw(37) << left << "" << "What do you want to do ? [1 to 4] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Please choice Between 1 to 4 ? ");
		return Choice;
	}

	static void _ShowTransactionsDeposit()
	{
		//cout << "Transactions Deposit Will be here.........\n";
		clsDepositScreen::ShowTransactionsDeposit();
	}
	
	static void _ShowTransactionswithdraw()
	{
		//cout << "Transactions withdraw Will be here.........\n";
		clsWithdrawScreen::ShowTransactionsWithdraw();
	}

	static void _ShowTotalalBalance()
	{
		//cout << "Totalal Balance Will be here.........\n";
		clsTotalBalanceScreen::ShowTotalbalances();
	}

	static void _GoToBackTransactions()
	{
		cout << "\nPress any key to go back to Transactions Menu .....";
		system("pause>0");
		ShowTransactionsMenu();
	}

	static void _PerForTransactionsMenuOptions(enTransactionsMenuOptions TransactionsMenuOption)
	{
		switch (TransactionsMenuOption)
		{
			case enTransactionsMenuOptions::enDeposit:
			{
				system("cls");
				_ShowTransactionsDeposit();
				_GoToBackTransactions();
				break;
			}
			case enTransactionsMenuOptions::enWithdraw:
			{
				system("cls");
				_ShowTransactionswithdraw();
				_GoToBackTransactions();
				break;
			}

			case enTransactionsMenuOptions::enTotalBalance:
			{
				system("cls");
				_ShowTotalalBalance();
				_GoToBackTransactions();
				break;
			}
			case enTransactionsMenuOptions::eShowMainMenu:
			{

			}
		
		}
	}

public:
	
	static void ShowTransactionsMenu()
	{
		system("cls");
		_DrawScreenHeader("\tTransActions Menu Screen");
		cout <<setw(37) << left << "" << "=====================================================\n\n";
		cout <<setw(37) << left << "" << "\t\tTransActions Menu Screen\n\n";
		cout <<setw(37) << left << "" << "=====================================================\n";
		cout <<setw(37) << left << "" << "\t[1] Deposit.\n";
		cout <<setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout <<setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout <<setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout <<setw(37) << left << "" << "=====================================================\n";


		_PerForTransactionsMenuOptions((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

