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
//  readFromCsv(char *filename, int *numberOfRows, char arrayofWebsites[MAXN][MAXCHAR]);
int **readFromCsv(char *filename, int *n, char websites[MAXN][MAXCHAR]){
    char row[MAXCHAR];
    char *token;

    FILE *fp = fopen(filename, "r");
    char delimit[] = ",\n";
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
        token = strtok(row, delimit);
        int i = 0;
        while(token != NULL && i < *n)
        {
            strcpy(websites[i], token);
            token = strtok(NULL, delimit);
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

        token = strtok(row, delimit);
        int i;
        // Checking which website index(i) is the current row
        for(i = 0; i < *n; i++){
            if(strncmp(token, websites[i], 
            strlen(token) < strlen(websites[i])?strlen(token):strlen(websites[i])) == 0){
                break;
            }
        }
        token = strtok(NULL, delimit);
        int j = 0;
        // Reading the 1's
        while(token != NULL)
        {
            array[i][j] = (strchr(token,'1') != NULL);
            token = strtok(NULL, delimit);
            j++;
        }
    }
    fclose(fp);
    return array;
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

void freeArray(int **array, int n){
    for(int i = 0; i<n; i++){
        free(array[i]);
    }
    free(array);
}

// int main(void)
// {
//     int n = 0;
//     char websites[MAXN][MAXCHAR];
//     int **arr = readFromCsv("../SampleInput.csv", &n, websites);

//     // convert the double pointer to an array
//     int array[n][n];
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<n; j++){
//             array[i][j] = arr[i][j];
//         }
//     }
//     // print the array
//     for (int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             printf("%d ", array[i][j]);
//         }
//         printf("\n");
//     }

//     // write the array to a file
//     writeToCsv(n, websites, array, "../outputs/test1.csv");
    
//     freeArray(arr, n);
//     return 0;
// }