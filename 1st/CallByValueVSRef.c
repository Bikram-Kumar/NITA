#include <stdio.h>

void change_cbv(int), change_cbr(int *);


int main () {
    int x = 100;
    printf("Value of x before calling change_cbv: %d\n", x);
    change_cbv(x);
    printf("Value of x after calling change_cbv: %d\n", x);
    
    change_cbr(&x);
    printf("Value of x after calling change_cbr: %d\n", x);
}

void change_cbv(int num) {
    printf("Value of num passed to change_cbv: %d\n", num);
    num += 100;
    printf("Value of num after changing in change_cbv: %d\n", num);
}

void change_cbr(int *num) {
    printf("Value of num passed to change_cbr: %d\n", *num);
    (*num) += 100;
    printf("Value of num after changing in change_cbr: %d\n", *num);
}