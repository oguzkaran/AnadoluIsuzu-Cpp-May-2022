#ifndef CSDUTIL_H_
#define CSDUTIL_H_

#include <stdlib.h>
#include <time.h>

#define CSD_RANDOMIZE() srand((unsigned int)time(NULL))

#ifdef __cplusplus
extern "C" {
#endif
	inline void csd_randomize()
	{
		srand((unsigned int)time(NULL));
	}

	int csd_random_int(int a, int b);
#ifdef __cplusplus
}
#endif


#endif //CSDUTIL_H_

