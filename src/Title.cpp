#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

#include "./../include/Title.hh"
#include "./../include/Time.hh"

void title()
{

    cout << "\n\n\n";

    cout << "\n\t\t\t\t***************************************************";
    cout << "\n\t\t\t\t***************************************************";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**---------MORNING STAR SCHOOL RATLAM------------**";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**----------SCHOOL MANAGEMENT SYSTEM-------------**";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**                                               **";
    cout << "\n\t\t\t\t**                            BY: viresh Panchal **";
    cout << "\n\t\t\t\t***************************************************";
    cout << "\n\t\t\t\t***************************************************";
    cout << "\n\n";

    cout << "\n\t\t\t\tPress any key to continue...............\t";

    getchar();
}

void headerTitle()
{
    string dt, Loc_date, Loc_time;
    Time t;
    Loc_date = t.get_date();
    Loc_time = t.get_time();

    system("clear");

    cout << "\n\n";
    cout << "\n\t\t\t*******Morning Star School Ratlam*******";
    cout << "\n";
    cout << "\n\tDate and Time : " << Loc_date << " and " << Loc_time;
    cout << "\n\n";
}