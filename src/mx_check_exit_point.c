#include "../inc/minilibmx.h"

bool mx_check_exit_point(char **arr, int x2, int y2) {
    if (arr[x2][y2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        return false;
    } else return true;
}
