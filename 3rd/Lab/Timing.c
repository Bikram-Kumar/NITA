#include <stdio.h>
#include <time.h>

#define ITERATIONS 30000

double for_time();
double while_time();
double do_while_time();
double goto_time();
double recursion_time();


int main() {
    double f, w, d, g, r;
    f = for_time();
    w = while_time();
    d = do_while_time();
    g = goto_time();
    r = recursion_time();
    printf("Time taken by for: %.2lf s\n", f);
    printf("Time taken by while: %.2lf s\n", w);
    printf("Time taken by do while: %.2lf s\n", d);
    printf("Time taken by goto: %.2lf s\n", g);
    printf("Time taken by recursion: %.2lf s\n", r);

    return 0;
}


double for_time () {
    time_t t1 = time(NULL);
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Hello World! %d\n", i);
    }

    return (difftime(time(NULL), t1));

}

double while_time () {
    time_t t1 = time(NULL);
    int i = 0;
    while (i < ITERATIONS) {
        printf("Hello World! %d\n", i);
        i++;
    }

    return difftime(time(NULL), t1);

}
double do_while_time () {
    time_t t1 = time(NULL);

    int i = 0;

    do {
        printf("Hello World! %d\n", i);
        i++;
    } while (i < ITERATIONS);
    

    return difftime(time(NULL), t1);

}
double goto_time () {
    time_t t1 = time(NULL);

    int i = 0;
    loop:
        printf("Hello World! %d\n", i);
        i++;
        if (i < ITERATIONS) goto loop;
    

    return difftime(time(NULL), t1);

}

void print(int i) {
    if (i < ITERATIONS) {
        printf("Hello World! %d\n", i);
        print(i+1);
    }
}

double recursion_time () {
    time_t t1 = time(NULL);

    print(0);
    

    return difftime(time(NULL), t1);

}