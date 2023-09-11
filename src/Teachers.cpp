#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std;

// include file
#include "./../include/Title.hh"
#include "./../include/Admin.hh"
#include "./../include/Teachers.hh"
#include "./../include/course.hh"

int teacher::lastlineReadCSV()
{
    // Open the CSV file for reading
    ifstream infile("./data_files/Teachers.csv");

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

    // int num = std::stoi(firstWord);
    int num = std::atoi(firstWord.c_str());

    // cout << num << endl;
    infile.close();
    return num;
}

void teacher::input()
{
    // ofstream fout;
    // ifstream ftc;
    fstream fout;
    fout.open("./data_files/Teachers.csv", ios::in | ios::app);
    if (fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\n\t\t\t\tTEACHER DETAILS";
    cout << "\n\n\n\t\tEnter First Name :- ";
    cin >> fName;
    cout << "\n\t\tEnter Last Name :- ";
    cin >> lName;
    cout << "\n\t\tEnter Age :- ";
    cin >> Age;
    if (Age <= minAge || Age >= maxAge)
    {
        return void(cout << "\n\tSorry, Your age is Less than 18 and grather than 65. \n");
        usleep(2000000);
    }

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

    subjects sb;
    list<string> subList;
    sb.setSubList(subList);
    sb.subListShow(subList);

    cout << "\n\t\tEnter Subject ID :- ";
    cin >> SubjectID;

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

        if ("TeacherId" != ls)
        {
            fout.seekp(0);
            fout << "TeacherId, First Name, Last Name, Age, Gender, Mobile No, Address, Subject Id\n";
        }
        else
        {
            int num = lastlineReadCSV();
            // cout << "num : " << num << endl;
            if (Tid == num)
            {
                num++;
                Tid = num;
                // cout << "Tid1 :" << Tid << endl;
            }
            else
            {
                Tid = 1;
                // cout << "Tid2 :" << Tid << endl;
            }
            fout << Tid << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << SubjectID << "\n";
        }
    }
    else
    {
        ofstream file("./data_files/Teachers.csv");
        if (file.fail())
        {
            cout << "\n\n\t\tFile Opened Fail!..." << endl;
            usleep(1000000);
            admin ad;
            ad.AdminAdd();
        }
        file << "TeacherId, First Name, Last Name, Age, Gender, Mobile No, Address, Subject Id\n";
        file << Tid << "," << fName << "," << lName << "," << Age << "," << Gender << "," << Mobile_No << "," << Address << "," << SubjectID << "\n";

        file.close();
    }

    fout.close();
}

void teacher::showTeacher()
{
    ifstream fin;
    fin.open("./data_files/Teachers.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(2000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\t\tTeacher Id :- ";
    string id;
    cin >> id;

    int count = 0;

    vector<string> row;

    string line, word, fw, temp, roll2;

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
            cout << "\n\n\t\t\t\tTEACHER DETAILS\n\n";
            cout << "\t\tName :- " << row[1] << " " << row[2];
            cout << "\n\t\tAge :- " << row[3];
            cout << "\n\t\tGender :- " << row[4];
            cout << "\n\t\tMobile No :- " << row[5];
            cout << "\n\t\tAddress :- " << row[6];
            cout << "\n\t\tSubject Id :- " << row[7];
            cout << "\n";
            break;
        }
    }
    if (count == 0)
    {
        cout << "\n\t\t\tRecord not found\n";
    }

    getchar();
}

void teacher::removeTeacher()
{
    ifstream fin;
    ofstream fout;
    fin.open("./data_files/Teachers.csv", ios::in);
    fout.open("./data_files/temp.csv", ios::out);
    if (fin.fail() || fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(2000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\t\tTeacher Id :- ";
    string id;
    cin >> id;

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
            cout << "\n\t" << line << endl;
        }
    }

    fin.close();
    remove("./data_files/Teachers.csv");

    for (const auto &l : lines)
    {
        fout << l << endl;
    }

    rename("./data_files/temp.csv", "./data_files/Teachers.csv");
    fout.close();

    getchar();
}