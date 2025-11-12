.PHONY: all clean

PROJ=$(abspath ..)
SRC_DIR=$(PROJ)/basic_ops/src
OBJ_DIR=$(PROJ)/basic_ops/obj
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib

CC=gcc
AR=ar

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))
TARGET=$(LIB_DIR)/libmybasic.a

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(LIB_DIR)
	$(AR) rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
