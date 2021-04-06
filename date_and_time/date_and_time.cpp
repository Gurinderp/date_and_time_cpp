// Program    : Date and Time
// Author     : Gurinderpreet Singh
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

/*
    compute_jdn(year, month, day, jdn);
    compute_dow(year, month, day, dow );
    get_month_name(month, month_name);
    get_weekday_name(dow, weekday_name);
    display_date(year, month, day);
    display_time(hour, minute);
    display_hour(hour);
    display_minute(minute);
    display_ampm(hour);
*/

// Describe this module...
//
void compute_jdn(int year, int month, int day, int& jdn)
{
    // A processing module that computes the JDN for the given date, as in Lab #3.
    int a, b, c, d;
    a = (14 - month) / 12;
    b = (month - 3) + (12 * a);
    c = 4800 + year - a;
    d = (c / 4) - (c / 100) + (c / 400);
    jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

//
// Describe this module...
//
void compute_dow(int year, int month, int day, int& dow)
{
    // A processing module that computes the weekday number for the given date, as in Lab #4.
    int jdn;
    compute_jdn(year, month, day, jdn);
    dow = (jdn + 1) % 7;
}

//
// Describe this module...
//
void get_month_name(int month, std::string& month_name)
{
    // A processing module that determines the month name corresponding to the given month number.
}

//
// Describe this module...
//
void get_weekday_name(int dow, std::string& weekday_name)
{
    // A processing module that determines the weekday name corresponding 
    // to the given weekday number(where zero is "Sunday", 1 is "Monday", etc.).
}

//
// Describe this module...
//
void display_date(int year, int month, int day)
{
    // An input module that obtains the current date and time components from the system clock. 
    // The year is a four-digit integer accurate for years since 1900, the month an integer from 1 to 12, 
    // the day an integer from 1 to 31, the hour an integer from 0 to 23, and the minute an integer from 0 
    // to 59. (Note: A full implementation of this module is provided in the datetime.cpp starter file; you are 
    // not responsible for understanding the details of how this module works, as it depends on concepts 
    // introduced in CISP 360.)
    std::cout << month << '/' << day << '/' << year;
}

//
// Describe this module...
//
void display_time(int hour, int minute)
{
    // An output module that displays a date on the screen given the component year, month, and day numbers — 
    // e.g., Thursday, March 18, 2021. (Note: Due to the logic involved, this module would normally be 
    // implemented as a processing module that produces a string.Concatenation of strings and numbers in C++ 
    // requires knowledge of “string streams”, which are out of scope for CISP 301. Including the necessary 
    // logic in this output module to send results to the screen is a reasonable compromise, as the code could 
    // then easily be transformed into a processing module that uses a string stream instead of the std::cout stream.)
    std::cout << hour << ':' << minute;
}

//
// Describe this module...
//
void display_hour(int hour)
{
    // An output module that displays the hour on the screen in 12 - hour format given an hour in 24 - hour format.
}

//
// Describe this module...
//
void display_minute(int minute)
{
    // An output module that displays the given minute on the screen.Minutes are displayed with a leading zero when less than ten.
}

//
// Describe this module...
//
void display_ampm(int hour)
{
    // An output module that displays “a.m.” or “p.m.” on the screen given an hour in 24 - hour format.
}