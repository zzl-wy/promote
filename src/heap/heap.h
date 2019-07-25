#ifndef __HEAP_H__
#define __HEAP_H__
#include "util.h"

typedef struct ___heap__ heap_desc_s;

heap_desc_s* heap_init(int capacity);
heap_desc_s* heap_init_heapify(int array[],int len);

void heap_deinit(heap_desc_s* heap);
int heap_count(heap_desc_s* heap);
int heap_isempty(heap_desc_s* heap);

int heap_getmax(heap_desc_s* heap);


int heap_insert(heap_desc_s* heap,int item);

void heap_output(heap_desc_s* heap);
void test_heap();

//=========================================
typedef struct ___indexheap__ indexheap_s;
indexheap_s* indexheap_init(int capacity);
void indexheap_deinit(indexheap_s* heap);

int indexheap_insert(indexheap_s* heap,int item);
int indexheap_getmax(indexheap_s* heap);

int indexheap_isempty(indexheap_s* heap);
int indexheap_count(indexheap_s* heap);

int indexheap_debug(indexheap_s* heap);

#endif //__HEAP_H__
