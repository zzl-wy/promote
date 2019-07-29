#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"
#include "queue.h"

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

	int array[] = {50,35,71,28,40,69,81,76,100};
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

	int contain;
	contain = bst_contain(bst_desc,40);
	printf("bst_contain[40]=%d\n",contain);
	
	contain = bst_contain(bst_desc,69);
	printf("bst_contain[69]=%d\n",contain);

	contain = bst_contain(bst_desc,30);
	printf("bst_contain[30]=%d\n",contain);

	contain = bst_contain(bst_desc,91);
	printf("bst_contain[91]=%d\n",contain);

	int *value;
	
	value = bst_search(bst_desc,40);
	if(value)
	{
		printf("bst_search[40]=%d\n",*value);
	}
	else
	{
		printf("bst_search[40] not exsist\n");
	}

	value = bst_search(bst_desc,69);
	if(value)
	{
		printf("bst_search[69]=%d\n",*value);
	}
	else
	{
		printf("bst_search[69] not exsist\n");
	}

	value = bst_search(bst_desc,30);
	if(value)
	{
		printf("bst_search[30]=%d\n",*value);
	}
	else
	{
		printf("bst_search[30] not exsist\n");
	}

	value = bst_search(bst_desc,91);
	if(value)
	{
		printf("bst_search[91]=%d\n",*value);
	}
	else
	{
		printf("bst_search[91] not exsist\n");
	}

//	bst_preorder(bst_desc);
//	bst_inorder(bst_desc);
//	bst_postorder(bst_desc);
	bst_levelorder(bst_desc);

#if 0
	bst_removemin(bst_desc);
	size = bst_size(bst_desc);
	printf("3==>bst_size=%d\n",size);
	bst_levelorder(bst_desc);
#endif

#if 0
	for(int j = 0; j < 9;j ++)
	{
		bst_removemax(bst_desc);
		size = bst_size(bst_desc);
		printf("3==>bst_size=%d\n",size);
		bst_levelorder(bst_desc);
		printf("\n\n");
	}
#endif

	bst_remove(bst_desc,71);
	size = bst_size(bst_desc);
	printf("3==>bst_size=%d\n",size);
	bst_levelorder(bst_desc);

	bst_destroy(bst_desc);
}

