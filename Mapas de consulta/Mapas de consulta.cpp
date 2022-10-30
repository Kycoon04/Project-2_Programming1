#include <iostream>
#include"CImg.h"
#include"Header.h"
#include "stdlib.h"

using namespace cimg_library;
using namespace std;

int main() {
    CImgDisplay ventana;
    CImg<unsigned char> imagen;
    unsigned int w, h;
    int options; bool resp = false;
    Lista_Escuelas a; a.Cargar_Escuelas(a);
    Lista_Colegio b; b.Cargar_Colegio(b);
    Lista_Poblados c; c.Cargar_Poblados(c);
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
            system("pause");
        }
        if (options == 2) {
            a.Mostrar_Escuelas(); 
            system("pause");
        }
        if (options == 3) {
            b.Mostrar_Colegio();
            system("pause");
        }
        if (options == 4) {
            CImg<unsigned char> img("Imagen.png");
            w = img.width();
            h = img.height();
            ventana.resize(w, h, true);
            ventana.set_title("Mapa");
            imagen.assign(img);
            ventana.display(imagen);
        }
        if (options == 5) {
        }
        if (options == 6) {
        }
        if (options == 7) {
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
            c.Indices_Poblados(c); system("pause"); break;
            case 2: 
            b.Indices_Colegio(b); system("pause"); break;
            case 3:
            a.Indices_Escuelas(a); system("pause"); break;
            default: cout<< "Digite el numero correcto" << endl;
            }
        }
        if (options == 9) {
        }
        if (options == 10) {
        }
    }
    return 0;
}
