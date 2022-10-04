#include "Utils.h"
#include <cstdlib>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

double funcion_de_x(double x, int grado, vector<int> coeficientes);
double funcion_derivada(double x, int grado, vector<int> coeficientes);
double* funcion_raiz(double x, int grado, vector<int> coeficientes);

/**
 * Evaluador de polinomios.
 *
 * @param argc Cantidad de argumentos
 * @param argv matriz de argumentos
 * @return El código de salida del programa.
 */
int main(int argc, char **argv) {
  int exitCode;
  vector<int> coeficiente;

  /// Si no hay argumentos suficientes mostramos un texto por defecto.
  if (argc != 3) {
  	cout << "Argumentos inválidos, ejecute el programa de la siguiente forma:" << endl;
	cout << argv[0] << " \"[integral polinomica]\" [valor]" << endl;
    exitCode = EXIT_FAILURE;
  } else {
    /// Procesamos
    const string polinomio(argv[1]);
    const double valor = atof(argv[2]);
    cout << endl << "polinomio (cmd): " << polinomio << endl;
    cout << "Valor: " << valor << endl;
    vector<Monomio> monomios = Utils::convertir(polinomio);//S	e convierte el polinomio ingresado en coeficiente y grado
    vector<Monomio>::size_type i = 0;
    Monomio monomio = monomios[i];
    int grado = monomio.GetGrado(); //Se obtiene el grado a traves de la funcion
    double aux_grado = grado;
    
    //Se almacenan los coeficientes dentro de un vector
    for (i = 0; i < monomios.size(); i++) {
	Monomio monomio = monomios[i];
	
	//Se pushea un '0' dentro del vector
	while (monomio.GetGrado() < aux_grado){
		coeficiente.push_back(0);
		aux_grado--;
	}
	
	//Se le pushea el valor de un coeficiente al vector ubicado dentro de una variable auxiliar
	double aux = monomio.GetCoeficiente();
	coeficiente.push_back(aux);
	aux_grado--;
    }
    
    //Se verifica si hay raiz
    while(1)
    {
        double* rt = funcion_raiz(valor, grado, coeficiente);
        if (rt[1] == 1) //En caso de que exista, se entrega el valor
        {
            cout << "" << endl;
            cout << "Una de las raices es: " << rt[0] << endl;
            cout << "" << endl;
            cout << "=== Integrantes === " << endl;
            cout << "" << endl;
            cout << "Matias Silva Farias" << endl;
            cout << "" << endl;
            cout << "Matias Alarcon Guajardo" << endl;
            cout << "" << endl;
            cout << "Juan Pablo Gonzalez" << endl;
            cout << "" << endl;
            cout << "Karina Sanchez Pino" << endl;
            cout << "" << endl;
            cout << "Ismael Jara Gutierrez" << endl;
            return exitCode;
        }
        else{ //Caso contrario, el loop se detendra en un valor y lo mostrara
            cout << "" << endl;
            cout << "No se encontraron raices" << endl;
            cout << "" << endl;
            cout << "=== Integrantes === " << endl;
            cout << "" << endl;
            cout << "Matias Silva Farias" << endl;
            cout << "" << endl;
            cout << "Matias Alarcon Guajardo" << endl;
            cout << "" << endl;
            cout << "Juan Pablo Gonzalez" << endl;
            cout << "" << endl;
            cout << "Karina Sanchez Pino" << endl;
            cout << "" << endl;
            cout << "Ismael Jara Gutierrez" << endl;
            return exitCode;
        
        }
    }
    
    double resultado = Utils::evaluar(monomios, valor);
    //cout << "Resultado: " << resultado << endl;
    exitCode = EXIT_SUCCESS;
  }

  cout << "" << endl;
  cout << "=== Integrantes === " << endl;
  cout << "" << endl;
  cout << "Matias Silva Farias" << endl;
  cout << "" << endl;
  cout << "Matias Alarcon Guajardo" << endl;
  cout << "" << endl;
  cout << "Juan Pablo Gonzalez" << endl;
  cout << "" << endl;
  cout << "Karina Sanchez Pino" << endl;
  cout << "" << endl;
  cout << "Ismael Jara Gutierrez" << endl;

  return exitCode;
}

double funcion_de_x(double x, int grado, vector<int> coeficientes)
{
    double value = 0;
    int i = 0;
    grado = grado+1;
    while(grado--)
    {
        value = value + coeficientes[i]*pow(x,grado);
        i++;
    }

    return value;
}

//Funcion que deriva el polinomio
double funcion_derivada(double x, int grado, vector<int> coeficientes)
{
    double value = 0;
    int i = 0;

    while (grado > 1)
    {
        value += grado*coeficientes[i]*pow(x,grado-1);
        i++;
        grado--;
    }
    value += coeficientes[i];

    return value;
}

//Funcion raiz, que permite obtener la raiz
double* funcion_raiz(double x, int grado, vector<int> coeficientes)
{
    double* y = new double[2];
    
    for (int i = 0; i < 200; i++)
    {
        double z = funcion_de_x(x,grado,coeficientes);

        if (z > 0.000001 || z < -0.000001)
        {
            x = x - (funcion_de_x(x,grado,coeficientes)/funcion_derivada(x,grado,coeficientes));
        }
        else{
            y[0] = x;
            y[1] = 1;
            return y;
        }
    }
    y[0] = x;
    y[1] = 0;
    return y;
}
