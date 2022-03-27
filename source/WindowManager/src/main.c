#include <gtk/gtk.h>
//https://prognotes.net/2016/03/gtk-3-c-code-hello-world-tutorial-using-glade-3/

//pointer to label 1 & 2
GtkWidget *g_label1;
GtkWidget *g_label2;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
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
void on_Btn1_clicked(){
	char strcnt[255]={"\0"};
	
	//set label1 to hello world
	gtk_label_set_text(GTK_LABEL(g_label1),"Hello World");
	count++;
	sprintf(strcnt,"%d",count);
	//set label2 to strcnt
	gtk_label_set_text(GTK_LABEL(g_label2),strcnt);
}
