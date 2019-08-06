#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "graph_queue.h"

typedef struct _qnode_
{
    Element e;
    struct _qnode_* next;
}qnode_s;

typedef struct __graph_queue__
{
    qnode_s* front;
    qnode_s* rear;
}graph_queue_s;

//初始化空队列
graph_queue_s* graph_queue_init(void)
{
	graph_queue_s* q = malloc0(sizeof(graph_queue_s));
	
    q->front=q->rear=(qnode_s *)malloc0(sizeof(qnode_s));
    q->front->next=NULL;

	return q;
}

void graph_queue_push(graph_queue_s *q,Element e)
{
    qnode_s* node;

	node = malloc0(sizeof(qnode_s));
    node->e = e;
    node->next = NULL;
    q->rear->next=node;
    q->rear=node;
}

void graph_queue_pop(graph_queue_s *q)
{
    qnode_s* node;

    if(q->front == q->rear)
	{	
		return ;
    }
	
    node = q->front->next;

    q->front->next = node->next;
    if(q->front->next == NULL)
    {
		q->rear = q->front;
	}
	
    free(node);
    return;

}


Element graph_queue_front(graph_queue_s *q)
{
    if(q->front == q->rear)
    {
		return -1;
	}
	
    return q->front->next->e;
}

int graph_queue_empty(graph_queue_s *q)
{
    return q->front == q->rear ? 1 : 0;
}

void graph_queue_deinit(graph_queue_s *q)
{
	while(!graph_queue_empty(q))
	{
		graph_queue_pop(q);
	}
}

