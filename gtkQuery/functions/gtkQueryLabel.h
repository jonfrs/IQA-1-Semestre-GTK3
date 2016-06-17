
#define TXT_STD_SIZE 30
#define LABEL_STD() {write, writeDouble}

gtkQueryLabel label (char *label_name) {

	gtk.label = (GtkLabel*) gtk_builder_get_object(gtk.builder, label_name);

	gtkQueryLabel label = LABEL_STD();

	return label;
}

void write (char text[TXT_STD_SIZE]) {

	gtk_label_set_text(gtk.label, text);
}

void writeDouble (double number) {

	char text[TXT_STD_SIZE];
	
	sprintf(text, "%f", number);

	gtk_label_set_text(gtk.label, text);
}