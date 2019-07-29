#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__
#include "util.h"

typedef struct __dense_graph_ dense_graph_s;

dense_graph_s* dense_graph_init(int vertex_cnt,int directed);
void dense_graph_deinit(dense_graph_s*	dense_graph);

int dense_graph_e(dense_graph_s*	dense_graph);
int dense_graph_v(dense_graph_s*	dense_graph);

int dense_graph_has_edge(dense_graph_s*	dense_graph,int v,int w);
void dense_graph_add_edge(dense_graph_s*	dense_graph,int v,int w);

#endif //__DENSE_GRAPH_H__
