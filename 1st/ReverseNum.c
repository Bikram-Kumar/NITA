#include <stdio.h>

int main () 
{
    int a, r, n = 0;
    printf("Enter number to reverse: ");
    scanf("%d", &a);
    
    
    while (a != 0) 
    {
        r = a % 10;
        a = (a - r)/10;
        n = (n * 10) + r;

    }
    printf("The reversed number is %d\n", n);
    
    
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

    #ifdef WIN32

    getch();
    
    #endif
    
    return 0;
    
}