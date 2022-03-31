#include "linklist.h"
/* Driver program to test above functions*/
int main()
{
/* Start with the empty list */
struct node* head = NULL;

// Insert 6. So linked list becomes 6->NULL
append(&head, "hellow");

// Insert 7 at the beginning. So linked list becomes 7->6->NULL
push(&head, "subhendu");

// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
push(&head, "this ");

// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
append(&head, "is");

// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
insertAfter(head->next, "Linked List");

printf("\n Created Linked list is: ");
printList(head);

return 0;
}

