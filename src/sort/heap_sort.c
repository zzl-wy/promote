#include <stdio.h>
#include <string.h>
#include "sort.h"
#include "../heap/heap.h"

//堆排序
void heap_sort(int array[],int len)
{
	heap_desc_s* heap;

	heap = heap_init(len);
	for(int i = 0; i < len; i++)
	{
		heap_insert(heap,array[i]);
	}

	for(int i = len-1; i >= 0; i--)
	{
		array[i] = heap_getmax(heap);
	}
	heap_deinit(heap);

	return ;
}

void heap_sort_heapify(int array[],int len)
{
	heap_desc_s* heap;

	heap = heap_init_heapify(array,len);

	for(int i = len-1; i >= 0; i--)
	{
		array[i] = heap_getmax(heap);
	}
	heap_deinit(heap);

	return ;
}

void __shiftdown(int array[],int len,int index)
{
	while(index*2+1 < len)
	{
		int j = 2*index+1;//在此轮循环中,data[k]和data[index]交换位置

		if(j+1 < len && array[j] < array[j+1])
		{
			j = j + 1;
		}

		if(array[j] <= array[index])
		{
			break;
		}

		swap(array, index, j);
		index = j;
	}

	return ;
}

void heap_sort_origin(int array[],int len)
{
	 for(int i = (len-1)/2; i >= 0; i--)
	 {
		 __shiftdown(array,len,i);
	 }

	 for(int i = len-1; i > 0; i--)
	 {
		swap(array,i,0);
		__shiftdown(array,i,0);
	 }

	 return ;
}

