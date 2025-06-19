#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_io_macro.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
#include "sort.h"

int main() {
    double *data;
    int n;

    printf("LOAD DATA...\n");
    INPUT_N(&data, &n);

    printf("RAW DATA:\n\t");
    OUTPUT(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    OUTPUT(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    OUTPUT(data, n);

    printf("\nFINAL DECISION:\n\t");

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}
