#include <stdbool.h>
#include <stdio.h>

#define MAXN 50
#define MAXCHAR 1000

#include "../include/helper.h"

/* it finds the partitions and prints them, and returns the number of partitions */
int partition(int n, int a[n][n], char websites[MAXN][MAXCHAR]){
    int count = 0;
    int b[n][n];
    int c[n];
    for(int i = 0; i<n; i++){
        c[i] = 0;
        for(int j = 0; j<n; j++){
            b[i][j] = -1;
        }
    }
    b[0][0] = 0;
    count = 1;
    c[0] ++;
    for(int i = 1; i<n; i++){
        bool flag = false;
        for(int j = 0; j<count; j++){
            if(a[i][b[j][0]]){
                b[j][c[j]] = i;
                c[j] ++;
                flag = true;
                break;
            }
        }
        if(!flag){
            b[count][0] = i;
            c[count] ++;
            count++;
        }
    }
    printf("Number of partitions is: %d\n", count);
    for(int i = 0; i < count; i++){
        printf("Partition [%d] is:\t", b[i][0]);
        for(int j = 0; j<c[i]; j++){
            printf("%s\t", websites[b[i][j]]);
        }
        printf("\n");
    }
    return count;
}

// int main(void){
//     char websites[MAXN][MAXCHAR] = {"ikh", "ehfihe", "fekf", "hfieh", "fhgu"};
//     // char websites[MAXN][MAXCHAR] = {};
//     int a[6][6] = {{1,1,1,0,0,0},{1,1,1,0,0,0},{1,1,1,0,0,0},{0,0,0,1,1,0},{0,0,0,1,1,0},{0,0,0,0,0,1}};
//     printf("Reflexive: %s\n", isReflexive(6,a) ? "true" : "false");
//     printf("Symmetric: %s\n", isSymmetric(6,a) ? "true": "false");
//     printf("Antisymmetric: %s\n", isAntiSymmetric(6,a) ? "true": "false");
//     printf("Transitive: %s\n", isTransitive(6,a) ? "true" : "false" );
//     printf("Equivalence: %s\n", isEquivalence(6,a) ? "true" : "false" );
//     partition(6,a, websites);
// }
