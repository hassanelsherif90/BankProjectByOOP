#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrencyMainScreen.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private :

	static void _PrintCurrencyRecord (clsCurrency Currency)
	{
		cout << "\nCurrency Card";
		cout << "\n____________________________________\n";
		cout << "Country	   : " << Currency.Country () << endl;;
		cout << "Currency Code : " << Currency.CurrencyCode () << endl;
		cout << "Currency Name : " << Currency.CurrencyName () << endl;
		cout << "Rate (1$)     : " << Currency.Rate() << endl;
		cout << "\n____________________________________\n\n";
	}

	static void _ShowResult (clsCurrency Currency)
	{
		
		if ( !Currency.IsEmpty () )
		{
			cout << "\nCurrency Found :) \n";
			_PrintCurrencyRecord ( Currency );
		}
		else
		{
			cout << "\nCurrency Not Found :) \n\n";
		}
	}

public:
	static void ShowFindCurrency ()
	{
		_DrawScreenHeader ( "\t Find Currency " );

		cout << "\n Find By : [1] Code Or[2] Country ? ";
		short Answer = clsInputValidate::ReadShortNumberBetween(1, 2);
		

		if (Answer == 1 )
		{
			cout << "\nPlease Enter Code : ";
			string Code = clsInputValidate::ReadString ();
			clsCurrency Currency = clsCurrency::FindByCode( Code );
			_ShowResult ( Currency );

			
		}
		else
		{
			cout << "\nPlease Enter Country : ";
			string Country = clsInputValidate::ReadString ();
			clsCurrency Currency = clsCurrency::FindByCountry ( Country );
			_ShowResult ( Currency );

		}
	}
};

