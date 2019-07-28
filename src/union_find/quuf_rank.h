#ifndef __QUCK_UNION_UF_RANK_H__
#define __QUCK_UNION_UF_RANK_H__
#include "util.h"

typedef struct ___quuf_rank_ quuf_rank_s;
quuf_rank_s* quuf_rank_init(int n);
void quuf_rank_deinit(quuf_rank_s* quuf_rank);

int quuf_rank_find(quuf_rank_s* quuf_rank,int p);
void quuf_rank_union(quuf_rank_s* quuf_rank,int p,int q);

int quuf_rank_isconnected(quuf_rank_s* quuf_rank,int p,int q);

#endif //__QUCK_UNION_UF_RANK_H__
