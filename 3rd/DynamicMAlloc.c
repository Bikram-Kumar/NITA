#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void scan_arr(int* arr, int* end);
void print_arr_with_address(int* arr, int n);
void print_arr(char* message, int* start, int* end);
void bubble_sort(int* start, int* end);
int hcf(int* x, int* y);
void handle_modify_detail(int* reg_no, float* cgpa, int* semester, int n);

void p1(), p2(), p3(), p4(), p5();



int main() {

    // p1();
    // p2();
    // p3();
    p4();
    // p5();

    return 0;
}




// Demonstrate the usage of `malloc()`, `calloc()`, `realloc()` and `free()` functions
void p1(){
    int n = 10;

    printf("Allocating memory for %d ints on heap...\n", n);
    int* arr_m = malloc(n * sizeof(int)); // malloc takes 1 arg
    int* arr_c = calloc(n, sizeof(int)); // calloc takes 2 args
    
    printf("Memory address allocated by malloc = %p to %p\n\tcalloc = %p to %p\n", arr_m, arr_m+n, arr_c, arr_c+n);
    // calloc sets default values while malloc stores garbage
    printf("Default values of memory allocated by malloc = %d(garbage), calloc = %d\n", arr_m[0], arr_c[0]);
    arr_m[0] = 6;
    arr_c[0] = 45;
    printf("Values after assignment: arr_m[0] = %d, arr_c[0] = %d\n", arr_m[0], arr_c[0]); 


    // realloc moves previously allocated data to new memory with new size
    arr_m = realloc(arr_m, 5*n); // increase allocated memory size
    arr_c = realloc(arr_c, n/2); // decrease it

    printf("New memory address of arr_m = %p to %p\n\tarr_c = %p to %p\n", arr_m, arr_m+(5*n), arr_c, arr_c+(n/2));
    printf("arr_m[0] = %d, arr_c[0] = %d\n", arr_m[0], arr_c[0]); // data is copied to new address

    printf("Freeing up the allocated memory on heap after use...\n");
    free(arr_m);
    free(arr_c);

}


// Implement Dynamic Memory Allocation and accept an array of size n. Display the elements and addreses accordingly.
void p2(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));

    printf("Enter array (%d): ", n);
    scan_arr(arr, arr+n);
    print_arr_with_address(arr, n);

    free(arr);

}



// Implement any sorting algorithm using DMA on any array of sizxe n
void p3(){

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));

    printf("Enter array (%d): ", n);
    scan_arr(arr, arr+n);

    bubble_sort(arr, arr+n);

    print_arr("Sorted Array: ", arr, arr+n);

    free(arr);

}


// Accept data about n students such as registration no., cgpa and semester. Display these details accordingly.
// Modify the student details based on registration no.
void p4() {

    int n, opt = 1;
    printf("Enter n: ");
    scanf("%d", &n);

    int* reg_no = malloc(n * sizeof(int));
    float* cgpa = malloc(n * sizeof(float));
    int* semester = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter student %d details (Reg_No CGPA Semester): ", i);
        scanf("%d %f %d", reg_no + i, cgpa + i, semester + i);
    }

    while (opt == 1 || opt == 2) {
        printf("Choose option:\n1. Display\n2. Modify\n(*) Exit\n: ");
        scanf("%d", &opt);

        if (opt == 1) {

            printf("Index\tReg_No\tCGPA\tSemester\n");
            for (int i = 0; i < n; i++) {
                printf("%d\t%d\t%g\t%d\n", i, *(reg_no + i), *(cgpa + i), *(semester + i));
            }

        } else if (opt == 2) {
            handle_modify_detail(reg_no, cgpa, semester, n);
        }
    }



    free(reg_no);
    free(cgpa);
    free(semester);

}


// Implement recursion along with DMA. Find the HCF of the given nums
void p5(){

    int* nums = malloc(2 * sizeof(int));

    printf("Enter nums: ");
    scanf("%d %d", nums, nums+1);

    int h = (*(nums) > *(nums+1)) ? hcf(nums, nums+1): hcf(nums+1, nums);

    printf("HCF of %d and %d is %d\n", *nums, *(nums+1), h);

    free(nums);
}






void scan_arr(int* arr, int* end){
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



void bubble_sort(int* start, int* end) {

    int temp;
    bool swapped;
    do {
        swapped = false;
        for (int* i = start; i < end-1; i++) {

            if (*i > *(i+1)) {
                temp = *(i+1);
                *(i+1) = *i;
                *i = temp;
               
                swapped = true;
            }
        }
        end--;
    } while (swapped);
    

}


void print_arr(char* message, int* start, int* end){
    printf("%s", message);

    while (start < end) {
        printf("%d ", *start);
        start++;
    }

    printf("\n");
}





int hcf(int* x, int* y) {
    int r = (*x) % (*y);
    
    if (r == 0) return (*y);
    
    return hcf(y, &r);
    
}


void handle_modify_detail(int* reg_no, float* cgpa, int* semester, int n) {
    int query_reg, index = -1;
    printf("Enter Reg_No to modify: ");
    scanf("%d", &query_reg);

    for (int i = 0; i < n; i++) {
        if (reg_no[i] == query_reg) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Entered Reg_No not found!\n");
        return;
    }

    printf("Enter new details (CGPA Semester): ");
    scanf("%f %d", cgpa+index, semester+index);
    printf("Details modified successfully!\n");

}