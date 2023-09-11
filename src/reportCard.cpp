#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <sstream>

using namespace std;

// inline file
#include "./../include/reportCard.hh"
#include "./../include/Admin.hh"
#include "./../include/Title.hh"

void reportCard::input()
{

    ofstream fout;
    ifstream fin;
    fin.open("./data_files/Students.csv", ios::in);
    fout.open("./data_files/reportCard.csv", ios::app);
    if (fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        admin ad;
        ad.AdminAdd();
    }

    ifstream fst;
    string lline, fs, tc = "StudentId";
    fst.open("./data_files/reportCard.csv", ios::in);
    while (getline(fst, lline))
    {
        fs = lline.substr(0, lline.find(","));
        if (fs == tc)
        {
            fst.close();
        }
        else
        {
            fout << "StudentId,Full Name, Total Number, Percentage, Grade\n";
        }
    }
    fst.close();

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
            count = 1;

            if ("M101" == row[7])
            {
                system("clear");
                headerTitle();
                int maths, hindi, english, physics, chemistry;

                cout << "\n\n\tStudent Name : "
                     << row[1] << " " << row[2];
                cout << "\n\n\t\t\tREPORT CARD DITAILS";
                cout << "\n\n\t\tEnter Maths Mark : ";
                cin >> maths;
                cout << "\n\n\t\tEnter Hindi Mark : ";
                cin >> hindi;
                cout << "\n\n\t\tEnter English Mark : ";
                cin >> english;
                cout << "\n\n\t\tEnter Physics Mark : ";
                cin >> physics;
                cout << "\n\n\t\tEnter Chemistry Mark : ";
                cin >> chemistry;

                totalNum = maths + hindi + english + physics + chemistry;
                double toNum = (maths + hindi + english + physics + chemistry) / 5.0;
                percentage = to_string(toNum);

                if (toNum >= 60)
                {
                    grade = 'A';
                }
                else if (toNum >= 50)
                {
                    grade = 'B';
                }
                else if (toNum >= 33)
                {
                    grade = 'C';
                }
                else
                {
                    grade = 'F';
                }

                fout << id << "," << row[1] << " " << row[2] << "," << totalNum << "," << percentage << "," << grade << endl;
            }
            else if ("S102" == row[7])
            {
                system("clear");
                headerTitle();
                int science, hindi, english, physics, chemistry;

                cout << "\n\n\tStudent Name : "
                     << row[1] << " " << row[2];
                cout << "\n\n\t\t\tREPORT CARD DITAILS";
                cout << "\n\n\t\tEnter Science Mark : ";
                cin >> science;
                cout << "\n\n\t\tEnter Hindi Mark : ";
                cin >> hindi;
                cout << "\n\n\t\tEnter English Mark : ";
                cin >> english;
                cout << "\n\n\t\tEnter Physics Mark : ";
                cin >> physics;
                cout << "\n\n\t\tEnter Chemistry Mark : ";
                cin >> chemistry;

                totalNum = science + hindi + english + physics + chemistry;
                double toNum = (science + hindi + english + physics + chemistry) / 5.0;
                percentage = to_string(toNum);

                if (toNum >= 60)
                {
                    grade = 'A';
                }
                else if (toNum >= 50)
                {
                    grade = 'B';
                }
                else if (toNum >= 33)
                {
                    grade = 'C';
                }
                else
                {
                    grade = 'F';
                }

                fout << id << "," << row[1] << " " << row[2] << "," << totalNum << "," << percentage << "," << grade << endl;
            }
            else if ("C103" == row[7])
            {
                system("clear");
                headerTitle();
                int Accountancy, Business, Economics, Mathematics, English, Pheducation;

                cout << "\n\n\tStudent Name : "
                     << row[1] << " " << row[2];
                cout << "\n\n\t\t\tREPORT CARD DITAILS";
                cout << "\n\n\t\tEnter Accountancy Mark : ";
                cin >> Accountancy;
                cout << "\n\n\t\tEnter Business Mark : ";
                cin >> Business;
                cout << "\n\n\t\tEnter Economics Mark : ";
                cin >> Economics;
                cout << "\n\n\t\tEnter Mathematics Mark : ";
                cin >> Mathematics;
                cout << "\n\n\t\tEnter English Mark : ";
                cin >> English;
                cout << "\n\n\t\tEnter Physical Education Mark : ";
                cin >> Pheducation;

                totalNum = Accountancy + Business + Economics + Mathematics + English + Pheducation;
                double toNum = (Accountancy + Business + Economics + Mathematics + English + Pheducation) / 6.0;
                percentage = to_string(toNum);

                if (toNum >= 60)
                {
                    grade = 'A';
                }
                else if (toNum >= 50)
                {
                    grade = 'B';
                }
                else if (toNum >= 33)
                {
                    grade = 'C';
                }
                else
                {
                    grade = 'F';
                }

                fout << id << "," << row[1] << " " << row[2] << "," << totalNum << "," << percentage << "," << grade << endl;
            }
            else if ("A104" == row[7])
            {
                system("clear");
                headerTitle();
                int English, Economics, History, Geography, Sociology, Psychology;

                cout << "\n\n\tStudent Name : "
                     << row[1] << " " << row[2];
                cout << "\n\n\t\t\tREPORT CARD DITAILS";
                cout << "\n\n\t\tEnter English Mark : ";
                cin >> English;
                cout << "\n\n\t\tEnter Economics Mark : ";
                cin >> Economics;
                cout << "\n\n\t\tEnter History Mark : ";
                cin >> History;
                cout << "\n\n\t\tEnter Geography Mark : ";
                cin >> Geography;
                cout << "\n\n\t\tEnter Sociology Mark : ";
                cin >> Sociology;
                cout << "\n\n\t\tEnter Psychology Mark : ";
                cin >> Psychology;

                totalNum = English + Economics + History + Geography + Sociology + Psychology;
                double toNum = (English + Economics + History + Geography + Sociology + Psychology) / 6.0;
                percentage = to_string(toNum);

                if (toNum >= 60)
                {
                    grade = 'A';
                }
                else if (toNum >= 50)
                {
                    grade = 'B';
                }
                else if (toNum >= 33)
                {
                    grade = 'C';
                }
                else
                {
                    grade = 'F';
                }

                fout << id << "," << row[1] << " " << row[2] << "," << totalNum << "," << percentage << "," << grade << endl;
            }

            break;
        }
    }
    if (count == 0)
    {
        cout << "\n\t\t\tRecord not found\n";
    }

    fin.close();
    fout.close();
}

void reportCard::showCard()
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
}
