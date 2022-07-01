#ifndef DATETIME_H_
#define DATETIME_H_

#include "general.h"

BOOL isleapyear(int year);
BOOL isvaliddate(int day, int month, int year);
int getdayofyear(int day, int month, int year);
int getdayofweek(int day, int month, int year);
BOOL isweekend(int day, int month, int year);
BOOL isweekday(int day, int month, int year);
BOOL todatestrTR(char s[], int day, int month, int year);
BOOL todatestrEN(char s[], int day, int month, int year);

#endif /*DATETIME_H_*/
