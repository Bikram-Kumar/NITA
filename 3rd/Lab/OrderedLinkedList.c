#include <stdio.h>
#include <stdlib.h>



/*     
    Organize a LinkedList while creating in such a way that it is ordered either ascending or descending.
    Also handle validation for duplicate elements.
*/

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

int compare(int a, int b, int order) {
    return (order) ? (a > b) : (a < b);
}



void list_add(ListNode** head, int val, int order) {
 
    if (compare(val, (*head)->val, order)) {
        ListNode* temp = *head;
        *head = create_list_node(val);
        (*head)->next = temp;
        return;
    }

    ListNode* prev = NULL;
    ListNode* curr = *head;

    while (curr) {
        if (curr->val == val) {
            printf("Value already in list!\n");
            return;
        }

        if (compare(val, curr->val, order)) {
            prev->next = create_list_node(val);
            prev->next->next = curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    prev->next = create_list_node(val);

}



void list_display(ListNode* head) {
    printf("Linked List: ");
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}



int main () {
    ListNode* head = NULL;
    
    int order;
    printf("Choose organizing order: \n1. Ascending\n2. Descending\n: ");
    scanf("%d", &order);
    if (order == 2) {
        order = 1;
    } else {
        order = 0;
    }
    
    int op = 1;
    while (op > 0 && op < 3) {
        printf("Choose operation:\n1. Insert\n2. Display\n(*) Exit\n: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                int val;
                printf("Enter value: ");
                scanf("%d", &val);

                if (!head) {
                    head = create_list_node(val);
                } else {
                    list_add(&head, val, order);
                }
                break;
            case 2:
                list_display(head);
                break;
        }

    }

    return 0;
}