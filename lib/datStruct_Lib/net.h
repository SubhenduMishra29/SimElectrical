#include "graph.h"
#include "linklist.h"
#include <string.h>
int create_empty_net(struct node** head);
int create_bus(struct node** head ,char str[]);
int create_line(struct node** head ,char str[]);
int create_trafo(struct node** head ,char str[]);
int create_switch(struct node** head ,char str[]);
int create_ext_grid(struct node** head ,char str[]);
int finalise_py(struct node* node);
void appendFiles(char source[], char destination[]);
