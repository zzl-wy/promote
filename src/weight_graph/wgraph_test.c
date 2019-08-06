#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "wsparse_graph.h"

void test_wsparse_graph(void)
{
	int vertex = 5;
	int edge = 5;

	wsgraph_s* wsgraph = wsgraph_init(vertex, 0);
	if(NULL == wsgraph)
	{
		abort();
	}

    for( int i = 0 ; i < edge ; i ++ )
	{
        int a = rand()%vertex;
        int b = rand()%vertex;

		wsgraph_add_edge(wsgraph, a, b,1.2);
    }


	wsgraph_print(wsgraph);
	return ;
}

void test_read_wsparse_graph(const char* filename)
{	
	FILE *fp;
    wsgraph_s* wsgraph;
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

    wsgraph = wsgraph_init(V, 0);
	if(NULL == wsgraph)
	{
		abort();
	}

	int a,b;
	double weight;
	for( int i = 0 ; i < E ; i ++ )
	{
		fgets(line,sizeof(line),fp);
		sscanf(line,"%d %u %lf",&a,&b,&weight);

		assert( a >= 0 && a < V );
		assert( b >= 0 && b < V );
		wsgraph_add_edge(wsgraph, a, b,weight);
	}

	wsgraph_print(wsgraph);	
	return ;
}

void test_wgraph()
{
    srand(time(NULL) );
//	test_wsparse_graph();

	test_read_wsparse_graph("/root/testWG1.txt");
	
	return ;
}

