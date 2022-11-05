#include <iostream>
#include"CImg.h"
#include"Header.h"
#include "stdlib.h"

using namespace cimg_library;
using namespace std;

int main() {
    int options; bool resp = false;
    CImg<unsigned char> img("Imagen.png");
    CImg<unsigned char> img1 = img;
    Lista_Escuelas a; a.Cargar_Escuelas(a);Lista_Colegio b; b.Cargar_Colegio(b);Lista_Poblados c;  c.Cargar_Poblados(c);
    int aux = c.getn_poblados(); struct eslabon_Poblados** ListaP = new eslabon_Poblados * [aux]; c.CargarVector_Poblados(ListaP);
    aux = a.getn_Escuelas(); struct eslabon_Escuelas** ListaE = new eslabon_Escuelas * [aux];a.CargarVector_Escuelas(ListaE);
    aux = b.getn_Colegio(); struct eslabon_Colegio** ListaC = new eslabon_Colegio * [aux]; b.CargarVector_Colegio(ListaC);
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
            c.Mostrar_Poblados();
        }
        if (options == 2) {
            a.Mostrar_Escuelas(); 
        }
        if (options == 3) {
            b.Mostrar_Colegio();
        }
        if (options == 4) {
            c.Graficar_Poblaciones(img,c);
            img1 = img;
        }
        if (options == 5) {
            a.Graficar_Escuelas(img, a);
        }
        if (options == 6) {
            struct eslabon_Escuelas* auxXa = a.Pri();
            struct eslabon_Poblados* auxXc = c.Pri();
            b.Graficar_Todo(img,auxXa,b, auxXc);
        }
        if (options == 7) {
            int opcion = 0;
            system("cls");

            cout << "De que lista quiere aplicar el indice: " << endl;
            cout << "                  Poblados                 (1)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Colegios                 (2)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Escuelas                 (3)" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
                c.Mostrar_IndicePoblados(ListaP); system("pause"); break;
            case 2:
                b.Mostrar_IndiceColegios(ListaC); system("pause"); break;
            case 3:
                a.Mostrar_IndiceEscuelas(ListaE); system("pause"); break; break;
            default: cout << "Digite el numero correcto" << endl;
            }
        }
        if (options == 8) {
            int opcion = 0;
            system("cls");
            
            cout << "De que lista quiere aplicar el indice: " << endl;
            cout << "                  Poblados                 (1)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Colegios                 (2)" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "                  Escuelas                 (3)" << endl;
            cout << "---------------------------------------------" << endl;
            cin >> opcion;
            switch (opcion) {
            case 1:
            c.Indices_Poblados(ListaP); system("pause"); break;
            case 2: 
            b.Indices_Colegio(ListaC); system("pause"); break;
            case 3:
            a.Indices_Escuelas(ListaE); system("pause"); break;
            default: cout<< "Digite el numero correcto" << endl;
            }
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
