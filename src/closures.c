#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "helper.c"

/* calculates reflexive closure of a relation */
bool reflexive_closure(int n, int a[n][n]){
    int b[n][n];
    memcpy(b, a, sizeof(int) * n * n);
    for (int i = 0; i < n; i++){
        a[i][i] = 1;
    }
    if (matrix_equals(n, a, b)) { return true; }
    else { return false; }
}

/* calculate symmetric closure of a relation */
bool symmetric_closure(int n, int a[n][n]){
    int b[n][n];
    memcpy(b, a, sizeof(int) * n * n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] == 1){
                a[j][i] = 1;
            }
        }
    }
    if (matrix_equals(n, a, b)) { return true; }
    else { return false; }
}

/* calculate transitive closure of a relation */
bool transitive_closure(int n, int a[n][n]){
    int b[n][n];
    memcpy(b, a, sizeof(int) * n * n);
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
    if (matrix_equals(n, a, b)) { return true; }
    else { return false; }
}

// int main(void){
//     int a[3][3] = {{0, 1, 1}, {1, 0, 0}, {1, 1, 0}};
//     bool k = transitive_closure(3, a);
//     for (int i = 0; i < 3; i++){
//         for (int j = 0; j < 3; j++){
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     printf("%d\n", k);
// }