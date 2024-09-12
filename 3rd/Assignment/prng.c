#include <stdio.h>
#include <limits.h>

double random();

int main () {
    int l, u, n;
    printf("Enter lower limit: ");
    scanf("%d", &l);
    printf("Enter upper limit: ");
    scanf("%d", &u);
    printf("Enter number of random numbers to generate: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", (int)(l + (random() * u)));
    }
    printf("\n");
    return 0;
}

void show () {
    int m = 2000, n = 168;
    int k = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (random() > 0.5) {
                printf("%c", 254);
                k++;
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("%lf\n", (double)k/(m*n));
}

double random() {

    static int a = 745587445;
    a ^= a >> 7;
    a ^= a << 9;
    a ^= a >> 13;
    return ((double)a/INT_MAX);
}
