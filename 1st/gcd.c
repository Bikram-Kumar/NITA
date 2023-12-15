#include <stdio.h>

int gcd(int,int);
   
int main()
{
    int x,y,g;
    scanf("%d %d", &x, &y);
    
    g = (x < y) ? gcd(y,x) : gcd(x,y);
    
    printf("%d\n", g);
    
    return 0;
}



int gcd(int x, int y) {
    int r = x % y;
    
    if (r == 0) return y;
    
    return gcd(y,r);
    
}