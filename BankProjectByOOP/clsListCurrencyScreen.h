#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrncy.h"
#include "clsScreen.h"

using namespace std;

class clsListCurrencyScreen : protected clsScreen
{
private:

	

	static void _PrintListCurrency (clsCurrency Currency)
	{
		cout << setw ( 8 ) << left << "";
		cout << "| " << setw ( 30 ) << Currency.Country();
		cout << "| " << setw ( 10 ) << left  << Currency.CurrencyCode();
		cout << "| " << setw ( 45 ) << left  << Currency.CurrencyName();
		cout << "| " << setw ( 20 ) << left   << Currency.Rate();
	}

public:

	static void ShowListCurrencyScreen ()
	{
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList ();

		string SubTitle = "\t (" + to_string ( vCurrency.size () ) + ") Clients ";

		_DrawScreenHeader ( "\t List Currency Screen" , SubTitle );


		cout << setw ( 8 ) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;

		cout << setw ( 8 ) << left << "";
		cout << "| " << left << setw (30) << "Country";
		cout << "| " << left <<  setw ( 10 ) << "Code";
		cout << "| " << left <<  setw ( 45 ) << "Name";
		cout << "| " << left <<  setw ( 10 ) << "Rate (1 $) ";

		cout << setw ( 8 ) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;

		if ( vCurrency.size () == 0 )
			cout << "\n\t\t\tNo Currency Available In the System!";
		else

		for ( clsCurrency C : vCurrency )
		{
			_PrintListCurrency ( C );
			cout << endl;
		}

		cout << setw ( 8 ) << left << "" << "\n\t___________________________________________";
		cout << "____________________________________________________________\n" << endl;

	}

};

