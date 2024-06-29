#include <stdio.h>
#include <string.h>
int longestUniqueSubstring(char *str, char *result) 
{
    int n = strlen(str);
    int maxLen = 0; 
    int start = 0; 
    int startMax = 0; 
    int index[256]; 
    for (int i = 0; i < 256; i++) 
    {
        index[i] = -1;
    }
    for (int j = 0; j < n; j++) 
    {
        if (index[(unsigned char)str[j]] >= start) 
        {
            start = index[(unsigned char)str[j]] + 1;
        }
        index[(unsigned char)str[j]] = j;
        if (j - start + 1 > maxLen) 
        {
            maxLen = j - start + 1;
            startMax = start;
        }
    }
    strncpy(result, str + startMax, maxLen);
    result[maxLen] = '\0';
    return maxLen;
}
int main() 
{
    char str[1000];
    char result[1000];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    int length = longestUniqueSubstring(str, result);
    printf("The length of the longest substring without repeating characters is: %d\n", length);
    printf("The longest substring without repeating characters is: %s\n", result);
    return 0;
}
