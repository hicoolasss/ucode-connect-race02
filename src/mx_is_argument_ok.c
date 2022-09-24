#include "../inc/minilibmx.h"

bool mx_is_argument_ok(const char *argument) {
    for (int i = 0; argument[i]; i++) {
        if (!mx_isdigit(argument[i]) && !mx_isspace(argument[i])) {
            mx_printerr("error\n");   
            return false;
        }
    }
    return true;
}
