#include "gtkQuery/gtkQuery.h"

void onClick() {

	label("label").write("Hello gtkQuery !!");
}	

int main (int argc, char *argv[]) {

	gtkQueryStart(argc, argv, "helloGtkQuery.xml");
	
	window("window").show();

	button("button").send();
	
	gtk_main();
}


