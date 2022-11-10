#pragma once
#include <iostream>
#include"CImg.h"
using namespace cimg_library;
using namespace std;

struct eslabon_Lista{
protected:
	eslabon_Lista* pro_eslabon;
	string Nombre;
	string Cantidad;
	string Provincia;
	string Canton;
	string Distrito;
	string x;
	string y;
public:
	eslabon_Lista(string a, string b, string xs, string ys);
	eslabon_Lista(string a, string b, string c, string d, string e, string xs, string ys);
	virtual ~eslabon_Lista();
	virtual eslabon_Lista* Pro();
	virtual void SetPro(eslabon_Lista*);
	virtual string GetNombre() { return Nombre; };
	virtual string GetCantidad() { return Cantidad; };
	virtual string GetProvincia() { return Provincia; };
	virtual string GetCanton() { return Canton; };
	virtual string GetDistrito() { return Distrito; };
	virtual string Getx() { return x; };
	virtual string Gety() { return y; };
};

class Lista {
protected:
	eslabon_Lista* p_Listas;
	eslabon_Lista* u_Listas;
	int n;
public:
	 Lista();
	~Lista();
	virtual eslabon_Lista* Pri();
	virtual eslabon_Lista* Ult();
	virtual int getn_Lista();
	virtual bool Vacio_Lista();
	virtual void Vaciar_Lista();
	virtual void Cargar_Lista(Lista&) { cout << "nada" << endl; }
	virtual void operator<<(eslabon_Lista*);
	virtual void Mostrar_Lista() { cout << "nada"<<endl; }
	virtual void Graficar_Lista(CImg<unsigned char>& img);
	virtual void Graficar_TLista(CImg<unsigned char>& img, Lista&, Lista&, Lista&);
	virtual void CargarVector(eslabon_Lista** Lista);
	virtual void Mostrar_Indice(eslabon_Lista** Indice)=0;
	virtual void merge(struct eslabon_Lista** Indice, int const left, int const mid, int const right,bool tipo);
	virtual void mergeSort(struct eslabon_Lista** Indice, int izquierda, int derecha, bool tipo);
	virtual void Graficar_ListaProvincia(CImg<unsigned char>& img);
	virtual void GenerarIndices(eslabon_Lista** Lista);
};
class Lista_Poblados : public Lista {
private: 
public:
	Lista_Poblados();
	void Mostrar_Lista();
	void Cargar_Lista(Lista&);
	void Mostrar_Indice(eslabon_Lista** Indice);
};

class Lista_Colegios : public Lista {
private:
public:
	Lista_Colegios();
	void Mostrar_Lista();
	void Cargar_Lista(Lista&);
	void Mostrar_Indice(eslabon_Lista** Indice);
};
class Lista_Escuelas : public Lista {
private:
public:
	Lista_Escuelas();
	void Mostrar_Lista();
	void Cargar_Lista(Lista&);
	void Mostrar_Indice(eslabon_Lista** Indice);
};