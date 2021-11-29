// #define MAXCHAR 1000
// #define MAXN 50
// #include <stdlib.h>
// #include <string.h>
// #include <stdio.h>
// #include <ctype.h>

// char *trimwhitespace(char *s) {
//     char *ptr;
//     if (!s)
//         return NULL;   // handle NULL string
//     if (!*s)
//         return s;      // handle empty string
//     for (ptr = s + strlen(s) - 1; (ptr >= s) && isspace(*ptr); --ptr);
//     ptr[1] = '\0';
//     return s;
// }

// void writeToCsv(int n, char websites[MAXN][MAXCHAR], int array[n][n], char *fileName)
// {
//     FILE *fp;
//     fp = fopen(fileName,"w");
//     for(int i = 0; i<n; i++){
//         fprintf(fp,",%s",websites[i]);
//     }
//     for(int i = 0; i<n; i++){
//         fprintf(fp,"\n%s", trimwhitespace(websites[i]));
//         for(int j = 0; j<n; j++){
//             fprintf(fp,",%d",array[i][j]);
//         }
//     }
//     fprintf(fp,"\n");
//     fclose(fp);
// }
// int main(){
//     char websites1[MAXN][MAXCHAR] = {"1","2","4","6","8"};
//     int array1[5][5] = {{1,1,1,1,1},
//                         {0,1,1,1,1},
//                         {0,0,1,0,1},
//                         {0,0,0,1,0},
//                         {0,0,0,0,1}};
//     writeToCsv(5,websites1,array1,"divides.csv");

//     char subsets[MAXN][MAXCHAR] = {"{}", "{a}","{b}","{c}","{ab}","{ac}","{bc}","{abc}"};
//     int array2[8][8] = {{1,1,1,1,1,1,1,1},
//                         {0,1,0,0,1,1,0,1},
//                         {0,0,1,0,1,0,1,1},
//                         {0,0,0,1,0,1,1,1},
//                         {0,0,0,0,1,0,0,1},
//                         {0,0,0,0,0,1,0,1},
//                         {0,0,0,0,0,0,1,1},
//                         {0,0,0,0,0,0,0,1}};
//     writeToCsv(8, subsets, array2, "subsets.csv");

// }