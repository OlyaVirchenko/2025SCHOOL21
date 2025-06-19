#include <stdio.h>
#include <string.h>

#define MAX 512
#define MAX_INPUT 1024

// Чтение и вывод содержимого файла
int read_file(const char* file_path) {
    int error_flag = 0;
    int error_empty = 0;
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        error_flag = 1;
    } else {
        // int ch;
        error_empty = 1;

        if (error_empty) {
            error_flag = 1;
        } else {
            printf("\n");
        }

        fclose(file);
    }
    return error_flag;
}

// Печать содержимого файла
int print_file(const char* file_path) {
    int error_flag = 0;
    FILE* file = fopen(file_path, "r");

    if (!file) {
        error_flag = 1;
    }

    char buffer[MAX_INPUT];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
    // printf("\n");

    return error_flag;
}

// Добавление текста в файл
int append_text(const char* file_path) {
    int error_flag = 0;

    // Проверяем существует ли файл и доступен ли для чтения
    FILE* test = fopen(file_path, "r");
    if (!test) {
        error_flag = 1;
    } else {
        char input[MAX_INPUT];
        // Открываем для добавления
        FILE* file = fopen(file_path, "a");
        if (file == NULL) {
            error_flag = 1;
        } else {
            if (!fgets(input, sizeof(input), stdin)) {
                // printf("n/a\n");

                fclose(file);
                error_flag = 1;
            } else {
                // Удаляем символ перевода строки, если он есть
                input[strcspn(input, "\n")] = '\0';
                fprintf(file, "%s", input);
            }
            fclose(file);
        }
        fclose(file);
        return error_flag;
    }

    return error_flag;
}

int main() {
    int work_flag = 1;
    char file_path[MAX];

    int result;
    while (scanf("%d", &work_flag) == 1) {
        if (work_flag == -1) {
            break;
        } else if (work_flag == 1) {
            scanf("%511s", file_path);

            result = read_file(file_path);
            if (result == 1) {
                printf("n/a\n");
                continue;
            }
        } else if (work_flag == 2) {
            getchar();
            result = append_text(file_path);
            if (result == 1) {
                printf("n/a\n");
                continue;
            }
            print_file(file_path);
        }
    }
}