#define SPIN_STD() {getSpin, adjustSpin}

#define STD_DIGITS 3

gtkQuerySpinButton spin(char* spin_name) {

	gtk.spin = (GtkSpinButton*)gtk_builder_get_object(gtk.builder, spin_name);

	gtkQuerySpinButton spin = SPIN_STD();

	return spin;
}

double getSpin () {

	double value = (double)gtk_spin_button_get_value(gtk.spin);

	return value;
}

void adjustSpin (double value, double lower, double upper, double step_up, double step_down, double page_size) {

	gtk.adjust = gtk_adjustment_new(value, lower, upper, step_up, step_down, page_size);
	
	gtk_spin_button_set_adjustment(gtk.spin, gtk.adjust);
}