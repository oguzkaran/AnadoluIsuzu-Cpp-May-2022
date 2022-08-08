#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void simplify(int *pa, int *pb)
{
    int a = abs(*pa);
    int b = abs(*pb);
    int min = a < b ? a : b;

    for (int i = min; i >= 2; --i) {
        if (a % i == 0 && b % i == 0) {
            *pa /= i;
            *pb /= i;
            break;
        }
    }
}

int main(void)
{
    for (;;) {
        int a, b;
        printf("Input numerator and denominator:");
        fflush(stdin);
        scanf("%d%d", &a, &b);

        simplify(&a, &b);

        printf("%d / %d\n", a, b);

        if (a == 0 && b == 0)
            break;
    }

    return 0;
}
