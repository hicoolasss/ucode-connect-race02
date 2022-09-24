#pragma once
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);
bool mx_is_map_ok(char *filename);
bool mx_is_argument_ok(const char *argument);
bool mx_is_coordinates_ok(int x1, int x2, int y1, int y2, int rows, int columns);
bool mx_check_entry_point(char **arr, int x1, int y1);
bool mx_check_exit_point(char **arr, int x2, int y2);
bool mx_find_path(char **arr, char **temp, int x1, int y1, int x2, int y2, int rows, int columns, int *length);


void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
void mx_strdel(char **str);
void mx_path_to_file(char **temp, int rows, int columns);
void mx_print_res(int dist, int len);
void mx_freeing_mem(char **arr, int rows);


int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
int mx_atoi(const char *str);
int mx_strncmp(const char *s1, const char *s2, int n);
int mx_find_max_way(char **arr, char **temp, int x1, int y1, int rows, int columns);


char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int n);
char *mx_strtrim(const char *str);
char *mx_file_to_str(const char *filename);
char **mx_array_to_2d(char *string, int *rows, int *columns);
