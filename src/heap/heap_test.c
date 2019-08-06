#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "heap.h"

void test_heap2()
{
	heap_desc_s* heap;
	int tmp;

	srand(time(NULL));

	heap = heap_init(100);
	for(int i = 0; i < 50; i++)
	{
		tmp = rand()%100;
		heap_insert(heap,tmp);
	}

	printf("heap_count=%d\n",heap_count(heap));
	while(!heap_isempty(heap))
	{
		printf("%d ",heap_getmax(heap));
	}
	printf("\n");
	exit(0);
}

void test_heap()
{
	indexheap_s* heap;
	int tmp;

	srand(time(NULL));
	heap = indexheap_init(100);
	for(int i = 0; i < 100; i++)
	{
		tmp = rand()%100;
		indexheap_insert(heap,tmp);
	}

	printf("indexheap_count=%d\n",indexheap_count(heap));
	indexheap_debug(heap);
	printf("\n\n");
	
	while(!indexheap_isempty(heap))
	{
		printf("%d ",indexheap_getmax(heap));
	}
	printf("\n");
	exit(0);
}

