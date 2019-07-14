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


