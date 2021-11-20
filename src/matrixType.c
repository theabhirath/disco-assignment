#include <stdbool.h>
#include <stdio.h>

bool isReflexive(int n, int a[n][n]){
    for(int i = 0; i<n; i++){
        if(!a[i][i])
            return false;
    }
    return true;
}

bool isSymmetric(int n, int a[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[i][j] && a[j][i]){}
            else if(a[i][j] || a[j][i]){
                return false;
            }
            else{}
        }
    }
    return true;
}

bool isTransitive(int n, int a[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]){
                for(int k = 0; k<n; k++){
                    if(a[j][k]){
                        if(!a[i][k])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

bool isAntisymmetric(int n, int a[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j] && a[j][i]){
                return false;
            }
        }
    }
    return true;
}

bool isEquivalence(int n, int a[n][n]){
    return isReflexive(n,a) && isSymmetric(n,a) && isTransitive(n,a);
}

bool isPartialOrdering(int n, int a[n][n]){
    return isReflexive(n,a) && isAntisymmetric(n,a) && isTransitive(n,a);
}

// int main(void){
//     int a [3][3]= {{1,0,1},{0,1,0},{1,0,1}};
//     printf("Reflexive: %s\n", isReflexive(3,a) ? "true" : "false");
//     printf("Symmetric: %s\n", isSymmetric(3,a) ? "true": "false");
//     printf("Transitive: %s\n", isTransitive(3,a) ? "true" : "false" );
//     return 0;
// }