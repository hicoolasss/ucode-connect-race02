#include "../inc/minilibmx.h"

void mx_print_res(int dist, int len) {
    mx_printstr("dist=");
    mx_printint(dist);
    mx_printstr("\n");
    mx_printstr("exit=");
    mx_printint(len);
    mx_printstr("\n");
}
