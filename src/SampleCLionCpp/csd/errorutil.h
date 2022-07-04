#ifndef CSD_ERRORUTIL_H_
#define CSD_ERRORUTIL_H_

#ifdef __cplusplus
extern "C" {
#endif
	void csd_exit_fail(const char* msg);
	void csd_exit_with_code(const char* msg, int code);
#ifdef __cplusplus
}
#endif

#endif //CSD_ERRORUTIL_H_
