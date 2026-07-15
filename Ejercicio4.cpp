#include <iostream>
#include "proyecto.h"

using namespace std;

//Ejercicio 4
void calculadora(){
	
	int opcion;
	double x;
	
	do{
		cout<<"\n======CALCULADORA CIENTIFICA======\n";
//		cout << "Elige una operacion: " << endl;
		cout << "1.Seno\n2.Coseno\n3.Tangente\n4.Ln(x)\n5.Log10(x)\n0.Salir\n"; //Mostrar el menu de opciones
		cout << "Eliga una operacion: ";
		cin >> opcion;
		
		if(opcion >= 1 && opcion <= 5){
			cout<<"--------------------------"<<endl;
			cout << "Ingrese el valor de x: ";	//Solicitar el valor de x
			cin >> x; 
		}
		
		switch(opcion){  //Escoger la operacion a realizar
			case 1:
				cout<<"\n========== SENO ==========\n";
				cout << "sen(" << x << ") = " << seno(x) << endl;
				break; 
			case 2:
				cout<<"\n========= COSENO =========\n";
				cout << "cos(" << x << ") = " << coseno(x) << endl;
				break;
			case 3:
				cout<<"\n======== TANGENTE ========\n";
				cout << "tan(" << x << ") = " << tangente(x) << endl;
				break;
			case 4:
				cout<<"\n=========== LN ===========\n";
				cout << "Ln(" << x << ") = " << logNatural(x) << endl;
				break;
			case 5:
				cout<<"\n=========== LOG ===========\n";
				cout << "Log(" << x << ") = " << log10(x) << endl;
				break;
			case 0:
    			cout<<"-----------------------------";
				cout << "\nSaliendo de la calculadora...\n";
    			break;
    		default:
    			cout<<"----------------";
    			cout<< "\nOpcion Invalida\n";
		}
	} while(opcion!=0);
}
double potencia(double base, int exp){	//Funcion potencia, recibe como parametros una base y un exponente
    double resultado = 1;	//inicializzar resultado en 1

    for(int i = 0; i < exp; i++)	//bucle para realizar la potencia
        resultado *= base;	// multiplicar la base "exp" veces

    return resultado;	//devolver el resultado
}
double factorial(int n){	//funcion factorial (n!)
    double fact = 1;	//inicializar factorial en 1

    for(int i = 2; i <= n; i++) //bucle para obtener el factorial
        fact *= i;	//multiplicar desde 2 hasta n

    return fact;	//Devuelve el factorial
}
double seno(double x){	//funcion seno utilizando polinomios de Taylor
	double suma = 0;	//Variable donde se acumula la suma de todos los terminos
	
	for(int n=0;n<20;n++){	//bucle para calcular 20 terminos de la serie
		// polinomio de Taylor para calcular seno
		double termino = potencia(-1, n) * potencia(x, 2*n + 1) / factorial(2*n + 1);
		/*
		potencia(-1,n) llama a la funcion potencia para alternar el signo de cada termino del polinomio de Taylor
		potencia(x, 2n + 1) llama a la funcion potencia para utilizar los exponentes impares
		factorial(2n + 1) llama a la funcion factorial para utilizar denominadores de factoriales de numeros impares
		*/	
		suma += termino;	// realiza la sumatoria de cada termino calculado	
	}
	return suma;	//retorna el resultado de la suma (aproximacion del seno)
}
double coseno(double x){ 	//funcion coseno utilizando polinomios de Taylor
	double suma = 0;	//Variable donde se acumula la suma de todos los terminos
	
	for(int n=0;n<20;n++){	//bucle para calcular 20 terminos de la serie
	// polinomio de Taylor para calcular coseno
		double termino = potencia(-1, n) * potencia(x, 2*n) / factorial(2*n);
		/*
		potencia(-1,n) llama a la funcion potencia para alternar el signo de cada termino del polinomio de Taylor
		potencia(x, 2n) llama a la funcion potencia para utilizar los exponentes pares
		factorial(2n) llama a la funcion factorial para utilizar denomnadores de factoriales de numeros pares
		*/
		suma += termino;	//realiza la sumatoria de cada termino calculado
	}
	return suma;	//retorna el resultado de la suma (aproximacion del coseno)
}
double tangente(double x){	//funcion tangente
	//definicion de tangente sen/cos
	return seno(x) / coseno(x);		//llama a la funcion seno y coseno, y retorna la division entre el seno y coseno
}
double logNatural(double x){ //funcion logaritmo natural utilizando polinomios de Taylor
	if(x <= 0){
		cout << "Error: ln(x) no esta definido para x <= 0" << endl;	//verificacion del domino
		return -1;	//retorna -1 para indicar que ocurrio un error
	}
	const double ln2 =  0.693147180559945309;	// se guarda Ln(2) como una constante
	int k = 0;	//variable que contara cuantas veces de va a dividir o multiplicar "x" por 2 posteriormente
	
	//====El polinomio de Taylor no converge para valores mayores a 2=====
	//propiedades de logaritmos ln(2x) = ln 2 + ln x, ln(x/2) = ln x - ln 2
	while(x > 2.0){	//mietras el numero sea mayor que dos entra al bucle
		x /= 2.0;	// divir el numero entre 2
		k++;	//aumentar el contador
	}
	while(x < 0.5){	//mientras el numero sea menor que 0.5 entra al bucle
		x *= 2.0;	//multiplicar el numero por 2
		k--;	//disminuir el contador
	}
	double suma = 0;	//inicializar variable suma en 0
	double u = x-1;		//cambio de variable para cada termino del polinomio
	double termino = u;	//primer termino del polinomio igual a u
	
	for(int n=1;n<=20;n++){	//ciclo para calcular 20 terminos del polinomio
		suma += termino / n;	//sumatoria de cada termino del polinomio
		termino *= -u;	//cambiar el signo y generar la potencia de cada termino
	}
	return suma + (k * ln2);	// aplicar propiedades de logaritmos y retornar ln del valor ingresado originalmente
}
double log10(double x){
	//propiedades de logaritmos log10(x) = lnx/ln10
	return logNatural(x) / logNatural(10); //aplicar propiedades de logaritmos llamando a la funcion logaritmo natural
}
