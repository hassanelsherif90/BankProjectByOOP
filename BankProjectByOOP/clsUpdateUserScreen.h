#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nRead User Info :\n\n";
        cout << "\nFirstName      : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nLastName       : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEmail          : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nPhone          : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nPassword       : ";
        User.Password = clsInputValidate::ReadString();

        User.Permissions = _ReadUserPermission();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n__________________________";
        cout << "\nFirstName    : " << User.FirstName;
        cout << "\nLastName     : " << User.LastName;
        cout << "\nFull Name    : " << User.FullName();
        cout << "\nEmail        : " << User.Email;
        cout << "\nPhone        : " << User.Phone;
        cout << "\nPassword     : " << User.Password;
        cout << "\nBalance      : " << User.Permissions;
        cout << "\n__________________________";
    }

    static int _ReadUserPermission()
    {
        int Permissions = 0;
        char answer = 'n';

        cout << "\nDo You want give full access ? y/n";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nShow Client List ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactiond;
        }

        cout << "\nManage user ? y/n ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactiond;
        }

        return Permissions;
    }

public:
    static void ShowUpdateUser()
    {
        _DrawScreenHeader("\t  Update User\n");
        string UserName;

        cout << "\nPlease Enter User Name : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is already Used, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);
        cout << "\n\nUpdate User :\n";
        cout << "_____________________";

        _ReadUserInfo(User);
        cout << "_____________________";

        clsUser::enSaveResults SaveResults;

        SaveResults = User.Save();

        switch (SaveResults)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Name Updated Successfully :) \n";
            _PrintUser(User);
            break;
        }

        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User Name was not saved because it’s Empty :( \n";
            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nUser Name is already Used";
            break;
        }
        }

        cout << endl;
    }
};

