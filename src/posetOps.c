#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "../include/helper.h"

/* finds the greatest element in the poset if it exists */
int greatestElement(int n, int a[n][n], int b[n]){
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
            break; 
        }
    }
    return m;
}

/* finds the least element of the poset if it exists */
int leastElement(int n, int a[n][n], int b[n]){
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
            break;
        }
    }
    return m;
}

/* finds the maximal elements in the poset */
int maximal(int n, int a[n][n], int b[n]){
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        bool isMaximal = true;
        for (int j = 0; j < n; j++)
        {
            if(j!=i && a[i][j]){
                isMaximal = false;
                break;
            }
        }
        if (isMaximal){
            b[m] = i;
            m++;
        }   
    }
        return m;
    
}

/* finds the minimal elements in the poset */
int minimal(int n, int a[n][n], int b[n]){
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        bool isMinimal = true;
        for (int j = 0; j < n; j++)
        {
            if(j!=i && a[j][i]){
                isMinimal = false;
                break;
            }
        }
        if (isMinimal){
            b[m] = i;
            m++;
        }   
    }
        return m;
    
}

/* finds upper bound of the elements in array c (with "ln" elements) wrt. array d (with n^2 elements)
 and stores it in array b */
int upperBound(int n, int ln, int c[ln], int d[n][n],  int b[n]){
    /*6*/
	int dc = 0;
	for (int i=0; i<n; i++){
		for(int j=0; j<ln; j++){
			if(d[c[j]][i]==0){
				break;
			}
			if(j==(ln-1)){
				b[dc]=i;
				dc++;
			}
		}
	}
	return dc;
}

/* finds lower bound of the elements in array c (with "ln" elements) wrt. array d (with n^2 elements)
 and stores it in array b */
int lowerBound(int n, int ln, int c[ln], int d[n][n],  int b[n]){
    /*7*/
	int dc = 0;
	for (int i=0; i<n; i++){
		for(int j=0; j<ln; j++){
			if(d[i][c[j]]==0){
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
/* Lattice has only one minimal and one maximal. Use functions for part 4 and part 5 of Menu 4. Any pair of elements has just one join and one meet */	
    int b[n];
    if(maximal(n, a, b)>1){
        return 0;
    }
    if(minimal(n, a, b)>1){
        return 0;
    }
    int inp[2];
    /*upperBound and lowerBound can't be zero for any pair*/
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            inp[0]=i;
            inp[1]=j;
            if(upperBound(n, 2, inp, a, b)==0 || lowerBound(n, 2, inp, a, b)==0){
                return 0;
            }
        }
    }
    return 1;
}

void getHasseMatrix(int n, int a[n][n], int b[n][n]){
    // Copying a to b and 0ing diagonal elements
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            b[i][j] = a[i][j];
        }
        b[i][i] = 0;
    }
    bool trans = true;
    while(trans){
        trans = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++){
                    if(b[i][j] && b[j][k] && b[i][k]){
                        b[i][k] = 0;
                        trans = true;
                    }
                }
            }
                
        }             
    }
}

