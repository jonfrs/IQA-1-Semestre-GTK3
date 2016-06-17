
GtkBuilder *builder;
GtkWindow *window;
GtkEntry *entry;
GtkLabel *label;
GtkButton *send;
GtkSpinButton *spin;

//prototipos de funções
void gtk_signal_handler_init();

//gtk_start_engine(argc, argv);



//Funções
void gtk_start_engine(int argc, char **argv) {

    //Funcao principal do gtk
    gtk_init(&argc, &argv);


    //Cria o seu objeto builder
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "teste.xml" ,NULL);

    //Cria o objeto window
    window = (GtkWindow*)gtk_builder_get_object(builder, "mainWindow");

    //Cria o objeto label
    label = (GtkLabel*)gtk_builder_get_object (builder, "iqaLabel");

    //Cria o objeto send
    send = (GtkButton*)gtk_builder_get_object(builder, "calcButton");         


    //Chame essa para configurar o spin button !!!!
    gtk_cfg_spin_button();

    //Chama os widgets (mostra a janela)
    gtk_widget_show((GtkWidget*)window);

    //Inicia os recebimentos de sinais !!!
    gtk_signal_handler_init();

    //Main loop do gtk
    gtk_main();
}

