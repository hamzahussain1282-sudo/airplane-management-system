#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Data.h"
#include "City.h"
#include "Country.h"
#include "OnlineData.h"

using namespace std;

bool CountryVerifier(int n)
{
    if (n < 1 || n > 25)
    {
        return false;
    }
    return true;
}

bool CityVerifier(int n)
{
    if (n < 1 || n > 5)
    {
        return false;
    }
    return true;
}

bool AeroplaneVerifier(int n)
{
    if (n < 1 || n > 10)
    {
        return false;
    }
    return true;
}

bool BookedAeroplaneVerifier(int n, int n2)
{
    if (n < 1 || n > n2)
    {
        return false;
    }
    return true;
}

class AdminPanel
{
    int option, option2;
    Data My_A_Data;
    DataBase MyDataBase;
    City* Functional_Cities = new City[5];
    Country* My_Countries = new Country[25];
    OnlineData My_Online_Data;

public:
    // ! Parameteried Constructor 
    AdminPanel(Data obj, DataBase obj2, City* ptr1, Country* ptr2, OnlineData obj3)
    {
        this->My_A_Data = obj;
        this->MyDataBase = obj2;
        this->Functional_Cities = ptr1;
        this->My_Countries = ptr2;
        this->My_Online_Data = obj3;
    }

    // ? Two Sister Brother Function
    OnlineData Data_Returner()
    {
        return DataReturner();
    }
    OnlineData DataReturner()
    {
        return this->My_Online_Data;
    }

    //* Function to help admin Shedule flights and also update the data accordingly
    void Flight_Shedule()
    {
        cout << "You have following Cities\n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ": " << Functional_Cities[i].Get_Name() << endl;
        }
        cout << "Enter the Number of City\n";
        cin >> this->option;

        while (!CityVerifier(this->option))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Number of City\n";
            cin >> this->option;
        }

        cout << "This City has following Aeroplanes Avaliable \n";

        Functional_Cities[this->option - 1].AeroplaneDisplayer();

        cout << "Enter the Aeroplane You want to set the shedule\n";
        cin >> this->option2;

        while (!AeroplaneVerifier(this->option2))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Aeroplane You want to set the shedule\n";
            cin >> this->option2;
        }

        Functional_Cities[this->option - 1].AeroplaneFunctionality(this->option2 - 1);
    }

    //* Function to help admin Add route the sheduled flights 
    void New_Route_Adder()
    {
        int routecounter;
        cout << "You have following Cities\n";

        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ": " << Functional_Cities[i].Get_Name() << endl;
        }

        cout << "Enter the Number of City\n";
        cin >> this->option;

        while (!CityVerifier(this->option))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Number of City\n";
            cin >> this->option;
        }

        routecounter = Functional_Cities[this->option - 1].AeroplaneDispalyerSheduleSet();

        if (routecounter == 0)
        {
            return;
        }
        cout << "Enter the Aeroplane You want to set the Route\n";
        cin >> this->option2;

        while (!AeroplaneVerifier(this->option2))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Aeroplane You want to set the Route\n";
            cin >> this->option2;
        }
        int val = Functional_Cities[this->option - 1].AeroplaneRouteSet(option2 - 1);

        if (val == 2)
        {
            return;
        }

        if (val == 1)
        {
            int Selection;
            cout << "You can Select one of the following Cities\n";

            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ": " << Functional_Cities[i].Get_Name() << endl;
            }

            cout << "Enter the Number of City you want to set as Destination\n";
            cin >> Selection;
            while (!CityVerifier(Selection))
            {
                cout << "Invalid Option\n";
                cout << "Enter the Number of City you want to set as Destination\n";
                cin >> Selection;
            }

            while (!Functional_Cities[this->option - 1].DestinationSet(this->option2 - 1, Selection))
            {
                cout << "Enter the Number of City you want to set as Destination\n";
                cin >> Selection;
                while (!CityVerifier(Selection))
                {
                    cout << "Invalid Option\n";
                    cout << "Enter the Number of City you want to set as Destination\n";
                    cin >> Selection;
                }
            }
            cout << "Destination of Aeroplane Set successful\n";
        }

        if (val == 0)
        {
            int Selection2;
            cout << "You can select one of the following Countries\n";
            for (int i = 0; i < 25; i++)
            {

                cout << i + 1 << ": " << My_Countries[i].GetName() << endl;
            }

            cout << "Enter the Number of Country you want to set as Destination\n";
            cin >> Selection2;
            while (!CountryVerifier(Selection2))
            {
                cout << "Invalid Option\n";
                cout << "Enter the Number of Country you want to set as Destination\n";
                cin >> Selection2;
            }

            Functional_Cities[this->option - 1].Destination_Set_Country(this->option2 - 1, Selection2);
            cout << "Destination of Aeroplane Set successful\n";
        }
    }

    //* Function to help admin to Restrict seats in any plane of any city
    void Passenger_Restricter()
    {
        cout << "You have following Cities\n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ": " << Functional_Cities[i].Get_Name() << endl;
        }
        cout << "Enter the Number of City\n";
        cin >> this->option;

        while (!CityVerifier(this->option))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Number of City\n";
            cin >> this->option;
        }

        cout << "This City has following Aeroplanes Avaliable \n";

        Functional_Cities[this->option - 1].AeroplaneDisplayer();

        cout << "Enter the Aeroplane You want to restrict passengers\n";
        cin >> this->option2;

        while (!AeroplaneVerifier(this->option2))
        {
            cout << "Invalid Option\n";
            cout << "Enter the Aeroplane You want to restrict passengers\n";
            cin >> this->option2;
        }

        Functional_Cities[this->option - 1].PassengerModerator(this->option2 - 1);
    }

    //* To show a menue after Login or Register to perform different functionalities  
    bool FunctionailityChoser()
    {
        cout << "What you want to do\n";
        cout << "1. Maintain and update Flight Shedule\n";
        cout << "2. Add New Routes\n";
        cout << "3. Restrict the Number of Passengers\n";
        cout << "4. Update airline Inquiry Details\n";
        cout << "5. Reset Password or Username\n";
        cout << "6. Go Back\n";
        cin >> this->option;
        string ssi;
        switch (this->option)
        {
        case 1:
            this->Flight_Shedule();
            break;
        case 2:
            this->New_Route_Adder();
            break;
        case 3:
            this->Passenger_Restricter();
            break;
        case 4:
            cout << "Enter the New Airline Inquiry\n";
            cin.ignore();
            getline(cin, ssi);
            cout << "Updated Successfully\n";
            break;
        case 5:
            MyDataBase.Reseter();
            break;
        case 6:
            My_Online_Data.Updator(Functional_Cities);
            return false;
            break;

        default:
            cout << "Invalid Option\n";
            break;
        }

        return true;
    }

    //* Storing Admin Data in a class Data which contains a Dynamic Array and increase its size 
    void RegisterMaker()
    {
        bool FunCheck = true;
        string s;
        cout << "Enter a unique User-Name\n";
        cin >> s;

        My_A_Data.setUsername(s);
        My_A_Data.setPasswordPro();

        MyDataBase.DataSaver(s, My_A_Data.getPassword());
        cout << "You have Registered Successfully\n\n";
        while (FunCheck)
        {
            FunCheck = this->FunctionailityChoser();

            if (FunCheck)
                system("pause");
            system("cls");
        }
    }

    //* Help to Login after verifying the previous Login Details
    void LoginMaker()
    {
        bool FunCheck = true;
        if (MyDataBase.GetCounter() == 0)
        {
            cout << "Please make an account first\n";
            system("pause");
            return;
        }
        string s, p;
        cout << "Enter your Username\n";
        cin >> s;

        p = My_A_Data.PasswordInputter();

        while (!MyDataBase.DataChecker(s, p))
        {
            cout << "Incorrect Username or Password\n";
            cout << "Enter your Username\n";
            cin >> s;
            p = My_A_Data.PasswordInputter();
        }

        cout << "You have Logged in Successfully\n\n";
        while (FunCheck)
        {
            FunCheck = this->FunctionailityChoser();
            if (FunCheck)
                system("pause");
            system("cls");
        }
    }

    //* The Main menue of Admin Panel containing a WHILE Loop which will keep on runing until go back is pressed
    bool MenueDisplayer()
    {
        bool check = true;
        cout << "Welcome to Admin Panel\n";
        cout << "1. Login     2. Register     3.Go Back\n";
        cin >> this->option;
        switch (this->option)
        {
        case 1:
            this->LoginMaker();
            break;
        case 2:
            this->RegisterMaker();
            break;
        case 3:
            check = false;
            return check;
            break;

        default:
            cout << "Invalid Option\n";

            break;
        }
        return check;
    }

    //* Default Constructor
    AdminPanel()
    {
    }
};