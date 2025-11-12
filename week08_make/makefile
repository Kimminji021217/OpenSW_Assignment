PROJ_DIR = $(shell pwd)
SRC_DIR  = $(PROJ_DIR)/src
INC_DIR  = $(PROJ_DIR)/include
BIN_DIR  = $(PROJ_DIR)/bin
OBJ_DIR  = $(PROJ_DIR)/obj
LIB_DIR  = $(PROJ_DIR)/lib

CC = gcc
AR = ar

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

TARGET = $(BIN_DIR)/myapp
LIB = $(LIB_DIR)/libmybasic.a

.PHONY: all clean make_basic

all: $(TARGET)

$(TARGET): $(LIB) $(OBJ_DIR)/myapp.o
	$(CC) -o $@ $(OBJ_DIR)/myapp.o -L$(LIB_DIR) -lmybasic -I$(INC_DIR)

basic: $(LIB)

$(LIB): $(OBJ_DIR)/add.o $(OBJ_DIR)/sub.o $(OBJ_DIR)/mul.o $(OBJ_DIR)/div.o
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/*.a $(TARGET)
