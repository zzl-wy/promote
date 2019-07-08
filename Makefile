CC = gcc
CFLAGS += $(CPUFLAG) $(CPUFLAG1) -std=gnu99 -Wall -g 

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
	$(OBJ_SORT)bubble_sort.o

#############################入口#########################	
all:\
	mkdir\
	$(BIN)promote
	

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
$(BIN)promote:$(mainObj) $(sortObj)
	$(CC) $(CFLAGS) $(mainObj) $(sortObj) -o $(BIN)promote

####################main.o##########################
$(OBJ)main.o:\
	$(SRC)main.c 
	$(CC) $(CFLAGS) -fPIC -c $(SRC)main.c -o $(OBJ)main.o

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
