#include "gtkQuery/gtkQuery.h"
#include "mediator.h"

//Escrever função de cálculo de IQA neste arquivo  
#include "gtkQuery/calculoIQA.h" 

int main (int argc, char *argv[]) {

 gtkQueryStart(argc, argv, "janIQA.xml");
 
 window("mainWindow").show();

 button("calcButton").send(calculaIqa);
 
 gtk_main();
}