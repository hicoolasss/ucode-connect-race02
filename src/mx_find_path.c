#include "../inc/minilibmx.h"

bool mx_find_path(char **arr, char **temp, int x1, int y1, int x2, int y2, int rows, int columns, int *length)
{
    const char free_space = '.';
    int px[rows * columns], py[rows * columns];
    int len = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int x = 0;
    int y = 0;
    int k = 0;
    int d = 0;
    bool stop = false;
    arr[y1][x1] = 48;
    while (!stop && arr[y2][x2] == free_space) {
        stop = true;
        for (y = 0; y < rows; y++) {
            for (x = 0; x < columns; x++) {
                if (arr[y][x] == d + 48) {
                    for (k = 0; k < 4; k++) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 
                        && iy < rows 
                        && ix >= 0          //можешь поменять если хо
                        && ix < columns 
                        &&arr[iy][ix] == free_space) {
                            stop = false;
                            arr[iy][ix] = d + 1 + 48;
                        }
                    }
                }
            }
        }
    d++;
    }
    if (arr[y2][x2] == free_space) {
        mx_printerr("route not found\n");
        return false; 
    }
    len = arr[y2][x2] - 48;
    if (len <= 0) {
       mx_printerr("route not found\n");
       return false; 
    }
    x = x2;
    y = y2;
    d = len;
    while (d > 0) {
        px[d] = x;
        py[d] = y;
        d--;
        for (k = 0; k < 4; ++k) {
            int iy = y + dy[k], ix = x + dx[k];
            if (iy >= 0 
            && iy < rows 
            && ix >= 0      // это тоже
            && ix < columns 
            && arr[iy][ix] == d + 48) {
                x = x + dx[k];
                y = y + dy[k];
                break;
            }
        }
    }
    px[0] = x1;
    py[0] = y1;
    for (int i = 0; i < len ; ++i)
        temp[py[i]][px[i]] = '*';
    temp[y2][x2] = '*';
    *length = len;
    return true;
}
