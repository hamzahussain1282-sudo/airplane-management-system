#include <iostream>
#include <string>
#include "OnlineData.h"
#include<conio.h>
#ifdef Data
#include "Data.h"
#endif
using namespace std;

class PassengerPanel
{
    int option;

    static int counter;
    int Rescount;

    bool Passport;
    string PassportType;
    bool Stamp;

    PData My_P_Data;
    PDataBase My_Data_Base;
    OnlineData OnlineDataAcess;

public:

    PassengerPanel()
    {
        Rescount = 0;
    }

    //* Parameterized Constructor
    PassengerPanel(string type, bool P, bool ST, PData obj1, PDataBase obj2, OnlineData obj3)
    {
        this->PassportType = type;
        this->Passport = P;
        this->Stamp = ST;
        this->My_P_Data = obj1;
        this->My_Data_Base = obj2;
        this->OnlineDataAcess = obj3;
    }

    //* A Paragraph for Inquiry Details 
    void Basic_Detail_Viewer()
    {
        cout << "NUCES Airline Flight System (NAFS) is a flight reservation system for a newly established airline operating in five major cities of Pakistan. The airline has ten airplanes stationed in each city, and a maximum of five planes can land at an airport at a time. NAFS offers ten local and five international flights departing from each airport daily. Each airplane has a seating capacity of 50 passengers in economy class and 10 in business class. The system provides a user-friendly interface for flight reservation and booking, managing flight schedules, airport management, and passenger management. NAFS adheres to COVID-19 safety measures by maintaining social distancing on all flights.\n";
    }

    //* To Show the sheduled flights to registered and unregistered user
    void Flight_Shedule_Viewer()
    {
        int opt;
        cout << "1. View Full Routes \n";
        cout << "2. Search with Customized Keywords\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            OnlineDataAcess.RouteDisplayer();
            break;
        case 2:
            OnlineDataAcess.RouteDisplayerCK();
            break;
        default:
            cout << "Invalid Option\n";
        }
    }

    //* To Reserve a Flight for a Registered user 
    void Flight_Reserver()
    {
        int count;
        Rescount++;
        string s1, s2;

        cout << "Welcome to Flight Booking \n";

        cout << "Enter your Account Number\n";
        cin >> s1;

        cout << "Enter you PIN\n";
        int Ch;
        Ch = _getch();
        while (Ch != 13)
        {
            if (Ch == '\b')
            {
                if (!s2.empty())
                {
                    s2.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                s2.push_back(Ch);
                cout << "*";
            }
            Ch = _getch();
        }

        cout << "\n";

        if (VerifyFinancialDetail(My_Data_Base, s1, s2))
        {
            cout << "Account details Verified\n";
            OnlineDataAcess.Flight_Reserver(PassportType, Stamp, Passport, Rescount);
        }
        else
        {
            cout << "Invalid Financial Details\n";
            Rescount--;
        }
    }

    //* To Cancel a Booked flight for a registered user
    void Flight_Canceler()
    {
        fstream Taker;
        int Choser;
        Taker.open("Booking_Details.txt", ios::in);
        string Line;
        if (Taker.peek() == EOF)
        {
            cout << "This Passenger has No Booked Flights\n";
            return;
        }

        cout << "Enter the Aeroplane Number you want to cancel flight\n\n";
        int Fcount = 0;
        while (getline(Taker, Line))
        {
            Fcount++;
            int mycity = Line[4] - 48;
            int myairport = Line[15] - 48;
            char SeatType = Line[17];
            if (Line.length() > 25)
            {
                myairport = 10;
                SeatType = Line[18];
            }

            OnlineDataAcess.FlightCancelorshow(mycity - 1, myairport - 1, SeatType);
            cout << "\nDo you want to Cancel this Seat\n";
            cout << "1. Yes      2.No\n";
            cin >> Choser;
            switch (Choser)
            {
            case 1:
                OnlineDataAcess.FlightCancelor(mycity - 1, myairport - 1, SeatType, Fcount);
                Fcount--;
                break;
            case 2:
                break;

            default:
                break;
            }
        }
    }

    //* A Menue for the Registered User
    bool FunctionailityChoser_R()
    {
        cout << "What you want to do\n";
        cout << "1. View Basic Details about NAFS \n";
        cout << "2. View Flight Shedule Detail\n";
        cout << "3. Reserve Flight\n";
        cout << "4. Cancel Flight\n";
        cout << "5. Reset Password or Username\n";
        cout << "6. Go Back\n";
        cin >> this->option;

        switch (this->option)
        {
        case 1:
            Basic_Detail_Viewer();
            break;
        case 2:
            Flight_Shedule_Viewer();
            break;
        case 3:
            Flight_Reserver();
            break;
        case 4:
            Flight_Canceler();
            break;
        case 5:
            My_Data_Base.Reseter();
            break;
        case 6:
            return false;
            break;

        default:
            cout << "Invalid Option\n";
            break;
        }
        return true;
    }

    //* A Menue for the Un-Registered User 
    bool FunctionailityChoser_P()
    {
        cout << "What you want to do\n";
        cout << "1. View Basic Details about NAFS \n";
        cout << "2. View Flight Shedule Detail\n";
        cout << "3. Go Back\n";
        cin >> this->option;

        switch (this->option)
        {

        case 1:
            Basic_Detail_Viewer();
            break;
        case 2:
            Flight_Shedule_Viewer();
            break;
        case 3:
            return false;
            break;

        default:
            cout << "Invalid Option\n";
            break;
        }
        return true;
    }

    //* To Validate the account number
    bool AccountNumberVerify(string s)
    {
        if (s.length() < 10)
            return false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < 48 || s[i] > 57)
            {
                return false;
            }
        }
        return true;
    }

    //* To the Validate the account code 
    bool AccountCodeVerify(string s)
    {
        if (s.length() > 4 || s.length() < 4)
            return false;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < 48 || s[i] > 57)
            {
                return false;
            }
        }
        return true;
    }

    //* A Function to Initiate Guest Mode
    void GuestReceiever()
    {
        bool check = true;
        cout << "You have Continued as Guest\n";

        //? This Loop will run until the User press back button
        while (check)
        {
            check = this->FunctionailityChoser_P();
            if (check)
            {
                system("pause");
            }
        }
    }

    //* A Function to initiate Registeration mode 
    void RegisterMaker()
    {
        bool check = true;
        string s, c;
        cout << "Enter a unique User-Name\n";
        cin >> s;

        My_P_Data.setUsername(s);

        cout << "Enter Your Valid CNIC Number \n";
        cin >> c;

        while ((!My_P_Data.CNICVerifier(c)))
        {
            cout << "CNIC is not Valid  \n";
            cout << "Enter Your Valid CNIC Number \n";
            cin >> c;
        }

        if (My_Data_Base.GetCounter() != 0)
        {
            if (!My_Data_Base.CNIC_Checker(c))
            {
                cout << "This User has already registered \n";
                system("pause");
                return;
            }
            My_Data_Base.CnicSaver(c);
        }

        else
        {
            My_Data_Base.CnicSaver(c);
        }
        string No, code;
        cout << "Enter your Account Number for Payment and Transaction\n";
        cin >> No;

        while (!AccountNumberVerify(No))
        {
            cout << "Invalid Account Number Format\n";
            cout << "Enter your Account Number for Payment and Transaction\n";
            cin >> No;
        }

        My_P_Data.SetCardno(No);

        cout << "Enter the 4 Digit Security code of Account Number for Online Transactions\n";
        cin >> code;

        while (!AccountCodeVerify(code))
        {
            cout << "Invalid Format for Security Code \n";
            cout << "Enter the 4 Digit Security code of Account Number for Online Transactions\n";
            cin >> code;
        }

        My_P_Data.SetSecurityCode(code);
        My_Data_Base.FinancialDataSaver(No, code);

        My_P_Data.setPasswordPro();
        My_Data_Base.DataSaver(s, My_P_Data.getPassword());
        bool pcheck = false;
        while (!pcheck)
        {
            cout << "Do you have a Valid Passport\n";
            cout << "1. Yes    2. No\n";
            cin >> this->option;

            switch (this->option)
            {
            case 1:
                Passport = true;
                cout << "What is the type of your Passport\n";
                cout << "1. Local   2. Foreign\n";
                cin >> this->option;

                switch (this->option)
                {
                case 1:
                    PassportType = "Local";
                    pcheck = true;
                    break;
                case 2:
                    PassportType = "Foreign";
                    cout << "Do you have a Visa Stamp on your Passport\n";
                    cout << "1. Yes    2. No\n";
                    cin >> this->option;

                    switch (this->option)
                    {
                    case 1:
                        Stamp = true;
                        pcheck = true;
                        break;
                    case 2:
                        Stamp = false;
                        pcheck = true;
                        break;

                    default:
                        cout << "Invalid Option\n";
                        break;
                    }
                    break;

                default:
                    cout << "Invalid Option\n";
                    break;
                }

                cout << "Thanks for filling the Information\n";

                break;
            case 2:
                Passport = false;
                pcheck = true;
                break;
            default:
                cout << "Invalid Option\n";
                break;
            }
        }
        cout << "You have Registered Successfully\n\n";

        while (check)
        {
            if (check)
            {
                system("pause");
            }
            system("cls");
            check = this->FunctionailityChoser_R();
        }
    }

    //* A Function to initiate Login mode 
    void LoginMaker()
    {
        bool check = true;
        if (My_Data_Base.GetCounter() == 0)
        {
            cout << "Please make an account first\n";
            system("pause");
            return;
        }

        string s, p;
        cout << "Enter your User-Name\n";
        cin >> s;
        p = My_P_Data.PasswordInputter();

        while (!My_Data_Base.DataChecker(s, p))
        {
            cout << "Incorrect Username or Password\n";
            cout << "Enter your Username\n";
            cin >> s;
            p = My_P_Data.PasswordInputter();
        }

        cout << "You have Logged in Successfully\n\n";
        while (check)
        {
            check = this->FunctionailityChoser_R();
            if (check)
                system("pause");
            system("cls");
        }
    }

    //* This Function will run the Menue of Passenger pannel and will run util the user exit this module 
    bool MenueDisplayer(OnlineData Obj)
    {
        this->OnlineDataAcess = Obj;
        bool check = true;
        cout << "Welcome to Passenger Panel\n";
        cout << "1. Login     2. Register     3. Guest     4. Go Back\n";
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
            this->GuestReceiever();
            break;
        case 4:
            return false;
            break;

        default:
            cout << "Invalid Option\n";
            break;
        }
        return check;
    }
};

int PassengerPanel::counter = 1;