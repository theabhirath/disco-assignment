#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* calculates reflexive closure of a relation */
void reflexive_closure(int n, int a[n][n], int b[n][n]){
    memcpy(b, a, sizeof(int) * n * n);
    for (int i = 0; i < n; i++){
        b[i][i] = 1;
    }
}

/* calculates symmetric closure of a relation */
void symmetric_closure(int n, int a[n][n], int b[n][n]){
    memcpy(b, a, sizeof(int) * n * n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (b[i][j] == 1){
                b[j][i] = 1;
            }
        }
    }
}

/* calculate transitive closure of a relation */
void transitive_closure(int n, int a[n][n], int b[n][n]){
    memcpy(b, a, sizeof(int) * n * n);
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                b[i][j] = b[i][j] || (b[i][k] && b[k][j]);
            }
        }
    }
}

/* calculate the equivalence closure of a relation */
void equivalence_closure(int n, int a[n][n], int b[n][n]){
    memcpy(b, a, sizeof(int) * n * n);
    reflexive_closure(n, a, b);
    symmetric_closure(n, b, b);
    transitive_closure(n, b, b);
}
