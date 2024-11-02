#include <stdio.h>
#include <stdlib.h>
#include <time.h>




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

// return diff in millisec
double diff_timespec(struct timespec* ts1, struct timespec* ts2) {
    return ((difftime(ts1->tv_sec, ts2->tv_sec) * 1e-3) + ((ts1->tv_nsec - ts2->tv_nsec) * 1e-6));
}



int main () {
    int n, val, lcount = 0, bcount = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int* arr = malloc(sizeof(int) * n);
    printf("Enter array (sorted ascending): ");
    scan_arr(arr, arr+n);
    printf("Enter value to find: ");
    scanf("%d", &val);

    struct timespec ts1, ts2, ts3;

    timespec_get(&ts1, TIME_UTC); // it takes quite long for first call, so get time twice consecutively
    timespec_get(&ts1, TIME_UTC);
    int li = linear_search(arr, n, val, &lcount);
    timespec_get(&ts2, TIME_UTC);
    int bi = binary_search(arr, n, val, &bcount);
    timespec_get(&ts3, TIME_UTC);

    if (li == -1) printf("Value not found by linear search.\n");
    else printf("Value found at index %d by linear search.\n", li);
    
    if (bi == -1) printf("Value not found by binary search.\n");
    else printf("Value found at index %d by binary search.\n", bi);
    

    printf("Linear search took %d iterations and %lf ms\n", lcount, diff_timespec(&ts2, &ts1));
    printf("Binary search took %d iterations and %lf ms\n", bcount, diff_timespec(&ts3, &ts2));

    free(arr);
    
    return 0;
}