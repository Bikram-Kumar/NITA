#include <stdio.h>

int main () {
    
    int n, temp;
    int swapped;
    printf("Enter length of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    /*
    for (int i = 0; i < n-1; i++) {
        swapped = 0;
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        
        if (!swapped) break;
        
    }
    */
    
    
    
    int k = n;
    do {
        swapped = 0;
        for (int i = 0; i < k-1; i++) {
            if (arr[i] > arr[i+1]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
               
                swapped = 1;
            }
        }
        k -= 1;
    } while (swapped);
    
    
    
    
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}