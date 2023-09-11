#ifndef TEACHER
#define TEACHER

#include <string>

using namespace std;

class teacher
{
private:
    int Tid = 1;
    string fName, lName, Mobile_No, Address, SubjectID;
    int Age;
    char Gender;
    int minAge = 18, maxAge = 65;

public:
    int lastlineReadCSV();
    void input();
    void showTeacher();
    void removeTeacher();
    // void updateTeacher();
};

#endif