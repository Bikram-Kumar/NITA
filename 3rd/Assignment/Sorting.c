#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



#define N 30000


void swap (int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}



void bubble_sort(int* start, int* end) {
    bool swapped;
    do {
        swapped = false;
        for (int* i = start; i < end-1; i++) {
            if (*i > *(i+1)) {
                swap(i, i+1);
                swapped = true;
            }
        }
        end--;
    } while (swapped);

}



void insertion_sort(int* arr, int n){
    
    for (int i = 1; i < n; i++) {
        for (int j = i; (j > 0) && (arr[j] < arr[j-1]); j--) {
            swap(arr+j, arr+j-1);
        } 
    }
}


void shell_sort(int* arr, int n){
    int gaps[] = {701, 301, 132, 57, 23, 10, 4, 1}; // Ciura gap sequence

    for (int g = 0; g < sizeof(gaps)/sizeof(gaps[0]); g++) {
        
        // insertion sort for all gaps
        for (int i = gaps[g]; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while ((j >= gaps[g]) && (arr[j - gaps[g]] > temp)) {
                swap(arr+j, arr+j-1);
                j -= gaps[g];
            } 
            arr[j] = temp;
        }


    }

}





int main () {

    int arrB[N], arrI[N], arrS[N];
    for (int i = 0; i < N; i++){
        arrB[i] = rand();
        arrI[i] = arrB[i];
        arrS[i] = arrB[i];
        // printf("%d\n", arrB[i]);
    }

    time_t t1 = time(NULL);
    bubble_sort(arrB, arrB+N);
    time_t t2 = time(NULL);
    insertion_sort(arrI, N);
    time_t t3 = time(NULL);
    shell_sort(arrS, N);
    time_t t4 = time(NULL);

    printf(
        "Time taken by Bubble, Insertion and Shell sort algorithms are %lf, %lf and %lf, respectively.\n",
        difftime(t2, t1), difftime(t3, t2), difftime(t4, t3)
    );

    
    return 0;
}