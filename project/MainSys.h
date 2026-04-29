#pragma once
#include <iostream>
#include <fstream>
#include "AdminPanel.h"
#include "PassengerPanel.h"
#include "City.h"
#include "OnlineData.h"

using namespace std;

class MainSystem
{
    int Option;
    PassengerPanel MyPassengerPanel;
    AdminPanel MyAdminPanel;
    OnlineData MyOnlineData;
    City* Functional_Cities = new City[5];

public:
    //* Parameteried Constructor
    MainSystem(PassengerPanel obj1, AdminPanel obj2, OnlineData obj3)
    {
        this->MyPassengerPanel = obj1;
        this->MyAdminPanel = obj2;
        this->MyOnlineData = obj3;
    }

    MainSystem()
    {
    }

    //* Main menue of the System From where the System Starts
    void MenueDisplayer()
    {
        bool check = true;
        cout << endl;
        cout << "_________________________________________________________________" << endl;
        cout << "|                                                                |" << endl;
        cout << "|        Welcome to NUCES Airline Flight System                  |" << endl;
        cout << "|________________________________________________________________|" << endl;
        cout << endl;
        cout << "1. Admin Panel        2. Passenger Panel        3. Exit\n";
        cin >> this->Option;


        switch (this->Option)
        {
        case 1:
            //* A Loop to continue Displaying Admin Panel until the user press back
            while (check)
            {
                check = MyAdminPanel.MenueDisplayer();
                MyOnlineData = MyAdminPanel.Data_Returner();
                system("cls");
            }
            break;
        case 2:
            //* A Loop to continue displaying Passenger Panel until the user press back
            while (check)
            {
                check = MyPassengerPanel.MenueDisplayer(MyOnlineData);
                system("cls");
            }
            break;
        case 3:
            cout << "Program exit successfully \n";
            exit(0);
        default:
            cout << "Invalid Option\n";
            break;
        }
    }
};