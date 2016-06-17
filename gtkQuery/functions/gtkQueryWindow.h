#define WINDOW_STD() {show}

gtkQueryWindow window(char* window_name) {

	gtkQueryWindow window = WINDOW_STD();
	
	gtk.window = (GtkWindow*)gtk_builder_get_object(gtk.builder, window_name);

	return window;
}

void show () {

	gtk_widget_show((GtkWidget*)gtk.window);
}

