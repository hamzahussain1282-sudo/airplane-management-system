#include <iostream>
#include "MainSys.h"
using namespace std;

int main()
{
    MainSystem MainObj;

    while (true)
    {
        MainObj.MenueDisplayer();
        system("cls");
    }
}