#include <iostream>

using namespace std;

// include file
#include "./include/Title.hh"
#include "./include/rlpage.hh"
#include "./include/Admin.hh"

// src file
#include "./src/Title.cpp"
#include "./src/Time.cpp"
#include "./src/rlpage.cpp"
#include "./src/Admin.cpp"
#include "./src/Teachers.cpp"
#include "./src/course.cpp"
#include "./src/students.cpp"
#include "./src/reportCard.cpp"

int main()
{

    system("clear");
    title();

    rlpage();

    getchar();

    return 0;
}
