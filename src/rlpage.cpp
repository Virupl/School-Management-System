#include <iostream>
#include <unistd.h>

using namespace std;

// include file
#include "./../include/Title.hh"
#include "./../include/rlpage.hh"
#include "./../include/Admin.hh"
#include "./../include/students.hh"

void rlpage()
{
a:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t\t[1] Regitration";
    cout << "\n\t\t[2] Login";

    int i;
    cout << "\n\n\t\t\tEnter a number : ";
    cin >> i;

    if (i == 1)
    {
        system("clear");
        headerTitle();

        admin ad;
        ad.input();

        goto a;
    }
    else if (i == 2)
    {
    x:
        system("clear");
        headerTitle();

        cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
        cout << "\n\t\t[1] Admin Login";
        cout << "\n\t\t[2] Student Login";

        int m;
        cout << "\n\n\t\t\tEnter a number : ";
        cin >> m;

        if (m == 1)
        {
            system("clear");
            headerTitle();

            admin ad;
            ad.AdminLogin();
        }
        else if (m == 2)
        {
            system("clear");
            headerTitle();

            student st;
            st.studentLogin();
        }
        else
        {
            cout << "\n\n\t\tPlease, Choose Right Option...";
            usleep(2000000);
            goto x;
        }
    }
    else
    {
        cout << "\n\n\t\tPlease, Choose Right Option...";
        usleep(2000000);
        goto a;
    }
}
