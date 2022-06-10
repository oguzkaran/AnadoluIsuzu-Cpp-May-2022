#include "csd/datetimeutil.h"

static int g_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool csd_is_valid_date(int d, int m, int y)
{
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900)
        return false;

    return d <= csd_is_leap_year(y) && m == 2 ? 29 : g_days[m];;
}

bool csd_is_leap_year(int y)
{
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

