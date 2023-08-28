#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValidComment(const char* str) {
    int len = strlen(str);

    if (len < 2)
        return false;

    // Check if the string starts with "//"
    if (str[0] == '/' && str[1] == '/')
        return true;

    // Check if the string starts with "/*" and ends with "*/"
    if (str[0] == '/' && str[1] == '*' && str[len - 2] == '*' && str[len - 1] == '/')
        return true;

    return false;
}

int main() {
    char comment[100];
    printf("Enter a string: ");
    fgets(comment, sizeof(comment), stdin);

    // Remove the newline character from fgets()
    comment[strcspn(comment, "\n")] = '\0';

    if (isValidComment(comment))
        printf("Valid comment.\n");
    else
        printf("Not a valid comment.\n");

    return 0;
}
