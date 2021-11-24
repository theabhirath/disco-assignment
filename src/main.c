#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../include/helper.h"
#include "../include/visualiser.h"

#define MAXCHAR 1000
#define MAXN 50

int posetMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile);
int latticeMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile);

int main(void)
{
    printf("Welcome to our DisCo project!\n\n");
    /* reading the input csv file */
    FILE *fp;
    char row[MAXCHAR];
    char *token;

    fp = fopen("../SampleInput.csv", "r");
    char websites[MAXN][MAXCHAR];
    int n = 0;
    int count = 0;
    char delimit[] = ",\n";
    //  Reading the websites to websites[i]
    if (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);
        n = 1;
        for (int i = 0; row[i] != EOF; i++)
        {
            if (row[i] == ',' && i != 0)
            {
                n++;
            }
        }
        token = strtok(row, delimit);
        int i = 0;
        while (token != NULL && i < n)
        {
            strcpy(websites[i], token);
            token = strtok(NULL, delimit);
            i++;
        }
    }
    // array stores the 0-1 matrix of the given relation
    int array[n][n];
    memset(array, 0, n * n * sizeof(int));
    // printf("n = %d\n", n);
    for (int i = 0; i < n; i++)
    {
        char *ptr = websites[i];
        ptr = trimwhitespace(ptr);
    }
    // Reading the 0-1 matrix
    while (feof(fp) != true)
    {
        fgets(row, MAXCHAR, fp);

        token = strtok(row, delimit);
        int i;
        // Checking which website index(i) is the current row
        for (i = 0; i < n; i++)
        {
            if (strncmp(token, websites[i],
                        strlen(token) < strlen(websites[i]) ? strlen(token) : strlen(websites[i])) == 0)
            {
                break;
            }
        }
        token = strtok(NULL, delimit);
        int j = 0;
        // Reading the 1's
        while (token != NULL)
        {
            array[i][j] = (strchr(token, '1') != NULL);
            token = strtok(NULL, delimit);
            j++;
        }
    }

    /* main menu control flow */
    while (true)
    {
        printf("Home Menu:\n");
        printf("Enter 1 to determine if every website has a link to itself.\n");
        printf("Enter 2 to determine if it is always possible to return back to previous website"
               " from current website in one step.\n");
        printf("Enter 3 to determine if every website has all the links to the websites"
               "which are reachable from it.\n");
        printf("Enter 4 to determine if there exist any website that contains a link to itself.\n");
        printf("Enter 5 to determine if it impossible to return to the previous website"
               " from the current website in one step.\n");
        printf("Enter 6 to determine if it is impossible to return to the previous website"
               " from the current website in one step (excluding the cases where the current"
               " and previous website is same).\n");
        printf("Enter 7 to determine if it is possible to divide the network into multiple"
               " pieces such that every website in a piece is reachable from every other website"
               " in that piece.\n");
        printf("Enter 8 to determine if this relation is a poset.\n");
        printf("Enter 9 to exit.\n");

        int choice;
        scanf("%d", &choice);

        // exit case
        if (choice == 9)
        {
            return 0;
        }
        bool result;
        char *outputFile = "../outputs/output.csv";
        switch (choice)
        {
        /* does every website have a link to itself */
        case 1:
            result = isReflexive(n, array);
            if (result)
            {
                printf("Every website has a link to itself\n");
            }
            else
            {
                printf("Not every website has a link to itself. Would you like to visualise how"
                       " the network will look if we add the minimum links to satisfy the property? "
                       "Enter 1 for yes, and 0 to return back to the main menu.\n");
                int vis;
                scanf("%d", &vis);
                if (vis == 1)
                {
                    int b[n][n];
                    reflexive_closure(n, array, b);
                    // print array b
                    printf("\n");
                    printf("The reflexive closure of the relation has the matrix representation:\n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
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
            if (result)
            {
                printf("It is always possible to return back to the previous"
                       " website from the current website in one step?\n");
            }
            else
            {
                printf("Is it possible to always return back to the previous website from the "
                       "current website in one step. Would you like to visualise how"
                       " the network will look if we add the minimum links to satisfy the property? "
                       "Enter 1 for yes, and 0 to return back to the main menu.\n");
                int vis;
                scanf("%d", &vis);
                if (vis == 1)
                {
                    int b[n][n];
                    symmetric_closure(n, array, b);
                    // print array b
                    printf("\n");
                    printf("The symmetric closure of the relation has the matrix representation:\n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            printf("%d", b[i][j]);
                        }
                        printf("\n");
                    }
                    writeToCsv(n, websites, b, outputFile);
                    plot_digraph(outputFile);
                }
            }
            break;
        /* does every website have the links to all the websites reachable from it */
        case 3:
            result = isTransitive(n, array);
            if (result)
            {
                printf("Every website has the links to all the websites reachable from it\n");
            }
            else
            {
                printf("Not every website has the links to all the websites reachable from it. "
                       "Would you like to visualise how the network will look if we add the minimum "
                       "links to satisfy the property? Enter 1 for yes, and 0 to return back to "
                       "the main menu.\n");
                int vis;
                scanf("%d", &vis);
                if (vis == 1)
                {
                    int b[n][n];
                    transitive_closure(n, array, b);
                    //print array b
                    printf("\n");
                    printf("The transitive closure of the relation has the matrix representation:\n");
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            printf("%d", b[i][j]);
                        }
                        printf("\n");
                    }
                    writeToCsv(n, websites, array, outputFile);
                    plot_digraph(outputFile);
                }
            }
            break;
        /* does there exist any website that contains a link to itself */
        case 4:
            result = isAntiReflexive(n, array);
            if (!result)
            {
                printf("There exists a website that contains a link to itself.\n");
            }
            else
            {
                printf("There does not exist a website that contains a link to itself\n");
            }
            break;
        /* is it impossible to return to previous website from the current one in one step */
        case 5:
            result = isAntiSymmetric(n, array);
            if (!result)
            {
                printf("\nIt is impossible to return to previous website from the current one in"
                       " one step.\n\n");
            }
            else
            {
                printf("\nIt is possible to return to previous website from the current one in"
                       " one step.\n\n");
            }
            break;
        /* is it impossible to return to previous website from the current one in one step
            excluding the cases where the previous website is the same as the current one */
        case 6:
            result = isNDAntiSymm(n, array);
            if (result)
            {
                printf("It is impossible to return to previous website from the current one in"
                       "one step excluding the cases where the previous website is the same as the current"
                       " one.\n");
            }
            else
            {
                printf("It is possible to return to previous website from the current one in"
                       "one step excluding the cases where the previous website is the same as the current"
                       " one.\n");
            }
            break;
        /* is it possible to divide the network into multiple pieces such that every website in a 
            piece has a link to every website in that piece */
        case 7:
            result = isEquivalence(n, array);
            if (result)
            {
                printf("It is possible to divide the network into multiple pieces such that every"
                       " website in a piece has a link to every website in that piece. Would you like to "
                       "know the nodes in each piece? Enter 1 for yes, and 0 to return back to the main "
                       "menu.\n");
                int node;
                scanf("%d", &node);
                if (node == 1)
                {
                    partition(n, array, websites);
                }
            }
            else
            {
                printf("It is not possible to divide the network into multiple pieces such that "
                       "every website in a piece has a link to every website in that piece. Would you "
                       "like to visualise how the network will look if we add the minimum links to "
                       "satisfy the property? Enter 1 for yes, and 0 to return back to the main menu.\n");
                int vis;
                scanf("%d", &vis);
                if (vis == 1)
                {
                    int b[n][n];
                    equivalence_closure(n, array, b);
                    writeToCsv(n, websites, b, outputFile);
                    plot_digraph(outputFile);
                }
            }
            break;
        /* is this relation an example of a poset */
        case 8:
            result = isPartialOrdering(n, array);
            if (result)
            {
                // printf("This relation is an example of a poset.\n");
                printf("Yes\n");
                posetMenu(n, array, websites, outputFile);
            }
            else{
                printf("No\n");
            }
            break;
        default:
            break;
        }
    }
}

int posetMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile)
{
    int b[n][n];
    while (true)
    {
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        /* display the hasse diagram */
        case 1:
            getHasseMatrix(n, array, b);
            writeToCsv(n, websites, array, outputFile);
            plot_hasse(outputFile);
            break;
        /* display website whose link is available in every website */
        case 2:{
            int c[n];
            int m = greatestElement(n, array, c);
            if (m > 0)
            {
                printf("%s\n", websites[0]);
            }
            else
            {
                printf("There is no website whose link is available"
                       " in every website.\n");
            }
            break;
        }
        /* display website which has links to every website*/
        case 3:{
            int c[n];
            int m = leastElement(n, array, c);
            if (m > 0)
            {
                printf("%s\n", websites[0]);
            }
            else
            {
                printf("There is no website which has links"
                       " to every website.\n");
            }      
            break;
        }
        case 4:{
            int c[n];
            int m = maximal(n,array,c);
            if (m > 0)
            {
                for(int i = 0; i<m; i++){
                    printf("%s ", websites[i]);
                }
                printf("\n");
            }
            else
            {
                printf("There is no website which does not have "
                "links to any other website except itself.\n");
            }      
            break;

        }
        case 5:{
            int c[n];
            int m = minimal(n,array,c);
            if (m > 0)
            {
                for(int i = 0; i<m; i++){
                    printf("%s ", websites[i]);
                }
                printf("\n");
            }
            else
            {
                printf("There is no website which can't be reached from "
                "any other website except itself.\n");
            }      
            break;
        }
        case 6:{
            printf("Enter number of websites:\n");
            int ln;
            scanf("%d", &ln);
            getchar();
            printf("Enter %d website indices(0-indexed):\n", ln);
            int c[ln];
            for(int i = 0; i<ln; i++){
                scanf("%d", &c[i]);
                getchar();
            }
            int b[n];
            int m = upperBound(ln, n, c, array, b);
            for(int i = 0; i<m; i++){
                printf("%s ", websites[i]);
            }
            printf("\n");
            break;
        }
        case 7:{
            printf("Enter number of websites:\n");
            int ln;
            scanf("%d", &ln);
            getchar();
            printf("Enter %d website indices(0-indexed):\n", ln);
            int c[ln];
            for(int i = 0; i<ln; i++){
                scanf("%d", &c[i]);
                getchar();
            }
            int b[n];
            int m = lowerBound(ln, n, c, array, b);
            for(int i = 0; i<m; i++){
                printf("%s ", websites[i]);
            }
            printf("\n");
            break;
        }
        case 8:
            if(checkLattice(n, array)){
                printf("Yes\n");
                latticeMenu(n, array, websites, outputFile);
            }
            else{
                printf("No\n");
            }
            break;
        case 9:
            return 0;
        default:
            break;
        }
    }
}

int latticeMenu(int n, int array[n][n], char websites[MAXN][MAXCHAR], char *outputFile){
    while(true){
        int choice;
        scanf("%d", &choice);
        getchar();
        switch (choice){
            case 1:{
                int a,b;
                printf("Enter indices of two websites A and B:\n");
                scanf("%d", &a);
                scanf("%d", &b);
                int m = join(a, b, n, array);
                for(int i = 0; i<m; i++){
                    printf("%s ", websites[i]);
                }
                printf("\n");
                break;
            }
            case 2:{
                int a,b;
                printf("Enter indices of two websites A and B:\n");
                scanf("%d", &a);
                scanf("%d", &b);
                int m = meet(a, b, n, array);
                for(int i = 0; i<m; i++){
                    printf("%s ", websites[i]);
                }
                printf("\n");
                break;
            }
            case 3:
                if(isDistributive(n, array)){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
                break;
            case 4:
                return 0;
            default:
                break;
        }
    }
}