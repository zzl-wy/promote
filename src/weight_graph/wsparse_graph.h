#ifndef __WSPARSE_GRAPH_H__
#define __WSPARSE_GRAPH_H__
#include "util.h"

typedef struct __wsgraph_ wsgraph_s;
wsgraph_s* wsgraph_init(int vertex_cnt,int directed);
void wsgraph_deinit(wsgraph_s*	wsgraph);

int wsgraph_e(wsgraph_s*	wsgraph);
int wsgraph_v(wsgraph_s*	wsgraph);

int wsgraph_has_edge(wsgraph_s*	wsgraph,int v,int w);
void wsgraph_add_edge(wsgraph_s*	wsgraph,int v,int w,double weigth);

void wsgraph_print(wsgraph_s*	wsgraph);

#endif //__WSPARSE_GRAPH_H__
