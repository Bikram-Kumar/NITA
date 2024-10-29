#include <stdio.h>
#include <time.h>



#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif



int linear_search (int* arr, int n, int val, int* count) {
    for (int i = 0; i < n; i++) {
        (*count)++;
        if (arr[i] == val) return i;
        
    }
    return -1;
}


int binary_search (int* arr, int n, int val, int* count) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        (*count)++;
        if (arr[mid] < val) {
            left = mid + 1;
        } else if (arr[mid] > val) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}


void scan_arr(int* start, int* end){
    while (start < end) {
        scanf("%d", start);
        start++;
    }

}



int main () {
    int n, val, lcount = 0, bcount = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array: ");
    scan_arr(arr, arr+n);
    printf("Enter value to find: ");
    scanf("%d", &val);

    clock_t t1 = clock();
    int li = linear_search(arr, n, val, &lcount);
    clock_t t2 = clock();
    int bi = binary_search(arr, n, val, &bcount);
    clock_t t3 = clock();

    if (li == -1) {
        printf("Value not found by linear search.\n");
    } else {
        printf("Value found at index %d in %d iterations by linear search.\n", li, lcount);
    }
    if (bi == -1) {
        printf("Value not found by binary search.\n");
    } else {
        printf("Value found at index %d in %d iterations by binary search.\n", bi, bcount);
    }

    printf("Time taken by linear search = %.12lf s\n", (t2-t1) / CLOCKS_PER_SEC);
    printf("Time taken by binary search = %.12lf s\n", (t3-t2) / CLOCKS_PER_SEC);


    
    return 0;
}