#ifndef DATA_IO_H
#define DATA_IO_H

#define INPUT_N(data, n)                              \
    ({                                                \
        if (scanf("%d", n) != 1) {                    \
            return -1;                                \
        }                                             \
        *data = (double *)calloc(*n, sizeof(double)); \
        if (*data == NULL) {                          \
            return -1;                                \
        }                                             \
        for (int i = 0; i < *n; i++) {                \
            if (scanf("%lf", &(*data)[i]) != 1) {     \
                free(*data);                          \
                *data = NULL;                         \
                return -1;                            \
            }                                         \
        }                                             \
        0;                                            \
    })

#define OUTPUT(array, size)                   \
    ({                                        \
        if ((array) == NULL || (size) < 0) {  \
            return -1;                        \
        }                                     \
        for (size_t i = 0; i < (size); i++) { \
            printf("%.2lf", (array)[i]);      \
            if (i < (size) - 1) {             \
                printf(" ");                  \
            }                                 \
        }                                     \
        0;                                    \
    })

#endif