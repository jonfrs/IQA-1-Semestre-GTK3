


double q1 ( double indice ) { /* Coliformes Fecais : PESO 0.15 */

    showResult(indice);
	double A = 98.03, B = -36.45, C = 3.14, D = 0.067;
    
    if ( indice > 1e5 )
    	return 3.0;
    	
    if ( indice <= 0 ) 
		indice = 1;	

	/* 
	* v1.1 - Ajuste na equação para estimação da qualidade em funcao de quantidade de coliformes fecais
	* v1.2 - Ajustado a base do Log 	
    */
    
	indice = A + ( B * log10(indice)) + ( C * pow( log10(indice), 2 )) + (D * pow( log10(indice), 3 ));
	
	printf("COLIFORMES %f\n", indice);
    return indice;

}

double q2 ( double indice ) { /* pH : PESO 0.12 */

    showResult(indice);
	double A = 0.05421, B = 1.23, C = -0.09873;
    
    if ( indice >= 12 )
    	return 3.0;
    	
    if ( indice <= 2 )
	return 2.0;	

    indice = A * pow(indice, ((B*indice) + (C*pow(indice,2)))) + 5.213;
	
	printf("PH %f\n", indice);
    return indice;
}

double q3 ( double indice ) { /* Demanda Bioquímica de Oxigênio : PESO 0.1
							   *v 1.2 alterado o valor da variavel "B"
							   */
   showResult(indice);
    double A = 102.6, B = -0.1101;
    
    if ( indice > 30 )
    	return 2.0;
    	
    indice = A * exp((B*indice));
	
	printf("DBO %f\n", indice);
    return indice;

}

double q5 ( double indice ) { /* Fósforo total : PESO 0.1 */
	
    showResult(indice);
	double A = 213.7, B = -1.68, C = 0.3325;
    
    if ( indice > 10.0 )
    	return 5.0;
    	
    if ( indice >= 0.1 && indice < 0.2 )
		indice = 0;	

    indice = A * exp((B*pow(indice, C)));
	
	printf("FOSFORO %f\n", indice);
    return indice;

}

double q4 ( double indice ) { /* Nitrogênio total : PESO 0.1 */

    showResult(indice);
	double A = 98.96, B = -0.2232, C = -0.006457;
    
    if ( indice > 90 )
    	return 1.0;

    indice = A * pow(indice, (B + (C*indice)));

	printf("NITROGENIO %f\n", indice);
    return indice;

}

double q7 ( double indice ) { /* Turbidez : PESO 0.08 */

    showResult(indice);
    double A = 97.34, B = -0.01139, C = -0.04917;
    
    if ( indice > 100 )
    	return 5.0;
    	
    if ( indice < 0 )
		indice = 0;	
    
    indice = A * exp((B * indice) + (C*sqrt(indice)));
	
	printf("TURBIDEZ %f\n", indice);
    return indice;
}

double q6 ( double indice ) { /* Variação de Temperatura : PESO 0.1 */

    showResult(indice);
	double A = 0.0003869, B = 0.1815, C = 0.01081;
    printf("CHEGUEI NA TEMP\n");
    if ( indice <= -5 ) {
    	indice = 1;
		printf("TEMPERATURA %f\n", indice);
		return indice;
	}
    	
    if ( indice > 15 ) {
		indice = 9;	
		printf("TEMPERATURA %f\n", indice);
		return indice;
	}
	
    indice = (1 / ( ( A * pow ( (indice + B) , 2 )) + C ));

	printf("TEMPERATURA %f\n", indice);
    return indice;
}

double q8 ( double indice ) { /* Sólidos Totais : PESO 0.08 */

    showResult(indice);
	double A = 80.26, B = -0.00107, C = 0.03009, D = -0.1185;
    
    if ( indice > 500 )
    	return 30.0;
    	
    if ( indice < 0 )	
		indice = 0;
		
    indice = (A * exp( (B*indice) + (C*sqrt(indice)))) + (D * indice );

	printf("SOLIDOS %f\n", indice);
    return indice;

}

double q9 ( double indice ) { /*  Oxigênio Dissolvido : PESO 0.17 */

    showResult(indice);
     
    double A = 100.8, B = -106, C = -3745;
    
    if ( indice > 140.0 )
        return 47.0;

    indice = A * exp ( pow( (indice + B), 2 ) / C );
    
    printf("OXIGENIO %f\n", indice);
    return indice;

}

double iqaCalc(double **);
char* iqaQuality(double);


typedef double (*Func) (double);

double iqaCalc (double **valores){

    double entry;
    double peso;

    entry = valores[0];
    peso = valores[1];
    
    double iqa = 1; /* Variável usada para armazenar o valor do IQA calculado */
    
    int i; /*  Variáveis para serem usadas no controle de fluxo e laços */
    
    Func funcao[9] =  /* Vetor apontando para as funções das respectivas equações */
        {q1, q2, q3, q4, q5, q6, q7, q8, q9};     
    
    
    for (i=0; i<9; i++) {
        
        /*  O programa receberá os paramêtros passados pelo o usuário, que serão armazenados na variável 'param'
        e então passará o valor de 'param' como paramêtro para cada uma das respectivas equações descritas no artigo.
            Cada equação foi protótipada numa função de nome 'qN' sendo N o número de cada equação, variando de 1 até 9.
            Para facilitar o trabalho, foi linearizado o processo. A cada iteração, a variável 'param' será passada, 
        através de um vetor,para uma equação diferente. O valor obtido com o cálculo será então multiplicado 
        pela variável 'iqa' aonde será armazenado, ao final do laço, o valor do iqa calculado.  
        */
        
        iqa *= pow (funcao[i](entry[i]), peso[i]);
    
    }
    return iqa;
}