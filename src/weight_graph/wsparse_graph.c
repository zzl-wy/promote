#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "wsparse_graph.h"

typedef struct __wsgraph_edge_
{
	int vertex;
	double weigth;
	struct __wsgraph_edge_* next;
}wsgraph_edge_s;

typedef struct __wsgraph_vertex_
{
	wsgraph_edge_s* head;	
	wsgraph_edge_s* tail;

	int cnt;
}wsgraph_vertex_s;


//稀疏图使用 邻接表(Adjacency list) 表示
typedef struct __wsgraph_
{
	int vertex_cnt;//定点数目
	int edge_cnt;//边的数目

	int directed;
	wsgraph_vertex_s* wsgraph_vertex;
}wsgraph_s;


wsgraph_s* wsgraph_init(int vertex_cnt,int directed)
{
	wsgraph_s*	wsgraph;

	wsgraph = malloc0(sizeof(wsgraph_s));

	wsgraph->vertex_cnt = vertex_cnt;
	wsgraph->edge_cnt = 0;
	wsgraph->directed = directed;
	wsgraph->wsgraph_vertex = malloc0(sizeof(wsgraph_vertex_s)*vertex_cnt);
	
	return wsgraph;
}

static void wsgraph_free_vertex(wsgraph_vertex_s* wsgraph_vertex)
{
	wsgraph_edge_s* wsgraph_edge_free;
	wsgraph_edge_s* wsgraph_edge;

	if(wsgraph_vertex->cnt <= 0)
	{
		return ;
	}

	wsgraph_edge = wsgraph_vertex->head;
	for(int i = 0; i < wsgraph_vertex->cnt; i++)
	{
		wsgraph_edge_free = wsgraph_edge;
		wsgraph_edge = wsgraph_edge->next;
		safe_free(wsgraph_edge_free);
	}
}

void wsgraph_deinit(wsgraph_s*	wsgraph)
{
	//删除所有的边
	for(int i = 0; i < wsgraph->vertex_cnt; i++)
	{
		wsgraph_free_vertex(wsgraph->wsgraph_vertex+i);
	}

	safe_free(wsgraph->wsgraph_vertex);
	safe_free(wsgraph);

	return ;
}

int wsgraph_e(wsgraph_s*	wsgraph)
{
	return wsgraph->edge_cnt;
}

int wsgraph_v(wsgraph_s*	wsgraph)
{
	return wsgraph->vertex_cnt;
}


static int __wsgraph_has_edge(wsgraph_vertex_s* wsgraph_vertex,int w)
{
	wsgraph_edge_s* wsgraph_edge;

	wsgraph_edge = wsgraph_vertex->head;
	for(int i = 0; i < wsgraph_vertex->cnt; i++)
	{
		if(wsgraph_edge->vertex == w)
		{
			return 1;
		}
		
		wsgraph_edge = wsgraph_edge->next;
	}

	return 0;
}

int wsgraph_has_edge(wsgraph_s*	wsgraph,int v,int w)
{
	wsgraph_vertex_s* wsgraph_vertex;

	wsgraph_vertex = wsgraph->wsgraph_vertex + v;
	return __wsgraph_has_edge(wsgraph_vertex,w);
}

static void __wsgraph_add_edge(wsgraph_s*	wsgraph,int v,int w,double weigth)
{
	wsgraph_edge_s* wsgraph_edge;
	wsgraph_vertex_s* wsgraph_vertex;

	wsgraph_vertex = wsgraph->wsgraph_vertex + v;
	wsgraph_edge = malloc0(sizeof(wsgraph_edge_s));
	wsgraph_edge->vertex = w;
	wsgraph_edge->weigth = weigth;
	if(wsgraph_vertex->cnt == 0)
	{
		wsgraph_vertex->head = wsgraph_edge;
		wsgraph_vertex->tail = wsgraph_edge;
	}
	else
	{
		wsgraph_vertex->tail->next = wsgraph_edge;
		wsgraph_vertex->tail = wsgraph_edge;
	}

	wsgraph_vertex->cnt++;
	return;
}

void wsgraph_add_edge(wsgraph_s*	wsgraph,int v,int w,double weigth)
{
	//因为检查是否有平行边也就是调用wsgraph_has_edge为O(n)，成本较高，所以可以忽略平行边
	__wsgraph_add_edge(wsgraph,v,w,weigth);
	if(v != w && !wsgraph->directed)
	{
		__wsgraph_add_edge(wsgraph,w,v,weigth);
	}
	wsgraph->edge_cnt++;
}

static void wsgraph_print_vertex_edge(wsgraph_s*	wsgraph,int v)
{
	wsgraph_vertex_s* wsgraph_vertex;
	wsgraph_edge_s* wsgraph_edge;

	wsgraph_vertex = wsgraph->wsgraph_vertex + v;
	wsgraph_edge = wsgraph_vertex->head;
	
	printf("%d : ",v);
	for(int i = 0; i < wsgraph_vertex->cnt; i++)
	{
        printf("<%d:%lf> ",wsgraph_edge->vertex,wsgraph_edge->weigth);
		
		wsgraph_edge = wsgraph_edge->next;
	}
	printf("\n");
}

void wsgraph_print(wsgraph_s*	wsgraph)
{
    // O(E)
    for( int v = 0 ; v < wsgraph->vertex_cnt; v ++ )
	{
		wsgraph_print_vertex_edge(wsgraph,v);
    }

}



