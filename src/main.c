#include "../inc/minilibmx.h"


int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]");
        mx_printerr("\n");
        exit(1);
    }
    int rows = 0;
    int columns = 0;
    int len = 0;
    if (!mx_is_map_ok(argv[1])) exit(1);
    char *map_string = mx_file_to_str(argv[1]);
    char **arr = mx_array_to_2d(map_string, &rows, &columns);
    char **temp = mx_array_to_2d(map_string, &rows, &columns);
    if (!mx_is_argument_ok(argv[2])) exit(1);
    if (!mx_is_argument_ok(argv[3])) exit(1);
    if (!mx_is_argument_ok(argv[4])) exit(1);
    if (!mx_is_argument_ok(argv[5])) exit(1);
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);
    if (!mx_is_coordinates_ok(y1, y2, x1, x2, rows, columns)) exit(1);
    if (!mx_check_entry_point(arr, y1, x1)) exit(1);
    if (!mx_check_exit_point(arr, y2, x2)) exit(1);
    if (!mx_find_path(arr, temp, x1, y1, x2, y2, rows, columns, &len)) exit(1); 
    char **temp1 = mx_array_to_2d(map_string, &rows, &columns);
    int dist = mx_find_max_way(temp1, temp, x1,  y1, rows, columns);
    mx_printint(rows);
    mx_printchar('\n');
    mx_printint(columns);
    mx_print_res(dist, len); 
    mx_path_to_file(temp, rows, columns);
    free(map_string);
    map_string = NULL;
    mx_freeing_mem(arr, rows);
    mx_freeing_mem(temp, rows);
    mx_freeing_mem(temp1, rows);
    return 0;
}
