#include "../inc/minilibmx.h"

void mx_path_to_file(char **temp, int rows, int columns) {
    int file = open("path.txt", O_WRONLY);
    if (file < 0)
        file = open("path.txt", O_TRUNC | O_CREAT | O_WRONLY | 0777);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            write(file, &temp[i][j], 1);
    }
}
