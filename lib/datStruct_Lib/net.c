#include "net.h"

int create_empty_net(){
	//printf("import pandapower as pp\n");
	//printf("net = pp.create_empty_network()\n");
	FILE *out=fopen("empty_net.txt","a+");
	fputs("import pandapower as pp\n",out);
	fputs("net = pp.create_empty_network()",out);
	fclose(out);
	return 0;
}
int create_bus(char bus_type[],char bus_name[] ){// str1 is the name of the bus
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
int create_line(){
	//printf("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\", 		name=\"Line 1\")\n");
	FILE *out=fopen("line.txt","a+");
	fputs("line1 = pp.create_line(net, bus1, bus2, length_km=0.5, std_type=\"NA2XS2Y 1x240 RM/25 12/20 kV\",name=\"Line 1\")",out);
	fclose(out);
	return 0;
}
int create_trafo(){
	//printf("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 		10/0.4 kV\")\n");
	FILE *out=fopen("trafo.txt","a+");
	fputs("trafo1 = pp.create_transformer(net, bus2, bus4, name=\"6.6kV/415V transformer 1\", std_type=\"0.63 MVA 10/0.4 kV\")",out);
	fclose(out);
	return 0;
}
int create_switch(){
	//printf("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)\n");
	FILE *out=fopen("switch.txt","a+");
	fputs("sw1 = pp.create_switch(net, bus1, bus2, et=\"b\", type=\"CB\", closed=True)",out);
	fclose(out);
	return 0;	
}
int create_ext_grid(){
	//printf("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)\n");
	FILE *out=fopen("grid.txt","a+");
	fputs("pp.create_ext_grid(net, bus1, vm_pu=1.02, va_degree=50)",out);
	fclose(out);
	return 0;
}
// Function that appends the contents
void appendFiles(char source[],char destination[])
{
    // declaring file pointers
    FILE *fp1, *fp2;
 
    // opening files
    fp1 = fopen(source, "r");
    fp2 = fopen(destination, "a+");
 
    // If file is not found then return.
    if (!fp1 && !fp2) {
        printf("Unable to open/"
               "detect file(s)\n");
        return;
    }
 
    char buf[100];
 
    // explicitly writing "\n"
    // to the destination file
    // so to enhance readability.
    fprintf(fp2, "\n");
 
    // writing the contents of
    // source file to destination file.
    while (!feof(fp1)) {
        fgets(buf, sizeof(buf), fp1);//read the source file
       //fread(buf, sizeof(buf), 1, fp1);
	//	printf("looping ..%s\n",source);
        fprintf(fp2, "%s", buf);// write to destination file
        //fwrite(buf , 1 , sizeof(buf) , fp2 );        
    }
//	char ch;
//	while((ch=fgetc(fp1))!=EOF)
//		fputc(ch,fp2);
	
    //rewind(fp2);
 
    // printing contents of
    // destination file to stdout.
    //while (!feof(fp2)) {
    //   fgets(buf, sizeof(buf), fp2);
    //   printf("%s", buf);       
   // }
    
}
 

int finalise_py(){
	char source1[] = "empty_net.txt",
	source2[] = "bus.txt",
	source3[] = "line.txt",
	source4[] = "trafo.txt",
	source5[] = "switch.txt",
	source6[] = "grid.txt",
        destination[] = "test.py";        
        appendFiles(source1, destination);        
        appendFiles(source2, destination);
        appendFiles(source3, destination);       
        appendFiles(source4, destination);        
        appendFiles(source5, destination);        
        appendFiles(source6, destination);
              
return 0;
}
