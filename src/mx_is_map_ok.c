#include "../inc/minilibmx.h"

bool mx_is_map_ok(char *filename)
{
    int size = 0;
    int temp_size = 0;
    bool f_line = 1;
    int row_f = 0;
    int row_a = 0;
    char c;
    int file = open(filename, O_RDONLY);
    if (file < 0) { // no such file
        mx_printerr("map does not exist\n");
        return false;
    }
    while (read(file, &c, 1)) {
        size++;
        if (c != '\n') {
            if (f_line == 1)
                row_f += 1;
            else
                row_a += 1;
        } else {
            if (f_line == 0)
                if (row_f != row_a) {
                    mx_printerr("map error\n");
                    return false;
                }
            row_a = 0;
            f_line = 0;
        }
    }
    close(file);
    file = open(filename, O_RDONLY);
    while (read(file, &c, 1)) {
        if (c == '#' || c == '.' || c == '\n' || c == ',')
            temp_size++;
    }
    close(file);
    if (size != temp_size) { // forb c
        mx_printerr("map error\n");
        return false;
    } else if (size == 0) { // empty file
        mx_printerr("map does not exist\n");
        return false;
    }
    return true;
}
