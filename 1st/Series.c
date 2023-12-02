#include <stdio.h>

   
int n;
double sum;

void cube(), n_nf();
int factorial(int);

int main()
{
    printf("Enter N: ");
    scanf("%d", &n);
    
    printf("The series is: \n");
    
    n_nf();
    
    
    printf("\nSum = %lf\n", sum);
     
    
    
    return 0;
}


void cube() {
    sum = 1.0;
    printf("1/%d^3 ", 1);
    
    for (int i = 2; i <= n; i++) {
        printf("+ 1/%d^3 ", i);
        sum += 1.0 / (i * i * i);
    }
    
}


void n_nf() {
    printf("1/%d! ", n);
    int nf = factorial(n);
    sum = 1.0 / nf;
    
    for (int i = 2; i <= n; i++) {
        printf("+ %d/%d! ", i, n);
        sum += (double) i / (double)nf;
    }
    
}

int factorial(int num) {
    int f = 1;
    
    for (int i = 2; i <= num; i++) {
        f *= i;
    }
    return f;
}