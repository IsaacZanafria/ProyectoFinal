#include <iostream>
#include "proyecto.h"

using namespace std;

//Ejercicio 5
void laberinto(){
	int laberinto[][10] = {		//arreglo bidimensional para el laberinto
		{1,1,1,1,2,1,1,1,1,1},	// 2 representa el inicio del laberinto
		{1,1,1,1,0,0,0,0,1,1},	// 1 representa las paredes del laberinto
		{1,1,1,0,0,1,1,0,1,1},	// 0 representa los caminos del laberinto
		{0,0,0,0,1,1,1,0,1,1},	// 3 represneta la salida del laberinto
		{1,1,1,0,1,1,1,0,0,1},
		{1,0,0,0,0,1,1,1,1,1},
		{1,1,1,1,0,1,1,0,1,1},
		{1,1,1,1,0,0,0,0,1,1},
		{1,1,1,1,0,1,1,1,1,1},
		{1,1,1,0,0,0,0,3,1,1}
	};

	cout<<"-------------------";
    cout << "\n     LABERINTO      \n";
    cout<<"-------------------\n";
    imprimir(laberinto);	//llama a funcion imprimir para mostrar el laberinto original
    cout<<"-------------------\n";
    char respuesta;
    cout << "\n¿Desea resolver el laberinto? (S/N): ";
    cin >> respuesta;
    
    if(respuesta == 'S' || respuesta == 's'){
    	int inicioX, inicioY;	//declarar variables para el inicio del laberinto
    	buscarInicio(laberinto, inicioX, inicioY);	//llamar a funcion para buscar el inicio del laberinto

    	if(resolver(laberinto, inicioX, inicioY)){	//llamar a funcion resolver, enviando el laberinto y las posiciones del inicio
        	cout << "\nExiste un camino hacia la salida:\n\n";	// si retorna "true" existe solucion al laberinto
		
			cout<<"-------------------";
    		cout << "\nLaberinto resuelto:\n";
    		cout<<"-------------------\n";
    		imprimir(laberinto);	//imprimir laberinto resuelto
    		cout<<"-------------------\n";
		}else{
			cout<<"------------------------------------";
			cout << "\nNo existe un camino hacia la salida.\n";	// si retorna "false" no existe solucion al laberinto
		}
	}else{
		cout<<"-------------------------------";
		cout << "\nRegresando al menu principal...\n";
	}
}

void imprimir(int lab[][10]) {	//funcion imprimir laberinto
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << lab[i][j] << " ";
        }
        cout << endl;
    }
}

void buscarInicio(int lab[][10], int &x, int &y) {	//funcion buscar inicio, variables x e y por referencia
    for(int i = 0; i < 10; i++) {	//bucle para recorrer las filas
        for(int j = 0; j < 10; j++) {	//bucle para recorrer las columnas
            if(lab[i][j] == 2) {	//comprobar si la posicion contiene al inicio
                x = i;				//guardar las posiciones del inicio del laberinto
                y = j;
                return;	
            }	
        }
    }
}

bool resolver(int lab[][10], int x, int y) {	//funcion para resolver el laberinto
	//primer caso base: fuera de los límites del laberinto (no se puede seguir por ahi)
    if(x < 0 || x >= 10 || y < 0 || y >= 10) return false;	 
	//segundo caso base: pared o camino ya visitado 
    if(lab[x][y] == 1 || lab[x][y] == 4) return false;		
    //tercer caso base: salida encontrada
    if(lab[x][y] == 3) return true;
    
    // Marcar como visitado la posicion actual, excepto el inicio
    if(lab[x][y] != 2)	lab[x][y] = 4;
		
	
	//====Recursividad====
    //llama nuevamente a la funcion con una posicion hacia arriba
    if(resolver(lab, x - 1, y)) return true;	//si encuentra la salida retorna "true"

    //llama nuevamente a la funcion con una posicion hacia abajo
    if(resolver(lab, x + 1, y)) return true;	//si encuentra la salida retorna "true"

    //llama nuevamente a la funcion con una posicion hacia la izquierda
    if(resolver(lab, x, y - 1)) return true;	//si encuentra la salida retorna "true"	

    //llama nuevamente a la funcion con una posicion hacia la derecha
    if(resolver(lab, x, y + 1)) return true;	//si encuentra la salida retorna "true"	

   	//retroceso
    if(lab[x][y] == 4) lab[x][y] = 0;	//si no encuentra la salida en ningua direccion regresa desmarcando las casillas visitadas


    return false;	//informa a la llamada anterior que en esa posicion no existe camino hacia la salida
}
	
	
	
