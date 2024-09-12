#include <stdio.h>


void p1(), p2(), p3(), p4(), p5();
void p6(), p7(), p8(), p9(), p10();

int main () {
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8();
    // p9();
    p10();

    return 0;
}

void p1() {

    int a = 0, b = 1;

    if (b = a++) {
        printf("%d\n", a & b);
    } else {
        printf("%d\n", a ^ b);
    }

}


void p2(){
    int i;
    char c;

    scanf("%d", &i);
    scanf("%c", &c);

    printf("%d\n", i-c);

}


void p3(){
    int a = 6;
    int b = a++;
    while (b <= a+++1) {
        printf("%d %d ", a, b);
        b+=2;
    }
}

void p4(){
    int a = 1, b = 1, n = 8;

    do {
        a = (a + 1) % n;
        b = (b + 2) % n;
        printf("%d ", b);

    } while (a != b);
}

void p5(){
    int n[] = {8, 2050, 80, 6, 0, 45, 12};
    int i = printf("%d\n", n[1]);
    printf("%d\n", n[i]);
}

void p6(){
    int n = 15;
    for (int i = 14; i > 0; i--) {
        n &= i;
    }
    printf("%d\n", n);
}

void p7(){
    int arr[][3] = {{1, 2, 30}, {4, 50, 6}, {70, 8, 9}};
    int j = arr[0][0] ^ arr[1][0];
    printf("%d\n", *(arr[0] + j));

}





char fun(int n) {
    static int i;
    return (n+++i++);
}

void p8(){
    int n = 1;
    for (int i = 0; i < 5; i++ + 1) {
        n = fun(n);
        printf("%d ", n);
    }
}






int func (int n) {
    if (n == 1) return printf("%d\n", n);
    return (n * func(n-1));
}

void p9(){
    printf("%d\n", func(5));
}


void p10(){
    int a = 4;
    switch (a = (a = 5) ? (int)0.99*5 : 4) {
        default: printf("The ");
        case 5: printf("Quick ");
        case 1: printf("Brown ");
        case 4: printf("Fox\n");
    }

}

