#define ENTRY_STD() {getEntry, getEntryAsDouble}

gtkQueryEntry entry(char* entry_name) {

	gtk.entry = (GtkEntry*)gtk_builder_get_object(gtk.builder, entry_name);
	
	gtkQueryEntry entry = ENTRY_STD();

	return entry;
 }

const char *getEntry () {

	const char *entryText = gtk_entry_get_text(gtk.entry);

	return entryText;
}

double getEntryAsDouble () {

	const char *entryText = gtk_entry_get_text(gtk.entry);
	double entryValue = atof(entryText);

	return entryValue;
 } 

