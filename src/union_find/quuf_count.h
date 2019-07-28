#ifndef __QUCK_UNION_UF2_H__
#define __QUCK_UNION_UF2_H__
#include "util.h"

typedef struct ___quuf_count__ quuf_count_s;
quuf_count_s* quuf_count_init(int n);
void quuf_count_deinit(quuf_count_s* quuf_count);

int quuf_count_find(quuf_count_s* quuf_count,int p);
void quuf_count_union(quuf_count_s* quuf_count,int p,int q);

int quuf_count_isconnected(quuf_count_s* quuf_count,int p,int q);

#endif //__QUCK_UNION_UF2_H__