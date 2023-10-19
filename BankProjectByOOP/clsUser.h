#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;
class clsUser : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    struct stLoginRegisterRecord;



    string _PrepareLogin(string separator = "#//#")
    {
        string RecordLogin = "";
        RecordLogin += clsDate::GetSystemDateString() + separator;
        RecordLogin += UserName + separator;
        RecordLogin += Password + separator;
        RecordLogin += to_string(Permissions);

        return RecordLogin;

    }

    static stLoginRegisterRecord _ConvertLineToRegisterRecord(string Line, string Separator = "#//#")
    {
        stLoginRegisterRecord stLoginRecord;
        vector <string> vLoginRecord = clsString::Split(Line, Separator);

        stLoginRecord.DateTime = vLoginRecord[0];
        stLoginRecord.UserName = vLoginRecord[1];
        stLoginRecord.Password = vLoginRecord[2];
        stLoginRecord.Permissions = stoi(vLoginRecord[3]);

        return stLoginRecord;

    }

    static const short encryptionKey = 20;

    static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Separator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], clsUtil::DescriptedText(vUserData[5], encryptionKey), stoi(vUserData[6]));
    }

    static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Separator;
        UserRecord += User.LastName + Separator;
        UserRecord += User.Email + Separator;
        UserRecord += User.Phone + Separator;
        UserRecord += User.UserName + Separator;
        UserRecord += clsUtil::EncryptedText((User.Password), encryptionKey) + Separator;
        //UserRecord += (User.Password) + Separator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }

    static vector<clsUser> _LoadUsersDataFromFile()
    {

        vector<clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUsers.push_back(User);
            }

            MyFile.close();
        }

        return vUsers;
    }

    static void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out); // overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    // we only write records that are not marked for delete.
                    DataLine = _ConvertUserObjectToLine(U);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:

    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactiond = 32, pManageUsers = 64,
        pLoginRegisterRecord = 128
    };

    struct stLoginRegisterRecord
    {
        string UserName;
        string Password;
        string DateTime;
        int Permissions;
    };

    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults
    {
        svFaildEmptyObject = 0,
        svSucceeded = 1,
        svFaildUserExists = 2
    };

    enSaveResults Save()
    {

        switch (_Mode)
        {
            case enMode::EmptyMode:
                {
                    if (IsEmpty())
                    {
                        return enSaveResults::svFaildEmptyObject;
                    }
                }

            case enMode::UpdateMode:
                {
                    _Update();
                    return enSaveResults::svSucceeded;

                    break;
                }

            case enMode::AddNewMode:
                {
                    // This will add new record to file or database
                    if (clsUser::IsUserExist(_UserName))
                        {
                            return enSaveResults::svFaildUserExists;
                        }
                    else
                        {
                            _AddNew();
                            // We need to set the mode to update after add new
                            _Mode = enMode::UpdateMode;
                            return enSaveResults::svSucceeded;
                        }

                    break;
                }
        }
    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this -> Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            // 100000 & 100000 = 1 == 1
            // 010000 & 010000 = 2 == 2
            return true;
        else
            return false;
    }

    void RegisterLogin()
    {
        string stDate = _PrepareLogin();

        fstream MyFile;

        MyFile.open("LogRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDate << endl;
            MyFile.close();
        }
    }

    static vector <stLoginRegisterRecord> GetLoadRegisterUser()
    {

        vector<stLoginRegisterRecord> vLoginRegisterRecord;

        fstream MyFile;
        MyFile.open("LogRegister.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {

            string Line;
            stLoginRegisterRecord LoginRegisterRecord;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLineToRegisterRecord(Line);
                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close();
        }

        return vLoginRegisterRecord;
    }

 
};
