#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"

#define arraysize(x) (sizeof((x))/sizeof(x[0]))

void test_bst()
{
	bst_desc_s* bst_desc;
	
	bst_desc = bst_init();
	if(NULL == bst_desc)
	{
		printf("bst_init faild!\n");
		return ;
	}

	int array[] = {50,35,71,28,40,69,81,100};
	int size;
	int is_empty;
	
	size = bst_size(bst_desc);
	is_empty = bst_isempty(bst_desc);
	printf("1==>bst_size=%d,isempty=%d\n",size,is_empty);
	for(int i = 0; i < arraysize(array); i++)
	{
		bst_insert(bst_desc,array[i], i);
	}
	
	size = bst_size(bst_desc);
	is_empty = bst_isempty(bst_desc);
	printf("2==>bst_size=%d,isempty=%d\n",size,is_empty);

	

	bst_destroy(bst_desc);
}

