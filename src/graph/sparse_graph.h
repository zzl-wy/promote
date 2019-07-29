#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__
#include "util.h"

typedef struct __sparse_graph_ sparse_graph_s;

sparse_graph_s* sparse_graph_init(int vertex_cnt,int directed);
void sparse_graph_deinit(sparse_graph_s*	sparse_graph);

int sparse_graph_e(sparse_graph_s*	sparse_graph);
int sparse_graph_v(sparse_graph_s*	sparse_graph);

int sparse_graph_has_edge(sparse_graph_s*	sparse_graph,int v,int w);
void sparse_graph_add_edge(sparse_graph_s*	sparse_graph,int v,int w);

#endif //__SPARSE_GRAPH_H__