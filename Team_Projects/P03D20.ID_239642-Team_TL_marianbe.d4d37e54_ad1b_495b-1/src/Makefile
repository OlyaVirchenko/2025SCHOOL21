BUILD_DIR = ../build
SRC_DIR = .
TARGET = $(BUILD_DIR)/graph

CC = gcc
CFLAGS = -Wextra -Wall -Werror -std=c11

SOURCES = $(SRC_DIR)/graph.c $(SRC_DIR)/stack.c $(SRC_DIR)/validation.c $(SRC_DIR)/rpn.c
OBJECTS = $(SOURCES:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) -lm

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

rebuild: clean all

style:
	clang-format -n $(SRC_DIR)/*.c $(SRC_DIR)/*.h

add_style:
	clang-format -i $(SRC_DIR)/*.c $(SRC_DIR)/*.h

check:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC_DIR)/

leaks: $(TARGET)
	leaks -atExit -- $(TARGET)

run: $(TARGET)
	./$(TARGET)