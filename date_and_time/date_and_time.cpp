// Program    : Date and Time
// Author     : Type your name...
// Course     : CISP 301/Krofchok (Spring 2021)
// Section    : 16876 18037
// Description: Displays the current date and time.

#define _CRT_SECURE_NO_WARNINGS  // Disables Visual Studio warning about using
                                 //   the localtime() module
#include <ctime>
#include <iostream>
#include <string>

void get_datetime(int& year, int& month, int& day, int& hour, int& minute);
void compute_jdn(int year, int month, int day, int& jdn);
void compute_dow(int year, int month, int day, int& dow);
void get_month_name(int month, std::string& month_name);
void get_weekday_name(int dow, std::string& weekday_name);
void display_date(int year, int month, int day);
void display_time(int hour, int minute);
void display_hour(int hour);
void display_minute(int minute);
void display_ampm(int hour);

int main()
{
    int year,    // current year
        month,   // current month number (1..12)
        day,     // current day (1..31)
        hour,    // current hour (0..23)
        minute;  // current minute (0..59)

    get_datetime(year, month, day, hour, minute);

    // Display current date
    std::cout << "Today is ";
    display_date(year, month, day);
    std::cout << std::endl;

    // Display current time
    std::cout << "The current time is ";
    display_time(hour, minute);
    std::cout << std::endl;
}

//
// An input module that obtains the current date and time components from
// the system clock. The year is a four-digit integer accurate for years
// since 1900, the month an integer from 1 to 12, the day an integer from
// 1 to 31, the hour an integer from 0 to 23, and the minute an integer
// from 0 to 59.
//
void get_datetime(int& year, int& month, int& day, int& hour, int& minute)
{
    time_t now;
    struct tm* tm_ptr;

    time(&now);
    tm_ptr = localtime(&now);

    year = 1900 + tm_ptr->tm_year;
    month = 1 + tm_ptr->tm_mon;
    day = tm_ptr->tm_mday;
    hour = tm_ptr->tm_hour;
    minute = tm_ptr->tm_min;
}

// ***************************************************************************
// ** DO NOT CHANGE ANY LINES ABOVE THIS POINT, EXCEPT TO ADD YOUR NAME AND **
// ** SECTION NUMBER ON LINES 2 AND 4. ALL CHANGES ABOVE THIS POINT WILL BE **
// ** DISCARDED WHEN YOUR PROGRAM IS GRADED.                                **
// ***************************************************************************

//
// Describe this module...
//
void display_date(int year, int month, int day)
{
    std::cout << month << '/' << day << '/' << year;
}

//
// Describe this module...
//
void display_time(int hour, int minute)
{
    std::cout << hour << ':' << minute;
}
