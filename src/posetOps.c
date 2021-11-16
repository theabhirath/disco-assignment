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

int * displayreachable(int *c, int ln, int *d, int n){
	int a[n][n];
	memcpy(a, d, sizeof(int[n][n]));
	int arr[ln];
	memcpy(arr, c, sizeof(int[ln]));
	int b[];
	int dc = 0;
	for (int i=0; i<n; i++){
		for(int j=0; j<ln; j++){
			if(a[arr[j],i]==0){
				break;
			}
			if(j==ln-1){
				b[dc]=i;
				dc++;
			}
		}
	}
	return &b[0];
}

int * reachablefrom(int *c, int ln, int *d, int n){
	int a[n][n];
	memcpy(a, d, sizeof(int[n][n]));
	int arr[ln];
	memcpy(arr, c, sizeof(int[ln]));
	int b[];
	int dc = 0;
	for (int i=0; i<n; i++){
		for(int j=0; j<ln; j++){
			if(a[i,arr[j]]==0){
				break;
			}
			if(j==ln-1){
				b[dc]=i;
				dc++;	
			}
		}
	}
	return &b[0];
}			