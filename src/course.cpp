#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

// include file
#include "./../include/course.hh"
#include "./../include/Admin.hh"

int course::lastlineReadCSV()
{
    string line, lastLine;
    ifstream infile;
    string filename = "./data_files/Students.csv";
    infile.open(filename);

    if (infile.is_open())
    {
        char ch;
        infile.seekg(-1, ios::end); // move to location 65
        infile.get(ch);             // get next char at loc 66
        if (ch == '\n')
        {
            infile.seekg(-2, ios::cur); // move to loc 64 for get() to read loc 65
            infile.seekg(-1, ios::cur); // move to loc 63 to avoid reading loc 65
            infile.get(ch);             // get the char at loc 64 ('5')
            while (ch != '\n')          // read each char backward till the next '\n'
            {
                infile.seekg(-2, ios::cur);
                infile.get(ch);
            }

            getline(infile, lastLine);
            // cout << "The last line : " << lastLine << '\n';
        }
    }

    lastLine.resize(2);
    int num = std::atoi(lastLine.c_str());
    // cout << num << endl;
    // string newdata;
    // num++;
    // newdata = to_string(num);
    // cout << newdata << endl;

    return num;
}

void course::setCourseList()
{
    ofstream fout;
    ifstream fcr;
    fout.open("./data_files/CourseList.csv", ios::app);
    if (fout.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        admin ad;
        ad.AdminAdd();
    }

    cout << "\n\n\t\t\t\tCOURSE DETAILS";
    cout << "\n\n\t\tEnter Course Id :- ";
    cin >> Cid;
    cout << "\n\t\tEnter Course Name :- ";
    cin >> Cname;

    string line, fs, tc = "CourseId";
    fcr.open("./data_files/CourseList.csv", ios::in);
    while (getline(fcr, line))
    {
        fs = line.substr(0, line.find(","));
        if (fs == tc)
        {
            fcr.close();
        }
        else
        {
            fout << "CourseId, Course Name\n";
        }
    }

    fout << Cid << "," << Cname << "\n";

    fout.close();
    fcr.close();
}

void course::showCourseList()
{
    ifstream fin;
    fin.open("./data_files/CourseList.csv", ios::in);
    if (fin.fail())
    {
        cout << "\n\n\t\tFile Opened Fail!..." << endl;
        usleep(1000000);
        admin ad;
        ad.AdminAdd();
    }

    string line;
    cout << '\n';
    cout << "\n\t\t\t\tAll Course List With ID:\n\n";
    while (getline(fin, line))
    {
        cout << "\t\t" << line << endl;
    }

    cout << "\n\n";
}

void subjects::setSubList(list<string> &subList)
{
    subList.push_back("HINDI[H801]");
    subList.push_back("ENGLISH[E210]");
    subList.push_back("MATHS[M231]");
    subList.push_back("\n");
    subList.push_back("SCIENCE[S120]");
    subList.push_back("SANSKRIT[SK122]");
    subList.push_back("ARTS[A162]");
    subList.push_back("\n");
    subList.push_back("COMMERCE[C362]");
    subList.push_back("SCOIAL SCIENCE[SS132]");
}

void subjects::subListShow(list<string> g)
{
    list<string>::iterator it;
    cout << '\n';
    cout << "\n\t\tAll Subject List With ID:\n";
    for (it = g.begin(); it != g.end(); ++it)
    {
        cout << '\t' << *it;
    }
    cout << '\n';
}