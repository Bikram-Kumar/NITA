#include <stdio.h>


int main() {
    
    int n, k, flag = 0;
    printf("Enter length of array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter value to search: ");
    scanf("%d", &k);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("Value found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    
    if (!flag) {
        printf("Value not found in array.\n");
    }
    
    return 0;
}