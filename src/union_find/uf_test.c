#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "qfuf.h"
#include "quuf.h"

void test_qfuf_perfomance(int n);

void test_quuf_func(void);
void test_quuf_perfomance(int n);

void test_quuf_count_perfomance(int n);
void test_quuf_count_func(void);

void test_quuf_rank_func(void);
void test_quuf_rank_perfomance(int n);
void test_quuf_rank_pc_perfomance(int n);
void test_quuf_rank_pc_perfomance2(int n);

void test_union_find()
{
	int n = 1000000;
	
//	test_qfuf_perfomance(n);
	test_quuf_perfomance(n);
	test_quuf_count_perfomance(n);
	test_quuf_rank_perfomance(n);
	test_quuf_rank_pc_perfomance(n);
	test_quuf_rank_pc_perfomance2(n);

	exit(0);
}

