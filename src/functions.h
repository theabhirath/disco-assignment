#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// #include<stdio.h>
// #include<string.h>
#include<stdbool.h>
// #include <stdlib.h>
// #include <ctype.h>

// Constants
#define MAXCHAR 1000
#define MAXN 50
// Prototypes
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char * filename); //csv.c
bool matrix_equals(int n, int a[n][n], int b[n][n]); //helper.c
//closures.c :
bool reflexive_closure(int n, int a[n][n]); 
bool symmetric_closure(int n, int a[n][n]);
bool transitive_closure(int n, int a[n][n]);
//matricType.c
bool isReflexive(int n, int a[n][n]);
bool isSymmetric(int n, int a[n][n]);
bool isTransitive(int n, int a[n][n]);
bool isAntisymmetric(int n, int a[n][n]);
bool isEquivalence(int n, int a[n][n]);
bool isPartialOrdering(int n, int a[n][n]);
//patitions.c
int partition(int n, int a[n][n]);
//posetOps.c
int upperBound(int n, int a[n][n], int b[n]);
int lowerBound(int n, int a[n][n], int b[n]);
int maximal(int n, int a[n][n], int b[n]);
int minimal(int n, int a[n][n], int b[n]);
int getHasseMatrix(int n, int a[n][n], int b[n][n]);

#endif