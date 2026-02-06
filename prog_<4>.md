#***How can we implement the doubly linked list using structure? Write a method to insert(after
given node) and delete the node in doubly linked list. Write main() to demonstrate the use
of the functions.***

* **->doubly linkedlist requires a struct `node` with three attributes called :**
  * **->`data` of integer datatype**
  * **->`prev` of a datastructure node **
  * **->`next`of a datastructure node**
```
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
```
* ***to implement insert and delete nodes in a doubly linkedlist :***
   * ***->create a function insert_after***
  * **->checking:**
 ```
  if (prev_node == NULL) {
    printf("previous node can't be NULL\n");
    return;
}
  ```
   * **->we cannot insert a node after node that is NULL meaning it doesn't exist**
  * ***Memory Allocation:***
    * ```
      struct node* new_node = (struct node*)malloc(sizeof(struct node));
      new_node->data = new_data;
      ```
    * **We reserve space in memory for our new node and set its value. At this point, the node exists in memory but isn't connected to our list yet.**
 * ***Connecting the New Node ("Stitching"):***
   * ```
     new_node->next = prev_node->next; // Point new node forward to the successor
     new_node->prev = prev_node;       // Point new node backward to the predecessor
     prev_node->next = new_node;       // Update predecessor to point to new node

     if (new_node->next != NULL) {     // If a successor exists, point it back to new node
        new_node->next->prev = new_node;
     }
     ```
  * ***handling the right side neighbour***
    * **If our new node was inserted in the middle of a list (meaning there is a node after it), that neighbor is still pointing its prev pointer back at prev_node. We update that neighbor's prev pointer to point to our new_node instead.**
    * ```
      if (new_node->next != NULL) {
       new_node->next->prev = new_node;
      }
      ```
    
 

