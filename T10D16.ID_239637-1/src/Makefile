TARGET1 = ../build/Quest_1
TARGET2 = ../build/Quest_2
TARGET3 = ../build/Quest_3
TARGET4 = ../build/Quest_4
TARGET5 = ../build/Quest_5
CC = gcc
SOURCES = s21_string.c s21_string_test.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

$(TARGET1): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
%.o: %.c    
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5)
rebuild: clean all
strlen_tests:     
	$(CC) -DSTRLEN_TEST $(CFLAGS) $(SOURCES) -o $(TARGET1)
strcmp_tests: 
	$(CC) -DSTRCMP_TEST $(CFLAGS) $(SOURCES) -o $(TARGET2)
strcpy_tests:     
	$(CC) -DSTRCPY_TEST $(CFLAGS) $(SOURCES) -o $(TARGET3)
strcat_tests: 
	$(CC) -DSTRCAT_TEST $(CFLAGS) $(SOURCES) -o $(TARGET4)
strchr_tests:     
	$(CC) -DSTRCHR_TEST $(CFLAGS) $(SOURCES) -o $(TARGET5)
