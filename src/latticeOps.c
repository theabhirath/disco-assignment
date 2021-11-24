#include <stdio.h>
#include <string.h>

#include "../include/helper.h"

int join(int a, int b, int n, int d[n][n]){
	int arr[n][n];
	memcpy(arr, d, sizeof(int[n][n]));
	int inp[2] = {a,b};
	int mp;
    int joins[n];
	mp = upperBound(n, 2, inp, d, joins);
    if(mp == 1){
        return joins[0];
    }
    else{
	/* Select the one which can reach every other one. */
        for(int i = 0; i < mp; i++){
            for(int j=0;j<mp;j++){
                if(d[joins[i],joins[j]]==0){
                    break;
                }
                if(j==mp-1){
                    return joins[i];
                }
            }
        }
    }
}

int meet(int a, int b, int n, int d[n][n]){
	int arr[n][n];
	memcpy(arr, d, sizeof(int[n][n]));
	int inp[2] = {a,b};
	int mp;
    int meets[n];
	mp = lowerBound(n, 2, inp, d, meets);
    if(mp==1){
        return meets[0];
    }
    else{
	/* Select the one which is reachable from every other one. */
        for(int i=0; i<mp; i++){
            for(int j=0;j<mp;j++){
                if(d[meets[j],meets[i]]==0){
                    break;
                }
                if(j==mp-1){
                    return meets[i];
                }
            }
        }
    }
}

int complement(int a, int n, int b[n][n], int comp[n]){
    /* Returns the number of complements and the complements are stored in an array */
    int x=0;
    int c[n][n];
    memcpy(c, b, sizeof(int[n][n]));
    int arr[n];
    memcpy(arr, comp, sizeof(int[n]));
    int maxl[n];
    int minl[n];
    int maxnum = maximal(n, b, maxl);
    int minum = minimal(n, b, minl);
    for (int i=0; i<n; i++){
        if(join(a, i, n, b)==maxl[0]  && meet(a, i, n, b)==minl[0] ){
            comp[x]=i;
            x++;
        }
    }
    return x;
}


int isDistributive(int n, int b[n][n]){
    /* Check if all elements have only one complement, if yes, distributive */
    int noComp;
    int comps[n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            /*Check for complements*/
            noComp = complement(i, n, b, comps);
            if(noComp>1){
                return 0;
            }
        }
    }
    return 1;

}