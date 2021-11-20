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

int displayreachable(int ln, int n, int c[ln], int d[n][n], int b[n]){
    /*6*/
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

int reachablefrom(int ln, int n, int c[ln],  int d[n][n], int b[n]){
    /*7*/
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

int checkLattice(int n, int a[n][n]){
/* Lattice has only one minimal and one maximal. Use functions for part 4 and part 5 of Menu 4. 
Any pair of elements has just one join and one meet. */	
    int b[n];
    if(maximal(n, a[n][n], b[n])>1){
        return 0;
    }
    if(minimal(n, a[n][n], b[n])>1){
        return 0;
    }
    int inp[2];
    /*displayreachable and reachablefrom can't be zero for any pair*/
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            inp[0]=i;
            inp[1]=j;
            if(displayreachable(2, n, inp, a, b)==0 || reachablefrom(2, n, inp, a, b)==0){
                return 0;
            }
        }
    }
    return 1;
}