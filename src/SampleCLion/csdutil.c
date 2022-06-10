#include "csd/util.h"

int csd_random_int(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

