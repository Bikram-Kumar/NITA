#include <stdio.h>



void add(float, float), subtract(float, float), multiply (float, float), divide(float, float);

int main () {
    float a, b;
    int op;
    
    printf("Enter first number: ");
    scanf("%f", &a);
    printf("Enter second number: ");
    scanf("%f", &b);
    
    printf("Choose operation to perform (1/2/3/4): \n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &op);
    
    switch (op) {
        case 1:
            add(a, b);
            break;
        case 2:
            subtract(a, b);
            break;
        case 3:
            multiply(a,b);
            break;
        case 4:
            divide(a,b);
            break;
    }
    
    return 0;
}


void add(float a, float b) {
    printf("%f + %f = %f\n", a, b, a+b);
}
void subtract(float a, float b) {
    printf("%f - %f = %f\n", a, b, a-b);
}
void multiply(float a, float b) {
    printf("%f * %f = %f\n", a, b, a*b);
}
void divide(float a, float b) {
    printf("%f / %f = %f\n", a, b, a/b);
}