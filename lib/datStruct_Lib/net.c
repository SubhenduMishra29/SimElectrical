#include "net.h"

int create_empty_net(struct node** head){
	
	append(head, "import pandapower as pp\n");
	append(head, "net = pp.create_empty_network()\n");
	return 0;
}
int create_bus(struct node** head ,char str[] ){// str1 is the name of the bus
	append(head, str);
	return 0;
}
int create_line(struct node** head ,char str[]){
	append(head, str);
	return 0;
}
int create_trafo(struct node** head ,char str[]){
	append(head, str);
	//printf("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 		10/0.4 kV\")\n");
	//FILE *out=fopen("trafo.txt","a+");
	//fputs("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 10/0.4 kV\")",out);
	//fclose(out);
	return 0;
}
int create_switch(struct node** head ,char str[]){
	//printf("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");
	append(head, str);
	//FILE *out=fopen("switch.txt","a+");
	//fputs("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)",out);
	//fclose(out);
	return 0;	
}
int create_ext_grid(struct node** head ,char str[]){
	//printf("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
	append(head, str);
	//FILE *out=fopen("grid.txt","a+");
	//fputs("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)",out);
	//fclose(out);
	return 0;
}


 

int finalise_py(struct node* node){
	//printList(node);
	FILE *out=fopen("test.py","a+");
	while (node != NULL) {
		printf("%s", node->value);
		fputs(node->value,out);
		node = node->next;
    	}
    	fclose(out);
return 0;
}
