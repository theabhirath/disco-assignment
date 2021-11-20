#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHAR 1000
#define MAXN 50

char *trimwhitespace(char *str);
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char * filename);
int main(void){
    FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("../SampleInput.csv", "r");
    char websites [MAXN][MAXCHAR];
    int n = 0;
    int count = 0;
    //  Reading the websites to websites[i]
    if (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        n = 1;
        for(int i = 0; row[i] != EOF; i++)
        {
            if(row[i] == ',' && i!=0){
                n++;
            }
        }
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL && i <n)
        {
            strcpy(websites[i], token);
            token = strtok(NULL, ",");
            i++;
        }
    }
    // array stores the 0-1 matrix of the given relation
    int array[n][n];
    memset(array, 0 , n*n*sizeof(int));
    // printf("n = %d\n", n);
    for (int i = 0; i < n; i++)
    {
        char * ptr = websites[i];
        strcpy(websites[i], trimwhitespace(ptr));
        printf("%s\n", websites[i]);
    }
    // Reading the 0-1 matrix
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);

        token = strtok(row, ",");
        int i;
        // Checking which website index(i) is the current row
        for(i = 0; i<n; i++){
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
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    
}


//  Usage of writeToCsv:
//  writeToCsv(n, websites, array, "test1.txt");
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char * filename)
{
    FILE *fp;
    fp = fopen(filename,"w");
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

// Credits to Adam Rosenfield for his implementation of trim in C https://stackoverflow.com/a/122721
char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) 
    str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}
