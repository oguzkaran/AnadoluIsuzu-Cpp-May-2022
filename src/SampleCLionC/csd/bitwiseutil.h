#ifndef BITWISEUTIL_H_
#define BITWISEUTIL_H_

#include <stddef.h>

unsigned int csd_setbit(unsigned int val, unsigned int n);
unsigned int csd_clearbit(unsigned int val, unsigned int n);
unsigned int csd_get_nbitsset(unsigned int n);
unsigned int csd_get_nbitsclear(unsigned int n);
size_t csd_get_nunberofsetbits(unsigned int val);

#endif /* BITWISEUTIL_H_ */
