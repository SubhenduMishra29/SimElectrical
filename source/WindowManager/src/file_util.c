#include <gtk/gtk.h>
#include "file_util.h"
G_MODULE_EXPORT gboolean save_file(GtkWidget *caller){
GtkWindow *parent_window = GTK_WINDOW(caller);
GtkFileChooserNative *native;
GtkFileFilter *filter;
GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
gint res;

native = gtk_file_chooser_native_new("Save File",parent_window,action,"_Save","_Cancel");
filter = gtk_file_filter_new();
gtk_file_filter_add_pattern(filter, "*.cpp");
gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(native), filter);
gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(native), "test.cpp");
//gtk_widget_show_all(native);

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
