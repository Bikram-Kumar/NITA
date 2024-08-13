#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif


void scan_arr(int* start, int* end);
void print_arr(int* start, int* end);
void reverse_str(char *str);
bool isPrime(int n);
void print_sum (float* a, float* b);
void print_dif (float* a, float* b);
void print_mul (float* a, float* b);
void print_div (float* a, float* b);

void p1(), p2(), p3(), p4(), p5();


int main () {


    // p1();
    // p2();
    // p3();
    // p4();
    p5();


    return 0;
}


// Create an array of size n suzh that every individual address of the array has a new array of size m
void p1() {
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    int* arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter array %d (%d): ", i, m);
        arr[i] = malloc(sizeof(int) * m);
        scan_arr(arr[i], arr[i]+m);
    }


    for (int i = 0; i < n; i++) {
        printf("Array %d: ", i);
        print_arr(arr[i], arr[i]+m);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }

}


// Using pointers, accept a string array until the user terminates the input intentionally (without pressing enter)
void p2() {
    char str[512];
    printf("Enter a string (enter ; to terminate): ");
    for (int i = 0; i < 512; i++) {
        scanf("%c", str+i);

        if (*(str+i) == ';') {
            printf("\n");
            *(str+i) = '\0';
            break;
        }
    }
    printf("Entered string: %s", str);

}


// Implement reversal of a string using pointers
void p3() {
    char str[512];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Entered string: %s\n", str);
    reverse_str(str);
    printf("Reversed string: %s\n", str);
}


// a) Input an aray of size n using recursion and pointers and display it accordingly along with the addreses
// b) From the series of numbers, find out and display the prime numbers only
void p4() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    bool prime_flag = false;

    printf("Enter array (%d): ", n);
    scan_arr(arr, arr+n);
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            prime_flag = true;
            printf("Found prime %d at index %d\n", arr[i], i);
        }
    }
    if (!prime_flag) {
        printf("No primes found in array\n");
    }

}


// By using a menu-driven approach, user-defined functions and pointers, find the summation, subtraction,
// multiplication and division of two given numbers. Apply proper validation to handle undefined situations.
void p5() {
    float a, b;
    int opt;
    printf("Enter two nums: ");
    scanf("%f %f", &a, &b);
    while (true) {
        printf("Choose operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Restart\n(*) Exit\n: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                print_sum(&a, &b);
                break;
            case 2:
                print_dif(&a, &b);
                break;
            case 3:
                print_mul(&a, &b);
                break;
            case 4:
                print_div(&a, &b);
                break;
            case 5:
                p5(); 
                return;
            default:
                return;
        }
    }

}




void scan_arr(int* start, int* end){
    while (start < end) {
        scanf("%d", start);
        start++;
    }
}

void print_arr(int* start, int* end){
    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}


void reverse_str(char *str) {
    int length = strlen(str);
    char tmp;

    for (int i = 0; i < length/2; i++) {
        tmp = *(str+i);
        *(str+i) = *(str+length-i-1);
        *(str+length-i-1) = tmp;
    }
}

bool isPrime(int n) {
    if (n == 2) return true;
    if ((n < 2) || (n % 2 == 0)) return false;

    int s = sqrt(n);
    for (int i = 3; i <= s; i += 2) {
        if (isPrime(i) && (n % i == 0)) return false;
    }
    return true;
}

void print_sum (float* a, float* b) {
    printf("%g + %g = %g\n", *a, *b, (*a)+(*b));
}

void print_dif (float* a, float* b) {
    printf("%g - %g = %g\n", *a, *b, (*a)-(*b));
}

void print_mul (float* a, float* b) {
    printf("%g * %g = %g\n", *a, *b, (*a)*(*b));
}

void print_div (float* a, float* b) {
    if (*b == 0) {
        printf("Cannot divide by zero.\n");
        return;
    }
    printf("%g / %g = %g\n", *a, *b, (*a)/(*b));
}

