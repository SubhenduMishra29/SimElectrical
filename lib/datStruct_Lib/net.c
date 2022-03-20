#include "net.h"

void create_empty_net(){
	printf("import pandapower as pp\n");
	printf("net = pp.create_empty_network()\n");
}
void create_bus(){
	printf("bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
}
void create_line(){
	printf("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\", 		name=\"Line 1\")\n");
}
void create_trafo(){
	printf("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 		10/0.4 kV\")\n");
}
void create_switch(){
	printf("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");	
}
void create_ext_grid(){
	printf("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
}
