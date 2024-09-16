#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdint.h>

uint32_t rand_state;

void seed_random(int seed);
double random();

int main () {
    int l, u, n;
    printf("Enter lower limit: ");
    scanf("%d", &l);
    printf("Enter upper limit: ");
    scanf("%d", &u);
    printf("Enter number of random numbers to generate: ");
    scanf("%d", &n);

    seed_random(time(NULL));
    // int start = rand_state, p = 0;
    // do {
    //     random();
    //     p++;
    // printf("%d\n", p);
    // } while (start != rand_state);

    for (int i = 0; i < n; i++) {
        // printf("%lf ", random() );
        printf("%d ", (int)(l + (random() * (u-l))));
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

void seed_random(int seed){
    rand_state = seed;
    random();
    random();
}

double random(){

    rand_state ^= rand_state >> 7;
    rand_state ^= rand_state << 9;
    rand_state ^= rand_state >> 13;
    return ((double)rand_state/0xffffffffu);
}
