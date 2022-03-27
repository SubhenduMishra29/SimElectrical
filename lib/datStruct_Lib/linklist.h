#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define LARGE 200

struct node{
    char value[LARGE+1];
    struct node *next;
};
struct node *add_to_list(struct node *list, char *n);
void push(struct node** head_ref, char *new_data);
void append(struct node** head_ref, char *new_data);
void insertAfter(struct node* prev_node, char *new_data);
void printList(struct node* node);
void deleteNode(struct node** head_ref, char *key);
/* pull off the front node of the source and put it in dest */
void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* SortedMerge(struct node* a, struct node* b);
void insert(struct node* head1, struct node* head2,int k);
void mergeList(struct node* head1,struct node* head2);
