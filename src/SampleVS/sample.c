#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "csderrorutil.h"

void foo()
{
	csd_exit_fail("test");
}

#if 0

int main()
{
	int n;

	srand((unsigned int)time(NULL));
	printf("Input a number:");
	scanf("%d", &n);

	int *p;

	p = (int *)malloc(n * sizeof(int));

	if (!p) {
		fprintf(stderr, "Can not allocate memory\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; ++i)
		p[i] = rand() % 100;
	
	for (int i = 0; i < n; ++i)
		printf("%d ", p[i]);

	putchar('\n');

	free(p);	

	return 0;
}
#endif
