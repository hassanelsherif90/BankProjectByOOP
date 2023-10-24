#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateCurrencyScreen: protected clsScreen
{
private :
	static void _PrintCurrencyRecord ( clsCurrency Currency )
	{
		cout << "\nCurrency Card";
		cout << "\n____________________________________\n";
		cout << "Country	   : " << Currency.Country () << endl;;
		cout << "Currency Code : " << Currency.CurrencyCode () << endl;
		cout << "Currency Name : " << Currency.CurrencyName () << endl;
		cout << "Rate (1$)     : " << Currency.Rate () << endl;
		cout << "\n____________________________________\n\n";
	}

	static float _ReadRate ()
	{
		cout << "\nEnter New Rate : ";
		float Rate = clsInputValidate::ReadFloatNumber ();
		return Rate;
	}

public:
	static void ShowUpdateCurrencyRateScreen ()
	{
		_DrawScreenHeader ( "\t Update Currency " );

		cout << "\nPlease Enter Code : ";
		string Code = "";
		Code = clsInputValidate::ReadString ();

		while ( !clsCurrency::IsCurrencyExist ( Code ) )
		{
			cout << "\nCurrency Not Found, Please Enter Code : ";
			Code = clsInputValidate::ReadString ();
		}

		clsCurrency Currency = clsCurrency::FindByCode ( Code );

		_PrintCurrencyRecord ( Currency );

		cout << "\nare you sure update currency rate ? y / n ? ";

		char Answer = 'n';

		cin >> Answer;

		if ( Answer == 'y' || Answer == 'Y' )
		{
			cout << "\nUpdate Rate ";
			cout << "\n____________________________\n";
			Currency.UpdateRate ( _ReadRate ());
			cout << "\nCurrency Rate Updated Successfully:) \n";

			_PrintCurrencyRecord ( Currency );
		}


	}

};

