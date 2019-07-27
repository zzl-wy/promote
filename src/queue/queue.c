#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"

typedef struct _qnode_
{
    int e;
    struct _qnode_* next;
}qnode_s;

typedef struct __queue__
{
    qnode_s* front;
    qnode_s* rear;
}queue_s;

//初始化空队列
queue_s* queue_init(void)
{
	queue_s* q = malloc0(sizeof(queue_s));
	
    q->front=q->rear=(qnode_s *)malloc0(sizeof(qnode_s));
    q->front->next=NULL;
}

void queue_push(queue_s *q,int e)
{
    qnode_s* node;

	node = malloc0(sizeof(qnode_s));
    node->e = e;
    node->next = NULL;
    q->rear->next=node;
    q->rear=node;
}

void queue_pop(queue_s *q)
{
    qnode_s* node;

    if(q->front == q->rear)
	{	
		return ;
    }
	
    node = q->front->next;

    q->front->next = node->next;
    if(q->rear == q)
    {
		q->rear=q->front;
	}
	
    free(node);
    return;

}


int queue_front(queue_s *q)
{
    if(q->front == q->rear)
    {
		return -1;
	}
	
    qnode_s node = q->front->next;
    return node->e;
}

int queue_empty(queue_s *q)
{
    return q->front == q->rear ? 1 : 0;
}

