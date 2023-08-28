#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

int main()
{
    char input[100];
    char choice = 'y';

    printf("Enter the operations in the format (op arg1 arg2 result)\n");

    while (choice == 'y' || choice == 'Y')
    {
        printf("Operations:\n");
        fgets(input, sizeof(input), stdin);

        char* token = strtok(input, " \n");
        while (token != NULL)
        {
            strncpy(op, token, 2);
            token = strtok(NULL, " \n");
            strncpy(arg1, token, 5);
            token = strtok(NULL, " \n");
            strncpy(arg2, token, 5);
            token = strtok(NULL, " \n");
            strncpy(result, token, 5);

            if (strcmp(op, "+") == 0)
            {
                printf("MOV R0, %s\n", arg1);
                printf("ADD R0, %s\n", arg2);
                printf("MOV %s, R0\n", result);
            }
            else if (strcmp(op, "*") == 0)
            {
                printf("MOV R0, %s\n", arg1);
                printf("MUL R0, %s\n", arg2);
                printf("MOV %s, R0\n", result);
            }
            else if (strcmp(op, "-") == 0)
            {
                printf("MOV R0, %s\n", arg1);
                printf("SUB R0, %s\n", arg2);
                printf("MOV %s, R0\n", result);
            }
            else if (strcmp(op, "=") == 0)
            {
                printf("MOV R0, %s\n", arg1);
                printf("MOV %s, R0\n", result);
            }

            token = strtok(NULL, " \n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        getchar(); 
    }

    return 0;
}
