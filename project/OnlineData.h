#pragma once
#include <iostream>
#include "City.h"

using namespace std;

//* To Verify that cities entered are less than 5
bool CityVerifierPro(int n)
{
    if (n < 1 || n > 5)
    {
        return false;
    }
    return true;
}

class OnlineData
{
    City* Updated_City_Data;

public:

    //* To Display the name of the cities
    void CityDisplayer()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << " : " << Updated_City_Data[i].Get_Name() << endl;
        }
    }

    //* To Reserve a Flight for a registered user 
    void Flight_Reserver(string Ptype, bool stamp, bool Passport, int line)
    {
        if (!Passport)
        {
            cout << "You cannot Travel without a Passport\n";
            return;
        }
        int optR, opt2;

        cout << "Enter the Number of City from where you want to Book Flight\n";
        CityDisplayer();
        cin >> optR;

        while (!CityVerifierPro(optR))
        {
            cout << "Enter the Number of City from where you want to Book Flight\n";
            cin >> optR;
        }

        int counter = 0;
        counter = Updated_City_Data[optR - 1].SheduleViewer(counter);

        if (counter == 0)
        {
            cout << "There are No Flights sheduled for this City\n";
            return;
        }

        cout << "Enter the Aeroplane Number you want to Travel\n";
        cin >> opt2;

        while (!Updated_City_Data[optR - 1].AeroplaneConfirm(opt2 - 1))
        {
            cout << "Invalid Aeroplane Number Selected \n";
            cout << "Enter the Aeroplane Number you want to Travel\n";
            cin >> opt2;
        }
        fstream Obj;
        Obj.open("Booking_Details.txt", ios::out | ios::app);
        Obj << "City" + to_string(optR) + "," + "Aeroplane" + to_string(opt2);
        Obj.close();

        if (!Updated_City_Data[optR - 1].AiroplaneLastCheck(opt2 - 1, Ptype, stamp, line))
        {
            return;
        }
    }

    //* To Show the booked flights of a Passenger 
    void FlightCancelorshow(int CN, int AN, char SeatType)
    {
        Updated_City_Data[CN].CancelFlight_Show(AN, SeatType);
    }

    //* To Cancel a booked flight of a registered user 
    void FlightCancelor(int CN, int AN, char SeatType, int line_number)
    {
        Updated_City_Data[CN].CancelFlight(AN, SeatType, line_number);

    }

    //* To Display the flights sheduled by Admin to the Passenger to book
    int RouteDisplayer()
    {
        int counter = 0;
        for (int i = 0; i < 5; i++)
        {
            counter += Updated_City_Data[i].SheduleViewer(counter);
        }

        if (counter == 0)
        {
            cout << "There Are no Flights going on today check back later\n";
        }
        return counter;
    }

    //* To Display specific flights sheduled by Admin to the passenger to book 
    void RouteDisplayerCK()
    {
        int opt, counter = 0;
        cout << "Enter the Number of City you want to see shedule\n";

        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << " : " << Updated_City_Data[i].Get_Name() << endl;
        }

        cin >> opt;

        while (!CityVerifierPro(opt))
        {
            cout << "Invalid Number Enter again\n";
            cin >> opt;
        }
        counter = Updated_City_Data[opt - 1].SheduleViewer(counter);
        if (counter == 0)
        {
            cout << "There Are no Flights going on today check back later\n";
        }
    }

    //* Default Constructor 
    OnlineData()
    {
        Updated_City_Data = new City[5];
    }

    //! Parameterized Constructor
    OnlineData(City* ptr)
    {
        Updated_City_Data = new City[5];
        cout << "Hi";

        for (int i = 0; i < 5; i++)
        {
            cout << "Hi";
            this->Updated_City_Data[i] = ptr[i];
        }
    }

    void Updator(City* ptr)
    {
        for (int i = 0; i < 5; i++)
        {
            this->Updated_City_Data[i] = ptr[i];
        }
    }
};