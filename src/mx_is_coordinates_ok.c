#include "../inc/minilibmx.h"

bool mx_is_coordinates_ok(int x1, int x2, int y1, int y2, int rows, int columns) {
    if (x1 >= rows || x2 >= rows) {
        mx_printerr("points are out of map range\n");
        return false;
    } else if (y1 >= columns || y2 >= columns) {
        mx_printerr("points are out of map range\n");
        return false;
    } else return true;
}
