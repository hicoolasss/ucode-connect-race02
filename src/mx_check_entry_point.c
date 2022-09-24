#include "../inc/minilibmx.h"

bool mx_check_entry_point(char **arr, int x1, int y1) {
    if (arr[x1][y1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        return false;
    } else return true;
}
