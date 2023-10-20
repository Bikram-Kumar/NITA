#include <stdio.h>
#include <math.h>

int main() 
{
    int a;
    float s;
    printf("Enter number for prime test: ");
    scanf("%d", &a);
    
    s = sqrt(a);
    
    for (int i = 2; i <= s; i++) {
        if (a % i == 0) {
            printf("The number %d is divisible by %d and is not prime.\n", a, i);
            return 0;
        }
    }
    
    printf("The number %d is prime.\n", a);
    return 0;
}