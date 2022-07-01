#include <stdio.h>
#include "general.h"
#include "datetime.h"

static const int gs_daysofmonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static const char* gs_monthsTR[] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", 
                    "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};

static const char* gs_monthsEN[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

static const char* gs_daysofweekTR[] = { "Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi" };

static const char* gs_daysofweekEN[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };


static char* getdaysuffix(int day)
{
    char *suffix = "th";

    switch (day) {
    case 1:
    case 21:
    case 31:
        suffix = "st";
        break;
    case 2:
    case 22:
        suffix = "nd";
        break;
    case 3:
    case 23:
        suffix = "rd";
        break;
    }

    return suffix;
}

static int getmonthdays(int month, int year)
{
    return month == 2 && isleapyear(year) ? 29 : gs_daysofmonths[month - 1];
}

BOOL isleapyear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

BOOL isvaliddate(int day, int month, int year)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900)
        return FALSE;

    return day <= getmonthdays(month, year);
}

int getdayofyear(int day, int month, int year)
{
    int dayofyear = day;
    int m;

    for (m = month - 1; m >= 1; --m)
        dayofyear += gs_daysofmonths[m - 1];

    return dayofyear + (month > 2 && isleapyear(year) ? 1 : 0);
}

int getdayofweek(int day, int month, int year)
{
    int y;
    int totaldays = getdayofyear(day, month, year);

    for (y = 1900; y < year; ++y)
        totaldays += isleapyear(y) ? 366 : 365;

    return totaldays % 7;
}

BOOL isweekend(int day, int month, int year)
{
    int dayOfWeek = getdayofweek(day, month, year);

    return dayOfWeek == 0 || dayOfWeek == 6;
}

BOOL isweekday(int day, int month, int year)
{
    return !isweekend(day, month, year);
}

BOOL todatestrTR(char s[], int day, int month, int year)
{
    if (!isvaliddate(day, month, year))
        return FALSE;

    sprintf(s, "%d %s %d %s", day, gs_monthsTR[month - 1], year, gs_daysofweekTR[getdayofweek(day, month, year)]);

    return TRUE;
}

BOOL todatestrEN(char s[], int day, int month, int year)
{
    if (!isvaliddate(day, month, year))
        return FALSE;

    sprintf(s, "%d%s %s %d %s", day, getdaysuffix(day), gs_monthsEN[month - 1], year, gs_daysofweekEN[getdayofweek(day, month, year)]);

    return TRUE;
}


