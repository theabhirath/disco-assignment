#ifndef HELPER_H
#define HELPER_H

#include <stdbool.h>

#define MAXCHAR 1000
#define MAXN 50

/* closures.c */
void reflexive_closure(int n, int a[n][n], int b[n][n]);
void symmetric_closure(int n, int a[n][n], int b[n][n]);
void transitive_closure(int n, int a[n][n], int b[n][n]);
void equivalence_closure(int n, int a[n][n], int b[n][n]);

/* csv.c */
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char * fileName);
int **readFromCsv(char *filename, int *n, char websites[MAXN][MAXCHAR]);
char *trimwhitespace(char *s);
void freeArray(int **array, int n);

/* matrixType.c */
bool isReflexive(int n, int a[n][n]);
bool isSymmetric(int n, int a[n][n]);
bool isTransitive(int n, int a[n][n]);
bool isAntiReflexive(int n, int a[n][n]);
bool isAntiSymmetric(int n, int a[n][n]);
bool isAntiTransitive(int n, int a[n][n]);
bool isEquivalence(int n, int a[n][n]);
bool isPartialOrdering(int n, int a[n][n]);
bool isNDAntiSymm(int n, int a[n][n]);

/* partitions.c */
int partition(int n, int a[n][n], char websites[MAXN][MAXCHAR]);

/* latticeOps.c */
int join(int a, int b, int n, int d[n][n]);
int meet(int a, int b, int n, int d[n][n]);
int complement(int a, int n, int b[n][n], int comp[n]);
int isDistributive(int n, int b[n][n]);

/* posetOps.c */
int greatestElement(int n, int a[n][n], int b[n]);
int leastElement(int n, int a[n][n], int b[n]);
int maximal(int n, int a[n][n], int b[n]);
int minimal(int n, int a[n][n], int b[n]);
int upperBound(int n, int ln, int c[ln], int d[n][n], int b[n]);
int lowerBound(int n, int ln, int c[ln],  int d[n][n], int b[n]);
int checkLattice(int n, int a[n][n]);
void getHasseMatrix(int n, int a[n][n], int b[n][n]);

#endif