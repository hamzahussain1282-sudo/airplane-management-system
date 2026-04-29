# NUCES Airline Flight System (NAFS)
A comprehensive C++ console-based flight reservation and management system for a newly established airline operating across major cities in Pakistan.
## 📋 Overview
NUCES Airline Flight System (NAFS) is a flight ticketing and management platform that facilitates:

- Flight reservations and bookings
- Flight schedule management
- Airport operations management
- Passenger information management
- Administrative controls for airline operations

The system adheres to COVID-19 safety protocols by maintaining social distancing across all flights.
## 🚀 Features
## Admin Panel
Administrators can access the system with credentials to:

- Manage City Routes: Add, view, and modify flight routes between cities
- Manage Flights: Schedule flights, set departure/arrival times, and manage flight details
- Manage Airplane Information: Configure airplane details, seating capacity, and availability
- View All Passengers: Access comprehensive passenger booking records

## Passenger Panel
Passengers (both registered and unregistered) can:

- *View Flight Schedules*: Browse complete route information or search with custom keywords
- *Flight Reservation: Book* flights with account credentials
- *Check Availability*: View available seats in both Economy and Business class
- *Inquiry System*: Access detailed information about the airline system

🏗️ System Architecture
Core Components
Classes:

- MainSystem: Entry point and main menu handler
- AdminPanel: Administrative functions and authentication
- PassengerPanel: Passenger booking and inquiry interface
- Aeroplane: Airplane details, seating, and flight cost management
- City: City information and associated airports
- Country: Country-level data management
- Airport: Airport operations and airplane tracking
- Passenger: Passenger information (Economy/Business class)
- Data: Data persistence and file handling
- OnlineData: Runtime data management and route display

## Technical Specifications
### Fleet Information:

10 airplanes stationed per city
Maximum 5 planes can land at an airport simultaneously
10 local flights per airport daily
5 international flights per airport daily

### Seating Capacity:

Economy Class: 50 seats per airplane
Business Class: 10 seats per airplane

### Pricing (Base Rates):

Local Economy: PKR 10,500
Local Business: PKR 21,000
International Economy: PKR 22,000
International Business: PKR 44,000

## 📁 Project Structure
project/
├── Source.cpp              # Main entry point
├── MainSys.h              # Main system menu and routing
├── AdminPanel.h           # Admin authentication and management
├── PassengerPanel.h       # Passenger booking interface
├── Aeroplanes.h           # Airplane class and operations
├── City.h                 # City management
├── Country.h              # Country data
├── Airport.h              # Airport operations
├── Passenger.h            # Passenger information
├── Data.h                 # Data persistence layer
├── OnlineData.h           # Runtime data management
├── AdminData.txt          # Admin credentials storage
└── Passenger_Data.txt     # Passenger booking records
🛠️ Installation & Setup
Prerequisites

C++ Compiler (GCC, MinGW, or MSVC)
Windows OS (uses system("cls") and _getch())
Standard C++ libraries

## Compilation
Using g++:
bashg++ Source.cpp -o AirlineSystem.exe
Using Visual Studio:

Open the project folder
Create a new C++ Console Application project
Add all header files to the project
Build and run

Running the Application
bash./AirlineSystem.exe
📖 Usage Guide
For Administrators

Launch the application
Select option 1 for Admin Panel
Login with credentials (default: username: Admin, password: admin123)
Choose from management options:

Manage city routes
Schedule and modify flights
Configure airplane information
View passenger manifests



For Passengers

Launch the application
Select option 2 for Passenger Panel
Choose your action:

View basic system information
Browse flight schedules
Reserve a flight (requires account)
Check seat availability



Flight Booking Process

Enter your account number
Enter your PIN (displayed as asterisks for security)
Select departure and destination cities
Choose between Economy or Business class
Confirm booking and receive confirmation

🔐 Default Credentials
Admin Login:

Username: Admin
Password: admin123

⚠️ Security Note: Change default credentials in production deployment
🗃️ Data Storage
The system uses text file-based storage:

AdminData.txt: Stores admin credentials
Passenger_Data.txt: Stores passenger booking records

## ⚠️ Known Limitations

Console-based interface (no GUI)
Windows-specific commands (system("cls"), _getch())
File-based storage (no database integration)
Limited error handling for invalid inputs
Single admin account support

## 🔮 Future Enhancements

Database integration (MySQL/PostgreSQL)
Multi-platform support (Linux/Mac)
Graphical user interface (GUI)
Payment gateway integration
Email confirmation system
Multi-admin support with role-based access
Real-time seat availability updates
Ticket cancellation and refund management

## 👥 System Actors

Administrator: Manages flights, routes, and system configuration
Registered Passenger: Can book flights and view history
Unregistered User: Can view flight schedules and system information


## 👨‍💻 Contributing
[Hamza Hussain, Usman Wajid, Eesha Irfan]
