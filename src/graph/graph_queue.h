#ifndef __GRAPH_QUEUE_H__
#define __GRAPH_QUEUE_H__
#include "util.h"

typedef struct __graph_queue__ graph_queue_s;
typedef int Element;
graph_queue_s* graph_queue_init(void);
void graph_queue_deinit(graph_queue_s *q);

void graph_queue_push(graph_queue_s *q,Element e);
void graph_queue_pop(graph_queue_s *q);
Element graph_queue_front(graph_queue_s *q);
int graph_queue_empty(graph_queue_s *q);
#endif //__QUEUE_H__

