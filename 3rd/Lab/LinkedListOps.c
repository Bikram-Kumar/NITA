#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


ListNode* create_list_node(int val) {
    ListNode* node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void destroy_list(ListNode* head) {
    if (!head) return;
    destroy_list(head->next);
    free(head);
}



void list_display(ListNode* head) {
    printf("Linked List: ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int get_length(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}



void list_insert(ListNode** head, int pos, int val) {

    if (pos < 0 || pos > get_length(*head)) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 0) {
        ListNode* temp = *head;
        *head = create_list_node(val);
        (*head)->next = temp;
        return;
    }

    ListNode* node = *head;
    while (--pos) {
        node = node->next;
    }

    ListNode* temp = node->next;
    node->next = create_list_node(val);
    node->next->next = temp;
            
}


void handle_insert(ListNode** head) {

    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    if (!(*head)) {
        *head = create_list_node(val);
        return;
    }

    int op;

    printf("Insert at?\n 1. Back\n 2. Front\n 3. Position\n: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            list_insert(head, get_length(*head), val);
            break;
        case 2:
            list_insert(head, 0, val);
            break;
        case 3:
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);

            list_insert(head, pos, val);

            break;
    }
    
}




void list_delete(ListNode** head, int pos) {

    if (pos < 0 || pos >= get_length(*head)) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 0) {
        ListNode* temp = (*head)->next;
        free(*head);
        *head = temp;
        return;
    }

    ListNode* prev = NULL;
    ListNode* node = *head;
    while (pos--) {
        prev = node;
        node = node->next;
    }

    ListNode* temp = node->next;
    prev->next = temp;
    free(node);
             
}




void handle_delete(ListNode** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    int op;

    printf("Delete at?\n 1. Back\n 2. Front\n 3. Position\n: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            list_delete(head, get_length(*head)-1);
            break;
        case 2:
            list_delete(head, 0);
            break;
        case 3:
            int pos;
            printf("Enter position: ");
            scanf("%d", &pos);
            
            list_delete(head, pos);
            break;
    }
    
}





void handle_modify(ListNode* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= get_length(head)) {
        printf("Invalid position!\n");
        return;
    }
    

    while (pos--) {
        head = head->next;
    }

    int val;
    printf("Enter new value: ");
    scanf("%d", &val);

    head->val = val;

}


ListNode* list_reverse(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* node = head;
    ListNode* prev = NULL, *next;

    while (node) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    return prev;

}





int main () {

    ListNode* head = NULL;


    int op = 1;
    while (op > 0 && op < 7) {
        printf("Choose operation:\n1. Insert\n2. Delete\n3. Modify\n4. Show Length\n5. Reverse list\n6. Display\n(*) Exit\n: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                handle_insert(&head);
                break;
            case 2:
                handle_delete(&head);
                break;
            case 3:
                handle_modify(head);
                break;
            case 4:
                printf("%d\n", get_length(head));
                break;
            case 5:
                head = list_reverse(head);
                break;
            case 6:
                list_display(head);
                break;
        }

    }

    destroy_list(head);
    
    return 0;
}
