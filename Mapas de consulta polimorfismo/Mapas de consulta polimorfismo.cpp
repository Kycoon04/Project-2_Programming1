#include <iostream>
#include"CImg.h"
#include"Header.h"
#include <string>
#include "stdlib.h"
using namespace cimg_library;
using namespace std;

int main()
{
	int options; bool resp = false;
	CImg<unsigned char> img("mapacr.png");
	CImg<unsigned char> img1 = img;
	Lista_Poblados obj1; obj1.Cargar_Lista(obj1); Lista_Escuelas obj2; obj2.Cargar_Lista(obj2); Lista_Colegios obj3; obj3.Cargar_Lista(obj3);
	int n = obj1.getn_Lista(); eslabon_Lista** ListaP = new eslabon_Lista * [n]; obj1.CargarVector(ListaP);
	n = obj2.getn_Lista(); eslabon_Lista** ListaE = new eslabon_Lista * [n]; obj2.CargarVector(ListaE);
	n = obj3.getn_Lista(); eslabon_Lista** ListaC = new eslabon_Lista * [n]; obj3.CargarVector(ListaC);
    while (resp == false) {
        system("cls");
        cout << endl << "-----------------MENU DE MAPA----------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "                    Salir                  (0)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "        Imprimir en texto Poblaciones      (1)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "         Imprimir en texto Escuelas        (2)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "         Imprimir en texto Colegios        (3)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "             Graficar Poblaciones          (4)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "              Graficar Escuelas            (5)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "  Graficar Poblaciones,Escuelas y Colegios (6)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "     Graficar e imprimir: Personalizada    (7)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "         Generar e imprimir indices        (8)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "   imprimir y graficar listado parametro   (9)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "   imprimir y graficar listado provincia   (10)" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Para realizar alguno de estos procesos digite el numero que le corresponde: " << endl;
        cin >> options;
        if (options == 0) {
            resp = true;
        }
        if (options == 1) {
            obj1.Mostrar_Lista();
        }
        if (options == 2) {
            obj2.Mostrar_Lista();
        }
        if (options == 3) {
            obj3.Mostrar_Lista();
        }
        if (options == 4) {
            obj1.Graficar_Lista(img);
            img = img1;
        }
        if (options == 5) {
            obj2.Graficar_Lista(img);
            img = img1;
        }
        if (options == 6) {
            obj1.Graficar_TLista(img, obj1, obj2, obj3);
        }
        if (options == 7) {
            int opcion = 0;
            system("cls");

            cout << "Que lista quiere ver: " << endl;
            cout << "                  Escuelas                 (1)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Colegios                 (2)" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
                obj2.Graficar_ListaProvincia(img); break;
            case 2:
                obj3.Graficar_ListaProvincia(img); break;
            default: cout << "Digite el numero correcto" << endl;
            }
        }
        if (options == 8) {
            int opcion = 0;
            system("cls");

            cout << "De que lista quiere aplicar el indice: " << endl;
            cout << "                  Poblados                 (1)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Escuelas                 (2)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Colegios                 (3)" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
                obj1.GenerarIndices(ListaP); break;
            case 2:
                obj2.GenerarIndices(ListaE); break;
            case 3:
                obj3.GenerarIndices(ListaC); break;
            default: cout << "Digite el numero correcto" << endl;
            }
            system("pause");
        }
        if (options == 9) {
        }
        if (options == 10) {
        }
    }
    delete[] ListaP;
    delete[] ListaE;
    delete[] ListaC;
	return 0;
}
