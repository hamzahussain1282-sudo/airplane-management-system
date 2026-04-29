#pragma once
#include <iostream>
using namespace std;

class Country
{
    string CName;
    static int counter;

public:

    //* Parameterized Constructor
    Country(string name)
    {
        this->CName = name;
    }

    string GetName()
    {
        return this->CName;
    }

    //* Default Constructor
    Country()
    {
        counter++;

        switch (counter)
        {
        case 1:
            CName = "United Arab Emarates";
            break;
        case 2:
            CName = "United Kingdom";
            break;
        case 3:
            CName = "Canada";
            break;
        case 4:
            CName = "Germany";
            break;
        case 5:
            CName = "France";
            break;
        case 6:
            CName = "Italy";
            break;
        case 7:
            CName = "Turkey";
            break;
        case 8:
            CName = "Spain";
            break;
        case 9:
            CName = "Qatar";
            break;
        case 10:
            CName = "Bahrain";
            break;
        case 11:
            CName = "Kuwait";
            break;
        case 12:
            CName = "Oman";
            break;
        case 13:
            CName = "China";
            break;
        case 14:
            CName = "Afghanistan";
            break;
        case 15:
            CName = "Malaysia";
            break;
        case 16:
            CName = "Singapore";
            break;
        case 17:
            CName = "Thiland";
            break;
        case 18:
            CName = "Japan";
            break;
        case 19:
            CName = "South-Korea";
            break;
        case 20:
            CName = "Australia";
            break;
        case 21:
            CName = "New Zealand";
            break;
        case 22:
            CName = "South Africa";
            break;
        case 23:
            CName = "Kenya";
            break;
        case 24:
            CName = "Egypt";
            break;
        case 25:
            CName = "Iran";
            break;
        default:
            counter = 1;
            CName = "United Arab Emarates";
            break;
        }
    }

};

int Country::counter = 0;