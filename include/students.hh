#ifndef STUDENT
#define STUDENT

#include <string>

using namespace std;

class student
{
private:
    int Sid = 1;
    string fName, lName, Mobile_No, Address, courseId, userId, Password;
    int Age, roll_No;
    char Gender;

public:
    int lastlineReadCSV();
    void input();
    void showStudent();
    void studentLogin();
    void showStudentSide(string id);
    void updateStd(string id);
    void removeStd();
};

#endif