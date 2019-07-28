#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quuf.h"

//quick union union find
typedef struct ___quuf__
{
	int* parent;
	int count;
}quuf_s;

quuf_s* quuf_init(int n)
{
	quuf_s* quuf;

	quuf = malloc0(sizeof(quuf_s));
	quuf->count = n;
	quuf->parent = malloc0(sizeof(int)*n);

	for(int i = 0; i < n; i++)
	{
		quuf->parent[i] = i;
	}

	return quuf;
}


void quuf_deinit(quuf_s* quuf)
{
	free(quuf->parent);
	free(quuf);
}

//quick find
int quuf_find(quuf_s* quuf,int p)
{
	assert(p >= 0 && p < quuf->count);

	while(p != quuf->parent[p]) 
	{
		p = quuf->parent[p];
	}

	return p;
}

int quuf_isconnected(quuf_s* quuf,int p,int q)
{
	int p_find = quuf_find(quuf,p);
	int q_find = quuf_find(quuf,q);

	return  p_find == q_find;
}

void quuf_union(quuf_s* quuf,int p,int q)
{
	int p_root = quuf_find(quuf,p);
	int q_root = quuf_find(quuf,q);

	if(p_root == q_root)
	{
		return;
	}

	quuf->parent[p_root] = q_root;

	return;
}

#include <time.h>
void test_quuf_perfomance(int n)
{
	clock_t startTime;
	clock_t endTime;
	quuf_s* quuf;

	quuf = quuf_init(n);
	if(NULL == quuf)
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

		quuf_union(quuf, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		quuf_isconnected(quuf, a, b);
	}
	
	endTime = clock();
	printf("QUUF, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

void test_quuf_func(void)
{
	quuf_s* quuf;
	int ret;

	quuf = quuf_init(10);
	if(NULL == quuf)
	{
		printf("uf_init faild!\n");
		return;
	}

	print_array(quuf->parent, quuf->count);
	quuf_union(quuf, 0, 1);

	print_array(quuf->parent, quuf->count);

	quuf_union(quuf, 8, 9);
	print_array(quuf->parent, quuf->count);

	printf("\n");
	ret = quuf_isconnected(quuf, 0, 1);
	printf("quuf_isconnected[0]=%d\n",ret);

	ret = quuf_isconnected(quuf, 9, 8);
	printf("quuf_isconnected[1]=%d\n",ret);

	ret = quuf_isconnected(quuf, 3, 4);
	printf("quuf_isconnected[2]=%d\n",ret);

	ret = quuf_isconnected(quuf, 7, 4);
	printf("quuf_isconnected[3]=%d\n",ret);

	return ;
}

