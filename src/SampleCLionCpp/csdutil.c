#include <ctype.h>
#include "csd/util.h"

int csd_random_int(int a, int b)
{
	return rand() % (b - a + 1) + a;
}


void csd_fill_random_int_array(int *p, size_t size, int min, int max)
{
    for (size_t i = 0; i < size; ++i)
        p[i] = rand() % (max - min) + min;
}

char *csd_strupper(char *s)
{
    char *temp = s;

    while (*temp != '\0') {
        *temp = (char)toupper(*temp);
        ++temp;
    }

    return s;
}
