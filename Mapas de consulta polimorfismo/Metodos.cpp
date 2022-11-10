#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>
#include"CImg.h"
#include <sstream>
#include <stdlib.h>
using namespace std;
using namespace cimg_library;
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//eslabon padre
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
eslabon_Lista::eslabon_Lista(string a, string b, string xs, string ys) {
	pro_eslabon = NULL; Nombre = a; Cantidad = b; x = xs; y = ys;
}
eslabon_Lista::eslabon_Lista(string a, string b, string c, string d, string e, string xs, string ys) {
	pro_eslabon = NULL;  Nombre = a; Cantidad = b; Provincia = c; Canton = d; Distrito = e; x = xs; y = ys;
}
eslabon_Lista::~eslabon_Lista() { pro_eslabon = NULL; }
eslabon_Lista* eslabon_Lista::Pro() { return pro_eslabon; };
void eslabon_Lista::SetPro(eslabon_Lista* q) { pro_eslabon=q; };
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//Lista padre
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
Lista::Lista(){
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
}
Lista::~Lista()
{
	Vaciar_Lista();
}
eslabon_Lista* Lista::Pri() { return p_Listas; }
eslabon_Lista* Lista::Ult() { return u_Listas; }
int  Lista::getn_Lista() { return n; }
bool Lista::Vacio_Lista()
{
	return (p_Listas == NULL && u_Listas == NULL);
}
void Lista::Vaciar_Lista()
{
	eslabon_Lista* aux1, * aux2;
	aux2 = NULL;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		aux2 = aux1;
		if (aux1 != u_Listas) aux1 = aux1->Pro(); else aux1 = NULL;
		delete aux2;
	};
	p_Listas = NULL; u_Listas = NULL;
}
void Lista::operator<<(eslabon_Lista* q)
{
	if (p_Listas == NULL) 
	{
		q->SetPro(q); p_Listas = u_Listas = q;
	}
	else
	{
		q->SetPro(p_Listas);
		u_Listas->SetPro(q);
		u_Listas = q;
	}
}
void Lista::Graficar_Lista(CImg<unsigned char>& img)
{
	CImgDisplay ventana;
	CImg<unsigned char> imagen;
	unsigned int w, h;
	w = img.width();
	h = img.height();
	ventana.resize(w, h, true);
	ventana.set_title("Mapa");
	imagen.assign(img);
	const unsigned char negro[] = { 0, 0, 255 };
	struct eslabon_Lista* auxXs = Pri();
	while (auxXs != NULL)
	{
		int auxX = stoi(auxXs->Getx());
		int auxY = stoi(auxXs->Gety());
		imagen.draw_circle(auxX, auxY, 1, negro);
		if (auxXs != u_Listas)
			auxXs = auxXs->Pro();
		else
			auxXs = NULL;
	}
	ventana.display(imagen); system("pause");
}
void Lista::Graficar_TLista(CImg<unsigned char>& img, Lista&a, Lista&b, Lista&c) {
	CImgDisplay ventana;
	CImg<unsigned char> imagen;
	unsigned int w, h;
	w = img.width();
	h = img.height();
	ventana.resize(w, h, true);
	ventana.set_title("Mapa");
	imagen.assign(img);
	const unsigned char azul[] = { 0, 0, 255 };
	const unsigned char verde[] = { 0, 255, 0 };
	const unsigned char rojo[] = { 255, 0, 0 };
	struct eslabon_Lista* auxXa = a.Pri();
	struct eslabon_Lista* auxXb = b.Pri();
	struct eslabon_Lista* auxXc = c.Pri();
	int auxX; int auxY;
	for (int i = 0; i < a.getn_Lista(); i++) {
		auxX = stoi(auxXb->Getx());
		auxY = stoi(auxXb->Gety());
		imagen.draw_circle(auxX, auxY, 1, rojo);
		auxX = stoi(auxXa->Getx());
		auxY = stoi(auxXa->Gety());
		imagen.draw_circle(auxX, auxY, 1, verde);
		auxX = stoi(auxXc->Getx());
		auxY = stoi(auxXc->Gety());
		imagen.draw_circle(auxX, auxY, 1, azul);
		auxXb = auxXb->Pro();
		auxXa = auxXa->Pro();
		auxXc = auxXc->Pro();
	}
	ventana.display(imagen); system("pause");
}

void Lista::CargarVector(eslabon_Lista** Lista) {
	struct eslabon_Lista* aux1;
	aux1 = Pri();
	for (int i = 0; i < getn_Lista(); ++i) {
		Lista[i] = aux1;
		aux1 = aux1->Pro();
	}
}
void Lista::mergeSort(struct eslabon_Lista** Indice, int izquierda, int derecha,bool tipo)
{
	if (tipo == true) {
		if (izquierda < derecha) {

			int i, j, inf1 = izquierda, mit = (izquierda + derecha) / 2, inf2 = mit + 1;

			mergeSort(Indice, izquierda, mit, tipo);
			mergeSort(Indice, inf2, derecha, tipo);
			for (i = izquierda; i < derecha; i++) {

				if ((inf1 < inf2) && (izquierda < derecha) && (inf2 <= derecha)) {

					if (stoi(Indice[inf1]->GetCantidad()) > stoi(Indice[inf2]->GetCantidad())) {
						for (j = inf2; j > inf1; j--) {
							swap(Indice[j], Indice[j - 1]);
						}
						inf2++;
					}
					inf1++;
				}
				else {
					break;
				}
			}
		}
	}
	else {
		if (izquierda < derecha) {

			int i, j, inf1 = izquierda, mit = (izquierda + derecha) / 2, inf2 = mit + 1;

			mergeSort(Indice, izquierda, mit, tipo);
			mergeSort(Indice, inf2, derecha, tipo);
			for (i = izquierda; i < derecha; i++) {

				if ((inf1 < inf2) && (izquierda < derecha) && (inf2 <= derecha)) {

					if (Indice[inf1]->GetNombre() > Indice[inf2]->GetNombre()) {
						for (j = inf2; j > inf1; j--) {
							swap(Indice[j], Indice[j - 1]);
						}
						inf2++;
					}
					inf1++;
				}
				else {
					break;
				}
			}
		}
	}
}
void Lista::Graficar_ListaProvincia(CImg<unsigned char>& img) {
	cout << "Escriba el nombre de la provincia (EN MAYUSCULAS): ";
	string provincia;
	cin.ignore();
	getline(cin, provincia);
	CImg<unsigned char> imagen;
	imagen.assign(img);
	const unsigned char negro[] = { 0, 0, 255 };
	struct eslabon_Lista* auxXs = Pri();
	int cont = 0;
	for (int i = 0; i < n; i++) {
		if (auxXs->GetProvincia() == provincia) {
			int auxX = stoi(auxXs->Getx());
			int auxY = stoi(auxXs->Gety());
			imagen.draw_circle(auxX, auxY, 1, negro);
			cont++;
		}
		auxXs = auxXs->Pro();
	}
	if (cont != 0) {
		CImgDisplay ventana;
		unsigned int w, h;
		w = img.width();
		h = img.height();
		ventana.resize(w, h, true);
		ventana.set_title("Mapa");
		cout << "Encontrados: " << cont << endl;
		ventana.display(imagen); system("pause");
	}
	else {
		cout << endl << "Porfavor escriba un nombre correcto" << endl; system("pause");
	}
}
void Lista::GenerarIndices(eslabon_Lista** Lista) {
	int opcion,n;
	bool tipo = true;
	cout << "Que indice quiere aplicar:  " << endl;
	cout << "                  Nombre                   (1)" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "                 Cantidad                  (2)" << endl;
	cout << "---------------------------------------------" << endl;
	cin >> opcion;
	switch (opcion) {
	case 1: tipo = false; break;
	case 2: tipo = true; break;
	default: cout << "Digite el numero correcto" << endl;
	}
	n = getn_Lista();
	mergeSort(Lista, 0, n - 1,tipo);
	Mostrar_Indice(Lista);
}
void Lista::GraficarParametro(CImg<unsigned char>& imagen, eslabon_Lista** Lista) {
	int opcion;
	string elem="";
	bool tipo = true;
	cout << "De que lista quiere aplicar el parametro:  " << endl;
	cout << "                  Nombre                   (1)" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "                 Cantidad                  (2)" << endl;
	cout << "---------------------------------------------" << endl;
	cin >> opcion;
	switch (opcion) {
	case 1:
		cout << "Escriba el nombre de la poblacion para filtrar: ";;
		cin.ignore();
		getline(cin, elem);
		tipo = false;
		busquedaBinaria(Lista, elem, imagen, tipo);
		break;
	case 2:
		cout << "Escriba el numero de habitantes para filtrar: "; cin >> elem; 
		tipo = true; 
		busquedaBinaria(Lista, elem, imagen, tipo);
		break;
	default: cout << "Digite el numero correcto" << endl;
	}
	
}
int Lista::busquedaBinaria(eslabon_Lista** Lista, string elem, CImg<unsigned char>& imagen, bool tipo) {
	int n;
	n = getn_Lista();
	int inicio = 0;
	int fin = n - 1;
	int mitad;
	bool continuar = true;
	
	if(tipo==true){
		mergeSort(Lista, 0, n - 1, tipo);
		while ((continuar)) {
			mitad = (inicio + fin) / 2;
			if (!(inicio <= fin)) {
				continuar = false;
			}
			if (stoi(elem) == stoi(Lista[mitad]->GetCantidad())) {
				continuar = false;
			}
			else {
				if (stoi(elem) > stoi(Lista[mitad]->GetCantidad()))
					inicio = mitad + 1;
				else
					fin = mitad - 1;
			}
		}
		while (stoi(Lista[mitad-1]->GetCantidad()) == stoi(Lista[mitad]->GetCantidad())) {
			mitad--;
		}
	}
	else
	{
		mergeSort(Lista, 0, n - 1, tipo);
		while ((continuar)) {
			mitad = (inicio + fin) / 2;
			if (!(inicio <= fin)) {
				continuar = false;
			}
			if (elem == Lista[mitad]->GetNombre()) {
				continuar = false;
			}
			else {
				if (elem > Lista[mitad]->GetNombre())
					inicio = mitad + 1;
				else
					fin = mitad - 1;
			}
		}
		while (Lista[mitad - 1]->GetNombre() == Lista[mitad]->GetNombre()) {
			mitad--;
		}
	}
	return mitad;
}
void Lista::GraficarDosParametro(CImg<unsigned char>& imagen, eslabon_Lista** Lista) {
	string elem;
	int n;
	int tipo = true;
	n = getn_Lista();
	mergeSort(Lista, 0, n - 1,true);
	cout << "Escriba el numero de habitantes para filtrar: " << endl; cin >> elem;
	//busquedaBinariaParametro(Lista, elem, imagen, tipo);
}
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//Lista Poblados
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
Lista_Poblados::Lista_Poblados()
{
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
}

void Lista_Poblados::Mostrar_Lista() {
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Poblacion: " << aux1->GetNombre() << " - Numero de Habitantes: " << aux1->GetCantidad() << " - X: " << aux1->Getx() << " - Y: " << aux1->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
	}
	system("pause");
}
void Lista_Poblados::Cargar_Lista(Lista& h) {
	string fil_nam3 = "poblados2.txt";
	ifstream handle0;
	string line, aux[4];
	string a, b, x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true;
	while (continuar) {
		getline(handle0, line);
		if (!handle0.eof()) {
			for (int i = 0; i < 3; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q);
				line = line.substr(q + 1, -1);
			}
			aux[3] = line.substr(0, -1);
		}
		else {
			continuar = false;
		}
		a = aux[0], b = aux[1], x = aux[2], y = aux[3];
		eslabon_Lista* aux1 = new eslabon_Lista(a, b, x, y);
		h << aux1;
		n++;
	}
}
void Lista_Poblados::Mostrar_Indice(eslabon_Lista** Indice) {
	int i = 0;
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Poblacion: " << Indice[i]->GetNombre() << " - Numero de Habitantes: " << Indice[i]->GetCantidad() << " - X: " << Indice[i]->Getx() << " - Y: " << Indice[i]->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
		i++;
	}
}
int Lista_Poblados::busquedaBinaria(eslabon_Lista** Lista, string elem, CImg<unsigned char>& imagen, bool tipo) {
	Lista_Poblados aux1;
	int mitad= Lista::busquedaBinaria(Lista, elem, imagen, tipo);
	int size;
	size = getn_Lista();
	for (int i = mitad; i < size - 1; ++i) {
		struct eslabon_Lista* aux = new eslabon_Lista(Lista[i]->GetNombre(), Lista[i]->GetCantidad(), Lista[i]->Getx(), Lista[i]->Gety());
		aux1 << aux;
		aux1.n++;
	}
	aux1.Mostrar_Lista();
	aux1.Graficar_Lista(imagen);
	aux1.~Lista_Poblados();
	return mitad;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//Lista Colegio
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
Lista_Colegios::Lista_Colegios(){
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
}

void Lista_Colegios::Mostrar_Lista() {
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Institucion: " << aux1->GetNombre() << " - Numero de estudiantes: " << aux1->GetCantidad() << " - Provincia: " << aux1->GetProvincia() <<" - Canton: " << aux1->GetCanton() << " - Distrito: " << aux1->GetDistrito() << " - X: " << aux1->Getx() << " - Y: " << aux1->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
	}
	system("pause");
}
void Lista_Colegios::Cargar_Lista(Lista& h) {
	string fil_nam3 = "colegios2.txt";
	ifstream handle0;
	string line, aux[7];
	string a, b, c, d, e, x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true;
	while (continuar) {
		getline(handle0, line);
		if (!handle0.eof()) {
			for (int i = 0; i < 7; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q);
				line = line.substr(q + 1, -1);
			}
		}
		else {
			continuar = false;
		}
		a = aux[0], b = aux[1], c = aux[2], d = aux[3], e = aux[4], x = aux[5], y = aux[6];
		struct eslabon_Lista* aux1 = new eslabon_Lista(a, b,c,d,e, x, y);
		h << aux1;
		n++;
	}
}
void Lista_Colegios::Mostrar_Indice(eslabon_Lista** Indice) {
	int i = 0;
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Institucion: " << Indice[i]->GetNombre() << " -  Numero de estudiantes: " << Indice[i]->GetCantidad() << " -  Provincia: " << Indice[i]->GetProvincia() <<
			" -  Canton: " << Indice[i]->GetCanton() << " -  Distrito: " << Indice[i]->GetDistrito() << " -  X: " << Indice[i]->Getx() << " -  Y: " << Indice[i]->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
		i++;
	}
}
int Lista_Colegios::busquedaBinaria(eslabon_Lista** Lista, string elem, CImg<unsigned char>& imagen, bool tipo) {
	Lista_Colegios aux1;
	int mitad = Lista::busquedaBinaria(Lista, elem, imagen, tipo);
	int size;
	size = getn_Lista();
	for (int i = mitad; i < size - 1; ++i) {
		struct eslabon_Lista* aux = new eslabon_Lista(Lista[i]->GetNombre(), Lista[i]->GetCantidad(), Lista[i]->GetProvincia(), Lista[i]->GetCanton(), Lista[i]->GetDistrito(), Lista[i]->Getx(), Lista[i]->Gety());
		aux1 << aux;
		aux1.n++;
	}
	aux1.Mostrar_Lista();
	aux1.Graficar_Lista(imagen);
	aux1.~Lista_Colegios();
	return mitad;
}
void Lista_Colegios::busquedaBinariaParametro(CImg<unsigned char>& imagen, eslabon_Lista** Lista) {
	
	string elem;
	int n;
	int tipo = true;
	n = getn_Lista();
	mergeSort(Lista, 0, n - 1,true);
	cout << "Escriba el numero de habitantes para filtrar: " << endl; cin >> elem;
	Lista_Colegios aux1;
	cout << "Escriba el nombre de la provincia (EN MAYUSCULAS): ";
	string provincia;
	cin.ignore();
	getline(cin, provincia);
	int mitad = Lista::busquedaBinaria(Lista, elem, imagen, tipo);
	int size;
	size = getn_Lista();
	for (int i = mitad; i < size - 1; ++i) {
		if (Lista[i]->GetProvincia() == provincia) {
			struct eslabon_Lista* aux = new eslabon_Lista(Lista[i]->GetNombre(), Lista[i]->GetCantidad(), Lista[i]->GetProvincia(), Lista[i]->GetCanton(), Lista[i]->GetDistrito(), Lista[i]->Getx(), Lista[i]->Gety());
			aux1 << aux;
			aux1.n++;
		}
	}
	aux1.Mostrar_Lista();
	aux1.Graficar_Lista(imagen);
	aux1.~Lista_Colegios();
}
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
//Lista Escuela
//-------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
Lista_Escuelas::Lista_Escuelas() {
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
}
void Lista_Escuelas::Mostrar_Lista() {
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Institucion: " << aux1->GetNombre() << " - Numero de estudiantes: " << aux1->GetCantidad() << " - Provincia: " << aux1->GetProvincia() << " - Canton: " << aux1->GetCanton() << " - Distrito: " << aux1->GetDistrito() << " - X: " << aux1->Getx() << " - Y: " << aux1->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
	}
	system("pause");
}
void Lista_Escuelas::Cargar_Lista(Lista& h) {
	string fil_nam3 = "escuelas2.txt";
	ifstream handle0;
	string line, aux[7];
	string a, b, c, d, e, x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true;
	while (continuar) {
		getline(handle0, line);
		if (!handle0.eof()) {
			for (int i = 0; i < 7; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q);
				line = line.substr(q + 1, -1);
			}
		}
		else {
			continuar = false;
		}
		a = aux[0], b = aux[1], c = aux[2], d = aux[3], e = aux[4], x = aux[5], y = aux[6];
		struct eslabon_Lista* aux1 = new eslabon_Lista(a, b, c, d, e, x, y);
		h << aux1;
		n++;
	}
}
void Lista_Escuelas::Mostrar_Indice(eslabon_Lista** Indice) {
	int i = 0;
	eslabon_Lista* aux1;
	aux1 = Pri();
	while (aux1 != NULL)
	{
		cout << "Nombre de Institucion: " << Indice[i]->GetNombre() << " -  Numero de estudiantes: " << Indice[i]->GetCantidad() << " -  Provincia: " << Indice[i]->GetProvincia() <<
			" -  Canton: " << Indice[i]->GetCanton() << " -  Distrito: " << Indice[i]->GetDistrito() << " -  X: " << Indice[i]->Getx() << " -  Y: " << Indice[i]->Gety() << '\n';
		if (aux1 != Ult())
			aux1 = aux1->Pro();
		else
			aux1 = NULL;
		i++;
	}
}
int Lista_Escuelas::busquedaBinaria(eslabon_Lista** Lista, string elem, CImg<unsigned char>& imagen, bool tipo) {
	Lista_Escuelas aux1;
	int mitad = Lista::busquedaBinaria(Lista, elem, imagen, tipo);
	int size;
	size = getn_Lista();
	for (int i = mitad; i < size - 1; ++i) {
		struct eslabon_Lista* aux = new eslabon_Lista(Lista[i]->GetNombre(), Lista[i]->GetCantidad(), Lista[i]->GetProvincia(), Lista[i]->GetCanton(), Lista[i]->GetDistrito(), Lista[i]->Getx(), Lista[i]->Gety());
		aux1 << aux;
		aux1.n++;
	}
	aux1.Mostrar_Lista();
	aux1.Graficar_Lista(imagen);
	aux1.~Lista_Escuelas();
	return mitad;
}
void Lista_Escuelas::busquedaBinariaParametro(CImg<unsigned char>& imagen, eslabon_Lista** Lista) {
	string elem;
	int n;
	int tipo = true;
	n = getn_Lista();
	mergeSort(Lista, 0, n - 1,true);
	cout << "Escriba el numero de habitantes para filtrar: " << endl; cin >> elem;
	Lista_Escuelas aux1;
	cout << "Escriba el nombre de la provincia (EN MAYUSCULAS): ";
	string provincia;
	cin.ignore();
	getline(cin, provincia);
	int mitad = Lista::busquedaBinaria(Lista, elem, imagen, tipo);
	int size;
	size = getn_Lista();
	for (int i = mitad; i < size - 1; ++i) {
		if (Lista[i]->GetProvincia() == provincia) {
			struct eslabon_Lista* aux = new eslabon_Lista(Lista[i]->GetNombre(), Lista[i]->GetCantidad(), Lista[i]->GetProvincia(), Lista[i]->GetCanton(), Lista[i]->GetDistrito(), Lista[i]->Getx(), Lista[i]->Gety());
			aux1 << aux;
			aux1.n++;
		}
	}
	aux1.Mostrar_Lista();
	aux1.Graficar_Lista(imagen);
	aux1.~Lista_Escuelas();
}