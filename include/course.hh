#ifndef COURSE
#define COURSE

#include <string>
#include <list>

using namespace std;

class course
{
private:
    string Cid;
    string Cname;

public:
    int lastlineReadCSV();
    void setCourseList();
    void showCourseList();
};

class subjects
{
private:
    list<string> subList;

public:
    void setSubList(list<string> &subList);
    void subListShow(list<string> g);

    const list<string> &getStatements() const
    {
        return subList;
    }
};

#endif