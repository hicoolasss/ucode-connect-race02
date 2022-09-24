#include "../inc/minilibmx.h"

char *mx_file_to_str(const char *filename) {
    int size = 0;
    int i = 0;
    char c;
    int file = open(filename, O_RDONLY);
    while (read(file, &c, 1)) {
        if (c == '#' || c == '.' || c == '\n')
            size++;
    }
    if (size == 0) return NULL;
    close(file);
    char *string = mx_strnew(size);
    file = open(filename, O_RDONLY);
    while (read(file, &c, 1)) {
        if (c == '#' || c == '.' || c == '\n') {
            string[i] = c;
            i++;
        }
    }
    string[size] = '\0';
    close(file);
    return string;
}
