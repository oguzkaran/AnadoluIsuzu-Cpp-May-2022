#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "csdutil.h"

void clearstdin(void)
{
    int ch;

    while ((ch = getchar()) != '\n')
        ;
}

int islittleendian(void)
{
    short a = 0x0001;

    return *(char*)&a == 0x01;
}


void displayi(const int p[], int size)
{
    int i;

    for (i = 0; i < size; ++i)
        printf("%d ", p[i]);

    putchar('\n');
}

int getmaxi(const int p[], int size)
{
    int max = p[0];
    int i;

    for (i = 1; i < size; ++i)
        if (max < p[i])
            max = p[i];

    return max;
}

const int* getmaxiaddr(const int p[], int size)
{
    const int *pm = &p[0];
    int i;

    for (i = 1; i < size; ++i)
        if (p[i] > *pm)
            pm = &p[i];

    return pm;    
}


double getavgi(const int p[], int size)
{
    return getsumi(p, size) / (double)size;
}

int getsumi(const int p[], int size)
{
    int sum = 0;
    int i;

    for (i = 0; i < size; ++i)
        sum += p[i];

    return sum;
}

int *randomi(int p[], int size, int min, int max)
{
    int i;

    for (i = 0; i < size; ++i)
        p[i] = rand() / (RAND_MAX / (max - min)) + min;

    return p;
}

void swapi(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void bsorti(int p[], int size)
{
    int i, k;

    for (i = 0; i < size - 1; ++i)
        for (k = 0; k < size - 1 - i; ++k)
            if (p[k] > p[k + 1])
                swapi(p + k, p + k + 1); /* swapi(&p[k], &p[k + 1]); */
}


int* reversearrayi(int p[], int size)
{
    int i;
    int half = size / 2;

    for (i = 0; i < half; ++i)
        swapi(&p[i], &p[size - 1 - i]);

    return p;
}

void putsrev(const char *s)
{
    int i;
    
    for (i = strlen(s) - 1; i >= 0; --i)
        putchar(s[i]);

    putchar('\n');
}

int getcharcount(const char *s, char ch)
{
    int count = 0;

    while (*s != '\0') {
        if (*s == ch)
            ++count;
        ++s;
    }

    return count;
}

char *csdstrupr(char* s)
{
    char* temp = s;

    while (*s != '\0') {
        *s = toupper(*s);
        ++s;
    }

    return s;

}

char* csdstrlwr(char* s)
{
    char* temp = s;

    while (*s != '\0') {
        *s = tolower(*s);
        ++s;
    }

    return s;
}

void printstrings(const char* const pc[])
{
    int i;

    for (i = 0; pc[i] != NULL; ++i)
        printf("%s\n", pc[i]);
}


char *concatstrings(const char* const pc[], char s[], char delim[])
{
    int i;

    s[0] = '\0';
    for (i = 0; pc[i] != NULL; ++i) {
        if (i != 0)
            strcat(s, delim);
        strcat(s, pc[i]);
    }
    
    return s;
}

char* randomtext(char s[], size_t size)
{
    size_t i;
    s[0] = '\0';

    for (i = 0; i < size; ++i)
        s[i] = rand() % 26 + (rand() % 2 == 0 ? 'A' : 'a');

    s[i] = '\0';

    return s;        
}


char* csdgets(char* buf, size_t n)
{
    if (fgets(buf, (int)n, stdin) == NULL)
        return NULL;


    buf[strlen(buf) - 1] = '\0';

    return buf;
}

char* csdgetscs(char* buf, size_t n)
{
    size_t len;

    if (fgets(buf, (int)n, stdin) == NULL)
        return NULL;

    len = strlen(buf);

    if (buf[len  - 1] != '\n')
        clearstdin();

    buf[len - 1] = '\0';

    return buf;
}