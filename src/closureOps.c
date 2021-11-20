#include <stdbool.h>

bool matrix_equals(int n, int a[n][n], int b[n][n]){
    int result = true;
    for (int i = 0; i < n; i++){
        if (result == false){
            break;
        }
        for (int j = 0; j < n; j++){
            if (a[i][j] != b[i][j]){
                result = false;
                break;
            }
        }
    }
    return result;
}