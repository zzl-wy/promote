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

void dense_graph_print_vertex_edge(dense_graph_s*	dense_graph,int v)
{
	int index;

	index = v*dense_graph->vertex_cnt;
	printf("%d : ",v);

	for(int i = 0;i < dense_graph->vertex_cnt; i++)
	{
		if(dense_graph->g[index+i] > 0)
		{
			printf("%d ",i);
		}
	}
	printf("\n");	
}

// O(E)
void dense_graph_print(dense_graph_s*	dense_graph)
{
    for( int v = 0 ; v < dense_graph->vertex_cnt; v ++ )
	{
		dense_graph_print_vertex_edge(dense_graph,v);
    }
}

static void dense_graph_component_dfs(dense_graph_s*	dense_graph,char* visited,int v)
{
	int index;

	visited[v] = 1;
	index = v*dense_graph->vertex_cnt;	
	printf("%d ",v);
	for(int i = 0;i < dense_graph->vertex_cnt; i++)
	{
		if(dense_graph->g[index+i] > 0 && visited[i] == 0)
		{
			dense_graph_component_dfs(dense_graph,visited,i);
		}
	}

	return ;
}

void dense_graph_component(dense_graph_s*	dense_graph)
{
	char visited[dense_graph->vertex_cnt];
	int cnt = 0;

	for(int i = 0; i < dense_graph->vertex_cnt; i++)
	{
		visited[i] = 0;
	}

	for(int i = 0; i < dense_graph->vertex_cnt; i++)
	{
		if(0 == visited[i])
		{
			cnt++;
			printf("dense_graph comnent[%d]:",cnt);
			dense_graph_component_dfs(dense_graph,visited,i);
			printf("\n");
		}
	}

	return ;
}

static void dense_graph_path_dfs(dense_graph_s*	dense_graph,char* visited,char* from,int v)
{
	int index;

	visited[v] = 1;
	index = v*dense_graph->vertex_cnt;
	for(int i = 0;i < dense_graph->vertex_cnt; i++)
	{
		if(dense_graph->g[index+i] > 0 && visited[i] == 0)
		{
			from[i] = v;
			dense_graph_path_dfs(dense_graph,visited,from,i);
		}
	}

}

void dense_graph_path(dense_graph_s*	dense_graph,int v,int w)
{
	char visited[dense_graph->vertex_cnt];
	char from[dense_graph->vertex_cnt];

	for(int i = 0; i < dense_graph->vertex_cnt; i++)
	{
		visited[i] = 0;
		from[i] = -1;
	}

 	dense_graph_path_dfs(dense_graph,visited,from,v);
	if(0 == visited[w])
	{
		printf("%d==>%d no path!\n",v,w);
	}

	printf("dense graph=>%d==>%d path:\n",v,w);
	int a = w;
	int flag = 0;
	while(-1 != a)
	{
		if(1 == flag)
		{
			printf("<---");
		}
		else
		{
			flag = 1;
		}
		
		printf("%d",a);
		a = from[a];
	}
	printf("\n");

	return ;
}

//BFS广度优先遍历，求无权图的的最短路径
void dense_graph_shortest_path(dense_graph_s*	dense_graph,int v,int w)
{
#if 0
	char visited[dense_graph->vertex_cnt];
	char from[dense_graph->vertex_cnt];
	char ord[dense_graph->vertex_cnt];
	queue_s* q = queue_init();	

	for(int i = 0; i < dense_graph->vertex_cnt; i++)
	{
		visited[i] = 0;
		from[i] = -1;
		ord[i] = -1;
	}


	queue_push(q,v);
	visited[v] = 1;
	ord[v] = 0;

	while(!queue_empty(q))
	{
		int index;
		int value = queue_front(q);

		queue_pop(q);
		visited[value] = 1;
		index = value*dense_graph->vertex_cnt;
		for(int i = 0;i < dense_graph->vertex_cnt; i++)
		{
			if(dense_graph->g[index+i] > 0 && visited[i] == 0)
			{
				from[i] = value;
				queue_push(q,i);
			}
		}		
	}


 	dense_graph_path_dfs(dense_graph,visited,from,v);
	if(0 == visited[w])
	{
		printf("%d==>%d no path!\n",v,w);
	}

	printf("dense graph=>%d==>%d path:\n",v,w);
	int a = w;
	int flag = 0;
	while(-1 != a)
	{
		if(1 == flag)
		{
			printf("<---");
		}
		else
		{
			flag = 1;
		}
		
		printf("%d",a);
		a = from[a];
	}
	printf("\n");
#endif
	return ;
}

