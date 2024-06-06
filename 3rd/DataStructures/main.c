
#include "main.h"
#define NEW(x) malloc(sizeof(x))


void print_child (Tree* t) {
    for (int i = 0; i < t->degree; i++) {
        printf("%d ", t->children[i]->val);
    }
}


void print(Tree* t) {
    print_child(t);
    printf("\n");
    for (int i = 0; i < t->degree; i++) {
        print_child(t->children[i]);
        printf(" ");
    }
    printf("\n");
    
}

void print_arr(char* mess, BinaryTree** arr, BinaryTree** end) {
    printf("%s", mess);
    while (arr < end) {
        printf("%d ", (*arr)->val);
        arr++;
    }
    printf("\n");
}





int main() {
    BinaryTree* t = create_binary_tree(0);
    
    t->set_left(t, create_binary_tree(1));
    t->set_right(t, create_binary_tree(2));
    
    t->set_left(t->left, create_binary_tree(3));
    t->set_right(t->left, create_binary_tree(4));
    t->set_left(t->right, create_binary_tree(5));
    t->set_right(t->right, create_binary_tree(6));
    
    t->set_right(t->left->right, create_binary_tree(10));
    t->set_right(t->right->left, create_binary_tree(12));
   
    
    printf("size: %d\n", t->get_size(t));

    
    
    BinaryTree** arr = malloc(sizeof(BinaryTree*) * t->get_size(t));
    
    t->traverse_bfs(t, arr);
    print_arr("bfs: ", arr, arr + t->get_size(t));
    
    t->traverse_pre(t, arr);
    print_arr("pre: ", arr, arr + t->get_size(t));
    
    t->traverse_in(t, arr);
    print_arr("in: ", arr, arr + t->get_size(t));
    
    t->traverse_post(t, arr);
    print_arr("post: ", arr, arr + t->get_size(t));
    
    t->destroy(t);
    free(arr);
    
    return 0;
}