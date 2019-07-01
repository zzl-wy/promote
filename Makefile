CC = gcc
CFLAGS += $(CPUFLAG) $(CPUFLAG1) -std=gnu99 -Wall -g 

#定义路径
BASE = ./
BIN = ./bin/
OBJ = ./obj/
SRC = ./

OBJ_SORT = $(OBJ)/
SRC_SORT = $(SRC)
sortObj = \
	$(OBJ_SORT)sort.o

#############################入口#########################	
all:\
	mkdir\
	$(BIN)sorttest
	

#############################建立目录########################	
mkdir:
	test -d $(BIN) || mkdir -p $(BIN)
	test -d $(OBJ) || mkdir -p $(OBJ)
	test -d $(OBJ_SORT) || mkdir -p $(OBJ_SORT)

#############################清理文件########################
.PHONY : clean
clean:
	rm -rf $(OBJ)*
	rm -rf $(BIN)*	
	
#############################生成执行文件#########################

$(BIN)sorttest:$(sortObj)
	$(CC) $(CFLAGS) $(sortObj) -o $(BIN)sorttest

$(OBJ_SORT)sort.o:\
	$(SRC_SORT)sort.c 
	$(CC) $(CFLAGS) -fPIC -c $(SRC_SORT)sort.c -o $(OBJ_SORT)sort.o
