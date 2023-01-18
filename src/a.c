#include <stdio.h>
void displayString(char str[]);

int main()
{
    char str[5];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    char c = 'a';
    displayString(str); // Passing string to a function.
    printf("sudah nih\n");
    scanf("%c", &c);
    printf("out: %c\n", c);
    return 0;
}
void displayString(char str[])
{
    printf("String Output: ");
    puts(str);
}