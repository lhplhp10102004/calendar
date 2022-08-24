// Day,Time functions
#pragma once
#include "library.cpp"


vector <string> stringMonth = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
short days[6][7];
short nonLeapYear[13];
short    LeapYear[13];
int days_of_month[12] = {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};    //number of days in a month

struct __today
{
    short  day;
    short  month;
    short  year;
    string date;
    string month_s;
} today;

void getToday(){
    today.date = __DATE__;
    stringstream Date;
    Date << today.date;
    Date >> today.month_s >> today.day >> today.year;
    today.month = static_cast <short> (find(stringMonth.begin(), stringMonth.end(),today.month_s) - stringMonth.begin());
}

void initDaysOfMonth(){
    LeapYear[0] = 0; LeapYear[1] = 31;
    nonLeapYear[0] = 0;

    for (int i = 1; i <= 12; ++i) nonLeapYear[i] = nonLeapYear[i-1] + days_of_month[i-1];
    for (int i = 2; i <= 12; ++i) LeapYear[i] = nonLeapYear[i] + 1;
    // For example: Numbers of day between 01/01/2022 and 01/07/2022 equal to nonLeapYear[7-1]
}

void initDays(short month, short year){
    /*
        Monday      -> 0
        Tuesday     -> 1
        Wednesday   -> 2
        Thursday    -> 3
        Friday      -> 4
        Saturday    -> 5
        Sunday      -> 6

        01/01/2001  -> Monday -> 0

        01/01/2001  => 0
        01/01/2002  => 365          == 365 * (2002 - 2001) + (2002 - 2001) div 4
        01/01/2003  => 365 * 2      == 365 * (2003 - 2001) + (2003 - 2001) div 4
        01/01/2004  => 365 * 3      == 365 * (2004 - 2001) + (2004 - 2001) div 4
        01/01/2005  => 365 * 4 + 1  == 365 * (2005 - 2001) + (2005 - 2001) div 4
        01/01/2022  => 365 * 21 + 5 == 7670 mod 7 == 5  --> Saturday
        01/02/2022  => 7670 + nonLeapYear[2 - 1] == 7701 mod 7 == 1 --> Tuesday
        01/08/2022  => 7670 + nonLeapYear[8 - 1] == 7882 mod 7 == 0 --> Monday
        24/08/2022  => 7882 + (24 - 1) == 7905 == 2 --> Wednesday
    */
   
    int step1 = 365 * (year - 2001) + (year - 2001)/4;
    int step2 = step1 + ((year % 4 == 0)? LeapYear[month - 1] : nonLeapYear[month - 1]);
    short stepFinal = step2 % 7;

    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 7; ++j)
        {
            days[i][j] = 7 * i + j + 1 - stepFinal;
        }
}

bool validDay (short day, short month, short year){
    if (day <= 0) return false;
    if (month == 2){
        if (year % 4) return (day <= 28);
        return (day <= 29);
    }
    return day <= days_of_month[month - 1];
}