
#include "main.h"



void print_num(char* mess, int num) {
    printf("%s: %d\n", mess, num);
}

void print_arr(char* mess, int* arr, int* end) {
    printf("%s", mess);
    while (arr < end) {
        printf("%d ", (*arr));
        arr++;
    }
    printf("\n");
}

void print_garr(char* mess, char** arr, char** end) {
    printf("%s", mess);
    while (arr < end) {
        printf("%s ", (*arr));
        arr++;
    }
    printf("\n");
}





int main() {

    char name[] = "Bikram";
    DArray* arr = create_empty_darray();
    GArray* garr = create_empty_garray();
    
    for (int i = 0; i < 168; i++) {
        arr->append(arr, 6);
        garr->append(garr, name);
        
    }
    
    print_num("size", arr->size);
    print_num("size", garr->size);
    print_num("cap", arr->capacity);
    print_num("cap", garr->capacity);
    
    arr->shrink_to_fit(arr);
    garr->shrink_to_fit(garr);
        
    print_num("size", arr->size);
    print_num("size", garr->size);
    print_num("cap", arr->capacity);
    print_num("cap", garr->capacity);
    
    print_arr("DArray: ", arr->arr, arr->arr+arr->size);
    print_garr("GArray: ", garr->arr, garr->arr+garr->size);
    arr->destroy(arr);
    garr->destroy(garr);
    
    return 0;
}