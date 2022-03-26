#include "net.h"

void main(){
	/* Start with the empty list */
	struct node* head = NULL;
	create_empty_net(head);
	printf(" %s \n", head->value);
	create_bus(head,"-bus1","HV Busbar");
	//create_line();
	//create_trafo();
	//create_switch();
	//create_ext_grid();
	finalise_py(head);
}
