#include "dynamicarray.h"
#include <stdlib.h>
#include <string.h>

#define DEF_CAPACITY		2

HDARRAY createDArrayWithCapacity(size_t capacity)
{
	HDARRAY hDArray;

	if ((hDArray = (HDARRAY)malloc(sizeof(DARRAY))) == NULL)
		return NULL;

	if ((hDArray->p = (data_t*)malloc(sizeof(data_t) * capacity)) == NULL) {
		free(hDArray);
		return NULL;
	}

	hDArray->size = 0;
	hDArray->capacity = capacity;

	return hDArray;
}

HDARRAY createDArray(void)
{
	return createDArrayWithCapacity(DEF_CAPACITY);
}

int setCapacityDArray(HDARRAY hDArray, size_t newCapacity)
{
	data_t* pNewArray;

	if (newCapacity < hDArray->size)
		return -1;

	if (newCapacity == hDArray->capacity)
		return newCapacity;

	if ((pNewArray = (data_t*)realloc(hDArray->p, newCapacity * sizeof(data_t))) == NULL)
		return -1;

	hDArray->p = pNewArray;
	hDArray->capacity = newCapacity;

	return newCapacity;
}


int addItemDArray(HDARRAY hDArray, const data_t* p)
{
	if (hDArray->size >= hDArray->capacity && setCapacityDArray(hDArray, hDArray->capacity * 2) == -1)
		return -1;

	hDArray->p[hDArray->size] = *p;

	return hDArray->size++;
}

int insertItemDArray(HDARRAY hDArray, size_t idx, const data_t* p)
{
	if (idx > hDArray->size)
		return -1;

	if (hDArray->size >= hDArray->capacity && setCapacityDArray(hDArray, hDArray->capacity * 2) == -1)
		return -1;

	memmove(&hDArray->p[idx + 1], &hDArray->p[idx], (hDArray->size - idx) * sizeof(data_t));
	hDArray->p[idx] = *p;

	++hDArray->size;

	return idx;
}

int deleteItemByIdxDArray(HDARRAY hDArray, size_t idx)
{
	if (idx >= hDArray->size)
		return -1;

	memmove(&hDArray->p[idx], &hDArray->p[idx + 1], (hDArray->size - idx - 1) * sizeof(data_t));

	--hDArray->size;

	return idx;
}

void trimToSizeDArray(HDARRAY hDArray)
{	
	setCapacityDArray(hDArray, hDArray->size > 0 ? hDArray->size : DEF_CAPACITY);
}

void freeDArray(HDARRAY hDArray)
{
	free(hDArray->p);
	free(hDArray);
}

size_t sizeDArray(HDARRAY hDArray)
{
	return hDArray->size;
}

size_t capacityDArray(HDARRAY hDArray)
{
	return hDArray->capacity;
}

data_t itemDArray(HDARRAY hDArray, size_t idx)
{
	return hDArray->p[idx];
}

void clearDArray(HDARRAY hDArray)
{
	hDArray->size = 0;
}

