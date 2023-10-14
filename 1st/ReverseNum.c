#include <stdio.h>

int main () 
{
    int a, r;
    printf("Enter number to reverse: ");
    scanf("%d", &a);
    
    
    printf("The reversed number is ");
    
    while (a != 0) 
    {
        r = a % 10;
        a = a - r;
        a = a / 10;
        printf("%d", r);
    }
    
    
/*
    int length = snprintf(NULL, 0, "%d", a);
    
    char s[length];
    char temp;
    snprintf(s, length + 1, "%d", a);
    
    for (int i = 0; i < (length / 2); i++) {
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
    
    printf("%s", s);
    
    */
    
    
    return 0;
    
}