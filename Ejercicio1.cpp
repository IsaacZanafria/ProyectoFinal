#include <iostream>
#include "proyecto.h"

using namespace std;

//Ejercicio 1
void redNeuronal() {

    // Datos iniciales de entrenamiento
    double X[] = {0, 1, 2, 3, 4};
    double Y[] = {1, 3, 5, 7, 9};

    int n = 5; //Guardar la cantidad de datos iniciales

    // Parámetros iniciales
    double w = 0.0;
    double b = 0.0;

    double m = 0.1; // taza de aprendizaje
    int repeticiones = 500; // numero de repeticiones 
 
    for(int repeticion = 0; repeticion <= repeticiones; repeticion++) {  //bucle para controlar el entrenamiento, cada repeticion mejora la prediccion de la recta
		
		//Inicializar gradientes
        double dw = 0.0;
        double db = 0.0;
        double mse = 0.0; //error cuadratico medio

        for(int i=0;i<n;i++) { //Bucle para recorrer todos los datos
			
			//Propagacion hacia adelante
            double yPred = w * X[i] + b;

            // calcular el error
            double error = yPred - Y[i];

            mse += error * error; //acumular el error (elevar el error al cuadrado)

            //Gradientes
            dw += error * X[i]; // gradiente del peso
            db += error; //gradiente del intercepto
        }

        mse /= n; // calcular el error promedio

        dw = (2.0/n) * dw; //promedio del gradiente
        db = (2.0/n) * db; //promedio del intercepto

        // Actualización
        w = w - m * dw;
        b = b - m * db;
		
		//mostrar el progreso
        if(repeticion % 50 == 0) {
            cout << "Repeticion: " << repeticion // muestra la repeticion actual
                 << " MSE: " << mse  // muestra el error promedio
                 << " w: " << w  //muestra el peso actual
                 << " b: " << b << endl;  //muestra el intercepto actual
        }
    }

    cout << "\nEntrenamiento finalizado\n";
    cout << "Peso (w) = " << w << endl;  // muestra la pendiente final aprendida
    cout << "Bias (b) = " << b << endl;	 // muestra el intercepto final aprendido

    // Predicción
    double x;

    cout << "\nIngrese un valor de X: ";
    cin >> x;

    double y = w * x + b;  //calcular la prediccion con los parametros aprendidos

    cout << "Prediccion Y = " << y << endl;
}
