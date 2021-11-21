#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include "functions.h"
void plot(char * fname);

int main(void){
    int a[5][5] = {
        {1, 0, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 1}};
    printf("Reflexive: %s\n", isReflexive(5, a) ? "true" : "false");
    printf("Symmetric: %s\n", isSymmetric(5, a) ? "true" : "false");
    printf("Antisymmetric: %s\n", isAntisymmetric(5, a) ? "true" : "false");
    printf("Transitive: %s\n", isTransitive(5, a) ? "true" : "false");
    printf("Partial Ordering: %s\n", isPartialOrdering(5, a) ? "True" : "False");
    char ws[5][MAXCHAR] = {"w1","w2","w3","w4","w5"};
    int b[5][5] = {{0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    int c [5][5] = {0};
    getHasseMatrix(5,a,c);
    printf("Hasse: %s\n", matrix_equals(5,b,c)?"Correct":"Wrong");
    char* fn = "testPartailOrder.csv";
    writeToCsv(5, ws,c, fn);
    plot(fn);
}
void plot(char * fname){
    int pid;
    if((pid = fork())==0){
        if(execlp("python", "python","/mnt/c/Users/rohan/Desktop/disco-assignment/visualiser/visualise hasse.py",fname,(char*)NULL)==-1){
        	execlp("python3", "python3","/mnt/c/Users/rohan/Desktop/disco-assignment/visualiser/visualise hasse.py",fname,(char*)NULL);
        };
    }
    exit(0);
}