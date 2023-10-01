#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

class clsInputValidate
{

public:

	static bool IsNumbeBetween(int Num, int From , int To)
	{
		return (From < Num < To);
	}
	
	static bool IsNumbeBetween(double Num, double From , double To)
	{
		return (From < Num < To);
	}
	

	static bool IsNumbeBetween(clsDate Date, clsDate DateFrom , clsDate DateTo)
	{
		if (clsDate::IsDate1BeforeDate2(DateTo, DateFrom))
		{
			clsDate::SwapDates(DateTo, DateFrom);
		}
		
		return clsDate::IsDate1AfterDate2(Date, DateFrom) && clsDate::IsDate1AfterDate2(Date, DateFrom);
	}


	static int ReadIntNumber(string Message)
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message << endl;
		}

		
		return Number;
	}
	
	
	static float ReadFloatNumber()
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		
		return Number;
	}




	static bool IsValiDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string S = "";

		getline(cin >> ws, S);

		return S;
	}
	


};

