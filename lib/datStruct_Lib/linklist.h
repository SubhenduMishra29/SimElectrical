#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
