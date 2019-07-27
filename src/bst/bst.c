#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bst.h"

typedef struct __bst_node_
{
	int key;
	int value;

	struct __bst_node_* left;
	struct __bst_node_* right;	
}bst_node_s;


typedef struct __bst_desc__
{
    bst_node_s *root;
    int count;
}bst_desc_s;

bst_desc_s* bst_init(void)
{
	bst_desc_s*	bst_desc;

	bst_desc = malloc(sizeof(bst_desc_s));
	if(NULL == bst_desc)
	{
		return NULL;
	}

	bst_desc->root = NULL;
	bst_desc->count = 0;
	return bst_desc;
}

//后序遍历递归删除BST树的节点
void __bst_destroy(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return ;
	}

	__bst_destroy(bst_desc,node->left);
	__bst_destroy(bst_desc,node->right);
	safe_free(node);;

	return ;
}

void bst_destroy(bst_desc_s*	bst_desc)
{
	__bst_destroy(bst_desc, bst_desc->root);
}

int bst_size(bst_desc_s*	bst_desc)
{
	return bst_desc->count;
}

int bst_isempty(bst_desc_s*	bst_desc)
{
	return bst_desc->count == 0;
}

static bst_node_s* create_bst_node(int key,int value)
{
	bst_node_s* bst_node = malloc0(sizeof(bst_node_s));

	bst_node->key = key;
	bst_node->value = value;

	return bst_node;
}

static bst_node_s* _bst_insert(bst_desc_s*	bst_desc,bst_node_s* node,int key,int value)
{
	if(NULL == node)
	{
		bst_desc->count++;
		return create_bst_node(key, value);
	}
	
	if(node->key == key)
	{
		node->value = value;
	}
	else if(node->key > key)
	{
		node->left = _bst_insert(bst_desc, node->left, key, value);
	}
	else
	{
		node->right = _bst_insert(bst_desc, node->right, key, value);
	}

	return node;
}

void bst_insert(bst_desc_s*	bst_desc,int key,int value)
{
	bst_desc->root = _bst_insert(bst_desc,bst_desc->root,key,value);
	printf("bst_insert[%d] key=%d,value=%d\n",bst_desc->count,key,value);
}

static int __bst_contain(bst_desc_s*	bst_desc,bst_node_s* node,int key)
{
	int ret;
	
	if(NULL == node)
	{
		return 0;
	}

	if(node->key == key)
	{
		return 1;
	}
	else if(node->key > key)
	{
		ret = __bst_contain(bst_desc, node->left, key);
	}
	else
	{
		ret = __bst_contain(bst_desc, node->right, key);
	}

	return ret;
}

int bst_contain(bst_desc_s*	bst_desc,int key)
{
	return __bst_contain(bst_desc, bst_desc->root, key);
}

static bst_node_s* __bst_search(bst_desc_s*	bst_desc,bst_node_s* node,int key)
{
	bst_node_s* ret;
	
	if(NULL == node)
	{
		return NULL;
	}

	if(node->key == key)
	{
		ret = node;
	}
	else if(node->key > key)
	{
		ret = __bst_search(bst_desc, node->left, key);
	}
	else
	{
		ret = __bst_search(bst_desc, node->right, key);
	}

	return ret;

}

int* bst_search(bst_desc_s*	bst_desc,int key)
{
	bst_node_s* bst_node;

	bst_node = __bst_search(bst_desc, bst_desc->root,key);
	if(NULL ==  bst_node)
	{
		return NULL;
	}

	return &bst_node->value;
}

//先序遍历
void __bst_preorder(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return ;
	}

	printf("%d ",node->key);
	__bst_preorder(bst_desc,node->left);
	__bst_preorder(bst_desc,node->right);

	return ;
}

void bst_preorder(bst_desc_s*	bst_desc)
{
	printf("preorder:");
	__bst_preorder(bst_desc, bst_desc->root);
	printf("\n");
}

//中序遍历
void __bst_inorder(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return ;
	}

	__bst_inorder(bst_desc,node->left);
	printf("%d ",node->key);
	__bst_inorder(bst_desc,node->right);

	return ;
}

void bst_inorder(bst_desc_s*	bst_desc)
{
	printf("inorder:");
	__bst_inorder(bst_desc, bst_desc->root);	
	printf("\n");
}

//后序遍历
void __bst_postorder(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return ;
	}

	__bst_postorder(bst_desc,node->left);
	__bst_postorder(bst_desc,node->right);
	printf("%d ",node->key);

	return ;
}
void bst_postorder(bst_desc_s*	bst_desc)
{
	printf("postorder:");
	__bst_postorder(bst_desc, bst_desc->root);	
	printf("\n");
}

//bst层序遍历需要借助一个队列
#include "queue.h"

void bst_levelorder(bst_desc_s*	bst_desc)
{
	queue_s* q = queue_init();	
    bst_node_s *node;

	if(bst_desc->root == NULL)
	{
		return ;
	}

	printf("levelorder:");
	queue_push(q,bst_desc->root);	
	while(!queue_empty(q))
	{
		node = queue_front(q);
		printf("%d ",node->key);
		queue_pop(q);

		if(node->left)
		{
			queue_push(q,node->left);	
		}
		if(node->right)
		{
			queue_push(q,node->right);
		}
	}

	queue_deinit(q);
	printf("\n");
	return ;
}

//删除最小值
static bst_node_s * __bst_removemin(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return NULL;
	}

	if(NULL != node->left)
	{
		node->left = __bst_removemin(bst_desc, node->left);
		return node;
	}
	else
	{
		bst_node_s *node_right;
		
		node_right = node->right;
		bst_desc->count--;
		free(node);
		return node_right;
	}
}

void bst_removemin(bst_desc_s*	bst_desc)
{
	bst_desc->root = __bst_removemin(bst_desc, bst_desc->root);
	return ;
}

//删除最大值
static bst_node_s * __bst_removemax(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return NULL;
	}

	if(NULL != node->right)
	{
		node->right = __bst_removemax(bst_desc, node->right);
		return node;
	}
	else
	{
		bst_node_s *node_left;
		
		node_left = node->left;
		bst_desc->count--;
		free(node);
		return node_left;
	}
}

void bst_removemax(bst_desc_s*	bst_desc)
{
	bst_desc->root = __bst_removemax(bst_desc, bst_desc->root);
	return ;
}

//删除元素
static bst_node_s* __bst_minimun(bst_desc_s*	bst_desc,bst_node_s *node)
{
	if(NULL == node)
	{
		return NULL;
	}

	if(NULL == node->left)
	{
		return node;
	}

	return __bst_minimun(bst_desc,node->left);
}

static bst_node_s* __bst_remove(bst_desc_s*	bst_desc,bst_node_s *node,int key)
{
	if(key > node->key)
	{
		node->right = __bst_remove(bst_desc, node->right, key);
		return node;
	}
	else if(key < node->key)
	{
		node->left = __bst_remove(bst_desc, node->left, key);
		return node;
	}
	else//找到要删除的key
	{
		if(NULL == node->left)
		{
			bst_node_s* node_right;
			
			node_right = node->right;
			free(node);
			return node_right;
		}

		if(NULL == node->right)
		{
			bst_node_s* node_left;
			
			node_left = node->left;
			free(node);
			return node_left;
		}

		bst_node_s *min_node;
		bst_node_s *new_node;

		min_node = __bst_minimun(bst_desc, node->right);
		new_node = create_bst_node(min_node->key, min_node->value);
		bst_desc->count++;

		new_node->right = __bst_removemin(bst_desc,node->right);
		new_node->left = node->left;
		free(node);
		bst_desc->count--;

		return new_node;
	}
	


	return node;
}
void bst_remove(bst_desc_s*	bst_desc,int key)
{
	bst_desc->root = __bst_remove(bst_desc, bst_desc->root,key);
	return ;
}

