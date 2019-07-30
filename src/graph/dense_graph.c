#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dense_graph.h"

//稠密图使用 邻接矩阵（Adjacency matrix） 表示
typedef struct __dense_graph_
{
	int vertex_cnt;//定点数目
	int edge_cnt;//边的数目

	int directed;
	char* g;
}dense_graph_s;


dense_graph_s* dense_graph_init(int vertex_cnt,int directed)
{
	dense_graph_s*	dense_graph;

	dense_graph = malloc0(sizeof(dense_graph_s));

	dense_graph->vertex_cnt = vertex_cnt;
	dense_graph->edge_cnt = 0;
	dense_graph->directed = directed;
	dense_graph->g = malloc0(sizeof(char)*vertex_cnt*vertex_cnt);
	
	return dense_graph;
}

void dense_graph_deinit(dense_graph_s*	dense_graph)
{
	safe_free(dense_graph);
	safe_free(dense_graph->g);
}

int dense_graph_e(dense_graph_s*	dense_graph)
{
	return dense_graph->edge_cnt;
}

int dense_graph_v(dense_graph_s*	dense_graph)
{
	return dense_graph->vertex_cnt;
}

int dense_graph_has_edge(dense_graph_s*	dense_graph,int v,int w)
{
	int index = v*dense_graph->vertex_cnt+w;
	return dense_graph->g[index] > 0;
}

void dense_graph_add_edge(dense_graph_s*	dense_graph,int v,int w)
{
	int index;
	
	if(dense_graph_has_edge(dense_graph,v,w))
	{
		return  ;
	}

	index = v*dense_graph->vertex_cnt+w;
	dense_graph->g[index] = 1;
	if(!dense_graph->directed)
	{
		index = w*dense_graph->vertex_cnt+v;
		dense_graph->g[index] = 1;	
	}
	dense_graph->edge_cnt++;
}

