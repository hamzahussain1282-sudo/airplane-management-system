#pragma once
#include <iostream>
using namespace std;

class Airport
{
    int Local_Flight_Count;
    int International_Flight_Count;
    int Airplanes_Landed;
    string name;

public:

    //! Parameteried Constructor 
    Airport(int LFC, int IFC, int AL, string name)
    {
        this->Local_Flight_Count = LFC;
        this->International_Flight_Count = IFC;
        this->Airplanes_Landed = AL;
        this->name = name;
    }

    Airport()
    {
        Local_Flight_Count = 0;
        International_Flight_Count = 0;
        Airplanes_Landed = 0;
        name = "";
    }

    // * Getters and Setters 
    string GetName()
    {
        return this->name;
    }

    int Get_Airplane_Landed()
    {
        return this->Airplanes_Landed;
    }

    void Airplane_Landed_Update()
    {
        this->Airplanes_Landed++;
    }

    void SetName(string s)
    {
        this->name = s;
    }
};