CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

BUILD_DIR = ../build
TARGET = $(BUILD_DIR)/cipher

.PHONY: all clean cipher

all: cipher

cipher:
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) cipher.c -o $(TARGET)

clean:
	rm -rf $(BUILD_DIR)