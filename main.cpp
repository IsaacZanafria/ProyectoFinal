#include <iostream>
#include "proyecto.h"

using namespace std;

int main(){
	int opcion;

	do{
    	cout << "===== MENU =====\n";
    	cout << "1. Red Neuronal\n";
    	cout << "2. Calculadora\n";
    	cout << "3. Laberinto\n";
    	cout << "0. Salir\n";
    	cout << "Opcion: ";
    	cin >> opcion;

    	switch(opcion){
        	case 1:
        	    redNeuronal();
        	    break;
        	case 2:
        	    calculadora();
        	    break;
        	case 3:
        	    laberinto();
        	    break;
        	case 0:
        		cout<<"------------\n";
        	    cout << "Hasta luego.\n";
        	    break;
        	default:
        		cout<<"----------------\n";
            	cout << "Opcion invalida.\n";
    	}

	}while(opcion != 0);
	return 0;
}
