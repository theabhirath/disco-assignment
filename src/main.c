#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../include/helper.h"
#include "../include/visualiser.h"

#define MAXCHAR 1000
#define MAXN 50

int posetMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile);

int main(void){
    printf("Welcome to our DisCo project!\n");

    printf("Enter 1 to determine if every website has a link to itself.\n");
    printf("Enter 2 to determine if it always possible to return back to previous website" 
    " from current website in one step.");

    int choice;
    scanf("%d", &choice);

    // exit case
    if (choice == 9){
        return 0;
    }

    /* reading the input csv file */
    FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("../SampleInput.csv", "r");
    char websites [MAXN][MAXCHAR];
    int n = 0;
    int count = 0;
    //  Reading the websites to websites[i]
    if (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        n = 1;
        for(int i = 0; row[i] != EOF; i++)
        {
            if(row[i] == ',' && i!=0){
                n++;
            }
        }
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL && i <n)
        {
            strcpy(websites[i], token);
            token = strtok(NULL, ",");
            i++;
        }
    }
    // array stores the 0-1 matrix of the given relation
    int array[n][n];
    memset(array, 0 , n*n*sizeof(int));
    // printf("n = %d\n", n);
    for (int i = 0; i < n; i++)
    {
        char * ptr = websites[i];
        // strcpy(websites[i], trimwhitespace(ptr));
        printf("%s\n", websites[i]);
    }
    // Reading the 0-1 matrix
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);

        token = strtok(row, ",");
        int i;
        // Checking which website index(i) is the current row
        for(i = 0; i<n; i++){
            if(strncmp(token, websites[i], 
            strlen(token) < strlen(websites[i])?strlen(token):strlen(websites[i])) == 0){
                break;
            }
        }
        token = strtok(NULL, ",");
        int j = 0;
        // Reading the 1's
        while(token != NULL)
        {
            array[i][j] = (strchr(token,'1') != NULL);
            token = strtok(NULL, ",");
            j++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            printf("%d", array[i][j]);
        }
        printf("\n");
    }

    /* main menu control flow */
    while(true){
        bool result;
        char *outputFile = "../outputs/output.csv";
        switch (choice)
        {
            /* does every website have a link to itself */
            case 1:
                result = isReflexive(n, array);
                if (result){
                    printf("Every website has a link to itself\n");
                }
                else{
                    printf("Not every website has a link to itself. Would you like to visualise how"  
                    " the network will look if we add the minimum links to satisfy the property? "
                    "Enter 1 for yes, and 0 to return back to the main menu.\n");
                    int vis;
                    scanf("%d", &vis);
                    if (vis == 1){
                        int b[n][n];
                        reflexive_closure(n, array, b);
                        // print array b
                        for (int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < n; j++){
                                printf("%d", b[i][j]);
                            }
                            printf("\n");
                        }
                        writeToCsv(n, websites, b, outputFile);
                        plot_digraph(outputFile);
                    }
                }
                break;
            /* can we reach the previous website from the current one 
            in one step */
            case 2:
                result = isSymmetric(n, array);
                if (result){
                    printf("The network is symmetric\n");
                }
                else{
                    printf("The network is not symmetric. Would you like to visualise how"  
                    " the network will look if we add the minimum links to satisfy the property? "
                    "Enter 1 for yes, and 0 to return back to the main menu.\n");
                    int vis;
                    scanf("%d", &vis);
                    if (vis == 1){
                        int b[n][n];
                        symmetric_closure(n, array, b);
                        writeToCsv(n, websites, b, outputFile);
                        // plot_digraph(outputFile);
                    }
                }
                break;
            /* does every website have the links to all the websites reachable from it */
            case 3:
                result = isTransitive(n, array);
                if (result){
                    printf("Every website has the links to all the websites reachable from it\n");
                }
                else{
                    printf("Not every website has the links to all the websites reachable from it. " 
                    "Would you like to visualise how the network will look if we add the minimum "
                    "links to satisfy the property? Enter 1 for yes, and 0 to return back to "
                    "the main menu.\n");
                    int vis;
                    scanf("%d", &vis);
                    if (vis == 1){
                        int b[n][n];
                        transitive_closure(n, array, b);
                        //print array b
                        for (int i = 0; i < n; i++)
                        {
                            for(int j = 0; j < n; j++){
                                printf("%d", b[i][j]);
                            }
                            printf("\n");
                        }
                        writeToCsv(n, websites, array, outputFile);
                        // plot_digraph(outputFile);
                    }
                }
                break;
            /* does there exist any website that contains a link to itself */
            case 4:
                result = isAntiReflexive(n, array);
                if (!result){
                    printf("There exists a website that contains a link to itself\n");
                }
                break;
            /* is it impossible to return to previous website from the current one in one step */
            case 5:
                result = isAntiSymmetric(n, array);
                if (!result){
                    printf("It is impossible to return to previous website from the current one in"
                    "one step\n");
                }
                break;
            /* is it impossible to return to previous website from the current one in one step
            excluding the cases where the previous website is the same as the current one */
            case 6:
                result = isNDAntiSymm(n, array);
                if (result){
                    printf("It is impossible to return to previous website from the current one in"
                    "one step excluding the cases where the previous website is the same as the current" 
                    " one\n");
                }
                break;
            /* is it possible to divide the network into multiple pieces such that every website in a 
            piece has a link to every website in that piece */
            case 7:
                result = isEquivalence(n, array);
                if (result){
                    printf("It is possible to divide the network into multiple pieces such that every"
                    " website in a piece has a link to every website in that piece. Would you like to "
                    "know the nodes in each piece? Enter 1 for yes, and 0 to return back to the main "
                    "menu.\n");
                    int node;
                    scanf("%d", &node);
                    if (node == 1){
                        partition(n, array);
                    }
                }
                else{
                    printf("It is not possible to divide the network into multiple pieces such that "
                    "every website in a piece has a link to every website in that piece. Would you "
                    "like to visualise how the network will look if we add the minimum links to "
                    "satisfy the property? Enter 1 for yes, and 0 to return back to the main menu.\n");
                    int vis;
                    scanf("%d", &vis);
                    if (vis == 1){
                        int b[n][n];
                        equivalence_closure(n, array, b);
                        writeToCsv(n, websites, b, outputFile);
                        // plot_digraph(outputFile);
                    }
                }
                break;
            /* is this relation an example of a poset */
            case 8:
                result = isPartialOrdering(n, array);
                if (result){
                    printf("This relation is an example of a poset.\n");
                    posetMenu(n, array, websites, outputFile);
                }
                break;
            default:
                break;
        }
    }
    // free the memory for the double pointer
    // freeArray(array, n);
}

int posetMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile){
    while (true){
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            /* display the hasse diagram */
            case 1:
                {int b[n][n];
                getHasseMatrix(n, array, b);
                writeToCsv(n, websites, array, outputFile);
                // plot_hasse(outputFile);
                break;}
        }
    }
}