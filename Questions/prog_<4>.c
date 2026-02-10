#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insert_after(struct node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("previous node can't be NULL\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}


void delete_node(struct node** head_ref, struct node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }
    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }


    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

void print_list(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        if (node->next != NULL) printf("<-> ");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;
    insert_after(head, 20);      
    insert_after(head->next, 30); 
    printf("Created List: ");
    print_list(head);
    delete_node(&head, head->next);
    printf("After deleting middle node: ");
    print_list(head);

    return 0;
}
