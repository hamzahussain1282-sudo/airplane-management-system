#include<iostream>
using namespace std;
class Passenger
{
    string name;

public:

    Passenger()
    {
        this->name = "";
    }

    Passenger(string name)
    {
        this->name = name;
    }

};

class Economy_Passenger :public Passenger
{

};

class Business_Passenger :public Passenger
{

};