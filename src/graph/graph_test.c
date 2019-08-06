#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#include "sparse_graph.h"
#include "dense_graph.h"

void test_sparse_graph(int vertex,int edge)
{
	sparse_graph_s* sparse_graph = sparse_graph_init(vertex, 0);
	if(NULL == sparse_graph)
	{
		abort();
	}

    for( int i = 0 ; i < edge ; i ++ )
	{
        int a = rand()%vertex;
        int b = rand()%vertex;

		sparse_graph_add_edge(sparse_graph, a, b);
    }


	sparse_graph_print(sparse_graph);
	return ;
}

void test_dense_graph(int vertex,int edge)
{
    // Dense Graph
    dense_graph_s* dense_graph;
    dense_graph = dense_graph_init(vertex, 0);
	if(NULL == dense_graph)
	{
		abort();
	}

    for( int i = 0 ; i < edge ; i ++ )
	{
        int a = rand()%vertex;
        int b = rand()%vertex;
		dense_graph_add_edge(dense_graph, a, b);
    }

	dense_graph_print(dense_graph);
	printf("\n\n");
	dense_graph_component(dense_graph);
	return ;
}

void test_read_dense_graph(const char* filename)
{	
	FILE *fp;
    dense_graph_s* dense_graph;
	char line[128];
	int V, E;


	fp = fopen(filename, "r");
	if(NULL == fp)
	{
		printf("fopen %s failed!\n",filename);
		return ;
	}

	fgets(line,sizeof(line),fp);
	sscanf(line,"%d %u",&V,&E);

    dense_graph = dense_graph_init(V, 0);
	if(NULL == dense_graph)
	{
		abort();
	}

	int a,b;
	for( int i = 0 ; i < E ; i ++ )
	{
		fgets(line,sizeof(line),fp);
		sscanf(line,"%d %u",&a,&b);

		assert( a >= 0 && a < V );
		assert( b >= 0 && b < V );
		dense_graph_add_edge(dense_graph, a, b);
	}

	dense_graph_print(dense_graph);	
	printf("\n");
	dense_graph_component(dense_graph);
	printf("\n");
	dense_graph_path(dense_graph, 0, 6);

	printf("\n");
	dense_graph_shortest_path(dense_graph, 0, 6);
	dense_graph_shortest_path(dense_graph, 0, 3);

	return ;
}

void test_read_sparse_graph(const char* filename)
{	
	FILE *fp;
    sparse_graph_s* sparse_graph;
	char line[128];
	int V, E;


	fp = fopen(filename, "r");
	if(NULL == fp)
	{
		printf("fopen %s failed!\n",filename);
		return ;
	}

	fgets(line,sizeof(line),fp);
	sscanf(line,"%d %u",&V,&E);

    sparse_graph = sparse_graph_init(V, 0);
	if(NULL == sparse_graph)
	{
		abort();
	}

	int a,b;
	for( int i = 0 ; i < E ; i ++ )
	{
		fgets(line,sizeof(line),fp);
		sscanf(line,"%d %u",&a,&b);

		assert( a >= 0 && a < V );
		assert( b >= 0 && b < V );
		sparse_graph_add_edge(sparse_graph, a, b);
	}

	sparse_graph_print(sparse_graph);	
	printf("\n");
	sparse_graph_component(sparse_graph);
	printf("\n");
	sparse_graph_path(sparse_graph, 0, 6);

	sparse_graph_shortest_path(sparse_graph, 0, 6);
	sparse_graph_shortest_path(sparse_graph, 0, 3);

	return ;
}

void test_graph()
{
 //   int vertex = 20;
  //  int edge = 100;

    srand(time(NULL) );

	test_read_sparse_graph("/root/testG2.txt");
    printf("\n");
//	test_read_dense_graph("/root/testG1.txt");
	test_read_dense_graph("/root/testG2.txt");
	
	return ;
}

