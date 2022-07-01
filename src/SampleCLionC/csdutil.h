#ifndef CSDUTIL_H_
#define CSDUTIL_H_

/*includes*/
#include <stdlib.h>
#include <time.h>

/*Symbolic constants*/
#define TRUE	1
#define FALSE	0

/*Macros*/
#define crandomize() srand((unsigned int)time(NULL))

/* Function prototypes */
void displayi(const int p[], int size);
int getmaxi(const int p[], int size);
const int* getmaxiaddr(const int p[], int size);
double getavgi(const int p[], int size);
int getsumi(const int p[], int size);
int* randomi(int p[], int size, int min, int max);
void swapi(int *a, int *b);
void bsorti(int p[], int size);
int* reversearrayi(int p[], int size);
void putsrev(const char* s);
int getcharcount(const char* s, char ch);
void clearstdin(void);
char* csdstrupr(char* s);
char* csdstrlwr(char* s);
void printstrings(const char* const pc[]);
char* concatstrings(const char* const pc[], char s[], char delim[]);
char* randomtext(char s[], size_t size);

char* csdgets(char* buf, size_t n);
char* csdgetscs(char* buf, size_t n);
void clearstdin(void);
int islittleendian(void);

#endif /*CSDUTIL_H_*/
