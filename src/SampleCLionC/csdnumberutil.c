#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "csdnumberutil.h"

static const char *gs_ones[] = {"bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz", "dokuz"};
static const char *gs_tens[] = { "on", "yirmi", "otuz", "kirk", "elli", "altmis", "yetmis", "seksen", "doksan" };
static const char *gs_others[] = {"bin", "milyon", "milyar", "trilyon", "katrilyon", "katrilyar"};

char *numtotexttr(unsigned long val, char s[])
{
    int a, b, c;    
    int digits3[5];
    unsigned int temp;
    int i;
    *s = '\0';
    if (!val) {
        strcat(s, "sifir");
        return s;
    }

    temp = val;
    for (i = 0; val; ++i) {
        digits3[i] = val % 1000;
        val /= 1000;
    }

    val = temp;

    while (--i >= 0) {
        a = digits3[i] / 100;
        b = digits3[i] % 100 / 10;
        c = digits3[i] % 10;

        if (a) {
            if (a != 1) {
                strcat(s, gs_ones[a - 1]);
                strcat(s, " ");
            }
            strcat(s, "yuz");
        }

        if (b) {
            if (a)
                strcat(s, " ");
            strcat(s, gs_tens[b - 1]);
        }

        if (c) {
            if (b || a)
                strcat(s, " ");
            if (i != 1 || digits3[i] != 1)
                strcat(s, gs_ones[c - 1]);
        }

        if (i != 0)            
            if (a != 0 || b != 0 || c != 0) {                    
                strcat(s, " ");
                strcat(s, gs_others[i - 1]);
                strcat(s, " ");
            }
    }     

    return s;
}

int countdigits(int val)
{
    return val == 0 ? 1 : (int)log10(abs(val)) + 1;
}

BOOL isprime(int val)
{
    int i, result;
    int n;

    if (val <= 1)
        return FALSE;

    if (val % 2 == 0)
        return val == 2;

    if (val % 3 == 0)
        return val == 3;

    if (val % 5 == 0)
        return val == 5;

    if (val % 7 == 0)
        return val == 7;

    n = (int)sqrt(val);

    result = TRUE;
    for (i = 11; i <= n; i += 2)
        if (val % i == 0) {
            result = FALSE;
            break;
        }

    return result;
}

int max3(int a, int b, int c)
{
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}

int min3(int a, int b, int c)
{
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

