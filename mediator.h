

void showResult(double);
void gtk_cfg_spin_button();
void gtk_write_in_label(GtkLabel*, double);
double * gtk_get_value_from_entry();
double **gtk_values_from_form();
GtkSpinButton **gtk_get_spin();


double *gtk_get_value_from_entry() {

    //GtkEntry *_entry;

    char *entry[9] = {"entry1", "entry2", "entry3", "entry 4",
        "entry5", "entry6", "entry7", "entry8", "entry9"};

    static double value[9];
        
    for (int i=0; i<9; i++){    
        
        value = entry(entry[i]).getEntryAsDouble();

        //_entry = (GtkEntry*)gtk_builder_get_object(builder, entry[i]);
        //const char* _value = gtk_entry_get_text(_entry);
        //value[i] = atof(_value);
    }   

    return value;
}

double *gtk_get_value_from_spin () {

    static double value[9];

    GtkSpinButton **spin = gtk_get_spin();

    for (int i=0; i<9; i++){

        value[i] = (double)gtk_spin_button_get_value(spin[i]);
    }   

    return value;
}

/*
    Essa função é similar às anteriores, porém não retorna um ponteiro pra double,
        retorna um ponteiro para ponteiro de GtkSpinButton,
    Imagine o GtkSpinButton como se fosse um 'double' ou um 'int',
    Essa funcao retorna um ponteiro para ponteiros de GtkSpinButton, que sao os ponteiros para os spinbuttons da janela,
        um exemplo de uso está mais abaixo, quando precisamos ordenar os spins para podet ajustá-los    

*/

GtkSpinButton **gtk_get_spin() {

    static GtkSpinButton *_spin[9];

    char *spin[9] = {"spinbutton9", "spinbutton8", "spinbutton7", "spinbutton6",
        "spinbutton5", "spinbutton4", "spinbutton3", "spinbutton2", "spinbutton1"};
        
    for (int i=0; i<9; i++) {   
        
        _spin[i] = (GtkSpinButton*)gtk_builder_get_object(builder, spin[i]);    
    }   

    return _spin;   
}

double **gtk_values_from_form() {

    static double **values; 

    values[0] = gtk_get_value_from_spin();
    values[1] = gtk_get_value_from_entry();

    return values;

}

/*
    Essa função configura os spin buttons, ou seja, ela ajusta o valor inicial, minimo, maximo, etc
        de cada um dos spins buttons na tela,
    Observe que a funcao "gtk_spin_set_adjustment();" é chamada 9 vezes, uma vez para cada spin button
        e é dessa necessidade que surgiu a função gtk_get_spin(); que retorna ponteiro para ponteiro (**);
*/
void gtk_cfg_spin_button(){

	GtkAdjustment *adjustment;
	
    double spinPesoInit[9] = 
	{0.15, 0.12, 0.10, 0.10, 0.10, 0.10, 0.08, 0.08, 0.17};	

	for (int i=0; i<9; i++) {		
		adjustment = gtk_adjustment_new(
            spinPesoInit[i],
            spinMin 0.0,
            spinMax 1.0,
            spinIncrease 0.01,
            spinDescrease 0.01,
            spinPageSize 0.0
            );

		GtkSpinButton **spin = gtk_get_spin();

        gtk_spin_button_set_adjustment(spin[i], adjustment);
    }
}

void showResult(double indice) {
    
    printf("indice = %f\n", indice);
}