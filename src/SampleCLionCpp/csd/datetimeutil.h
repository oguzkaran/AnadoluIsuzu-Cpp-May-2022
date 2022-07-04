#ifndef DATETIMEUTIL_H_
#define DATETIMEUTIL_H_

#ifdef __cplusplus
    #include <cstdbool>
#else
    #include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
    bool csd_is_valid_date(int d, int m, int y);
    bool csd_is_leap_year(int y);
#ifdef __cplusplus
}
#endif


#endif //DATETIMEUTIL_H_
