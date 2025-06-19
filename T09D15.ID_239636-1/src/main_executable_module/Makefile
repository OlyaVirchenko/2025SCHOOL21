# Папки и имена
NAME := Quest_3
BUILD_DIR := ../../build
SRC_DIR := .
CC := gcc
CFLAGS := -Wall -Werror -Wextra -std=c11
# SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS := main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c sort.c ../yet_another_decision_module/decision.c
OBJS := $(SRCS:.c=.o)
TARGET := $(BUILD_DIR)/$(NAME)

.PHONY: all clean rebuild

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)    
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:    
	rm -f $(SRC_DIR)/*.o
	rm -f $(TARGET)
rebuild: clean all
