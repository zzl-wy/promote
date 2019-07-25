#ifndef __UTIL_H__
#define __UTIL_H__
#include <unistd.h>

#define safe_free(x) do\
{\
	if(NULL != (x))\
	{\
		free(x);\
		(x)=NULL;\
	}\
}while(0)

void print_array(int array[],int len);
void swap(int array[],int src,int dst);

void* malloc0(long int size);

#endif //__UTIL_H__
