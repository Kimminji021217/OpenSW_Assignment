PROJ_DIR = $(shell PWD)
SRC_DIR = $(PROJ_DIR)/src
OBJ_DIR = $(PROJ_DIR)/obj
BIN_DIR = $(PROJ_DIR)/bin
INC_DIR = $(PROJ_DIR)/include
LIB_DIR = $(PROJ_DIR)/lib

CC = gcc
.PHONY: all clean

TARGET = $(BIN_DIR)/myapp
LIB = $(LIB_DIR)/libmyops

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS := $(subst $(SRC_DIR)/myapp.c, , $(SRCS))
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))
# OBJS = $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o 
# 	$(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymul.o
# 	$(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -c $< -o $@ -I$(INC_DIR)

$(LIB).so.1.0: $(OBJS) | $(LIB_DIR)
	$(CC) -shared -fPIC $^ -o $@
	ln -sf $(LIB).so.1.0 $(LIB).so.1
	ln -sf $(LIB).so.1 $(LIB).so

$(TARGET): $(LIB).so.1.0 $(SRC_DIR)/myapp.c
	$(CC) -o $(BIN_DIR)/myapp $(SRC_DIR)/myapp.c -L$(LIB_DIR) -lmyops -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(LIB_DIR)/*.so* $(TARGET)