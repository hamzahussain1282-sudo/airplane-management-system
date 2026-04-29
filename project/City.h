#pragma once
#pragma once
#include "Airport.h"
#include "Aeroplanes.h"
#include <iostream>
#include <sstream>

using namespace std;

//* Validate Time 
bool validateTime(int hours, int minutes)
{
    if (hours < 0 || hours > 23)
    {
        return false;
    }

    if (minutes < 0 || minutes > 59)
    {
        return false;
    }

    return true;
}

//* Validate 2 Options 
bool DuoOptionVerifier(int n)
{
    if (n < 1 || n > 2)
    {
        return false;
    }
    return true;
}

bool HourVerification(int n)
{
    if (n < 1 || n > 24)
    {
        return false;
    }
    return true;
}

void LineRemover(int LineNumber)
{
    fstream Fobj;
    stringstream mystream;

    Fobj.open("Booking_Details.txt", ios::in);
    string myline;
    int current = 1;

    while (getline(Fobj, myline))
    {
        if (LineNumber == current)
        {
            current++;
            continue;
        }
        mystream << myline << endl;
        current++;
    }

    Fobj.close();
    Fobj.open("Booking_Details.txt", ios::out);

    Fobj << mystream.str();

    Fobj.close();
}

class City
{
    string Name;
    static int Count;
    int option, option2;
    Airport* My_Airport = new Airport[2];
    Aeroplane* My_Aeroplane = new Aeroplane[10];

public:

    //* Parameterized Constructor
    City(string Name, Airport* Ptr, Aeroplane* Ptr2)
    {
        this->Name = Name;
        this->My_Airport = Ptr;
        this->My_Aeroplane = Ptr2;
    }

    //* To check if the Route for the Aeroplane is Set 
    bool AeroplaneConfirm(int n)
    {
        return My_Aeroplane[n].GetRoute();
    }

    //* To Check If the Passenger has a Valid Passport for that flight
    bool AiroplaneLastCheck(int n, string PType, bool stamp, int line)
    {
        int Sopt, bill;
        fstream Inputter;

        string tempType = My_Aeroplane[n].Gett_Type_of_Flight();

        if ((tempType == "International") && (PType == "Local"))
        {
            cout << "Sorry you cannot Book an International Flight with a Local Passport\n";
            LineRemover(line);
            return false;
        }

        if ((tempType == "International") && (!stamp))
        {
            cout << "Sorry you cannot Book an International Flight without a Visa Stamp\n";
            LineRemover(line);
            return false;
        }

        bool Seatcheck = false;
        while (!Seatcheck)
        {
            cout << "Enter the Type of Seat you want to Buy\n";
            cout << "1. Economy Class    2. Business\n";
            cin >> Sopt;

            switch (Sopt)
            {
            case 1:
                if (My_Aeroplane[n].GetEconomySeats() > 0)
                {
                    bill = My_Aeroplane[n].SetTravelCost("Economy");
                    cout << "This Ticket will cost you " << bill << " Rupees\n";
                    cout << "Do you want to continue\n";
                    cout << "1. Yes    2. No\n";
                    cin >> option2;

                    bool mycheck = false;
                    while (!mycheck)
                    {
                        switch (this->option2)
                        {
                        case 1:
                            My_Aeroplane[n].setEconomySeats(My_Aeroplane[n].GetEconomySeats() - 1);

                            Inputter.open("Booking_Details.txt", ios::out | ios::app);

                            Inputter << ","
                                << "Economy\n";

                            Inputter.close();

                            cout << "Ticket bought successfully\n";

                            mycheck = true;
                            break;
                        case 2:
                            LineRemover(line);
                            return false;
                            mycheck = true;
                            break;
                        default:
                            cout << "Invalid Option\n";
                            break;
                        }
                    }
                }
                else
                {
                    cout << "There are not Enough seats on this Aeroplane\n";
                    LineRemover(line);
                    return false;
                }
                Seatcheck = true;
                break;

            case 2:
                if (My_Aeroplane[n].GetBusinessSeats() > 0)
                {
                    bill = My_Aeroplane[n].SetTravelCost("Business");
                    cout << "This Ticket will cost you " << bill << " Rupees\n";

                    cout << "Do you want to continue\n";
                    cout << "1. Yes    2. No\n";
                    cin >> option2;

                    bool mycheck = false;
                    while (!mycheck)
                    {
                        switch (this->option2)
                        {
                        case 1:
                            My_Aeroplane[n].setBusinessSeats(My_Aeroplane[n].GetBusinessSeats() - 1);
                            cout << "Ticket Bought successfully\n";

                            Inputter.open("Booking_Details.txt", ios::out | ios::app);

                            Inputter << ","
                                << "Business\n";

                            Inputter.close();

                            mycheck = true;
                            break;
                        case 2:
                            LineRemover(line);
                            return false;
                            mycheck = true;
                            break;
                        default:
                            cout << "Invalid Option\n";
                            break;
                        }
                    }
                }
                else
                {
                    cout << "There are not Enough seats on this Aeroplane\n";
                    LineRemover(line);
                    return false;
                }
                Seatcheck = true;
                break;

            default:
                cout << "Invalid Option\n";
                break;
            }
        }

        return true;
    }

    //* To Show the Passenger its booked flights
    void CancelFlight_Show(int n, char c)
    {
        if (c == 'B')
        {
            cout << "1 Business Seat in " << My_Aeroplane[n].GetName() << " flying from " << Name << " to " << My_Aeroplane[n].GetDestination() << endl;
        }

        if (c == 'E')
        {
            cout << "1 Economy Seat in " << My_Aeroplane[n].GetName() << " flying from " << Name << " to " << My_Aeroplane[n].GetDestination() << endl;
        }
    }

    //* To Cancel the Booked Flight of the Passenger
    void CancelFlight(int n, char c, int line)
    {
        LineRemover(line);

        if (c == 'B')
        {
            My_Aeroplane[n].setBusinessSeats(My_Aeroplane[n].GetBusinessSeats() + 1);
            cout << "Seat refunded successfully. " << My_Aeroplane[n].GetTravelCost() * (25 / 100.0) << " deducted as Penalty\n\n";
        }

        if (c == 'E')
        {
            My_Aeroplane[n].setEconomySeats(My_Aeroplane[n].GetEconomySeats() + 1);
            cout << "Seat refunded successfully. " << My_Aeroplane[n].GetTravelCost() * (25 / 100.0) << " deducted as Penalty\n\n";
        }
    }

    //* To Help admin to restrict the seats in the Plane
    void PassengerModerator(int n)
    {
        int n1;
        cout << "This Plane has " << My_Aeroplane[n].GetEconomySeats() << " Economy Seats and " << My_Aeroplane[n].GetBusinessSeats() << " Business seats\n";
        cout << "Select the Type of Seat You want to Restrict\n";
        cout << "1. Economy Seat\n";
        cout << "2. Business Seat\n";
        cout << "3. Go Back\n";
        cin >> this->option;
        switch (this->option)
        {
        case 1:
            cout << "Enter the New Number for Economy Seats\n";
            cin >> n1;
            while (n1 < 1 || n1 > 50)
            {
                cout << "Invalid Seats Entered\n";
                cout << "Enter the New Number for Economy Seats\n";
                cin >> n1;
            }

            My_Aeroplane[n].setEconomySeats(n1);

            cout << "Economy seats updated successfully\n";

            break;
        case 2:

            cout << "Enter the New Number for Business Seats\n";
            cin >> n1;
            while (n1 < 1 || n1 > 10)
            {
                cout << "Invalid Seats Entered\n";
                cout << "Enter the New Number for Business Seats\n";
                cin >> n1;
            }

            My_Aeroplane[n].setBusinessSeats(n1);

            cout << "Business seats updated successfully\n";

            break;

        case 3:

            return;

        default:
            cout << "Invalid Option Selected \n";
            break;
        }
    }

    //* To Display those Aeroplanes whose Shedule is set
    int SheduleViewer(int c)
    {
        int counter1 = 0;

        for (int i = 0; i < 10; i++)
        {
            if (My_Aeroplane[i].GetRoute())
            {
                counter1++;
                c++;
                cout << My_Aeroplane[i].GetName() << " will fly " << My_Aeroplane[i].Gett_Type_of_Flight() << "ly from " << Name << " at " << My_Aeroplane[i].Get_Departure_TimeH() << " : " << My_Aeroplane[i].Get_Departure_TimeM() << " min and will land at " << My_Aeroplane[i].GetDestination() << " at " << My_Aeroplane[i].Get_Arrival_TimeH() << " : " << My_Aeroplane[i].Get_Arrival_TimeM() << " min\n";
                cout << "Economy Seats Left : " << My_Aeroplane[i].GetEconomySeats() << "  Ticket Price : " << My_Aeroplane[i].SetTravelCost("Economy") << endl;
                cout << "Business Seats Left : " << My_Aeroplane[i].GetBusinessSeats() << "  Ticket Price " << My_Aeroplane[i].SetTravelCost("Business") << endl;
            }
        }
        return counter1;
    }

    //*  To Check if there is a Clash between the Flight Timings
    bool Clash_Checker(int Plane, int a1, int b1, int c1, int d1)
    {
        int a, b, c, d;
        for (int i = 0; i < 10; i++)
        {
            if (i != Plane)
            {
                a = My_Aeroplane[i].Get_Departure_TimeH();
                b = My_Aeroplane[i].Get_Departure_TimeM();
                c = My_Aeroplane[i].Get_Arrival_TimeH();
                d = My_Aeroplane[i].Get_Arrival_TimeM();

                if (a1 > a && a1 < c)
                    return false;

                if (c1 > a && c1 < c)
                    return false;

                if (a1 == a)
                    if (b1 <= b)
                        return false;

                if (c1 == c)
                    if (d1 <= d)
                        return false;

                if (a1 == c)
                    if (b1 <= d)
                        return false;
            }
        }
        return true;
    }

    //* To Display all the names of the Aeroplanes 
    void AeroplaneDisplayer()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i + 1 << ": " << My_Aeroplane[i].GetName() << endl;
        }
    }

    //* To Set the Destination of Local Flights
    int DestinationSet(int n1, int n2)
    {
        switch (n2)
        {
        case 1:
            My_Aeroplane[n1].SetDestination("Islamabad");
            break;
        case 2:
            My_Aeroplane[n1].SetDestination("Lahore");
            break;
        case 3:
            My_Aeroplane[n1].SetDestination("Queeta");
            break;
        case 4:
            My_Aeroplane[n1].SetDestination("Peshawar");
            break;
        case 5:
            My_Aeroplane[n1].SetDestination("Karachi");
            break;

        default:
            break;
        }
        if (My_Aeroplane[n1].GetDestination() == Name)
        {
            cout << "Invalid Destination\n";
            return false;
        }
        return true;
    }

    //* To Set the Destination of International Flights
    void Destination_Set_Country(int n1, int n2)
    {
        switch (n2)
        {
        case 1:
            My_Aeroplane[n1].SetDestination("United Arab Emarates");
            break;
        case 2:
            My_Aeroplane[n1].SetDestination("United Kingdom");
            break;
        case 3:
            My_Aeroplane[n1].SetDestination("Canada");
            break;
        case 4:
            My_Aeroplane[n1].SetDestination("Germany");
            break;
        case 5:
            My_Aeroplane[n1].SetDestination("France");
            break;
        case 6:
            My_Aeroplane[n1].SetDestination("Italy");
            break;
        case 7:
            My_Aeroplane[n1].SetDestination("Turkey");
            break;
        case 8:
            My_Aeroplane[n1].SetDestination("Spain");
            break;
        case 9:
            My_Aeroplane[n1].SetDestination("Qatar");
            break;
        case 10:
            My_Aeroplane[n1].SetDestination("Bahrain");
            break;
        case 11:
            My_Aeroplane[n1].SetDestination("Kuwait");
            break;
        case 12:
            My_Aeroplane[n1].SetDestination("Oman");
            break;
        case 13:
            My_Aeroplane[n1].SetDestination("China");
            break;
        case 14:
            My_Aeroplane[n1].SetDestination("Afghanistan");
            break;
        case 15:
            My_Aeroplane[n1].SetDestination("Malaysia");
            break;
        case 16:
            My_Aeroplane[n1].SetDestination("Singapore");
            break;
        case 17:
            My_Aeroplane[n1].SetDestination("Thiland");
            break;
        case 18:
            My_Aeroplane[n1].SetDestination("Japan");
            break;
        case 19:
            My_Aeroplane[n1].SetDestination("South-Korea");
            break;
        case 20:
            My_Aeroplane[n1].SetDestination("Australia");
            break;
        case 21:
            My_Aeroplane[n1].SetDestination("New Zealand");
            break;
        case 22:
            My_Aeroplane[n1].SetDestination("South Africa");
            break;
        case 23:
            My_Aeroplane[n1].SetDestination("Kenya");
            break;
        case 24:
            My_Aeroplane[n1].SetDestination("Egypt");
            break;
        case 25:
            My_Aeroplane[n1].SetDestination("Iran");
            break;
        }
    }

    //* To Check if the route of Aeroplane is already set
    int AeroplaneRouteSet(int n)
    {
        int checker1;
        if (My_Aeroplane[n].GetRoute())
        {
            cout << "The Route for this Aeroplane is Already set\n";
            return 2;
        }
        cout << "This Plane will take off at " << My_Aeroplane[n].Get_Departure_TimeH() << " hr : " << My_Aeroplane[n].Get_Departure_TimeM() << " min and will Land at " << My_Aeroplane[n].Get_Arrival_TimeH() << " hr : " << My_Aeroplane[n].Get_Arrival_TimeM() << "\n";
        cout << "From Which Airport will this Plane take off\n";
        cout << "1. North Airport\n";
        cout << "2. South Airport\n";
        cin >> this->option;

        while (!DuoOptionVerifier(this->option))
        {
            cout << "Invalid Option\n";
            cout << "From Which Airport will this Plane take off\n";
            cout << "1. North Airport\n";
            cout << "2. South Airport\n";
            cin >> this->option;
        }

        switch (this->option)
        {
        case 1:

            while (My_Airport[0].Get_Airplane_Landed() > 5)
            {
                cout << "There is No space on this Airport\n";
                cout << "From Which Airport will this Plane take off\n";
                cout << "1. North Airport\n";
                cout << "2. South Airport\n";
                cin >> this->option;
            }

            My_Airport[0].Airplane_Landed_Update();
            break;
        case 2:

            while (My_Airport[1].Get_Airplane_Landed() > 5)
            {
                cout << "There is No space on this Airport\n";
                cout << "From Which Airport will this Plane take off\n";
                cout << "1. North Airport\n";
                cout << "2. South Airport\n";
                cin >> this->option;
            }
            My_Airport[1].Airplane_Landed_Update();

            break;

        default:
            cout << "Invalid Option\n";
            break;
        }

        if (My_Aeroplane[n].Gett_Type_of_Flight() == "Local")
        {
            checker1 = 1;
        }

        if ((My_Aeroplane[n].Gett_Type_of_Flight() == "International"))
        {
            checker1 = 0;
        }

        My_Aeroplane[n].SetRoute();
        return checker1;
    }

    //* Show those Aeroplanes whose timing is Set but Shedule is not set 
    int AeroplaneDispalyerSheduleSet()
    {
        int counter = 0;
        for (int i = 0; i < 10; i++)
        {
            if (My_Aeroplane[i].Get_Arrival_TimeH() != 25)
            {
                if (counter == 0)
                    cout << "You have the following Aeroplanes you can add Route to\n";
                counter++;
                cout << i + 1 << ": " << My_Aeroplane[i].GetName() << endl;
            }
        }
        if (counter == 0)
        {
            cout << "There are no sheduled flights for this City\n";
            return counter;
        }
        return counter;
    }

    //* To Get the Basic Information about the flight
    void AeroplaneFunctionality(int n)
    {
        My_Aeroplane[n].SetRouteP(false);

        int num1, num2;
        cout << "Please Set the Below Information about the Plane\n";
        cout << "How the Plane Travel\n";
        cout << "1. Locally        2. Internationally\n";
        cin >> this->option;

        while (!DuoOptionVerifier(this->option))
        {
            cout << "Invalid Option\n";
            cout << "How the Plane Travel\n";
            cout << "1. Locally        2. Internationally\n";
            cin >> this->option;
        }
        if (this->option == 1)
        {
            My_Aeroplane[n].Set_Type_of_Flight("Local");
        }
        else
            My_Aeroplane[n].Set_Type_of_Flight("International");

        cout << "Travel Type Set Successful\n";

        cout << "Enter the number of hours required to complete the flight journey\n";
        cin >> option;

        while (!HourVerification(this->option))
        {
            cout << "Invalid Hours\n";
            cout << "Enter the number of hours required to complete the flight journey\n";
            cin >> option;
        }

        while (My_Aeroplane[n].Gett_Type_of_Flight() == "Local" && option > 5)
        {
            cout << "Local Flight cannot be this much Long \n";
            cout << "Enter the number of hours required to complete the flight journey\n";
            cin >> option;

            while (!HourVerification(this->option))
            {
                cout << "Invalid Hours\n";
                cout << "Enter the number of hours required to complete the flight journey\n";
                cin >> option;
            }
        }
        My_Aeroplane[n].SetDuration_of_Flight(option);

        cout << "Flight Duration Set Successful\n";

        cout << "Enter the Departure time for this Flight (24 Hour Clock)\n";
        cout << "Hours : ";
        cin >> option;
        cout << "Minutes : ";
        cin >> option2;
        while (!validateTime(option, option2))
        {
            cout << "Invalid Hours or Minutes \n";
            cout << "Enter the Departure time for this Flight (24 Hour Clock)\n";
            cout << "Hours : ";
            cin >> option;
            cout << "Minutes : ";
            cin >> option2;
        }

        num1 = option + My_Aeroplane[n].GetDuration_of_Flight();
        num2 = option2;

        if (num1 > 23)
        {
            num1 -= 24;
        }

        while (!Clash_Checker(n, option, option2, num1, num2))
        {
            cout << "There is Clash with the other Flight Please Select an other Time \n";
            cout << "Enter the Departure time for this Flight (24 Hour Clock)\n";
            cout << "Hours : ";
            cin >> option;
            cout << "Minutes : ";
            cin >> option2;

            while (!validateTime(option, option2))
            {
                cout << "Invalid Hours or Minutes \n";
                cout << "Enter the Departure time for this Flight (24 Hour Clock)\n";
                cout << "Hours : ";
                cin >> option;
                cout << "Minutes : ";
                cin >> option2;
            }

            num1 = option + My_Aeroplane[n].GetDuration_of_Flight();
            num2 = option2;
        }

        cout << "Departure Time Set Successfully\n";

        My_Aeroplane[n].Set_Departure_Time(option, option2);

        My_Aeroplane[n].Set_Arrival_Time(option + My_Aeroplane[n].GetDuration_of_Flight(), option2);

        cout << "Expected Arrival Time will be " << My_Aeroplane[n].Get_Arrival_TimeH() << " : " << My_Aeroplane[n].Get_Arrival_TimeM() << endl;
    }

    //* Default Constructor 
    City()
    {
        My_Airport[0].SetName("North-Airport");
        My_Airport[1].SetName("South-Airport");

        Count++;

        switch (Count)
        {
        case 1:
            Name = "Islamabad";
            break;
        case 2:
            Name = "Lahore";
            break;
        case 3:
            Name = "Queeta";
            break;
        case 4:
            Name = "Peshawar";
            break;
        case 5:
            Name = "Karachi";
            break;
        default:
            Count = 1;
            Name = "Islamabad";

            break;
        }
    }

    string Get_Name()
    {
        return this->Name;
    }

    void set_Name(string s)
    {
        this->Name = s;
    }
};

int City::Count = 0;