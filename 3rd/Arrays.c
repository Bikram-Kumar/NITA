#include <stdio.h>
#include <stdbool.h>
#include <vadefs.h>

void reverse_array (int* start, int n);
void merge_arrays (int* arr1, int* arr2, int* arr_merged, int n);
int min_arr(int* start, int* end);
int max_arr(int* start, int* end);
void find_duplicates(int* start, int n);
bool arr_contains(int* start, int* end, int num);
void swap_arr(int* i1, int* i2);
void scan_arr (int* start, int* end);
void print_arr (char* message, int* start, int* end);
void p1(), p2(), p3(), p4(), p5();

int main() {

    // p1();
    // p2();
    // p3();
    p4();
    // p5();

    return 0;
}


// Reverse an array, accepting the elements from the user keyboard
void p1() {
    int arr[512];
    printf("Enter numbers from 0 to 1000 as array elements:\n");

    for (int i = 0; i < 512; i++) {
        int* ptr = arr + i;
        scanf("%d", ptr);
        if (*ptr < 0 || *ptr > 1000) {
            print_arr("Entered array: ", arr, ptr);
            reverse_array(arr, i);
            print_arr("Reversed array: ", arr, ptr);
            break;
        }
    }

}

// Merge two arrays of size n
void p2() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr1[n], arr2[n], arr_merged[n+n];

    printf("Enter 1st array (%d): ", n);
    scan_arr(arr1, arr1+n);
    printf("Enter 2nd array (%d): ", n);
    scan_arr(arr2, arr2+n);

    merge_arrays(arr1, arr2, arr_merged, n);
    print_arr("Merged Array: ", arr_merged, arr_merged+n+n);

}

// Find the smallest and largest num in array
void p3() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array (%d): ", n);
    scan_arr(arr, arr+n);

    printf("Smallest: %d\nLargest: %d\n", min_arr(arr, arr+n), max_arr(arr, arr+n));
}

// Find out the duplicate elements from an array
void p4() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array (%d): ", n);
    scan_arr(arr, arr+n);

    find_duplicates(arr, n);


}


// Swap elements of an array based on positions
void p5() {

    int arr[] = {7, 9, 56, 87, 0, 54};

    size_t arr_len = sizeof(arr) / sizeof(int);

    print_arr("Initial Array: ", arr, arr + arr_len);

    printf("Swapping (0,2) and (1,4)...\n");
    swap_arr(arr, arr+2);
    swap_arr(arr+1, arr+4);

    print_arr("Final Array: ", arr, arr + arr_len);


}



void reverse_array(int* start, int n) {

    int tmp;
    for (int i = 0; i < n/2; i++) {
        tmp = *(start + i);
        *(start + i) = *(start + n - i - 1);
        *(start + n - i - 1) = tmp;
    }

}

void merge_arrays(int* arr1, int* arr2, int* arr_merged, int n) {
    for (int i = 0; i < n; i++) {
        arr_merged[i] = arr1[i];
    }
    for (int i = 0; i < n; i++) {
        arr_merged[n+i] = arr2[i];
    }
}




int min_arr(int *start, int *end) {
    int* min = start++;

    while (start < end) {
        if (*min > *start) {
            min = start;
        }
        start++;
    }

    return *min;
}




int max_arr(int *start, int *end) {
      int* max = start++;

    while (start < end) {
        if (*max < *start) {
            max = start;
        }
        start++;
    }

    return *max;
}

void find_duplicates(int *start, int n) {

    int dups[n], dups_i = 0;

    for (int i = 0; i < n; i++) {

        int num = *(start+i);

        if (arr_contains(dups, dups+dups_i, num)) {
            printf("Found duplicate %d at index %d\n", num, i);

        } else if (arr_contains(start, start+i, num)) {
            printf("Found duplicate %d at index %d\n", num, i);
            dups[dups_i] = num;
            dups_i++;
        }
    }


}

bool arr_contains(int *start, int *end, int num)
{
    while (start < end) {

        if ((*start) == num) return true;
        start++;
    }
    return false;
}


void swap_arr(int *i1, int *i2) {
    int tmp = *i1;
    (*i1) = (*i2);
    (*i2) = tmp;
}

void scan_arr(int* start, int* end){
    while (start < end) {
        scanf("%d", start);
        start++;
    }

}

void print_arr(char* message, int* start, int* end){
    printf("%s", message);

    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}

