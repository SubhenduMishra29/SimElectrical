#include "linklist.h"
int main()
{
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	// allocate 3 nodes in the heap
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	printf("Starting of link list\n");
	strcpy(head->value,"Hellow ");
	// assign data in first node
	head->next = second; // Link first node with second

	strcpy(second->value,"This is C world\n"); // assign data to second node
	second->next = third;

	strcpy(third->value,"Welcome\n"); // assign data to third node
	third->next = NULL;

	printList(head);

	return 0;
}

