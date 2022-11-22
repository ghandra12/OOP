#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

string timeToString(long long ms)
{
    stringstream ss, ss2, ss3, ss4, ss5, ss6;
    string date = "";
    string clock = "";
    time_t seconds = ms / 1000;
    seconds += 3 * 60 * 60;
    struct tm* tm_date;

    tm_date = gmtime(&seconds);

    ss << tm_date->tm_year + 1900;
    date += ss.str();

    date += "-";

    if (tm_date->tm_mon + 1 < 10)
        date += "0";

    ss2 << tm_date->tm_mon + 1;
    date += ss2.str();

    date += "-";

    if (tm_date->tm_mday < 10)
        date += "0";

    ss3 << tm_date->tm_mday;
    date += ss3.str();

    if (tm_date->tm_hour < 10)
        clock += "0";

    ss4 << tm_date->tm_hour;
    clock += ss4.str();

    clock += "-";

    if (tm_date->tm_min < 10)
        clock += "0";

    ss5 << tm_date->tm_min;
    clock += ss5.str();

    clock += "-";

    if (tm_date->tm_sec < 10)
        clock += "0";

    ss6 << tm_date->tm_sec;
    clock += ss6.str();

    return date+" "+clock;
}

string  timeToString()
{
    long long ms;
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    return timeToString(ms);
}

int main()
{
    cout << "1631970174315 ms= " << timeToString(1631970174315) << endl;
    cout << "current time is " << timeToString(0);
}
