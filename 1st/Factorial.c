#include <stdio.h>

int factorial(int n) {
    if(n == 0) {
        return 1;
    } else if(n == 1) {
        return 1;
    } else {
        return (n * factorial(n-1));
    }
}

int main() {
    int n;
    printf("Enter number to calculate its factorial: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
}