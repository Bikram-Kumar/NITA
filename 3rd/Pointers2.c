#include <stdio.h>
#include <stdlib.h>



#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif


void scan_arr(int* arr, int* end);
void print_arr(int* start, int* end);


void p1(), p2(), p3(), p4(), p5(), p6();


int main () {


    p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();


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
}


// Implement reversal of a string using pointers
void p3() {
}


// a) Input an aray of size n using recursion and pointers and display it accordingly along with the addreses
// b) From the series of numbers, find out and display the prime numbers only
void p4() {
}


// By using a menu-driven approach, user-defined functions and pointers, find the summation, subtraction,
// multiplication and division of two given numbers. Apply proper validation to handle undefined situations.
void p5() {
}


// Using pointers, implement the following operations in an array: Insert, Delete, Display, and Modify
// Create a menu-driven architecture to implement the above.
void p6() {
}



void scan_arr(int* arr, int* end){
    while (arr < end) {
        scanf("%d", arr);
        arr++;
    }
}

void print_arr(int* start, int* end){
    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}
