#ifndef __QUICK_FIND_UF_H__
#define __QUICK_FIND_UF_H__
#include "util.h"

typedef struct _qfuf__ qfuf_s;
qfuf_s* qfuf_init(int n);
void qfuf_deinit(qfuf_s* qfuf);

int qfuf_find(qfuf_s* qfuf,int p);
void qfuf_union(qfuf_s* qfuf,int p,int q);

int qfuf_isconnected(qfuf_s* qfuf,int p,int q);

#endif //__QUICK_FIND_UF_H__