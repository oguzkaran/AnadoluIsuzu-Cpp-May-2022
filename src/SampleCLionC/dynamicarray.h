#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <stddef.h>

/*Type declarations*/

typedef int data_t;

typedef struct tagDARRAY {
	data_t* p;
	size_t capacity;
	size_t size;	
} DARRAY, *HDARRAY;

/*Function prototypes*/
HDARRAY createDArrayWithCapacity(size_t capacity);
HDARRAY createDArray(void);
int setCapacityDArray(HDARRAY hDArray, size_t newCapacity);
int addItemDArray(HDARRAY hDArray, const data_t *p);
int insertItemDArray(HDARRAY hDArray, size_t idx, const data_t* p);
int deleteItemByIdxDArray(HDARRAY hDArray, size_t idx);
void trimToSizeDArray(HDARRAY hDArray);
void freeDArray(HDARRAY hDArray);

/*Macros*/
size_t sizeDArray(HDARRAY hDArray); 
size_t capacityDArray(HDARRAY hDArray);
data_t itemDArray(HDARRAY hDArray, size_t idx);
void clearDArray(HDARRAY hDARray);

#endif /*DYNAMICARRAY_H_*/
