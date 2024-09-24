#include <stdio.h>
#include <time.h>

#define ITERATIONS 30000

time_t for_time();
time_t while_time();
time_t do_while_time();
time_t goto_time();
time_t recursion_time();


int main() {
    time_t f, w, d, g, r;
    f = for_time();
    w = while_time();
    d = do_while_time();
    g = goto_time();
    r = recursion_time();
    printf("Time taken by for: %lld s\n", f);
    printf("Time taken by while: %lld s\n", w);
    printf("Time taken by do while: %lld s\n", d);
    printf("Time taken by goto: %lld s\n", g);
    printf("Time taken by recursion: %lld s\n", r);

    return 0;
}


time_t for_time () {
    time_t t1 = time(NULL);
    for (int i = 0; i < ITERATIONS; i++) {
        printf("Hello World! %d\n", i);
    }

    return (time(NULL) - t1);

}

time_t while_time () {
    time_t t1 = time(NULL);
    int i = 0;
    while (i < ITERATIONS) {
        printf("Hello World! %d\n", i);
        i++;
    }

    return (time(NULL) - t1);

}
time_t do_while_time () {
    time_t t1 = time(NULL);

    int i = 0;

    do {
        printf("Hello World! %d\n", i);
        i++;
    } while (i < ITERATIONS);
    

    return (time(NULL) - t1);

}
time_t goto_time () {
    time_t t1 = time(NULL);

    int i = 0;
    loop:
        printf("Hello World! %d\n", i);
        i++;
        if (i < ITERATIONS) goto loop;
    

    return (time(NULL) - t1);

}

void print(int i) {
    if (i < ITERATIONS) {
        printf("Hello World! %d\n", i);
        print(i+1);
    }
}

time_t recursion_time () {
    time_t t1 = time(NULL);

    print(0);
    

    return (time(NULL) - t1);

}