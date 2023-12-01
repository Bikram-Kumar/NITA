#include <stdio.h>

int main()
{
    int a = 0, b = 1, temp;
    int n;
    printf("Enter number of terms to print: ");
    scanf("%d", &n);
    
    printf("%d ", a);
    if (n > 1) {
        printf("%d ", b);
    }
    
    
    for (int i = 2; i < n; i++) {
        printf("%d ", a + b);
        temp = a;
        a = b;
        b += temp;
    }
    
    
    printf("\n");
    
    return 0;
}