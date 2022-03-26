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

/* Takes two lists sorted in increasing order, and splices
their nodes together to make one big sorted list which
is returned. */
struct node* SortedMerge(struct node* a, struct node* b)
{
	/* a dummy first node to hang the result on */
	struct node dummy;

	/* tail points to the last result node */
	struct node* tail = &dummy;

	/* so tail->next is the place to add new nodes
	to the result. */
	dummy.next = NULL;
	while (1)
	{
		if (a == NULL)
		{
			/* if either list runs out, use the
			other list */
			tail->next = b;
			break;
		}
		else if (b == NULL)
		{
			tail->next = a;
			break;
		}
		if (a->value <= b->value)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}
	return(dummy.next);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
source, and move it to the front of the dest.
It is an error to call this with the source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

After calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(struct node** destRef, struct node** sourceRef)
{
	/* the front source node */
	struct node* newNode = *sourceRef;
	assert(newNode != NULL);

	/* Advance the source pointer */
	*sourceRef = newNode->next;

	/* Link the old dest off the new node */
	newNode->next = *destRef;

	/* Move dest to point to the new node */
	*destRef = newNode;
}

// This function prints contents of linked list starting
// from the given node
void printList(struct node* node)
{	
    while (node != NULL) {
        printf("%s", node->value);
        node = node->next;
    }
}


