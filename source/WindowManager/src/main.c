#include <gtk/gtk.h>

//pointer to label 1 & 2
GtkWidget *g_label1;
GtkWidget *g_label2;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Electrical.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Electrical"));
    gtk_builder_connect_signals(builder, NULL);
    
    //connect pointer to label 1 & 2
    g_label1 = GTK_WIDGET(gtk_builder_get_object(builder,"label1"));
    g_label2 = GTK_WIDGET(gtk_builder_get_object(builder,"label2"));

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

//call function when btn1 is clicked
int count=0;
// G_MODULE_EXPORT is added for window platform
G_MODULE_EXPORT void on_Btn1_clicked(){
	char strcnt[255]={"\0"};
	
	//set label1 to hello world
	gtk_label_set_text(GTK_LABEL(g_label1),"Hello World");
	count++;
	sprintf(strcnt,"%d",count);
	//set label2 to strcnt
	gtk_label_set_text(GTK_LABEL(g_label2),strcnt);
}
G_MODULE_EXPORT void on_Button_Design_clicked() {
	
}
G_MODULE_EXPORT void on_Button_Logic_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Relay_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Sl_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Mgr_clicked(){
		
}
G_MODULE_EXPORT void on_Button_Relay_Coord_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_save_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_new_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_redo_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_undo_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_execute_clicked(){
	
}
G_MODULE_EXPORT void on_Gen_Toolbar_File_clicked(){
	
}

G_MODULE_EXPORT void on_Gen_Toolbar_cut_clicked(){
	
}

