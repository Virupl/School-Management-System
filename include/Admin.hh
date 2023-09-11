#ifndef ADMIN
#define ADMIN

#include <string>

using namespace std;

class admin
{
private:
    string fName, lName, Mobile_No, address, ID, Password;
    char Gender;
    int Age;

public:
    void input();
    void AdminLogin();
    void AdminAdd();
    void showAdminData();
};

#endif