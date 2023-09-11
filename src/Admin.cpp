#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <string.h>

// include file
#include "./../include/Title.hh"
#include "./../include/Admin.hh"
#include "./../include/rlpage.hh"
#include "./../include/Teachers.hh"
#include "./../include/students.hh"
#include "./../include/course.hh"
#include "./../include/reportCard.hh"

using namespace std;

void admin::input()
{
    ofstream fout, fIP;

    fout.open("./data_files/Admin.txt", ios::out);
    fIP.open("./data_files/AdminIP.txt", ios::out);

    if (fout.fail() || fIP.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        rlpage();
    }

    cout << "\n\n\t\t\t\tADMIN DETAILS";
    cout << "\n\n\t\tEnter First Name :- ";
    cin >> fName;
    cout << "\n\t\tEnter Last Name :- ";
    cin >> lName;
    cout << "\n\t\tEnter Age :- ";
    cin >> Age;
    cout << "\n\t\tEnter Gender(Male for M // Female for F) :- ";
    cin >> Gender;
    while (Gender != 'M' && Gender != 'F')
    {
        cout << "\t\tM or F? :- ";
        cin >> Gender;
    }
m:
    cout << "\n\t\tEnter Mobile No :- ";
    cin >> Mobile_No;
    int SIZE = Mobile_No.length();
    if (SIZE > 12 || SIZE < 10)
    {
        cout << "\n\t Only 10 Digit Mobile No. Valid. Please Enter Right Number" << endl;
        usleep(2000000);
        goto m;
    }

    cout << "\n\t\tEnter Address :- ";
    cin >> address;
    cout << "\n\t\tEnter User ID :- ";
    cin >> ID;
    cout << "\n\t\tEnter Password :- ";
    cin >> Password;

    fout << "\n\t\tADMIN DETAILS\n\n"
         << "\t\tFirst Name : " << fName + " " + lName
         << "\n\t\tAge : " << Age
         << "\n\t\tGender : " << Gender
         << "\n\t\tMobile No : " << Mobile_No
         << "\n\t\tAddress : " << address;

    fIP << ID
        << endl
        << Password;

    cout << "\n\t\t\tInformation Saved Successfully\n\n";
    fout.close();
    fIP.close();
}

void admin::AdminLogin()
{
    char original_Id[20], original_Password[20];
    char temp_Id[20], temp_Password[20];

    ifstream fin;

repeat:
    cout << "\t\tEnter your ID : ";
    cin >> temp_Id;
    cout << "\t\tEnter your Password : ";
    cin >> temp_Password;

    fin.open("./data_files/AdminIP.txt", ios::in);

    if (fin.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        usleep(1000000);
        rlpage();
    }

    fin >> original_Id >> original_Password;

    if (strcmp(temp_Id, original_Id) == 0 && strcmp(temp_Password, original_Password) == 0)
    {
        cout << "\n\t\t\t\tLogin successful\n\n";

        usleep(1000000);

        system("clear");

        headerTitle();

        AdminAdd();
    }
    else
    {
        cout << "\n\tWrong Id and Password, Please try again. \n\n";
        goto repeat;
    }

    fin.close();
}

void admin::AdminAdd()
{
x:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t----------------------------------";
    cout << "\n\t\t[1] Add Teachers";
    cout << "\n\t\t[2] Add Courses";
    cout << "\n\t\t[3] Add Students";
    cout << "\n\t\t[4] Add Report Card";
    cout << "\n\t\t[5] Teachers Data";
    cout << "\n\t\t[6] Courses Data";
    cout << "\n\t\t[7] Students Data";
    cout << "\n\t\t[8] Report Data";
    cout << "\n\t\t[9] Admin Data";
    cout << "\n\t\t[10] Exit";
    cout << "\n\t----------------------------------";

    int i;
    cout << "\n\n\t\t\tEnter a number :- ";
    cin >> i;

    if (i == 1)
    {
    a:
        system("clear");
        headerTitle();

        teacher tc;
        tc.input();

        cout << "\n\n\t\tDo you want add more teachers (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(1000000);
            goto a;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(1000000);
            AdminAdd();
        }
    }
    else if (i == 2)
    {
    c:
        system("clear");
        headerTitle();

        course cs;
        cs.setCourseList();

        cout << "\n\n\t\tDo you want add more courses (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(1000000);
            goto c;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(1000000);
            AdminAdd();
        }
    }
    else if (i == 3)
    {
    b:
        system("clear");
        headerTitle();

        student st;
        st.input();

        cout << "\n\n\t\tDo you want add more students (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(10000);
            goto b;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(10000);
            AdminAdd();
        }
    }
    else if (i == 4)
    {
    v:
        system("clear");
        headerTitle();

        reportCard rc;
        rc.input();

        cout << "\n\n\t\tDo you want add more report card (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(1000000);
            goto v;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(1000000);
            AdminAdd();
        }
    }
    else if (i == 5)
    {
    q:
        system("clear");
        headerTitle();

        cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
        cout << "\n\t\t[1] Search Teacher";
        cout << "\n\t\t[2] Remove Teacher";

        int n;
        cout << "\n\n\t\t\tEnter a number :- ";
        cin >> n;
        if (n == 1)
        {
        m:
            system("clear");
            headerTitle();

            teacher tc;
            tc.showTeacher();

            cout << "\n\n\t\tDo you want seen more teachers (Y/N) :- ";
            char ch;
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                usleep(1000000);
                goto m;
            }
            else if (ch == 'N' || ch == 'n')
            {
                cout << "\n\t\t\t\tThanks You :) \n";
                usleep(1000000);
                AdminAdd();
            }
        }
        else if (n == 2)
        {
        s:
            system("clear");
            headerTitle();

            teacher tc;
            tc.removeTeacher();

            cout << "\n\n\t\tDo you want remove more teachers (Y/N) :- ";
            char ch;
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                usleep(1000000);
                goto s;
            }
            else if (ch == 'N' || ch == 'n')
            {
                cout << "\n\t\t\t\tThanks You :) \n";
                usleep(1000000);
                AdminAdd();
            }
        }
        else
        {
            cout << "\n\n\t\tWrong Option! Choose right option. :)\n";
            usleep(2000000);
            goto q;
        }
    }
    else if (i == 6)
    {
        system("clear");
        headerTitle();

        course cs;
        cs.showCourseList();

        cout << "\n\t\t\t\tPress any key to back...............\t";
        getchar();
        usleep(2000000);

        AdminAdd();
    }
    else if (i == 7)
    {
    w:
        system("clear");
        headerTitle();

        cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
        cout << "\n\t\t[1] Search Student";
        cout << "\n\t\t[2] Remove Student";

        int n;
        cout << "\n\n\t\t\tEnter a number :- ";
        cin >> n;

        if (n == 1)
        {
        n:
            system("clear");
            headerTitle();

            student st;
            st.showStudent();

            cout << "\n\n\t\tDo you want seen more students (Y/N) :- ";
            char ch;
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                usleep(1000000);
                goto n;
            }
            else if (ch == 'N' || ch == 'n')
            {
                cout << "\n\t\t\t\tThanks You :) \n";
                usleep(1000000);
                AdminAdd();
            }
        }
        else if (n == 2)
        {
        r:
            system("clear");
            headerTitle();

            student st;
            st.removeStd();

            cout << "\n\n\t\tDo you want seen more students (Y/N) :- ";
            char ch;
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                usleep(1000000);
                goto r;
            }
            else if (ch == 'N' || ch == 'n')
            {
                cout << "\n\t\t\t\tThanks You :) \n";
                usleep(1000000);
                AdminAdd();
            }
        }
        else
        {
            cout << "\n\n\t\tWrong Option! Choose right option. :)\n";
            usleep(2000000);
            goto w;
        }
    }
    else if (i == 8)
    {
    g:
        system("clear");
        headerTitle();

        reportCard rc;
        rc.showCard();

        cout << "\n\n\t\tDo you want seen more report card (Y/N) :- ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            usleep(1000000);
            goto g;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "\n\t\t\t\tThanks You :) \n";
            usleep(1000000);
            AdminAdd();
        }
    }
    else if (i == 9)
    {
        system("clear");
        headerTitle();

        ifstream fin;
        fin.open("./data_files/Admin.txt", ios::in);
        if (fin.fail())
        {
            cout << "\n\n\t\tFile Opened Fail!..." << endl;
            usleep(1000000);
            AdminAdd();
        }
        string line;
        while (getline(fin, line))
        {
            cout << line << endl;
        }

        getchar();
        getchar();

        cout << "\n\t\t\t\tPress any key to back...............\t";
        getchar();
        usleep(1000000);

        AdminAdd();
    }
    else if (i == 10)
    {
        system("clear");
        headerTitle();

        cout << "\n\n\t\tDo you want to exit! (Y/N) : ";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            cout << "\n\t\t\t\tThanks You :) \n\n\n\n\n";
            exit(1);
            usleep(1000000);
        }
        else if (ch == 'N' || ch == 'n')
        {
            usleep(2000000);
            AdminAdd();
        }
    }
    else
    {
        cout << "\n\n\t\tWrong Option! Choose right option. :)\n";
        usleep(2000000);
        goto x;
    }
}

void admin::showAdminData()
{
    ifstream fin;

    fin.open("./data_files/Admin.txt", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        rlpage();
    }
    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    getchar();
    getchar();
    usleep(1000000);
}