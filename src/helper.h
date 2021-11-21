#ifndef MAIN
#define MAIN

#include <stdbool.h>

#define MAXCHAR 1000
#define MAXN 50

/* closureOps.c */
bool matrix_equals(int n, int a[n][n], int b[n][n]);

/* closures.c */
bool reflexive_closure(int n, int a[n][n], int b[n][n]);
bool symmetric_closure(int n, int a[n][n], int b[n][n]);
bool transitive_closure(int n, int a[n][n], int b[n][n]);

/* csv.c */
void writeToCsv(int n, char websites[][MAXCHAR], int array[n][n], char * fileName);
int **readFromCsv(FILE *filePointer, int *n, char websites[MAXN][MAXCHAR]);
char *trimwhitespace(char *s);
void freeArray(int **array, int n);

/* matrixType.c */
bool isReflexive(int n, int a[n][n]);
bool isSymmetric(int n, int a[n][n]);
bool isTransitive(int n, int a[n][n]);
bool isAntisymmetric(int n, int a[n][n]);
bool isEquivalence(int n, int a[n][n]);
bool isPartialOrdering(int n, int a[n][n]);

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

#endif