#include "net.h"

void main(){
	/* Start with the empty list */
	struct node* head = NULL;
	struct node* c_bus = NULL;
	struct node* c_line = NULL;
	struct node* c_trafo = NULL;
	struct node* c_switch = NULL;
	struct node* c_grid = NULL;
	create_empty_net(&head);
	create_bus(&c_bus,"bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	create_bus(&c_bus,"bus2 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	create_line(&c_line,"line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\",name=\"Line 1\")\n");
	create_trafo(&c_trafo,"trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\",std_type=\"0.63 MVA 10/0.4 kV\")\n");
	create_switch(&c_switch,"sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");
	create_ext_grid(&c_grid,"pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
	mergeList(head, c_bus);
	mergeList(head, c_line);
	mergeList(head, c_trafo);
	mergeList(head, c_switch);
	mergeList(head, c_grid);
	finalise_py(head);
}
