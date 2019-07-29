CC = gcc
CFLAGS += $(CPUFLAG) $(CPUFLAG1) -std=gnu99 -Wall -g -I ./src/public/

#定义路径
BASE = /opt/promote/
BIN = $(BASE)/bin/
OBJ = $(BASE)/obj/
SRC = ./src/

mainObj = $(OBJ)main.o

OBJ_SORT = $(OBJ)/sort/
SRC_SORT = $(SRC)/sort/
sortObj = \
	$(OBJ_SORT)sort.o\
	$(OBJ_SORT)sort_util.o\
	$(OBJ_SORT)select_sort.o\
	$(OBJ_SORT)quick_sort.o\
	$(OBJ_SORT)insert_sort.o\
	$(OBJ_SORT)shell_sort.o\
	$(OBJ_SORT)merge_sort.o\
	$(OBJ_SORT)heap_sort.o\
	$(OBJ_SORT)bubble_sort.o

OBJ_HEAP = $(OBJ)/heap/
SRC_HEAP = $(SRC)/heap/
heapObj = \
	$(OBJ_HEAP)heap.o\
	$(OBJ_HEAP)index_heap.o\
	$(OBJ_HEAP)heap_test.o

OBJ_BST = $(OBJ)/bst/
SRC_BST = $(SRC)/bst/
bstObj = \
	$(OBJ_BST)bst.o\
	$(OBJ_BST)queue.o\
	$(OBJ_BST)bst_test.o

OBJ_UF = $(OBJ)/union_find/
SRC_UF = $(SRC)/union_find/
ufObj = \
	$(OBJ_UF)quuf.o\
	$(OBJ_UF)quuf_count.o\
	$(OBJ_UF)quuf_rank.o\
	$(OBJ_UF)qfuf.o\
	$(OBJ_UF)uf_test.o

OBJ_UTIL = $(OBJ)/util/
SRC_UTIL = $(SRC)/util/
utilObj = \
	$(OBJ_UTIL)util.o

#############################入口#########################	
all:\
	mkdir\
	$(BIN)promote
	

#############################建立目录########################	
mkdir:
	test -d $(BIN) || mkdir -p $(BIN)
	test -d $(OBJ) || mkdir -p $(OBJ)
	test -d $(OBJ_SORT) || mkdir -p $(OBJ_SORT)
	test -d $(OBJ_HEAP) || mkdir -p $(OBJ_HEAP)
	test -d $(OBJ_UTIL) || mkdir -p $(OBJ_UTIL)
	test -d $(OBJ_BST) || mkdir -p $(OBJ_BST)
	test -d $(OBJ_UF) || mkdir -p $(OBJ_UF)
	
#############################清理文件########################
.PHONY : clean
clean:
	rm -rf $(OBJ)*
	rm -rf $(BIN)*	
	
#############################生成执行文件#########################
$(BIN)promote:$(mainObj) $(utilObj) $(heapObj) $(sortObj) $(bstObj) $(ufObj)
	$(CC) $(CFLAGS) $(mainObj) $(utilObj) $(heapObj) $(sortObj) $(bstObj) $(ufObj) -o $(BIN)promote

####################main.o##########################
$(OBJ)main.o:\
	$(SRC)main.c 
	$(CC) $(CFLAGS) -fPIC -c $(SRC)main.c -o $(OBJ)main.o

####################UTIL模块##########################
$(OBJ_UTIL)util.o:\
	$(SRC_UTIL)util.c
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UTIL)util.c -o $(OBJ_UTIL)util.o

####################UF模块##########################
$(OBJ_UF)quuf.o:\
	$(SRC_UF)quuf.c\
	$(SRC_UF)quuf.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UF)quuf.c -o $(OBJ_UF)quuf.o

$(OBJ_UF)quuf_count.o:\
	$(SRC_UF)quuf_count.c\
	$(SRC_UF)quuf_count.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UF)quuf_count.c -o $(OBJ_UF)quuf_count.o

$(OBJ_UF)quuf_rank.o:\
	$(SRC_UF)quuf_rank.c\
	$(SRC_UF)quuf_rank.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UF)quuf_rank.c -o $(OBJ_UF)quuf_rank.o

$(OBJ_UF)qfuf.o:\
	$(SRC_UF)qfuf.c\
	$(SRC_UF)qfuf.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UF)qfuf.c -o $(OBJ_UF)qfuf.o

$(OBJ_UF)uf_test.o:\
	$(SRC_UF)uf_test.c
	$(CC) $(CFLAGS) -fPIC -c $(SRC_UF)uf_test.c -o $(OBJ_UF)uf_test.o

####################BST模块##########################
$(OBJ_BST)bst.o:\
	$(SRC_BST)bst.c\
	$(SRC_BST)bst.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_BST)bst.c -o $(OBJ_BST)bst.o

$(OBJ_BST)bst_test.o:\
	$(SRC_BST)bst_test.c\
	$(SRC_BST)bst.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_BST)bst_test.c -o $(OBJ_BST)bst_test.o

$(OBJ_BST)queue.o:\
	$(SRC_BST)queue.c\
	$(SRC_BST)queue.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_BST)queue.c -o $(OBJ_BST)queue.o

####################HEAP模块##########################
$(OBJ_HEAP)heap.o:\
	$(SRC_HEAP)heap.c\
	$(SRC_HEAP)heap.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_HEAP)heap.c -o $(OBJ_HEAP)heap.o

$(OBJ_HEAP)index_heap.o:\
	$(SRC_HEAP)index_heap.c\
	$(SRC_HEAP)heap.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_HEAP)index_heap.c -o $(OBJ_HEAP)index_heap.o

$(OBJ_HEAP)heap_test.o:\
	$(SRC_HEAP)heap_test.c\
	$(SRC_HEAP)heap.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_HEAP)heap_test.c -o $(OBJ_HEAP)heap_test.o
	

####################SORT模块##########################
$(OBJ_SORT)sort.o:\
	$(SRC_SORT)sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)sort.c -o $(OBJ_SORT)sort.o

$(OBJ_SORT)sort_util.o:\
	$(SRC_SORT)sort_util.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)sort_util.c -o $(OBJ_SORT)sort_util.o
	
$(OBJ_SORT)bubble_sort.o:\
	$(SRC_SORT)bubble_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)bubble_sort.c -o $(OBJ_SORT)bubble_sort.o

$(OBJ_SORT)insert_sort.o:\
	$(SRC_SORT)insert_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)insert_sort.c -o $(OBJ_SORT)insert_sort.o

$(OBJ_SORT)merge_sort.o:\
	$(SRC_SORT)merge_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)merge_sort.c -o $(OBJ_SORT)merge_sort.o

$(OBJ_SORT)shell_sort.o:\
	$(SRC_SORT)shell_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)shell_sort.c -o $(OBJ_SORT)shell_sort.o

$(OBJ_SORT)select_sort.o:\
	$(SRC_SORT)select_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)select_sort.c -o $(OBJ_SORT)select_sort.o

$(OBJ_SORT)quick_sort.o:\
	$(SRC_SORT)quick_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)quick_sort.c -o $(OBJ_SORT)quick_sort.o

$(OBJ_SORT)heap_sort.o:\
	$(SRC_SORT)heap_sort.c\
	$(SRC_SORT)sort.h
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)heap_sort.c -o $(OBJ_SORT)heap_sort.o
