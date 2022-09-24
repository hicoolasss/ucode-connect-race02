#include <stdlib.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
int mx_strlen(const char *s);
bool mx_isspace(char c);

char *mx_strtrim(const char *str) {
    int start = 0;
    int j = 0;
    int end = mx_strlen(str);
    if (str == NULL)
        return NULL;
    for (int i = 0; i < mx_strlen(str); i++)
        if (!mx_isspace(str[i])) {
            start = i;
            break;
        } 
    for (int i = mx_strlen(str) - 1; i >= start; i--)
        if (!mx_isspace(str[i])) {
            end = i;
            break;
        }
    int size = end - start + 2; 
    char *trm = mx_strnew(size);
    for(int i = start; i <= end; i++){
        trm[j] = str[i];
        j++;
    }
    return trm;
}
