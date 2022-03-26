// A simple C program for traversal of a linked list
#include "linklist.h"

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct node** head_ref, char *new_data)
{
	/* 1. allocate node */
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	/* 2. put in the data */
	//new_node->data = new_data;
	strcpy(new_node->value, new_data);
	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}
/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(struct node* prev_node, char *new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct node* new_node
		= (struct node*)malloc(sizeof(struct node));

	/* 3. put in the data */
	//new_node->data = new_data;
	strcpy(new_node->value, new_data);
	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}
/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(struct node** head_ref, char *new_data)
{
	/* 1. allocate node */
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	struct node *last = *head_ref; /* used in step 5*/
	//printf("Inside append \n");
	/* 2. put in the data */
	//new_node->data = new_data;
	strcpy(new_node->value, new_data);
	/* 3. This new node is going to be the last node, so make next
		of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new node as head */
	if (*head_ref == NULL)
	{
	*head_ref = new_node;
	return;
	}
	
	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}
/* Given a reference (pointer to pointer) to the head of a
   list and a key, deletes the first occurrence of key in
   linked list */
void deleteNode(struct node** head_ref, char *key)
{
    // Store head node
    struct node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->value == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}

// This function prints contents of linked list starting
// from the given node
void printList(struct node* node)
{
	printf("inside PrintList:\n");
	 printf(" %s ", node->value);
    while (node != NULL) {
        printf(" %s ", node->value);
        node = node->next;
    }
}


