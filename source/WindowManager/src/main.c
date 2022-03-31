#include <gtk/gtk.h>

//pointer to label 1 & 2
GtkWidget *g_label1;
GtkWidget *g_label2;
static void first_dialog(void)
{
    // This creates (but does not yet display) a message dialog with
    // the given text as the title.
    GtkWidget* hello = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
        "Hi, I'm a message dialog!");

    // The (optional) secondary text shows up in the "body" of the
    // dialog. Note that printf-style formatting is available.
    gtk_message_dialog_format_secondary_text(
        GTK_MESSAGE_DIALOG(hello),
        "This is secondary text with printf-style formatting: %d",
        99);

    // This displays our message dialog as a modal dialog, waiting for
    // the user to click a button before moving on. The return value
    // comes from the :response signal emitted by the dialog. By
    // default, the dialog only has an OK button, so we'll get a
    // GTK_RESPONSE_OK if the user clicked the button. But if the user
    // destroys the window, we'll get a GTK_RESPONSE_DELETE_EVENT.
    int response = gtk_dialog_run(GTK_DIALOG(hello));

    printf("response was %d (OK=%d, DELETE_EVENT=%d)\n",
           response, GTK_RESPONSE_OK, GTK_RESPONSE_DELETE_EVENT);

    // If we don't destroy the dialog here, it will still be displayed
    // (in back) when the second dialog below is run.
    gtk_widget_destroy(hello);
}


int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/Electrical.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Electrical"));
    gtk_builder_connect_signals(builder, NULL);
        
    g_object_unref(builder);
	g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
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

G_MODULE_EXPORT void on_Button_Design_clicked() {
	
}
G_MODULE_EXPORT void on_Button_Logic_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Relay_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Sl_clicked(){
	
}
G_MODULE_EXPORT void on_Button_Mgr_clicked(){
		first_dialog();
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
G_MODULE_EXPORT gboolean on_menuItem_file_new_button_press_event (GtkWidget *caller){
	GtkWindow *parent_window = GTK_WINDOW(caller);
	    GtkFileChooserNative *native;
	    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
	    gint res;

	    native = gtk_file_chooser_native_new("Save File",
		                                 parent_window,
		                                 action,
		                                 "_Save",
		                                 "_Cancel");

	    res = gtk_native_dialog_run(GTK_NATIVE_DIALOG(native));
	    if (res == GTK_RESPONSE_ACCEPT)
	    {
		char *filename;
		GtkFileChooser *chooser = GTK_FILE_CHOOSER(native);
		filename = gtk_file_chooser_get_filename(chooser);

		// save the file 
		//save_to_file(filename);

		g_free(filename);
	    }

	    g_object_unref(native);
	 
}
G_MODULE_EXPORT void on_menuItem_help_about_select (){
	 
} 
G_MODULE_EXPORT gboolean on_menuItem_file_quit_button_press_event(){
	 gtk_main_quit();
 }
