#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_PROD 10
#define MAX_TERM 10

int n;
char a[MAX_PROD][MAX_TERM];
char Result[MAX_TERM];
char subResult[MAX_TERM * 2];

void follow(char* Result, char c);
void first(char* Result, char c);
void addToResultSet(char Result[], char val);

int main() 
{
    int i;
    char choice;
    char c;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) 
    {
        printf("Enter production number %d: ", i + 1);
        scanf("%s", a[i]);
    }
   
    do 
    {
        printf("\nDo you want to find the FOLLOW set of a symbol (Y/N)? ");
        scanf(" %c", &choice);

        if (choice == 'Y' || choice == 'y') 
        {
            printf("Enter the symbol: ");
            scanf(" %c", &c);
            follow(Result, c);
            printf("FOLLOW(%c) = ", c);


            for (i = 0; Result[i] != '\0'; i++)
                printf("%c ", Result[i]);

        } 
        else 
        {
            break;
        }
    } 
    while (1);

    return 0;
}

void follow(char* Result, char c) 
{
    int k;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (a[0][0] == c)
        addToResultSet(Result, '$');

    for (int i = 0; i < n; i++) 
    {
        for (int j = 2; j < strlen(a[i]); j++) 
        {
            if (a[i][j] == c) 
            {
                if (a[i][j + 1] != '\0')
                    first(subResult, a[i][j + 1]);

                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(subResult, a[i][0]);

                for (k = 0; subResult[k] != '\0'; k++)
                    addToResultSet(Result, subResult[k]);
            }
        }
    }
}

void first(char* R, char c) 
{
    int k, m;

    if (!(isupper(c)) && c != '#')
        addToResultSet(R, c);

    for (k = 0; k < n; k++) 
    {
        if (a[k][0] == c) 
        {
            if (a[k][2] == '#' && c != a[k][0])
                follow(R, a[k][0]);
            else if (!(isupper(a[k][2])) && a[k][2] != '#')
                addToResultSet(R, a[k][2]);
            else
                first(R, a[k][2]);

            for (m = 0; R[m] != '\0'; m++)
                addToResultSet(Result, R[m]);
        }
    }
}

void addToResultSet(char Result[], char val) 
{
    int k;

    for (k = 0; Result[k] != '\0'; k++) 
    {
        if (Result[k] == val)
            return;
    }

    Result[k] = val;
    Result[k + 1] = '\0';
}
