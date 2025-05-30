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
        int temp = arr[i];
        int j;
        for (j = i; (j > 0) && (arr[j-1] > temp); j--) {
            arr[j] = arr[j-1];
        } 
        arr[j] = temp;
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
                arr[j] = arr[j-gaps[g]];
                j -= gaps[g];
            } 
            arr[j] = temp;
        }


    }

}




void selection_sort(int* arr, int n){
    int max;
    while (n--) {
        max = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i] > arr[max]) max = i;
        }
        swap(arr+n, arr+max);
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


double diffclock(clock_t t2, clock_t t1) {
    return (double)(t2 - t1) / CLOCKS_PER_SEC;
}



int main () {

    int arrBubble[N], arrInsert[N], arrShell[N], arrSelect[N];

    srand(time(NULL));
    for (int i = 0; i < N; i++){
        arrBubble[i] = rand();
        arrInsert[i] = arrBubble[i];
        arrShell[i] = arrBubble[i];
        arrSelect[i] = arrBubble[i];
        // printf("%d\n", arrBubble[i]);
    }

    clock_t t1 = clock();
    bubble_sort(arrBubble, arrBubble+N);
    clock_t t2 = clock();
    insertion_sort(arrInsert, N);
    clock_t t3 = clock();
    shell_sort(arrShell, N);
    clock_t t4 = clock();
    selection_sort(arrSelect, N);
    clock_t t5 = clock();

    // print_arr("Bubble: ", arrBubble, arrBubble+N);
    // print_arr("Insertion: ", arrInsert, arrInsert+N);
    // print_arr("Shell: ", arrShell, arrShell+N);
    // print_arr("Selection: ", arrSelect, arrSelect+N);

    printf(
        "Time taken by Bubble, Insertion and Shell sort algorithms are %lf s, %lf s and %lf s, respectively.\n",
        diffclock(t2, t1), diffclock(t3, t2), diffclock(t4, t3)
    );
    printf(
        "Time taken by Selection, -- and -- sort algorithms are %lf s, %lf s and %lf s, respectively.\n",
        diffclock(t5, t4), diffclock(t3, t2), diffclock(t4, t3)
    );

    
    return 0;
}