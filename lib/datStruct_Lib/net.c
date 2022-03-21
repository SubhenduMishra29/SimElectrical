#include "net.h"

int create_empty_net(){
	//printf("import pandapower as pp\n");
	//printf("net = pp.create_empty_network()\n");
	FILE *out=fopen("empty_net.txt","w+");
	fputs("import pandapower as pp\n",out);
	fputs("net = pp.create_empty_network()\n",out);
	fclose(out);
	return 0;
}
int create_bus(){
	//printf("bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	FILE *out=fopen("bus.txt","w+");
	fputs("bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n",out);
	fclose(out);
	return 0;
}
int create_line(){
	//printf("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\", 		name=\"Line 1\")\n");
	FILE *out=fopen("line.txt","w+");
	fputs("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\",name=\"Line 1\")\n",out);
	fclose(out);
	return 0;
}
int create_trafo(){
	//printf("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 		10/0.4 kV\")\n");
	FILE *out=fopen("trafo.txt","w+");
	fputs("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 10/0.4 kV\")\n",out);
	fclose(out);
	return 0;
}
int create_switch(){
	//printf("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");
	FILE *out=fopen("switch.txt","w+");
	fputs("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n",out);
	fclose(out);
	return 0;	
}
int create_ext_grid(){
	//printf("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
	FILE *out=fopen("grid.txt","w+");
	fputs("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n",out);
	fclose(out);
	return 0;
}
