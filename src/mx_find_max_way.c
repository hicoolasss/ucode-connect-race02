#include "../inc/minilibmx.h"

int mx_find_max_way(char **arr, char **temp, int x1, int y1, int rows, int columns)
{
    const char free_space = '.';
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int x = 0;
    int y = 0;
    int k = 0;
    int d = 0;
    bool breakpoint = 1;
    bool stop = false;
    arr[y1][x1] = 48;
    while (!stop || breakpoint) {
        stop = true;
        for (y = 0; y < rows; y++)
            for (x = 0; x < columns; x++)
                if (arr[y][x] == d + 48) {
                    for (k = 0; k < 4; ++k) {
                        int iy = y + dy[k], ix = x + dx[k];
                        if (iy >= 0 
                        && iy < rows 
                        && ix >= 0 
                        && ix < columns 
                        && arr[iy][ix] == free_space) {
                            stop = false;
                            arr[iy][ix] = (d + 1) + 48;
                        }
                    }
                }
        d++;
        breakpoint = 0;
    }
    int dist = arr[0][0] - 48;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (dist < arr[i][j] - 48)
                dist = arr[i][j] - 48;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (arr[i][j] == dist + '0') {
                if (temp[i][j] == '*')
                    temp[i][j] = 'X';
                else
                    temp[i][j] = 'D';
            }
        }
    }
    return dist;
}
