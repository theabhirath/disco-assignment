#include <stdbool.h>
int upperBound(int n, int a[n][n], int b[n]){
    int m = 0;
    for(int i = 0; i<n; i++){
        bool hasAllLinks = true;
        for (int j = 0; j < n; j++)
        {
            if(!a[j][i]){
                hasAllLinks = false;
                break;
            }
        }
        if (hasAllLinks)
        {
            b[m] = i;
            m++;
        }
    }
    return m;
}

int lowerBound(int n, int a[n][n], int b[n]){
    int m = 0;
    for(int i = 0; i<n; i++){
        bool hasAllLinks = true;
        for (int j = 0; j < n; j++)
        {
            if(!a[i][j]){
                hasAllLinks = false;
                break;
            }
        }
        if (hasAllLinks)
        {
            b[m] = i;
            m++;
        }
    }
    return m;
}

int maximal(int n, int a[n][n]m int b[n]){
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j!=i && !a[i][j]){
                b[m] = i;
                m++;
            }
        }   
    }
        return m;
    
}

int minimal(int n, int a[n][n], int b[n]){
    int m = 0;
    for (int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(j != i && !a[j][i]){
                b[m] = i;
                m++;
            }
        }
    }
    return m;
}