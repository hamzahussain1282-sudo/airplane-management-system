#pragma once
#include "Passenger.h"
#include <string>

class Aeroplane
{
    string Type_of_Flight;

    int Duration_of_Flight;
    string Name;
    static int counter;
    int Arrival_timeH, Arrival_timeM, Departure_timeH, Departure_timeM;
    bool RouteSet;

    long long int TravelC;
    string Destination;

    int Business_Seats, Economy_Seats;
    const int LocalFCostE, InternationalFCostE;
    const int LocalFCostB, InternationalFCostB;

    Economy_Passenger* My_E_Passenger = new Economy_Passenger[50];
    Business_Passenger* My_B_Passenger = new Business_Passenger[10];

public:
    //! Parameteried Constructor
    Aeroplane(string FT, int DT, string N, string D) : LocalFCostE(10500), InternationalFCostE(22000), LocalFCostB(21000), InternationalFCostB(44000)
    {
        this->Duration_of_Flight = DT;
        this->Type_of_Flight = FT;
        this->Name = N;
        this->Destination = D;
    }

    Aeroplane() : LocalFCostE(10500), InternationalFCostE(22000), LocalFCostB(21000), InternationalFCostB(44000)
    {
        TravelC = 0;
        Duration_of_Flight = 0;
        Business_Seats = 10;
        Economy_Seats = 50;
        this->RouteSet = false;
        Arrival_timeH = 25, Arrival_timeM = 25, Departure_timeH = 25, Departure_timeM = 25;
        counter++;
        if (counter == 11)
        {
            counter = 1;
        }
        Name = "Aeroplane " + to_string(counter);
    }

    // * Getter and Setters

    int SetTravelCost(string s1)
    {
        int n = this->GetDuration_of_Flight();
        string s = this->Gett_Type_of_Flight();
        if (s == "Local")
        {
            if (s1 == "Economy")
            {
                this->TravelC = LocalFCostE * n;
            }
            if (s1 == "Business")
            {
                this->TravelC = LocalFCostB;
            }
        }
        if (s == "International")
        {
            if (s1 == "Economy")
            {
                this->TravelC = InternationalFCostE * n;
            }
            if (s1 == "Business")
            {
                this->TravelC = InternationalFCostB * n;
            }
        }
        return this->TravelC;
    }

    int GetTravelCost()
    {
        return this->TravelC;
    }

    int GetBusinessSeats()
    {
        return this->Business_Seats;
    }

    void setBusinessSeats(int a)
    {
        this->Business_Seats = a;
    }

    void setEconomySeats(int a)
    {
        this->Economy_Seats = a;
    }

    int GetEconomySeats()
    {
        return this->Economy_Seats;
    }

    void SetDestination(string s)
    {
        this->Destination = s;
    }

    string GetDestination()
    {
        return this->Destination;
    }

    bool GetRoute()
    {
        return RouteSet;
    }

    void SetRoute()
    {
        this->RouteSet = true;
    }

    void SetRouteP(bool val)
    {
        this->RouteSet = val;
    }

    void Set_Arrival_Time(int a, int b)
    {
        if (a > 23)
        {
            a -= 24;
        }
        this->Arrival_timeH = a;
        this->Arrival_timeM = b;
    }

    int Get_Arrival_TimeH()
    {
        return Arrival_timeH;
    }

    int Get_Arrival_TimeM()
    {
        return Arrival_timeM;
    }

    void Set_Departure_Time(int a, int b)
    {
        this->Departure_timeH = a;
        this->Departure_timeM = b;
    }

    int Get_Departure_TimeH()
    {
        return Departure_timeH;
    }

    int Get_Departure_TimeM()
    {
        return Departure_timeM;
    }

    void SetDuration_of_Flight(int a)
    {
        this->Duration_of_Flight = a;
    }

    int GetDuration_of_Flight()
    {
        return this->Duration_of_Flight;
    }

    void Set_Type_of_Flight(string s)
    {
        this->Type_of_Flight = s;
    }

    string Gett_Type_of_Flight()
    {
        return this->Type_of_Flight;
    }

    void SetName(string s)
    {
        this->Name = s;
    }

    string GetName()
    {
        return this->Name;
    }
};

int Aeroplane::counter = 0;