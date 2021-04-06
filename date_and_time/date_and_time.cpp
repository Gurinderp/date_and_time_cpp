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
*/

//
// A processing module that computes the JDN for the given date.
//
void compute_jdn(int year, int month, int day, int& jdn)
{
    int a, b, c, d;
    a = (14 - month) / 12;
    b = (month - 3) + (12 * a);
    c = 4800 + year - a;
    d = (c / 4) - (c / 100) + (c / 400);
    jdn = day + (((153 * b) + 2) / 5) + (365 * c) + d - 32045;
}

//
// A processing module that computes the weekday number for the given date
//
void compute_dow(int year, int month, int day, int& dow)
{
    int jdn;
    compute_jdn(year, month, day, jdn);
    dow = (jdn + 1) % 7;
}

//
// A processing module that determines the month name corresponding to the 
// given month number.
//
void get_month_name(int month, std::string& month_name)
{
    if (month == 1) {
        month_name = "January";
    }
    else if (month == 2) {
        month_name = "February";
    }
    else if (month == 3) {
        month_name = "March";
    }
    else if (month == 4) {
        month_name = "April";
    }
    else if (month == 5) {
        month_name = "May";
    }
    else if (month == 6) {
        month_name = "June";
    }
    else if (month == 7) {
        month_name = "July";
    }
    else if (month == 8) {
        month_name = "August";
    }
    else if (month == 9) {
        month_name = "September";
    }
    else if (month == 10) {
        month_name = "October";
    }
    else if (month == 11) {
        month_name = "November";
    }
    else {
        month_name = "December";
    }
}

//
// A processing module that determines the weekday name corresponding 
// to the given weekday number.
//
void get_weekday_name(int dow, std::string& weekday_name)
{
    if (dow == 0) {
        weekday_name = "Sunday";
    }
    else if (dow == 1) {
        weekday_name = "Monday";
    }
    else if (dow == 2) {
        weekday_name = "Tuesday";
    }
    else if (dow == 3) {
        weekday_name = "Wednesday";
    }
    else if (dow == 4) {
        weekday_name = "Thursday";
    }
    else if (dow == 5) {
        weekday_name = "Friday";
    }
    else {
        weekday_name = "Saturday";
    }

}


void display_date(int year, int month, int day)
{
    // An output module that displays a date on the screen given the 
    // component year, month, and day numbers — e.g., Thursday, March 18, 2021.
    std::cout << month << '/' << day << '/' << year;
}

// An output / controller module that displays a time on the screen in 12 - 
// hour format given the component hour and minute numbers in 24 - hour format.
// This is accomplished by calling upon the services of the display_hour, 
// display_minuteand display_ampm modules described below.Five minutes after 
// midnight(hour = 0, minute = 5) shows 12:05 a.m.Two - thirty in the afternoon
// (hour = 14, minute = 30) shows 2 : 30 p.m. (As with the previous module, this
// module and those it calls would be better implemented as processing modules 
// that produce strings.)
void display_time(int hour, int minute)
{

    display_hour(hour);
    display_minute(minute);
    display_ampm(hour);

    std::cout << hour << ':' << minute;
}

//
// An output module that displays the hour on the screen in 12 - hour 
// format given an hour in 24 - hour format.
//
void display_hour(int hour)
{
    if (hour == 0) {
        hour = 12;
    }
    else if (hour > 12) {
        hour = hour - 12;
    }
}


void display_minute(int minute)
{
    // An output module that displays the given minute on the screen. Minutes are 
    // displayed with a leading zero when less than ten.
}


void display_ampm(int hour)
{
    // An output module that displays “a.m.” or “p.m.” on the screen given an hour 
    // in 24 - hour format.
    if (hour <= 11) {
        // a.m.
    }
    else {
        // p.m.
    }
}