#include <iostream>
#include <ctime>

using namespace std;

#include "./../include/Time.hh"

string Time::get_date() // function to converts date to string
{
    time_t now;
    char the_date[15];

    the_date[0] = '\0';

    now = time(NULL);

    if (now != -1)
    {
        strftime(the_date, 15, "%d.%m.%y", gmtime(&now));
    }

    return string(the_date);
}

/*------------------------------------------------------------------------------------*/

string Time::get_time()
{
    time_t rawtime;

    struct tm *timeinfo;

    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M %p", timeinfo);
    puts(buffer);

    return string(buffer);
}
