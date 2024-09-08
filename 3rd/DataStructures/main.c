
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

void print_ll(char* mess, DLinkedList* ll) {
    printf("%s", mess);
    while (ll != NULL) {
        printf("%d ", (ll->val));
        ll = ll->next;
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
    DLinkedList* ll = create_dlinkedlist(0);
    ll->push_back(ll, create_dlinkedlist(1));
    ll = ll->push_front(ll, create_dlinkedlist(5));
    ll->push_back(ll, create_dlinkedlist(15));
    ll = ll->push_front(ll, create_dlinkedlist(8));

    print_ll("hi: ", ll);
   
    return 0;
}