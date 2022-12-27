#ifndef CSD_UTIL_H_
#define CSD_UTIL_H_

#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#define CSD_RANDOMIZE() srand((unsigned int)time(NULL))

#ifdef __cplusplus
extern "C" {
#endif
	inline void csd_randomize()
	{
		srand((unsigned int)time(NULL));
	}

	int csd_random_int(int a, int b);

    void csd_fill_random_int_array(int *p, size_t, int min, int max);
    char *csd_strupper(char *s);
#ifdef __cplusplus
}
#endif


#endif //CSD_UTIL_H_

