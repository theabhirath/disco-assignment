#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "visualiser/visualiser.c"
#include "src/helper.h"

#define MAXCHAR 1000
#define MAXN 50

int main(void){
    printf("Welcome to our DisCo project!\n");

    int choice;
    scanf("%d", &choice);

    // exit case
    if (choice == 9){
        return 0;
    }

    /* reading the input csv file */
    FILE *fp = fopen("../SampleInput.csv", "r");
    int n = 0;
    char websites[MAXN][MAXCHAR];
    int **array = readFromCsv(fp, &n, websites);

    // print the websites
    for (int i = 0; i < n; i++){
        printf("%s\n", websites[i]);
    }
    // print the relation matrix
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    // free the array
    freeArray(array, n);

    // close the file
    fclose(fp);

}

/* main menu control flow */
// while(0){
//     switch (choice)
//     {
//     /* does every website have a link to itself */
//     case 1:
//         bool result = isReflexive(n, array);
//         if (result){
//             printf("Every website has a link to itself\n");
//         }
//         else{
//             printf("Not every website has a link to itself. Would you like to visualise how",  
//             " the network will look if we add the minimum links to satisfy the property? ",
//             "Enter 1 for yes, and 0 to return back to the main menu.\n");
//             int vis;
//             scanf("%d", &vis);
//             if (vis == 1){
//                 int b[n][n];
//                 reflexive_closure(n, array, b);
//                 writeToCsv(n, websites, b, "outputs/output.csv");
//                 plot("outputs/output.csv");
//             }
//         }
//         break;
//     /* can we reach the previous website from the current one 
//     in one step */
//     case 2:
//         bool result = isSymmetric(n, array);
//         if (result){
//             printf("The network is symmetric\n");
//         }
//         else{
//             printf("The network is not symmetric. Would you like to visualise how",  
//             " the network will look if we add the minimum links to satisfy the property? ",
//             "Enter 1 for yes, and 0 to return back to the main menu.\n");
//             int vis;
//             scanf("%d", &vis);
//             if (vis == 1){
//                 int b[n][n];
//                 symmetric_closure(n, array, b);
//                 writeToCsv(n, websites, b, "outputs/output.csv");
//                 plot("outputs/output.csv");
//             }
//         }
//         break;
//     /* does every website have the links to all the websites reachable from it */
//     case 3:
//         bool result = isTransitive(n, array);
//         if (result){
//             printf("Every website has the links to all the websites reachable from it\n");
//         }
//         else{
//             printf("Not every website has the links to all the websites reachable from it. ", 
//             "Would you like to visualise how the network will look if we add the minimum ",
//             "links to satisfy the property? Enter 1 for yes, and 0 to return back to ",
//             "the main menu.\n");
//             int vis;
//             scanf("%d", &vis);
//             if (vis == 1){
//                 int b[n][n];
//                 transitive_closure(n, array, b);
//                 writeToCsv(n, websites, b, "outputs/output.csv");
//                 plot("outputs/output.csv");
//             }
//         }
//         break;
//     /* does there exist any website that has a link to all the websites reachable from it */
//     case 4:

//     default:
//         break;
//     }
// }

