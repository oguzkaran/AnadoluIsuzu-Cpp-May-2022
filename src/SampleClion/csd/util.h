#ifndef CSD_UTIL_H_
#define CSD_UTIL_H_

#ifdef __cplusplus
    #include <cstddef>
    #include <cassert>
#else
    #include <stddef.h>
#include <assert.h>
#endif

#ifndef NDEBUG
    #define CSD_VERIFY(exp) assert(exp)
#else
    #define CSD_VERIFY(exp) ((void)(exp))
#endif

#ifdef __cplusplus
    #include <cstdlib>
    #include <ctime>

    #define CSD_RANDOMIZE() std::srand(static_cast<unsigned int>(std::time(nullptr)))
#else
    #include <stdlib.h>
    #include <time.h>

    #define CSD_RANDOMIZE() srand((unsigned int)time(NULL))
#endif

#ifdef __cplusplus
extern "C" {
#endif
	inline void csd_randomize()
	{
		CSD_RANDOMIZE();
	}

	int csd_random_int(int a, int b);

    void csd_fill_random_int_array(int *p, size_t, int min, int max);
    char *csd_strupper(char *s);
#ifdef __cplusplus
}
#endif


#endif //CSD_UTIL_H_

