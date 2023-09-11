#ifndef REPORDCARD
#define REPORDCARD

#include <vector>
#include <string>

using namespace std;

class reportCard
{
private:
    char grade;
    int totalNum;
    string percentage;

public:
    void input();
    void showCard();
};

#endif