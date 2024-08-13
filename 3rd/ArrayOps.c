#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifdef __INTELLISENSE__
  #pragma diag_suppress 28
#endif

#define ARR_MAX_SIZE 512


void handle_insert(int* arr, int* n);
void handle_delete(int* arr, int* n);
void print_arr(char* msg, int* start, int* end);
void handle_modify(int* arr, int* n);


// Using pointers, implement the following operations in an array: Insert, Delete, Display, and Modify
// Create a menu-driven architecture to implement the above.
int main() {

    int arr[ARR_MAX_SIZE];
    int n = 0, opt;


    while (true) {
        printf("Choose operation:\n1. Insert\n2. Delete\n3. Display\n4. Modify\n5. Restart\n(*) Exit\n: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                handle_insert(arr, &n);
                break;
            case 2:
                handle_delete(arr, &n);
                break;
            case 3:
                print_arr("Array: ", arr, arr+n);
                break;
            case 4:
                handle_modify(arr, arr+n);
                break;
            case 5:
                main(); 
                return 0;
            default:
                return 0;
        }
    }

    return 0;
}




void handle_insert(int* arr, int* n) {
    int num, index, temp;
    printf("Enter element to insert: ");
    scanf("%d", &num);
    printf("Enter index to insert into: ");
    scanf("%d", &index);
    if (index < 0 || index > *n) {
        printf("Cannot insert at given index!\n");
        return;
    }

    for (int i = index; i <= *n; i++) {
        temp = arr[i];
        arr[i] = num;
        num = temp;
    }

    (*n)++;

}

void handle_delete(int *arr, int *n) {
    int index;
    printf("Enter index to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= *n) {
        printf("No element at given index!\n");
        return;
    }

    for (int i = index; i < *n; i++) {
        arr[i] = arr[i+1];
    }

    (*n)--;

}

void print_arr(char* msg, int* start, int* end){
    printf("%s", msg);
    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}

void handle_modify(int *arr, int *n) {
    int index, num;
    printf("Enter index to modify: ");
    scanf("%d", &index);
    if (index < 0 || index >= *n) {
        printf("No element at given index!\n");
        return;
    }
    
    printf("Enter new value: ");
    scanf("%d", &num);

    arr[index] = num;

}
