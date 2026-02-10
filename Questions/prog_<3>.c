#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ;
    struct node *next ;
};

struct node *createnode(int new_data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = new_data;
    new_node -> next = NULL;
    return new_node;
}

// Fixed return type from Node to node
struct node *reverse_traversal(struct node *head){
    if (head == NULL) return NULL; // Handle empty list

    struct node *stack [1000];
    int top = -1;
    struct node *temp = head ;
    
    while (temp != NULL){
        stack [++top] = temp ;
        temp = temp ->next;
    }

    if (top >= 0){
        head = stack [top];
        temp = head ;
        while (top > 0){
            temp -> next = stack[--top];
            temp = temp -> next ;
        }
        temp -> next = NULL ;
    }
   return head;
}

void print_list(struct node *node){
    while (node != NULL){
        printf("%d",node -> data);
        if (node->next){
            printf("->");
        }
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Fixed type naming in main to match struct node
    struct node *head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    head = reverse_traversal(head);
    print_list(head);
    return 0;
}
