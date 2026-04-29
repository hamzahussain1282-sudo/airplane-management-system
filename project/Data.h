#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class Finance
{
    string Pname;
    string Aname;

public:

    Finance()
    {
        Pname = "";
        Aname = "";
    }

    Finance(string s1, string s2)
    {
        this->Pname = s1;
        this->Aname = s2;
    }

};

class Data
{
protected:
    string UserName;
    string password;

public:

    Data()
    {
        this->UserName = "";
        this->password = "";
    }

    //* Parameteried Constructor 
    Data(string s1, string s2)
    {
        this->UserName = s1;
        this->password = s2;
    }

    //* Checking if the Username is Valid 
    bool UserNameVerifier(string s)
    {
        if (s.length() < 1)
        {
            return false;
        }

        return true;
    }

    //* Checking if the Password is Valid 
    bool PasswordVerifier(string s)
    {
        bool ans = false, condition1=false, condition2 = false, condition3 = false, condition4 = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (((s[i] >= 33 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96)) && s.length() >= 8)
            {
                condition1 = true;
            }
        }
        for (int i = 0; i < s.length(); i++) // Checking for lowercase letter
        {
            if (s[i] >= 97 && s[i] <= 122)
            {
                condition2 = true;
            }
        }

        for (int i = 0; i < s.length(); i++) // checking for upper case
        {
            if (s[i] >= 65 && s[i] <= 90)
            {
                condition3 = true;
            }
        }

        for (int i = 0; i < s.length(); i++) // checking for numeric
        {
            if (s[i] >= 48 && s[i] <= 57)
            {
                condition4 = true;
            }
        }
        if (condition1 && condition2 && condition3 && condition4)
        {
            ans = true;
        }

        if (!ans)
            cout << "Password don't match the Criteria \n";
        return ans;
    }

    //* A Logic to Input password while hiding it and returning the password 
    string PasswordInputter()
    {
        int ch;
        string temppass;
        cout << "Enter your Password\n";
        ch = _getch();
        while (ch != 13)
        {
            if (ch == '\b')
            {
                if (!temppass.empty())
                {
                    temppass.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                temppass.push_back(ch);
                cout << "*";
            }
            ch = _getch();
        }
        cout << "\n";

        return temppass;
    }

    //* Getter and Setters 
    string getUsername()
    {
        return UserName;
    }

    void setUsername(string newUsername)
    {
        UserName = newUsername;
    }

    string getPassword()
    {
        return password;
    }

    void setPassword(string s)
    {
        this->password = s;
    }

    void setPasswordPro()
    {
        int ch;
        this->password = "";
        cout << "Enter your Password\n";
        ch = _getch();
        while (ch != 13)
        {
            if (ch == '\b')
            {
                if (!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                password.push_back(ch);
                cout << "*";
            }
            ch = _getch();
        }
        cout << "\n";
        while (!this->PasswordVerifier(this->password))
        {
            this->setPasswordPro();
        }
    }
};

//? A Class to hold Passenger Data Inherited from Class Data 
class PData : public Data
{
    string CNIC;
    string CardNo, Securitycode;

public:
    //* Getter and Setters 
    string GetCNIC()
    {
        return this->CNIC;
    }

    string GetCardno()
    {
        return this->CardNo;
    }

    void SetCardno(string s)
    {
        this->CardNo = s;
    }

    string GetSecurityCode()
    {
        return this->Securitycode;
    }

    void SetSecurityCode(string s)
    {
        this->Securitycode = s;
    }

    void SetCNIC(string s)
    {
        this->CNIC = s;
    }

    bool CNICVerifier(string s)
    {
        if (s.length() != 13)
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < 48 || s[i] > 57)
            {
                return false;
            }
        }

        return true;
    }
};

class DataBase
{
protected:
    Data* MyDataBase;
    int counter, currentlog, option;

public:
    DataBase()
    {
        counter = 0;
        MyDataBase = new Data[1];
    }

    int GetCounter()
    {
        return this->counter;
    }

    void Reseter()
    {
        string s;
        cout << "What you want to Reset\n";
        cout << "1. Username\n";
        cout << "2. Password\n";
        cin >> this->option;

        switch (this->option)
        {
        case 1:
            cout << "Enter New Username\n";
            cin >> s;
            MyDataBase[currentlog].setUsername(s);
            cout << "Username reset successsful\n";
            break;
        case 2:
            MyDataBase[currentlog].setPasswordPro();
            cout << "Password reset successful\n";
            break;

        default:
            cout << "Invalid Option\n";
            break;
        }
    }

    bool DataChecker(string u, string p)
    {
        bool check1 = false, check2 = false;
        for (int i = 0; i < counter; i++)
        {
            if (u == MyDataBase[i].getUsername())
            {
                check1 = true;
                if (p == MyDataBase[i].getPassword())
                {
                    check2 = true;
                    currentlog = i;
                }
            }

            if (check1 && check2)
            {
                return true;
            }
        }
        return false;
    }

    void DataSaver(string u, string p)
    {
        if (counter == 0)
        {
            this->currentlog = counter;
            fstream obj;
            obj.open("AdminData.txt", ios::app);
            if (obj.is_open())
            {
                obj << "Admin : " << counter + 1 << " Username :" << u << " , Password :" << p << endl;
            }
            obj.close();
            MyDataBase[counter].setPassword(p);
            MyDataBase[counter].setUsername(u);
            counter++;
        }

        else if (counter != 0)
        {

            Data* temp = new Data[counter];

            for (int i = 0; i < counter; i++)
            {
                temp[i] = MyDataBase[i];
            }

            counter++;

            MyDataBase = new Data[counter];

            for (int i = 0; i < counter - 1; i++)
            {
                MyDataBase[i] = temp[i];
            }

            this->currentlog = counter - 1;

            fstream obj;
            obj.open("AdminData.txt", ios::app);

            if (obj.is_open())
            {
                obj << "Admin : " << counter << " Username :" << u << " , Password :" << p << endl;
            }
            obj.close();

            MyDataBase[counter - 1].setPassword(p);
            MyDataBase[counter - 1].setUsername(u);
        }
    }
};

class PDataBase : public DataBase
{
    PData* MyPDataBase;

public:

    PDataBase(PData* ptr)
    {
        this->MyPDataBase = ptr;
    }

    PDataBase()
    {
        MyPDataBase = new PData[1];
    }

    //* Data Verifier to continue to Login 
    bool DataChecker(string u, string p)
    {
        bool check1 = false, check2 = false;
        for (int i = 0; i < counter; i++)
        {
            if (u == MyPDataBase[i].getUsername())
            {
                check1 = true;
                if (p == MyPDataBase[i].getPassword())
                {
                    check2 = true;
                    currentlog = i;
                }
            }
        }
        if (check1 && check2)
        {
            return true;
        }
        return false;
    }

    //* Checking if two Passengers have the same cnic
    bool CNIC_Checker(string s)
    {
        bool check = true;

        for (int i = 0; i < counter; i++)
        {
            if (s == MyPDataBase[i].GetCNIC())
            {
                check = false;
            }
        }
        return check;
    }

    //* Reseting the Passenger Username and Password
    void Reseter()
    {
        string s;
        cout << "What you want to Reset\n";
        cout << "1. Username\n";
        cout << "2. Password\n";
        cin >> this->option;

        switch (this->option)
        {
        case 1:
            cout << "Enter New Username\n";
            cin >> s;
            MyPDataBase[currentlog].setUsername(s);
            break;
        case 2:
            MyPDataBase[currentlog].setPasswordPro();

        default:
            cout << "Invalid Option\n";
            break;
        }
    }

    //* Saving the Cnic of the Passenger 
    void CnicSaver(string s)
    {
        if (counter == 0)
        {
            MyPDataBase[counter].SetCNIC(s);
            counter++;
            return;
        }
        else if (counter != 0)
        {
            PData* temp = new PData[counter];

            for (int i = 0; i < counter; i++)
            {
                temp[i] = MyPDataBase[i];
            }

            counter++;

            MyPDataBase = new PData[counter];

            for (int i = 0; i < counter - 1; i++)
            {
                MyPDataBase[i] = temp[i];
            }

            MyPDataBase[counter - 1].SetCNIC(s);
        }
    }

    //* Saving the Financial Details of the Passenger
    void FinancialDataSaver(string No, string code)
    {
        MyPDataBase[counter - 1].SetCardno(No);
        MyPDataBase[counter - 1].SetSecurityCode(code);
    }

    string GetCardNumber(int c)
    {
        return MyPDataBase[c].GetCardno();
    }

    string GetSecurityNumber(int c)
    {
        return MyPDataBase[c].GetSecurityCode();
    }

    //* To Save the Passenger Data in the File 
    void DataSaver(string u, string p)
    {
        fstream obj;
        obj.open("Passenger_Data.txt", ios::app);
        if (obj.is_open())
        {
            obj << "Passenger : " << counter << " Username :" << u << " , Password :" << p << endl;
        }
        obj.close();
        this->currentlog = counter - 1;
        MyPDataBase[counter - 1].setPassword(p);
        MyPDataBase[counter - 1].setUsername(u);
    }
};

bool VerifyFinancialDetail(PDataBase obj1, string s1, string s2)
{
    int c = obj1.GetCounter();

    bool check1 = false, check2 = false;

    for (int i = 0; i < c; i++)
    {

        if (s1 == obj1.GetCardNumber(i))
        {
            check1 = true;

            if (s2 == obj1.GetSecurityNumber(i))
            {
                check2 = true;
            }
        }

        if (check1 && check2)
        {
            return true;
        }
    }
    return false;
}