#include <stdio.h>
#include <time.h>

/*
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
*/



int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    clock_t t0 = clock();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < (n + i); j++) {
            if (j <= n-i) {
                printf("  ");
                if (n > 9) printf(" ");
            } else if (j <= n) {
                printf("%d ", j-n+i);
                if (n > 9 && (j-n+i < 10)) printf(" ");
            } else {
                printf("%d ", n+i-j);
                if (n > 9 && (n+i-j < 10)) printf(" ");
            }
        }
        printf("\n");
    }
    clock_t t1 = clock();

    printf("Time taken to print: %lf s", (double)(t1-t0) / CLOCKS_PER_SEC);

    return 0;
}


