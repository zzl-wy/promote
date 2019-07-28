#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quuf_count.h"

//quick union union find
typedef struct ___quuf_count__
{
	int count;
	int* parent;
	int* size;
}quuf_count_s;

quuf_count_s* quuf_count_init(int n)
{
	quuf_count_s* quuf_count;

	quuf_count = malloc0(sizeof(quuf_count_s));
	quuf_count->count = n;
	quuf_count->parent = malloc0(sizeof(int)*n);
	quuf_count->size = malloc0(sizeof(int)*n);

	for(int i = 0; i < n; i++)
	{
		quuf_count->parent[i] = i;
		quuf_count->size[i] = 1;
	}

	return quuf_count;
}


void quuf_count_deinit(quuf_count_s* quuf_count)
{
	free(quuf_count->parent);
	free(quuf_count->size);
	free(quuf_count);
}

//quick find
int quuf_count_find(quuf_count_s* quuf_count,int p)
{
	assert(p >= 0 && p < quuf_count->count);

	while(p != quuf_count->parent[p]) 
	{
		p = quuf_count->parent[p];
	}

	return p;
}

int quuf_count_isconnected(quuf_count_s* quuf_count,int p,int q)
{
	int p_find = quuf_count_find(quuf_count,p);
	int q_find = quuf_count_find(quuf_count,q);

	return  p_find == q_find;
}

void quuf_count_union(quuf_count_s* quuf_count,int p,int q)
{
	int p_root = quuf_count_find(quuf_count,p);
	int q_root = quuf_count_find(quuf_count,q);

	if(p_root == q_root)
	{
		return;
	}

	if(quuf_count->size[p_root] < quuf_count->size[q_root])
	{
		quuf_count->parent[p_root] = q_root;
		quuf_count->size[q_root] += quuf_count->size[p_root];
	}
	else
	{
		quuf_count->parent[q_root] = p_root;
		quuf_count->size[p_root] += quuf_count->size[q_root];
	}

	return;
}

#include <time.h>
void test_quuf_count_perfomance(int n)
{
	clock_t startTime;
	clock_t endTime;
	quuf_count_s* quuf_count;

	quuf_count = quuf_count_init(n);
	if(NULL == quuf_count)
	{
		printf("uf_init faild!\n");
		return;
	}
	
	srand(time(NULL) );
	startTime = clock();

	for( int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;

		quuf_count_union(quuf_count, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		quuf_count_isconnected(quuf_count, a, b);
	}
	
	endTime = clock();
	printf("QUUF COUNT, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

void test_quuf_count_func(void)
{
	quuf_count_s* quuf_count;
	int ret;

	quuf_count = quuf_count_init(10);
	if(NULL == quuf_count)
	{
		printf("quuf_count_init faild!\n");
		return;
	}

	print_array(quuf_count->parent, quuf_count->count);
	quuf_count_union(quuf_count, 0, 1);

	print_array(quuf_count->parent, quuf_count->count);

	quuf_count_union(quuf_count, 8, 9);
	print_array(quuf_count->parent, quuf_count->count);

	printf("\n");
	ret = quuf_count_isconnected(quuf_count, 0, 1);
	printf("quuf_count_isconnected[0]=%d\n",ret);

	ret = quuf_count_isconnected(quuf_count, 9, 8);
	printf("quuf_count_isconnected[1]=%d\n",ret);

	ret = quuf_count_isconnected(quuf_count, 3, 4);
	printf("quuf_count_isconnected[2]=%d\n",ret);

	ret = quuf_count_isconnected(quuf_count, 7, 4);
	printf("quuf_count_isconnected[3]=%d\n",ret);

	return ;
}

