#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
    
 private:
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


    public:
        static void  ShowDeleteUser()
        {
            _DrawScreenHeader("\t  Delete User\n");
            string UserName;

            cout << "\nPlease Enter User Name : ";
            UserName = clsInputValidate::ReadString();

            while (!clsUser::IsUserExist(UserName))
            {
                cout << "\nUser Name is not found, choose another one: ";
                UserName = clsInputValidate::ReadString();
            }

            clsUser User = clsUser::Find(UserName);
            _PrintUser(User);

            cout << "\nAre you Want to delete User Name ? y / n ? ";

            char Answer = 'N';
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                if (User.Delete())
                {
                    cout << "\nUser Name Deleted Successfully :) .";
                    _PrintUser(User);
                }
                else
                {
                    cout << "\nError User Name Was not Deleted .";
                }
            }
            else
            {
                cout << "\nUser Name Was not Deleted .";
            }

        }


};

