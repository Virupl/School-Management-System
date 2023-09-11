#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

#include "./../include/Title.hh"
#include "./../include/students.hh"
#include "./../include/Admin.hh"
#include "./../include/course.hh"
#include "./../include/rlpage.hh"

int student::lastlineReadCSV()
{
    // Open the CSV file for reading
    ifstream infile("./data_files/Students.csv");

    // Create a vector to store the lines of the CSV file
    vector<string> lines;

    // Read each line of the CSV file and store it in the vector
    string line;
    while (getline(infile, line))
    {
        lines.push_back(line);
    }

    // Get the last line of the CSV file
    string lastLine = lines.back();

    // Use a string stream to split the line into words
    istringstream iss(lastLine);
    string firstWord;
    getline(iss, firstWord, ',');

    // Print the first word of the last line of the CSV file
    // cout << firstWord << endl;

    // int num = stoi(firstWord);
    int num = std::atoi(firstWord.c_str());

    // cout << num << endl;
    infile.close();
    return num;
}

void student::input()
{
    fstream fout;

    fout.open("./data_files/Students.csv", ios::in | ios::app);
    if (fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\n\t\t\t\tSTUDENT DETAILS";
    cout << "\n\n\n\t\tEnter First Name :- ";
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
    cin >> Address;

    course cs;
    cs.showCourseList();

    cout << "\n\t\tEnter Course ID :- ";
    cin >> courseId;

    cout << "\n\t\tEnter User ID :- ";
    cin >> userId;

    cout << "\n\t\tEnter Password :- ";
    cin >> Password;

    // Create a vector to store the data
    vector<string> data;

    // Read the first line from the CSV file
    string line;
    getline(fout, line);

    // Use a stringstream to split the line into fields
    stringstream ss(line);
    string field;
    while (getline(ss, field, ','))
    {
        // Add each field to the data vector
        data.push_back(field);
    }

    // Print the data vector
    // for (auto field : data)
    // {
    //     cout << field << " ";
    // }
    // cout << endl;
    if (!data.empty())
    {

        string ls = data[0];

        // cout << ls << endl;

        if ("StudentId" != ls)
        {
            fout.seekp(0);
            fout << "StudentId, First Name, Last Name, Age, Gender, Mobile No, Address, Course Id, User Id, Password\n";
        }
        else
        {
            int num = lastlineReadCSV();
            if (Sid == num)
            {
                num++;
                Sid = num;
            }
            else
            {
                Sid = 1;
            }
            fout << Sid << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << courseId << "," << userId << "," << Password << "\n";
        }
    }
    else
    {
        ofstream file("./data_files/Students.csv");
        if (file.fail())
        {
            cout << "\n\n\t\tFile Opened Fail!..." << endl;
            usleep(1000000);
            admin ad;
            ad.AdminAdd();
        }
        file << "StudentId, First Name, Last Name, Age, Gender, Mobile No, Address, Course Id, User Id, Password\n";
        file << Sid << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << courseId << "," << userId << "," << Password << "\n";

        file.close();
    }
    fout.close();

    cout << "\n\t\t\tInformation Saved Successfully\n\n";
}

void student::showStudent()
{
    ifstream fin;
    fin.open("./data_files/Students.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(2000000);
        admin ad;
        ad.AdminAdd();
    }
    cout << "\n\t\tStudent Id :- ";
    string id;
    cin >> id;

    int count = 0;

    vector<string> row;

    string line, word, roll2;

    while (getline(fin, line))
    {

        row.clear();

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        roll2 = row[0];

        if (roll2 == id)
        {

            // Print the found data
            count = 1;
            cout << "\n\n\t\t\t\tSTUDENT DETAILS\n\n";
            cout << "\t\tName :- " << row[1] << " " << row[2];
            cout << "\n\t\tAge :- " << row[3];
            cout << "\n\t\tGender :- " << row[4];
            cout << "\n\t\tMobile No :- " << row[5];
            cout << "\n\t\tAddress :- " << row[6];
            cout << "\n\t\tCourse Id :- " << row[7];
            cout << "\n";
            break;
        }
    }
    if (count == 0)
    {
        cout << "\n\t\t\tRecord not found\n";
    }

    fin.close();
    getchar();
}

void student::studentLogin()
{
    string original_Id, original_Password;
    string temp_Id, temp_Password;

    ifstream fin;

repeat:
    cout << "\t\tEnter your ID : ";
    cin >> temp_Id;
    cout << "\t\tEnter your Password : ";
    cin >> temp_Password;

    fin.open("./data_files/Students.csv", ios::in);

    if (fin.fail())
    {
        cout << "\n\tFile failed to open. Please register fisrt then Login." << endl;
        usleep(1000000);
        rlpage();
    }

    vector<vector<string>> data;

    string line, word, roll2;

    while (!fin.eof())
    {
        vector<string> row;
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        data.push_back(row);
    }

    bool login_success = false;
    string str;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i][8] == temp_Id && data[i][9] == temp_Password)
        {
            login_success = true;
            str = data[i][0];
            break;
        }
    }
     fin.close();
    if (login_success)
    {
        cout << "\n\t\t\t\tLogin successful\n\n";

        usleep(1000000);

        showStudentSide(str);
    }
    else
    {
        cout << "\n\tWrong Id and Password, Please try again. \n\n";
        goto repeat;
    }
}

void student::showStudentSide(string id)
{
s:
    system("clear");
    headerTitle();

    cout << "\n\n\n\t\tPlease, Choose from the following Option:\n";
    cout << "\n\t\t[1] Profile";
    cout << "\n\t\t[2] Report Card";
    cout << "\n\t\t[3] Update Profile";

    int a;
    cout << "\n\n\t\t\tEnter a number : ";
    cin >> a;

    if (a == 1)
    {
        system("clear");
        headerTitle();

        ifstream fin;
        fin.open("./data_files/Students.csv", ios::in);
        if (fin.fail())
        {
            cout << "\n\n\t\tFile Opened Fail!..." << endl;
            usleep(2000000);
            admin ad;
            ad.AdminAdd();
        }

        int count = 0;

        vector<string> row;

        string line, word, tepId;

        while (getline(fin, line))
        {

            row.clear();

            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            tepId = row[0];

            if (tepId == id)
            {

                // Print the found data
                count = 1;
                cout << "\n\n\t\t\t\tSTUDENT DETAILS\n\n";
                cout << "\t\tName :- " << row[1] << " " << row[2];
                cout << "\n\t\tAge :- " << row[3];
                cout << "\n\t\tGender :- " << row[4];
                cout << "\n\t\tMobile No :- " << row[5];
                cout << "\n\t\tAddress :- " << row[6];
                cout << "\n\t\tCourse Id :- " << row[7];
                cout << "\n";
                break;
            }
        }
        if (count == 0)
        {
            cout << "\n\t\t\tRecord not found\n";
        }

        fin.close();

        getchar();
        getchar();
        usleep(1000000);
        goto s;
    }
    else if (a == 2)
    {
        ifstream fin;
        fin.open("./data_files/reportCard.csv", ios::in);
        if (fin.fail())
        {
            cout << "\n\n\t\tFile Opened Fail!..." << endl;
            usleep(1000000);
            admin ad;
            ad.AdminAdd();
        }

        int count = 0;

        vector<string> row;

        string line, word, roll2;

        while (getline(fin, line))
        {

            row.clear();

            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            roll2 = row[0];

            if (roll2 == id)
            {

                // Print the found data
                count = 1;
                cout << "\n\n\t\t\t\tREPORT CARD DETAILS\n\n";
                cout << "\t\tName :- " << row[1];
                cout << "\n\t\tTotal Number :- " << row[2];
                cout << "\n\t\tPercentage :- " << row[3];
                cout << "\n\t\tGrade :- " << row[4];
                cout << "\n";
                break;
            }
        }
        if (count == 0)
        {
            cout << "\n\t\t\tRecord not found\n";
        }

        fin.close();
        getchar();
        getchar();
        usleep(1000000);
        goto s;
    }
    else if (a == 3)
    {
    n:
        system("clear");
        headerTitle();

        updateStd(id);

        cout << "\n\t\t\t\tThanks You :) \n";
        usleep(1000000);
        showStudentSide(id);
    }
    else
    {
        cout << "\n\n\t\tWrong Option! Choose right option. :)\n";
        usleep(2000000);
        goto s;
    }
}

void student::removeStd()
{
    ifstream fin;
    ofstream fout;
    fin.open("./data_files/Students.csv", ios::in);
    fout.open("./data_files/temp1.csv", ios::out);
    if (fin.fail() || fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(2000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\t\tStudent Id :- ";
    string id;
    cin >> id;

    string line, firstWord;
    vector<string> lines;
    while (getline(fin, line))
    {
        firstWord = line.substr(0, line.find(","));
        if (firstWord != id)
        {
            lines.push_back(line);
        }
        else if (firstWord == id)
        {
            cout << "\n\t" << line << endl;
        }
    }

    fin.close();
    remove("./data_files/Students.csv");

    for (const auto &l : lines)
    {
        fout << l << endl;
    }

    rename("./data_files/temp1.csv", "./data_files/Students.csv");
    fout.close();

    getchar();
}

void student::updateStd(string id)
{
    ifstream fin;
    ofstream fout;
    fin.open("./data_files/Students.csv", ios::in);
    fout.open("./data_files/temp2.csv", ios::out);
    if (fin.fail() || fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(2000000);
    }

    // cout << "\n\t\tTeacher Id :- ";
    // string id;
    // cin >> id;

    string line, firstWord;
    vector<string> lines;
    while (getline(fin, line))
    {
        firstWord = line.substr(0, line.find(","));
        if (firstWord != id)
        {
            cout << "\n\t" << line << endl;
            lines.push_back(line);
        }
        else if (firstWord == id)
        {
            string fName, lName, Mobile_No, Address, courseId, userId, Password;
            int Age;
            char Gender;

            cout << "\n\n\t\t\t\tSTUDENT DETAILS";
            cout << "\n\n\n\t\tEnter First Name :- ";
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
            cin >> Address;

            course cs;
            cs.showCourseList();

            cout << "\n\t\tEnter Course ID :- ";
            cin >> courseId;

            cout << "\n\t\tEnter User ID :- ";
            cin >> userId;

            cout << "\n\t\tEnter Password :- ";
            cin >> Password;

            string a = to_string(Age);
            string s(1, Gender);

            string str1 = id + "," + fName + "," + lName + "," + a + "," + s + "," + Mobile_No + "," + Address + "," + courseId + "," + userId + "," + Password + "\n";

            lines.push_back(str1);

            cout << "\n\t" << line << endl;
        }
    }

    fin.close();
    remove("./data_files/Students.csv");

    for (const auto &l : lines)
    {
        fout << l << endl;
    }

    rename("./data_files/temp2.csv", "./data_files/Students.csv");
    fout.close();

    getchar();
}
