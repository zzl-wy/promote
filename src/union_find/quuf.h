#ifndef __QUCK_UNION_UF_H__
#define __QUCK_UNION_UF_H__
#include "util.h"

typedef struct ___quuf__ quuf_s;
quuf_s* quuf_init(int n);
void quuf_deinit(quuf_s* quuf);

int quuf_find(quuf_s* quuf,int p);
void quuf_union(quuf_s* quuf,int p,int q);

int quuf_isconnected(quuf_s* quuf,int p,int q);

#endif //__QUCK_UNION_UF_H__
