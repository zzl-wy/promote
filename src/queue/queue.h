#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "util.h"

typedef struct __queue__ queue_s;
queue_s* queue_init(void);
void queue_push(queue_s *q,int e);

void queue_pop(queue_s *q);
int queue_front(queue_s *q);
int queue_empty(queue_s *q);
#endif //__QUEUE_H__

