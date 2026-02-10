
### Structure and Node Creation


```
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

```

The `struct node` defines the link in the chain, consisting of an integer value and a pointer to the next node. The `createnode` function allocates memory for a new node on the "heap" and initializes its pointers to ensure no garbage values are stored.

----------

### Filling the Stack

```
struct node *reverse_traversal(struct node *head){
    if (head == NULL) return NULL; 

    struct node *stack [1000];
    int top = -1;
    struct node *temp = head ;
    
    while (temp != NULL){
        stack [++top] = temp ;
        temp = temp ->next;
    }

```

The algorithm first traverses the list from start to finish. During this walk, it stores the memory address of every node into an array acting as a **Stack**. Because stacks are "Last-In, First-Out," the last node of the list ends up at the very top of the stack.

----------

### Rebuilding the List

```
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

```
The second phase pulls nodes off the stack one by one. The original "tail" becomes the new `head`. As each node is popped, its `next` pointer is updated to point to the node that was previously _before_ it in the list. Finally, the original first node's `next` is set to `NULL` to mark the new end of the list.

----------

### Demonstration in Main
```
int main() {
    struct node *head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    // ... nodes 4 and 5
    head = reverse_traversal(head);
    print_list(head);
    return 0;
}

```

The `main()` function creates a chain of five nodes (1 through 5). It then passes the head to the reversal function and catches the returned pointer (the new head). The `print_list` function then confirms the success by outputting `5->4->3->2->1`.
