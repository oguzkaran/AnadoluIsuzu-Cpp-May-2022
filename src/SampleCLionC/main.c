#include <stdio.h>

typedef int I;
typedef int IA[5];

int main(void)
{
    I x = 20;
    IA a = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
        printf("%d ", a[i]);

    printf("\nx = %d\n", x);


    return 0;
}
