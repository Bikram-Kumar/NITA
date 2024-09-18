#include <stdio.h>
#include <time.h>
#include <stdint.h>


uint32_t rand_state;

void seed_random(int seed);
double random();
void show();

int main () {
    int l, u, n;
    printf("Enter lower limit: ");
    scanf("%d", &l);
    printf("Enter upper limit: ");
    scanf("%d", &u);
    printf("Enter number of random numbers to generate: ");
    scanf("%d", &n);

    // seed the generator with current time so that it's different across multiple runs
    seed_random(time(NULL));


    for (int i = 0; i < n; i++) {
        
        // printf("%lf ", random());  // uncomment to see actual random number

        printf("%d ", (int)(l + (random() * (u-l))));
    }

    printf("\n");

    // show();    // uncomment to show the random numbers as white and black pixels

    return 0;
}


// generates random bits and outputs them to `stdout` as white and black pixels
// (zoom out in console for better visualization)
void show () {

    int m = 50, n = 168; // rows and columns to fill with random pixels
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

    printf("%lf\n", (double)k/(m*n));  // shows ratio of total 1's generated
}



// initializes the state for random number generation
void seed_random(int seed){
    rand_state = seed;
    // first two states are close for close seeds, so discard them
    random();
    random();
}


// generates a random `double` between 0 and 1
double random(){

    rand_state ^= rand_state >> 7;
    rand_state ^= rand_state << 9;
    rand_state ^= rand_state >> 13;
    return ((double)rand_state/0xffffffffu);
}
