#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencyScreen.h"
#include "clsFindCurrencyScreen.h"

using namespace std;

class clsCurrencyMainScreen : protected clsScreen
{
private:

	enum enCurrencyMainOptionts
	{
		eListCurrency = 1, eFindCurrency = 2,
		eUpdateCurrency = 3, eCurrencyCalculator = 4, enMainMenu = 5
	};

	static short _ReadChoiceOptions ()
	{
		cout << setw ( 37 ) << left << "" << "What do you want to do ? [1 To 5] ? ";
		short Choice;

		Choice = clsInputValidate::ReadShortNumberBetween ( 1 , 5 , "Please Choice Between 1 To 5 ? " );
		return Choice;
	}

	static void _ShowListCurrenciesScreen ()
	{
		//cout << "\nWill List Currencies been Here!.\n\n";
		clsListCurrencyScreen::ShowListCurrencyScreen ();
	}

	static void _ShowFindCurrencyScreen ()
	{
		//cout << "\nWill Find Currency Screen been Here!.\n\n";
		clsFindCurrencyScreen::ShowFindCurrency ();
	}

	static void _ShowUpdateCurrencyScreen ()
	{
		cout << "\nWill Update Currency Screen been Here!.\n\n";
	}

	static void _ShowCurrencyCalculatorScreen ()
	{
		cout << "\nWill  Currency Calculator Screen been Here!.\n\n";
	}

	static void _ShowMainMenu ()
	{
		
	}

	static void _GoToBackCurrencyMenu ()
	{
		cout << setw ( 37 ) << left << "" << "Press any key to go back to Main Menu...\n ";
		system ( "pause>0" );
		ShowMainExChangeCurrency ();
	}

	static void _PerFormCurrencyOptions ( enCurrencyMainOptionts Option )
	{
		switch ( Option )
		{
			case enCurrencyMainOptionts::eListCurrency:
				{
					system ( "cls" );
					_ShowListCurrenciesScreen ();
					_GoToBackCurrencyMenu ();
					break;
				}
			case enCurrencyMainOptionts::eFindCurrency:
				{
					system ( "cls" );
					_ShowFindCurrencyScreen ();
					_GoToBackCurrencyMenu ();
					break;
				}
			case enCurrencyMainOptionts::eUpdateCurrency:
				{
					system ( "cls" );
					_ShowUpdateCurrencyScreen ();
					_GoToBackCurrencyMenu ();
					break;
				}

			case enCurrencyMainOptionts::eCurrencyCalculator:
				{
					system ( "cls" );
					_ShowCurrencyCalculatorScreen ();
					_GoToBackCurrencyMenu ();
					break;
				}

			case enCurrencyMainOptionts::enMainMenu:
				{
					_ShowMainMenu ();
					break;
				}
		}
	}

public:

	static void ShowMainExChangeCurrency ()
	{
		system ( "cls" );
		_DrawScreenHeader ( "\t Currency ExChange Main Screen" );

		cout << setw ( 37 ) << left << "" << "============================================\n";
		cout << setw ( 37 ) << left << "" << "\t\t\tCurrency ExChange Main Menu\n";
		cout << setw ( 37 ) << left << "" << "============================================\n";
		cout << setw ( 37 ) << left << "" << "\t[ 1 ] List Currencies.\n";
		cout << setw ( 37 ) << left << "" << "\t[ 2 ] Find Currency.\n";
		cout << setw ( 37 ) << left << "" << "\t[ 3 ] Update Rate.\n";
		cout << setw ( 37 ) << left << "" << "\t[ 4 ] Currency Calculator.\n";
		cout << setw ( 37 ) << left << "" << "\t[ 5 ] Main Menu.\n";
		cout << setw ( 37 ) << left << "" << "============================================\n";

		_PerFormCurrencyOptions ( (enCurrencyMainOptionts) _ReadChoiceOptions () );
	}
};

