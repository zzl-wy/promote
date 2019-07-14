#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "heap.h"

//使用数组存储二叉堆，因为堆是完全二叉树
//parent(i)=1/2
//left child(i)=2*i
//right child(i)=2*i+1

typedef struct ___heap__
{
	int capacity;
	int count;
	int data[0];
}heap_desc_s;
//============================================================
//shift down堆中移除元素
//todo优化swap
static void heap_shiftdown(heap_desc_s* heap,int index)
{
	while(index*2 <= heap->count)
	{
		int j = 2 * index;//在此轮循环中,data[k]和data[index]交换位置

		if(j+1 <= heap->count && heap->data[j] < heap->data[j+1])
		{
			j = j + 1;
		}

		if(heap->data[j] <= heap->data[index])
		{
			break;
		}

		swap(heap->data, index, j);
		index = j;
	}

	return ;
}

int heap_getmax(heap_desc_s* heap)
{
	int ret;
	
	assert(heap->count >= 1);

	ret = heap->data[1];
	swap(heap->data,1,heap->count);
	heap->count--;
	heap_shiftdown(heap, 1);
	return ret;
}

//============================================================
//heapify
//heapify给定一个数组将数组排列成堆
//算法复杂度是O(n),将N个元素逐步插入堆的复杂度是O(nlogn)
heap_desc_s* heap_init_heapify(int array[],int len)
{
	heap_desc_s* heap;

	heap = malloc(sizeof(int)*(len+1)+sizeof(heap_desc_s));
	if(heap == NULL)
	{
		abort();
	}
	memset(heap,0,sizeof(heap_desc_s));

	memcpy(heap->data+1,array,len*sizeof(int));
	heap->capacity = len;
	heap->count = len;
	
	for(int i = len/2; i >= 1; i--)
	{
		heap_shiftdown(heap,i);
	}
	
	return heap;
}

//============================================================
//shift up向堆中添加元素
static void heap_shiftup(heap_desc_s* heap,int index)
{
	while(index > 1 && heap->data[index/2] < heap->data[index])
	{
		swap(heap->data,index/2,index);
		index /= 2;
	}
}

int heap_insert(heap_desc_s* heap,int item)
{
	assert(heap->count+1<=heap->capacity);
	heap->data[heap->count+1] = item;
	heap->count++;
	heap_shiftup(heap,heap->count);

	return 0;
}


//============================================================
heap_desc_s* heap_init(int capacity)
{
	heap_desc_s*	heap;

	heap = malloc(sizeof(int)*capacity+sizeof(heap_desc_s));
	if(heap == NULL)
	{
		abort();
	}
	memset(heap,0,sizeof(heap_desc_s));

	heap->capacity = capacity;
	heap->count = 0;
	return heap;
}


void heap_deinit(heap_desc_s* heap)
{
	free(heap);
}

int heap_count(heap_desc_s* heap)
{
	return heap->count;
}

int heap_isempty(heap_desc_s* heap)
{
	return heap->count==0;
}

