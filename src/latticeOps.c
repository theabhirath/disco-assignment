#include<stdio.h>

#include "posetOps.c"

int join(int a, int b, int d[n][n], int n){
    /*Basically least upper bound*/
	int arr[n][n];
	memcpy(arr, d, sizeof(int[n][n]));
	int inp[2] = {a,b};
	int mp;
    int joins[n];
	mp = displayreachable(inp, 2, d[n][n], n, joins);
    if(mp==1){
        return joins[0];
    }
    else{
	/*Select the one which can reach every other one.*/
    }
}

int meet(int a, int b, int d[n][n], int n){
    /*Basically greatest upper bound*/
	int arr[n][n];
	memcpy(arr, d, sizeof(int[n][n]));
	int inp[2] = {a,b};
	int mp;
    int meets[n];
	mp = fromreachable(inp, 2, d[n][n], n, meets);
    if(mp==1){
        return meets[0];
    }
    else{
	/*Select the one which is reachable from every other one.*/
    }
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
        if(join(a, i, b[n][n], n)==maxl[0]  && meet(a, i, b[n][n], n)==minl[0] ){
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