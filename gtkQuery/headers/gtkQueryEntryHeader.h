typedef struct _gtkQueryEntry {

	const char* (*get) ();
 	double (*getAsDouble) ();	
 	

}gtkQueryEntry;

gtkQueryEntry entry(char*);
const char *getEntry ();
double getEntryAsDouble ();	
 	

