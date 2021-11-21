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

//  Usage of readFromCsv:
//  readFromCsv(*filePointer, int *numberOfRows, char arrayofWebsites[MAXN][MAXCHAR]);
int **readFromCsv(FILE *fp, int *n, char websites [MAXN][MAXCHAR]){
    char row[MAXCHAR];
    char *token;

    int count = 0;
    //  Reading the websites to websites[i]
    if (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        *n = 1;
        for(int i = 0; row[i] != EOF; i++)
        {
            if(row[i] == ',' && i != 0){
                (*n)++;
            }
        }
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL && i < *n)
        {
            strcpy(websites[i], token);
            token = strtok(NULL, ",");
            i++;
        }
    }
    
    // allocating memory for the array that stores the 0-1 matrix of the given relation
    int **array = malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++)
    {
        array[i] = malloc(*n * sizeof(int));
    }
    for (int i = 0; i < *n; i++)
    {
        for(int j = 0; j < *n; j++){
            array[i][j] = 0;
        }
    }
    for (int i = 0; i < *n; i++)
    {
        char *ptr = websites[i];
        ptr = trimwhitespace(ptr);
    }
    // Reading the 0-1 matrix
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);

        token = strtok(row, ",");
        int i;
        // Checking which website index(i) is the current row
        for(i = 0; i < *n; i++){
            if(strncmp(token, websites[i], 
            strlen(token) < strlen(websites[i])?strlen(token):strlen(websites[i])) == 0){
                break;
            }
        }
        token = strtok(NULL, ",");
        int j = 0;
        // Reading the 1's
        while(token != NULL)
        {
            array[i][j] = (strchr(token,'1') != NULL);
            token = strtok(NULL, ",");
            j++;
        }
    }
    return array;
}

//  Usage of writeToCsv:
//  writeToCsv(n, websites, array, "test1.txt");
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char *fileName)
{
    FILE *fp;
    fp = fopen(fileName,"w");
    for(int i = 0; i<n; i++){
        fprintf(fp,",%s",websites[i]);
    }
    for(int i = 0; i<n; i++){
        fprintf(fp,"\n%s", websites[i]);
        for(int j = 0; j<n; j++){
            fprintf(fp, ",%d",array[i][j]);
        }
    }
    fprintf(fp,"\n");
}

void freeArray(int **array, int n){
    for(int i = 0; i<n; i++){
        free(array[i]);
    }
    free(array);
}