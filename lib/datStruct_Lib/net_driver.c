#include "net.h"

void main(){
	create_empty_net();
	create_bus("-bus1","HV Busbar");
	create_line();
	create_trafo();
	create_switch();
	create_ext_grid();
	finalise_py();
}
