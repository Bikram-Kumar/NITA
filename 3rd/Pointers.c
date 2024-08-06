#include <stdio.h>



#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif



void print_multi_table(int* num);
void scan_arr(int* arr, int n);
void print_arr_with_address(int* arr, int n);
void change_arr_cbv(int arr[], int n);
void change_arr_cbr(int* arr, int n);
void print_arr(char* message, int* start, int* end);
void bubble_sort(int* start, int* end);

void p1(), p2(), p3(), p4(), p5();


int main () {


    // p1();
    // p2();
    // p3();
    // p4();
    p5();


    return 0;
}



// Using pointers, find the multiplication table of a number
void p1() {
    int n;
    printf("Enter a num: ");
    scanf("%d", &n);

    print_multi_table(&n);

}



// Find the sum of two numbers using pointers
void p2() {
    int a, b;
    int *ptr_a = &a, *ptr_b = &b;
    printf("Enter two numbers: ");
    scanf("%d %d", ptr_a, ptr_b);
    printf("Sum = %d\n", (*ptr_a) + (*ptr_b));
}



// Input an array of size n using pointers. Display the values in array along with their addresses
void p3() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter array (%d): ", n);
    scan_arr(arr, n);
    print_arr_with_address(arr, n);


}


// Implement the usage of call by value and call by reference.
// Use two different arrays for call by value and call by reference.
// Aim is to show that arrays can't be passed by value and the notation arr[] actually decays to a pointer
void p4() {
    int arr1[] = {5, 9, 6, 0};
    int arr2[] = {2, 13, 8, 7};

    printf("Initial value of arr1[1] = %d\n", arr1[1]);
    printf("Calling change by value for arr1...\n");
    change_arr_cbv(arr1, sizeof(arr1)/sizeof(int));
    printf("Final value of arr1[1] = %d\n", arr1[1]);

    printf("Initial value of arr2[3] = %d\n", arr2[3]);
    printf("Calling change by reference for arr2...\n");
    change_arr_cbr(arr2, sizeof(arr2)/sizeof(int));
    printf("Final value of arr2[3] = %d\n", arr2[3]);

}


// Implement Bubble Sort using pointers.
void p5() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];


    printf("Enter array (%d): ", n);
    scan_arr(arr, n);
    bubble_sort(arr, arr+n);

    print_arr("Sorted Array: ", arr, arr+n);

}



void print_multi_table(int* num) {
    for (int i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", *num, i, (*num) * i);
    }

}


void scan_arr(int* arr, int n){
    int* end = arr + n;
    while (arr < end) {
        scanf("%d", arr);
        arr++;
    }
}

void print_arr_with_address(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Element %d = %d, Address = %p\n", i, *(arr+i), arr+i);
    }
}



void change_arr_cbv(int arr[], int n) {
    printf("Changing arr[1] to 8 in call by value...\n");
    arr[1] = 8;
}



void change_arr_cbr(int* arr, int n) {
    printf("Changing arr[3] to 5 in call by reference...\n");
    arr[3] = 5;
}


void print_arr(char* message, int* start, int* end){
    printf("%s", message);

    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}



void bubble_sort(int* start, int* end) {
    int n = end - start;
    int k = n, swapped, temp;
    do {
        swapped = 0;
        for (int i = 0; i < k-1; i++) {
            if (*(start + i) > *(start+i+1)) {
                temp = *(start+i+1);
                *(start+i+1) = *(start+i);
                *(start+i) = temp;
               
                swapped = 1;
            }
        }
        k -= 1;
    } while (swapped);
    
    

}