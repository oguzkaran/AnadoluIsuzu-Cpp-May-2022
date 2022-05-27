#include <stdio.h>
#include <stdlib.h>
#include "csdutil.h"

void csd_exit_fail(const char* msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}

void csd_exit_with_code(const char* msg, int code)
{
	fprintf(stderr, "%s\n", msg);
	exit(code);
}
