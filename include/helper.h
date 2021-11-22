#ifndef MAIN
#define MAIN

#include <stdbool.h>

#define MAXCHAR 1000
#define MAXN 50

/* closures.c */
bool symmetric_closure(int n, int a[n][n], int b[n][n]);
bool transitive_closure(int n, int a[n][n], int b[n][n]);
bool equivalence_closure(int n, int a[n][n], int b[n][n]);

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
bool isAntisymmetric(int n, int a[n][n]);
bool isAntiTransitive(int n, int a[n][n]);
bool isEquivalence(int n, int a[n][n]);
bool isPartialOrdering(int n, int a[n][n]);
bool isNDAntiSymm(int n, int a[n][n]);

/* partitions.c */
int partition(int n, int a[n][n]);

/* latticeOps.c */
int join(int a, int b, int n, int d[n][n]);
int meet(int a, int b, int n, int d[n][n]);
int complement(int a, int n, int b[n][n], int comp[n]);
int isDistributive(int n, int b[n][n]);

/* posetOps.c */
int upperBound(int n, int a[n][n], int b[n]);
int lowerBound(int n, int a[n][n], int b[n]);
int maximal(int n, int a[n][n], int b[n]);
int minimal(int n, int a[n][n], int b[n]);
int displayreachable(int ln, int n, int c[ln], int d[n][n], int b[n]);
int reachablefrom(int ln, int n, int c[ln],  int d[n][n], int b[n]);
int checkLattice(int n, int a[n][n]);
void getHasseMatrix(int n, int a[n][n], int b[n][n]);

#endif