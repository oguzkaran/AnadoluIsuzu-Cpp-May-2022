#include "csd/bitwiseutil.h"

unsigned int csd_setbit(unsigned int val, unsigned int n)
{
    return val | 1 << n;
}

unsigned int csd_clearbit(unsigned int val, unsigned int n)
{
    return val & ~(1 << n);
}

unsigned int csd_get_nbitsset(unsigned int n)
{
    return ~(~0U << n);
}

unsigned int csd_get_nbitsclear(unsigned int n)
{
    return ~(~0U >> n);
}

size_t csd_get_nunberofsetbits(unsigned int val)
{
    size_t count = 0;

    do {
        if (val & 1)
            ++count;
        val >>= 1;
    } while (val);

    return count;
}