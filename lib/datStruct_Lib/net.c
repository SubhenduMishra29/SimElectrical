#include "net.h"

int create_empty_net(struct node *head){
	printf(" %s \n", head->value);
	//printf("import pandapower as pp\n");
	//printf("net = pp.create_empty_network()\n");
	append(&head, "import pandapower as pp\n");
	printf(" %s \n ", head->value);
	append(&head, "net = pp.create_empty_network()");
	printf(" %s \n", head->value);
	//FILE *out=fopen("empty_net.txt","a+");
	//fputs("import pandapower as pp\n",out);
	//fputs("net = pp.create_empty_network()",out);
	//fclose(out);
	return 0;
}
int create_bus(struct node *head,char bus_type[],char bus_name[] ){// str1 is the name of the bus
	// get the arguments and composes the string for forming the script
	char str[250];
	char str1[]=" = pp.create_bus(net, name=\"";
	char str3[]="\", vn_kv=6.6, type=\"b\")";
	// copy bus_type to str
	strcpy(str, bus_type);	
	// concatenates str and str1
	strcat(str, str1);
	strcat(str, bus_name);
	strcat(str, str3);
	//printf(str);
	//printf("bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")\n");
	FILE *out=fopen("bus.txt","a+");
	fputs("bus1 = pp.create_bus(net, name=\"HV Busbar\", vn_kv=6.6, type=\"b\")",out);
	fclose(out);
	return 0;
}
int create_line(struct node *head){
	//printf("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\", 		name=\"Line 1\")\n");
	FILE *out=fopen("line.txt","a+");
	fputs("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\",name=\"Line 1\")",out);
	fclose(out);
	return 0;
}
int create_trafo(struct node *head){
	//printf("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 		10/0.4 kV\")\n");
	FILE *out=fopen("trafo.txt","a+");
	fputs("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 10/0.4 kV\")",out);
	fclose(out);
	return 0;
}
int create_switch(struct node *head){
	//printf("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");
	FILE *out=fopen("switch.txt","a+");
	fputs("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)",out);
	fclose(out);
	return 0;	
}
int create_ext_grid(struct node *head){
	//printf("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
	FILE *out=fopen("grid.txt","a+");
	fputs("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)",out);
	fclose(out);
	return 0;
}


 

int finalise_py(struct node* node){
	printf("inside finalise_py:\n");
	printf(" %s ", node->value);
	printList(node);
return 0;
}
