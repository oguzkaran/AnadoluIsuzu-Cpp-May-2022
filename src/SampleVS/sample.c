#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "csderrorutil.h"

#define MAX_NAME_LEN 256

enum tagMARITALSTATUS {MARRIED, SINGLE, DIVORCED};

typedef struct tagPERSON {
	int no;
	char name[MAX_NAME_LEN + 1];
	enum MARITALSTATUS marital_status;
} PERSON;

#if 1

int main()
{
	PERSON p1 = { 1, "Oguz Karan", MARRIED };
	PERSON p2 = { 2, "Yavuz Karan", DIVORCED };
	PERSON p3 = { 3, "Kaan Aslan", SINGLE };




	return 0;
}
#endif
