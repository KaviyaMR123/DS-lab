#include <stdio.h>
int stringLength(const char *str) 
{
    const char *s = str;
    while (*s)
        s++;
    return s - str;
}
void stringCopy(char *dest, const char *src) 
{
    while ((*dest++ = *src++));
}
int stringCompare(const char *str1, const char *str2) 
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
void stringConcat(char *dest, const char *src) 
{
    while (*dest)
        dest++;
    while ((*dest++ = *src++));
}
int main() 
{
    char str1[100], str2[100];
    char dest[200];
    int choice;
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    printf("Choose an operation:\n");
    printf("1) String Length\n");
    printf("2) String Copy\n");
    printf("3) String Comparison\n");
    printf("4) String Concatenation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            printf("Length of the first string: %d\n", stringLength(str1));
            printf("Length of the second string: %d\n", stringLength(str2));
            break;
        case 2:
            stringCopy(dest, str1);
            printf("Copy of the first string: %s\n", dest);
            stringCopy(dest, str2);
            printf("Copy of the second string: %s\n", dest);
            break;
        case 3:
            if (stringCompare(str1, str2) == 0) 
            {
                printf("The strings are equal.\n");
            } 
            else 
            {
                printf("The strings are not equal.\n");
            }
            break;
        case 4:
            stringCopy(dest, str1);
            stringConcat(dest, str2);
            printf("Concatenation of the strings: %s\n", dest);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}
