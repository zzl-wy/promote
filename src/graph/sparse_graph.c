#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sparse_graph.h"

typedef struct __sgraph_edge_
{
	int vertex;
	struct __sgraph_edge_* next;
}sgraph_edge_s;

typedef struct __sgraph_vertex_
{
	sgraph_edge_s* head;	
	sgraph_edge_s* tail;

	int cnt;
}sgraph_vertex_s;


//稀疏图使用 邻接表(Adjacency list) 表示
typedef struct __sparse_graph_
{
	int vertex_cnt;//定点数目
	int edge_cnt;//边的数目

	int directed;
	sgraph_vertex_s* sgraph_vertex;
}sparse_graph_s;


sparse_graph_s* sparse_graph_init(int vertex_cnt,int directed)
{
	sparse_graph_s*	sparse_graph;

	sparse_graph = malloc0(sizeof(sparse_graph_s));

	sparse_graph->vertex_cnt = vertex_cnt;
	sparse_graph->edge_cnt = 0;
	sparse_graph->directed = directed;
	sparse_graph->sgraph_vertex = malloc0(sizeof(sgraph_vertex_s)*vertex_cnt);
	
	return sparse_graph;
}

static void sparse_graph_free_vertex(sgraph_vertex_s* sgraph_vertex)
{
	sgraph_edge_s* sgraph_edge_free;
	sgraph_edge_s* sgraph_edge;

	if(sgraph_vertex->cnt <= 0)
	{
		return ;
	}

	sgraph_edge = sgraph_vertex->head;
	for(int i = 0; i < sgraph_vertex->cnt; i++)
	{
		sgraph_edge_free = sgraph_edge;
		sgraph_edge = sgraph_edge->next;
		safe_free(sgraph_edge_free);
	}
}

void sparse_graph_deinit(sparse_graph_s*	sparse_graph)
{
	//删除所有的边
	for(int i = 0; i < sparse_graph->vertex_cnt; i++)
	{
		sparse_graph_free_vertex(sparse_graph->sgraph_vertex+i);
	}

	safe_free(sparse_graph->sgraph_vertex);
	safe_free(sparse_graph);

	return ;
}

int sparse_graph_e(sparse_graph_s*	sparse_graph)
{
	return sparse_graph->edge_cnt;
}

int sparse_graph_v(sparse_graph_s*	sparse_graph)
{
	return sparse_graph->vertex_cnt;
}


static int __sparse_graph_has_edge(sgraph_vertex_s* sgraph_vertex,int w)
{
	sgraph_edge_s* sgraph_edge;

	sgraph_edge = sgraph_vertex->head;
	for(int i = 0; i < sgraph_vertex->cnt; i++)
	{
		if(sgraph_edge->vertex == w)
		{
			return 1;
		}
		
		sgraph_edge = sgraph_edge->next;
	}

	return 0;
}

int sparse_graph_has_edge(sparse_graph_s*	sparse_graph,int v,int w)
{
	sgraph_vertex_s* sgraph_vertex;

	sgraph_vertex = sparse_graph->sgraph_vertex + v;
	return __sparse_graph_has_edge(sgraph_vertex,w);
}

static void __sparse_graph_add_edge(sparse_graph_s*	sparse_graph,int v,int w)
{
	sgraph_edge_s* sgraph_edge;
	sgraph_vertex_s* sgraph_vertex;

	sgraph_vertex = sparse_graph->sgraph_vertex + v;
	sgraph_edge = malloc0(sizeof(sgraph_edge_s));
	sgraph_edge->vertex = w;
	if(sgraph_vertex->cnt == 0)
	{
		sgraph_vertex->head = sgraph_edge;
		sgraph_vertex->tail = sgraph_edge;
	}
	else
	{
		sgraph_vertex->tail->next = sgraph_edge;
		sgraph_vertex->tail = sgraph_edge;
	}

	sgraph_vertex->cnt++;
	return;
}

void sparse_graph_add_edge(sparse_graph_s*	sparse_graph,int v,int w)
{
	//因为检查是否有平行边也就是调用sparse_graph_has_edge为O(n)，成本较高，所以可以忽略平行边
	__sparse_graph_add_edge(sparse_graph,v,w);
	if(v != w && !sparse_graph->directed)
	{
		__sparse_graph_add_edge(sparse_graph,w,v);
	}
	sparse_graph->edge_cnt++;
}

