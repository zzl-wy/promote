#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "quuf_rank.h"

//quick union union find
typedef struct ___quuf_rank_
{
	int count;
	int* parent;
	int* rank;
}quuf_rank_s;

quuf_rank_s* quuf_rank_init(int n)
{
	quuf_rank_s* quuf_rank;

	quuf_rank = malloc0(sizeof(quuf_rank_s));
	quuf_rank->count = n;
	quuf_rank->parent = malloc0(sizeof(int)*n);
	quuf_rank->rank = malloc0(sizeof(int)*n);

	for(int i = 0; i < n; i++)
	{
		quuf_rank->parent[i] = i;
		quuf_rank->rank[i] = 1;
	}

	return quuf_rank;
}


void quuf_rank_deinit(quuf_rank_s* quuf_rank)
{
	free(quuf_rank->parent);
	free(quuf_rank->rank);
	free(quuf_rank);
}

//=================================================================================
//quick find
int quuf_rank_find(quuf_rank_s* quuf_rank,int p)
{
	assert(p >= 0 && p < quuf_rank->count);

	while(p != quuf_rank->parent[p]) 
	{
		p = quuf_rank->parent[p];
	}

	return p;
}

int quuf_rank_isconnected(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_find = quuf_rank_find(quuf_rank,p);
	int q_find = quuf_rank_find(quuf_rank,q);

	return  p_find == q_find;
}

void quuf_rank_union(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_root = quuf_rank_find(quuf_rank,p);
	int q_root = quuf_rank_find(quuf_rank,q);

	if(p_root == q_root)
	{
		return;
	}

	if(quuf_rank->rank[p_root] < quuf_rank->rank[q_root])
	{
		quuf_rank->parent[p_root] = q_root;
	}
	else if(quuf_rank->rank[p_root] > quuf_rank->rank[q_root])
	{
		quuf_rank->parent[q_root] = p_root;
	}
	else
	{
		quuf_rank->parent[q_root] = p_root;
		quuf_rank->rank[p_root]++;
	}

	return;
}

//====================================================================================
//pc ==>path compression
int quuf_rank_find_pc(quuf_rank_s* quuf_rank,int p)
{
	assert(p >= 0 && p < quuf_rank->count);

	while(p != quuf_rank->parent[p]) 
	{
		quuf_rank->parent[p] = quuf_rank->parent[quuf_rank->parent[p]];
		p = quuf_rank->parent[p];
	}

	return p;
}

int quuf_rank_isconnected_pc(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_find = quuf_rank_find_pc(quuf_rank,p);
	int q_find = quuf_rank_find_pc(quuf_rank,q);

	return  p_find == q_find;
}

void quuf_rank_union_pc(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_root = quuf_rank_find_pc(quuf_rank,p);
	int q_root = quuf_rank_find_pc(quuf_rank,q);

	if(p_root == q_root)
	{
		return;
	}

	if(quuf_rank->rank[p_root] < quuf_rank->rank[q_root])
	{
		quuf_rank->parent[p_root] = q_root;
	}
	else if(quuf_rank->rank[p_root] > quuf_rank->rank[q_root])
	{
		quuf_rank->parent[q_root] = p_root;
	}
	else
	{
		quuf_rank->parent[q_root] = p_root;
		quuf_rank->rank[p_root]++;
	}

	return;
}

//====================================================================================
//pc ==>path compression2
int quuf_rank_find_pc2(quuf_rank_s* quuf_rank,int p)
{
	assert(p >= 0 && p < quuf_rank->count);

#if 0
	while(p != quuf_rank->parent[p]) 
	{
		quuf_rank->parent[p] = quuf_rank->parent[quuf_rank->parent[p]];
		p = quuf_rank->parent[p];
	}
#endif
	if(p != quuf_rank->parent[p])
	{
		quuf_rank->parent[p] = quuf_rank_find_pc(quuf_rank, quuf_rank->parent[p]);
	}

	return quuf_rank->parent[p];
}

int quuf_rank_isconnected_pc2(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_find = quuf_rank_find_pc2(quuf_rank,p);
	int q_find = quuf_rank_find_pc2(quuf_rank,q);

	return  p_find == q_find;
}

void quuf_rank_union_pc2(quuf_rank_s* quuf_rank,int p,int q)
{
	int p_root = quuf_rank_find_pc2(quuf_rank,p);
	int q_root = quuf_rank_find_pc2(quuf_rank,q);

	if(p_root == q_root)
	{
		return;
	}

	if(quuf_rank->rank[p_root] < quuf_rank->rank[q_root])
	{
		quuf_rank->parent[p_root] = q_root;
	}
	else if(quuf_rank->rank[p_root] > quuf_rank->rank[q_root])
	{
		quuf_rank->parent[q_root] = p_root;
	}
	else
	{
		quuf_rank->parent[q_root] = p_root;
		quuf_rank->rank[p_root]++;
	}

	return;
}

#include <time.h>

void test_quuf_rank_func(void)
{
	quuf_rank_s* quuf_rank;
	int ret;

	quuf_rank = quuf_rank_init(10);
	if(NULL == quuf_rank)
	{
		printf("uf_init faild!\n");
		return;
	}

	print_array(quuf_rank->parent, quuf_rank->count);
	quuf_rank_union(quuf_rank, 0, 1);

	print_array(quuf_rank->parent, quuf_rank->count);

	quuf_rank_union(quuf_rank, 8, 9);
	print_array(quuf_rank->parent, quuf_rank->count);

	printf("\n");
	ret = quuf_rank_isconnected(quuf_rank, 0, 1);
	printf("quuf_rank_isconnected[0]=%d\n",ret);

	ret = quuf_rank_isconnected(quuf_rank, 9, 8);
	printf("quuf_rank_isconnected[1]=%d\n",ret);

	ret = quuf_rank_isconnected(quuf_rank, 3, 4);
	printf("quuf_rank_isconnected[2]=%d\n",ret);

	ret = quuf_rank_isconnected(quuf_rank, 7, 4);
	printf("quuf_rank_isconnected[3]=%d\n",ret);

	return ;
}

void test_quuf_rank_perfomance(int n)
{
	clock_t startTime;
	clock_t endTime;
	quuf_rank_s* quuf_rank;

	quuf_rank = quuf_rank_init(n);
	if(NULL == quuf_rank)
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

		quuf_rank_union(quuf_rank, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		quuf_rank_isconnected(quuf_rank, a, b);
	}
	
	endTime = clock();
	printf("QUUF RANK, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

void test_quuf_rank_pc_perfomance(int n)
{
	clock_t startTime;
	clock_t endTime;
	quuf_rank_s* quuf_rank;

	quuf_rank = quuf_rank_init(n);
	if(NULL == quuf_rank)
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

		quuf_rank_union_pc(quuf_rank, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		quuf_rank_isconnected_pc(quuf_rank, a, b);
	}
	
	endTime = clock();
	printf("QUUF RANK PC, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

void test_quuf_rank_pc_perfomance2(int n)
{
	clock_t startTime;
	clock_t endTime;
	quuf_rank_s* quuf_rank;

	quuf_rank = quuf_rank_init(n);
	if(NULL == quuf_rank)
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

		quuf_rank_union_pc2(quuf_rank, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		quuf_rank_isconnected_pc2(quuf_rank, a, b);
	}
	
	endTime = clock();
	printf("QUUF RANK PC2, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

