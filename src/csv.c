#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 1000
#define MAXN 50

char *trimwhitespace(char *s) {
    char *ptr;
    if (!s)
        return NULL;   // handle NULL string
    if (!*s)
        return s;      // handle empty string
    for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}

//  Usage of writeToCsv:
//  writeToCsv(n, websites, array, "test1.txt");
void writeToCsv(int n, char websites[MAXN][MAXCHAR], int array[n][n], char *fileName)
{
    FILE *fp;
    fp = fopen(fileName,"w");
    for(int i = 0; i<n; i++){
        fprintf(fp,",%s",websites[i]);
    }
    for(int i = 0; i<n; i++){
        fprintf(fp,"\n%s", trimwhitespace(websites[i]));
        for(int j = 0; j<n; j++){
            fprintf(fp,",%d",array[i][j]);
        }
    }
    fprintf(fp,"\n");
    fclose(fp);
}