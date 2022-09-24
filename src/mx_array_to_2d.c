#include "../inc/minilibmx.h"

char **mx_array_to_2d(char *string, int *rows, int *columns) {
    int i = 0;
    int j = 0;
    int k = 0;
    int n_rows = 0;
    int n_columns = 1; //error couse this
    for (i = 0; i < mx_strlen(string); i++) {
        if (string[i] == '\n')
            n_rows++;
    }
    for (int i = 0; string[i] != '\n'; i++)
       n_columns++;
    char **arr = (char**) malloc(n_rows * 8);
    for (i = 0; i < n_rows; i++)
       *(arr + i) = (char*) malloc(n_columns * 4);
    for (i = 0; i < n_rows; i++) {
        for (j = 0; j < n_columns; j++) {
            arr[i][j] = string[k];
                k++;
        }
    }
    *rows = n_rows;
    *columns = n_columns;
    return arr;
}
