#pragma once
#include <iostream>
#include"CImg.h"
using namespace std;
bool const SI = true;
bool const NO = false;
using namespace cimg_library;
using namespace std;
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//header Lista Poblaciones
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
struct eslabon_Poblados {
public:
	struct eslabon_Poblados* pro_eslabon;
	string NombrePoblacion;
	string Habitantes;
	string x;
	string y;
public: 
	eslabon_Poblados(string a, string b, string xs, string ys);
	~eslabon_Poblados();
	struct eslabon_Poblados* Pro();
};
class Lista_Poblados{ //Lista de las poblaciones
private:
	struct eslabon_Poblados* p_Listas;
	struct eslabon_Poblados* u_Listas;
	int n;
public:
	Lista_Poblados();
	~Lista_Poblados();
	struct eslabon_Poblados* Pri();
	int getn_poblados();
	bool Vacio_Poblados();
	void Vaciar_Poblados();
	void operator<<(struct eslabon_Poblados*);
	void Borrar_Poblados(struct eslabon_Poblados*);
	void Mostrar_Poblados();
	void Mostrar_IndicePoblados(struct eslabon_Poblados** Indice);
	void Cargar_Poblados(Lista_Poblados&);
	void CargarVector_Poblados(struct eslabon_Poblados** Lista);
	void Indices_Poblados(struct eslabon_Poblados** Lista);
	void merge_PobladosHabitantes(struct eslabon_Poblados** Indice, int const left, int const mid, int const right);
	void mergeSort_PobladosHabitantes(struct eslabon_Poblados** Indice,int izquierda, int derecha);
	void merge_NombrePoblacion(struct eslabon_Poblados** Indice, int const left, int const mid, int const right);
	void mergeSort_NombrePoblacion(struct eslabon_Poblados** Indice, int izquierda, int derecha);
	void Graficar_Poblaciones(CImg<unsigned char>& imagen);
};

//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//Clase Lista Escuelas
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________

struct eslabon_Escuelas { //Lista de las escuelas
public:
	struct eslabon_Escuelas* pro_eslabon;
	string NombreIntitucion;
	string Estudiantes;
	string Provincia;
	string Canton;
	string Distrito;
	string x;
	string y;

public:
	eslabon_Escuelas(string a, string b, string c, string d, string e, string xs, string ys);
	~eslabon_Escuelas();
	struct eslabon_Escuelas* Pro();
};
class Lista_Escuelas {
private:
	struct eslabon_Escuelas* p_Listas;
	struct eslabon_Escuelas* u_Listas;
	int n;
public:
	Lista_Escuelas();
	~Lista_Escuelas();
	int getn_Escuelas();
	struct eslabon_Escuelas* Pri();
	bool Vacio_Escuelas();
	void Vaciar_Escuelas();
	void Mostrar_IndiceEscuelas(struct eslabon_Escuelas** Indice);
	void operator<<(struct eslabon_Escuelas*);
	void Borrar_Escuelas(struct eslabon_Escuelas*);
	void Mostrar_Escuelas();
	void Cargar_Escuelas(Lista_Escuelas&);
	void CargarVector_Escuelas(struct eslabon_Escuelas** Lista);
	void Indices_Escuelas(struct eslabon_Escuelas** Lista);
	void merge_EscuelasEstudiantes(struct eslabon_Escuelas** Indice, int const left, int const mid, int const right);
	void mergeSort_EscuelasEstudiantes(struct eslabon_Escuelas** Indice, int izquierda, int derecha);
	void merge_NombreEscuelas(struct eslabon_Escuelas** Indice, int const left, int const mid, int const right);
	void mergeSort_NombreEscuelas(struct eslabon_Escuelas** Indice, int izquierda, int derecha);
	void Graficar_Escuelas(CImg<unsigned char>& imagen);
	void Graficar_EscuelasParametro(CImg<unsigned char>& imagen);
};
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//Clase Lista Colegio
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________

struct eslabon_Colegio { //Lista de los Colegios
public:
	struct eslabon_Colegio* pro_eslabon;
	string NombreIntitucion;
	string Estudiantes;
	string Provincia;
	string Canton;
	string Distrito;
	string x;
	string y;

public:
	eslabon_Colegio(string a, string b, string c, string d, string e, string xs, string ys);
	~eslabon_Colegio();
	struct eslabon_Colegio* Pro();
};
class Lista_Colegio {
private:
	struct eslabon_Colegio* p_Listas;
	struct eslabon_Colegio* u_Listas;
	int n;
public:
	Lista_Colegio();
	~Lista_Colegio();
	int getn_Colegio();
	struct eslabon_Colegio* Pri();
	bool Vacio_Colegio();
	void Vaciar_Colegio();
	void Mostrar_IndiceColegios(struct eslabon_Colegio** Indice);
	void operator<<(struct eslabon_Colegio*);
	void Borrar_Colegio(struct eslabon_Colegio*);
	void Mostrar_Colegio();
	void Cargar_Colegio(Lista_Colegio&);
	void CargarVector_Colegio(struct eslabon_Colegio** Lista);
	void Indices_Colegio(struct eslabon_Colegio** Lista);
	void merge_ColegioEstudiantes(struct eslabon_Colegio** Indice, int const left, int const mid, int const right);
	void mergeSort_ColegioEstudiantes(struct eslabon_Colegio** Indice, int izquierda, int derecha);
	void merge_NombreColegio(struct eslabon_Colegio** Indice, int const left, int const mid, int const right);
	void mergeSort_NombreColegio(struct eslabon_Colegio** Indice, int izquierda, int derecha);
	void Graficar_Todo(CImg<unsigned char>& img, struct eslabon_Escuelas* a, Lista_Colegio& b, struct eslabon_Poblados* c);
	void Graficar_ColegioParametro(CImg<unsigned char>& img);
};