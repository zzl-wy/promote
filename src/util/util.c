#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void swap(int array[],int src,int dst)
{
	int tmp;
	
	tmp = array[src];
	array[src] = array[dst];
	array[dst] = tmp;
}

void print_array(int array[],int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d,",array[i]);

		if(i%16==0&&i>0)
		{
			printf("\n");
		}
	}	
	printf("\n");
}

void* malloc0(long int size)
{
	void* p;

	if(size <= 0)
	{
		abort();
	}
	
	p = malloc(size);
	if(NULL == p)
	{
		abort();
	}
	memset(p,0,size);

	return p;
}
