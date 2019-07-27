#ifndef __QUEUE_H__
#define __QUEUE_H__
#include "util.h"

typedef struct __queue__ queue_s;
typedef void* Element;
queue_s* queue_init(void);
void queue_deinit(queue_s *q);

void queue_push(queue_s *q,Element e);
void queue_pop(queue_s *q);
Element queue_front(queue_s *q);
int queue_empty(queue_s *q);
#endif //__QUEUE_H__

