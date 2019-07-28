#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "qfuf.h"

//quick find union find
typedef struct _qfuf__
{
	int* id;
	int count;
}qfuf_s;

qfuf_s* qfuf_init(int n)
{
	qfuf_s* qfuf;

	qfuf = malloc0(sizeof(qfuf_s));
	qfuf->count = n;
	qfuf->id = malloc0(sizeof(int)*n);

	for(int i = 0; i < n; i++)
	{
		qfuf->id[i] = i;
	}

	return qfuf;
}


void qfuf_deinit(qfuf_s* qfuf)
{
	free(qfuf->id);
	free(qfuf);
}

//quick find
int qfuf_find(qfuf_s* qfuf,int p)
{
	assert(p >= 0 && p < qfuf->count);

	return qfuf->id[p];
}

int qfuf_isconnected(qfuf_s* qfuf,int p,int q)
{
	return qfuf->id[p] == qfuf->id[q];
}

void qfuf_union(qfuf_s* qfuf,int p,int q)
{
	int p_id = qfuf_find(qfuf,p);
	int q_id = qfuf_find(qfuf,q);

	if(p_id == q_id)
	{
		return;
	}

	for(int i = 0; i < qfuf->count; i++)
	{
		if(qfuf->id[i] == p_id)
		{
			qfuf->id[i] = q_id;
		}
	}

	return;
}

#include <time.h>
void test_qfuf_perfomance(int n)
{
	clock_t startTime;
	clock_t endTime;
	qfuf_s* qfuf;

	qfuf = qfuf_init(n);
	if(NULL == qfuf)
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

		qfuf_union(qfuf, a, b);
	}
	for(int i = 0 ; i < n ; i ++ )
	{
		int a = rand()%n;
		int b = rand()%n;
		
		qfuf_isconnected(qfuf, a, b);
	}
	
	endTime = clock();
	printf("QFUF, %d ops, %lf s\n",2*n,(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return ;
}

