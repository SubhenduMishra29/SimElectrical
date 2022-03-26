#include "net.h"

void main(){
	/* Start with the empty list */
	struct node* main = NULL;
	struct node* head = NULL;
	struct node* c_bus = NULL;
	struct node* c_line = NULL;
	struct node* c_trafo = NULL;
	struct node* c_switch = NULL;
	create_empty_net(&head);
	create_bus(&c_bus,"bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	create_bus(&c_bus,"bus2 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	//create_line("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\",name=\"Line 1\")\n");
	//create_trafo();
	//create_switch();
	//create_ext_grid();
	main = SortedMerge(head, c_bus);
	finalise_py(main);
}
