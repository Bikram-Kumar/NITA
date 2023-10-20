#include <stdio.h>
#include <math.h>

int main() 
{
    // floor, ceil, pow, sqrt
    float f, c;
    int b, e, s;
    
    printf("Enter a floating point number to floor: ");
    scanf("%f", &f);
    printf("The floored number is %.0lf\n", floor(f));
    
    printf("Enter a floating point number to ceil: ");
    scanf("%f", &c);
    printf("The ceiled number is %.0lf\n", (ceil(c)));
    
    printf("Enter base and exponent (separated by a comma): ");
    scanf("%d, %d", &b, &e);
    printf("The base raised to exponent (%d^%d) is %.0lf\n", b, e, pow(b,e));
    
    printf("Enter a number to calculate its square root: ");
    scanf("%d", &s);
    printf("The square root of %d is %f\n", s, (sqrt(s)));
    
    return 0;
}