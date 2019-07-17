#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "heap.h"

typedef struct ___indexheap__
{
	int capacity;
	int count;
	int* data;
	int* index;
}indexheap_s;

static void indexheap_shiftdown(indexheap_s* heap,int index)
{
	while(index*2 >= heap->count)
	{
		int j = index*2;

		if(j+1 >= heap->count && heap->data[heap->index[j+1]] > heap->data[heap->index[j]])
		{
			j = j + 1;
		}

		if(heap->data[heap->index[index]] >= heap->data[heap->index[j]])
		{
			break;
		}

		swap(heap->index,index,j);
		index = j;
	}
	
	return ;
}

int indexheap_getmax(indexheap_s* heap)
{
	int ret;
	
	assert(heap->count >= 1);

	ret = heap->data[heap->index[1]];
	swap(heap->index,1,heap->count);
	heap->count--;
	indexheap_shiftdown(heap, 1);
	return ret;
}


//============================================================
//shift up向堆中添加元素
static void indexheap_shiftup(indexheap_s* heap,int index)
{
	while(index/2 >= 1)
	{
		if(heap->data[heap->index[index]] > heap->data[heap->index[index/2]])
		{
			swap(heap->index,index,index/2);
		}
		else
		{
			break;
		}

		index = index / 2;
	}
}

int indexheap_insert(indexheap_s* heap,int item)
{
	assert(heap->count+1 <= heap->capacity);
	heap->count++;
	heap->data[heap->count] = item;
	heap->index[heap->count] = heap->count;
	
	indexheap_shiftup(heap,heap->count);
	return 0;
}


//============================================================
indexheap_s* indexheap_init(int capacity)
{
	indexheap_s*	heap;
	int size;

	size = capacity + 1;
	heap = malloc(sizeof(indexheap_s));
	if(heap == NULL)
	{
		abort();
	}
	memset(heap,0,sizeof(indexheap_s));

	heap->data = malloc(size*sizeof(int));
	if(heap->data == NULL)
	{
		abort();
	}
	memset(heap->data,0,size*sizeof(int));
	
	heap->index = malloc(size*sizeof(int));
	if(heap->index == NULL)
	{
		abort();
	}
	memset(heap->index,0,size*sizeof(int));

	heap->capacity = capacity;
	heap->count = 0;
	return heap;
}


void indexheap_deinit(indexheap_s* heap)
{
	free(heap->data);
	free(heap->index);
	free(heap);
}

int indexheap_count(indexheap_s* heap)
{
	return heap->count;
}

int indexheap_isempty(indexheap_s* heap)
{
	return heap->count == 0;
}

