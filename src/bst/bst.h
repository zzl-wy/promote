#ifndef __BST_H__
#define __BST_H__
#include "util.h"

typedef struct __bst_desc__ bst_desc_s;

bst_desc_s* bst_init(void);
void bst_destroy(bst_desc_s*	bst_desc);

int bst_size(bst_desc_s*	bst_desc);	
int bst_isempty(bst_desc_s*	bst_desc);

void bst_insert(bst_desc_s*	bst_desc,int key,int value);
int bst_contain(bst_desc_s* bst_desc,int key);
int* bst_search(bst_desc_s*	bst_desc,int key);
#endif //__BST_H__
