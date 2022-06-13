#include <stdio.h>

struct SAMPLE {
    double b;
    int a;
    short c;

};

int main(void)
{
    printf("sizeof(int) = %u, sizeof(double) = %u, sizeof(short) = %u\n", sizeof(int), sizeof(double), sizeof(short));
    printf("sizeof(struct SAMPLE) = %u\n", sizeof(struct SAMPLE));
    struct SAMPLE s;

    printf("&s.a = %p, &s.b = %p, &s.c = %p\n", &s.a, &s.b, &s.c);

    return 0;
}
