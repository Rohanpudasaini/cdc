#include <stdio.h>
#include <ctype.h>

#define MAX_PRODUCTIONS 10
#define MAX_SYMBOLS 20

void FIRST(char[], char);
void addToResultSet(char[], char);

int numOfProductions;
char productionSet[MAX_PRODUCTIONS][MAX_SYMBOLS];

int main()
{
    int i;
    char choice;
    char c;
    char result[MAX_SYMBOLS];

    printf("How many number of productions? : ");
    scanf("%d", &numOfProductions);

    for (i = 0; i < numOfProductions; i++)
    {
        printf("Enter production number %d: ", i + 1);
        scanf(" %s", productionSet[i]);
    }

    do
    {
        printf("\nFind the FIRST of: ");
        scanf(" %c", &c);

        FIRST(result, c); // Compute FIRST; Get Answer in 'result' array

        printf("\nFIRST(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++)
        {
            printf("%c ", result[i]);
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[MAX_SYMBOLS];
    int foundEpsilon;

    subResult[0] = '\0';
    Result[0] = '\0';

    // If X is terminal, FIRST(X) = {X}
    if (!isupper(c))
    {
        addToResultSet(Result, c);
        return;
    }

    // If X is non-terminal, then read each production
    for (i = 0; i < numOfProductions; i++)
    {
        // Find production with X as LHS
        if (productionSet[i][0] == c)
        {
            if (productionSet[i][2] == '$')
            {
                addToResultSet(Result, '$');
            }
            else
            {
                j = 2;
                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        addToResultSet(Result, subResult[k]);
                    }
                    for (k = 0; subResult[k] != '\0'; k++)
                    {
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    }
                    // No epsilon found, no need to check the next element
                    if (!foundEpsilon)
                    {
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val)
{
    int k;
    for (k = 0; Result[k] != '\0'; k++)
    {
        if (Result[k] == val)
        {
            return;
        }
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
