#include "../inc/minilibmx.h"

void mx_freeing_mem(char **arr, int rows) {
    for (int i = 0; i < rows; i++)
        free(arr[i]);
    free(arr);
    arr = NULL;
}
