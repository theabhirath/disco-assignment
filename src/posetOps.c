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

int maximal(int n, int a[n][n], int b[n]){
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

int displayreachable(int c[ln], int ln, int d[n][n], int n, int b[n]){
	int a[n][n];
	memcpy(a, d, sizeof(int[n][n]));
	int arr[ln];
	memcpy(arr, c, sizeof(int[ln]));
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
	return dc;
}

int reachablefrom(int c[ln], int ln, int d[n][n], int n, int b[n]){
	int a[n][n];
	memcpy(a, d, sizeof(int[n][n]));
	int arr[ln];
	memcpy(arr, c, sizeof(int[ln]));
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
	return dc;
}			

int complement(int a, int b[n][n], int n, int comp[n]){
    /*Returns the number of complements and the complements are stored in an array*/
    int x=0;
    int c[n][n];
    memcpy(c, b, sizeof(int[n][n]));
    int arr[n];
    memcpy(arr, comp, sizeof(int[n]));
    int maxl[n];
    int minl[n];
    int maxnum = maximal(n, b[n][n], maxl[n]);
    int minum = minimal(n, b[n][n], maxl[n])
    for (int i=0; i<n; i++){
        if(join(a, i, n, b[n][n])==maxl[0]  && meet(a, i, n, b[n][n])==minl[0] ){
            comp[x]=i;
            x++;
        }
    }
    return x;
}

int isDistributive(int n, int b[n][n]){
    /*Check if all elements have only one complement, if yes, distributive*/
    int ifdist = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            /*Check for complements*/
        }
    }

}