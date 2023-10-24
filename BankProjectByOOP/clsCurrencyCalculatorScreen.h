#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static clsCurrency GetCurrency(string Message)
	{
		cout << Message << endl;

		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Code Not Found, Please Enter Currency1 Code : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrency(clsCurrency Currency, string Title)
	{
		cout << Title;
		cout << "\n____________________________________\n";
		cout << "Country	   : " << Currency.Country() << endl;
		cout << "Currency Code : " << Currency.CurrencyCode() << endl;
		cout << "Currency Name : " << Currency.CurrencyName() << endl;
		cout << "Rate (1$)     : " << Currency.Rate() << endl;
		cout << "\n____________________________________\n\n";
	}

	static void _PrintCalculationCurrency(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		float AmountInUSD = Currency1._ConvertToUsd(Amount);
		_PrintCurrency(Currency1, "Convert From");
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConvert From USD : \n";
		_PrintCurrency(Currency2, "To : ");
		float AmountOtherCurrency = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountOtherCurrency << " " << Currency2.CurrencyCode();
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			_DrawScreenHeader("\t Currency Calculator ");
			clsCurrency CurrencyFrom = GetCurrency("Please Enter Currency1 Code:");
			clsCurrency CurrencyTo = GetCurrency("Please Enter Currency2 Code:");
			cout << "\nEnter Amount To Exchange : ";
			float Amount = clsInputValidate::ReadFloatNumber();

			_PrintCalculationCurrency(Amount, CurrencyFrom, CurrencyTo);
			cout << "\nDo You Want to perform anther calculations ? y / n";
			cin >> Continue;
		}
	}
};
