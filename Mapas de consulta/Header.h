#pragma once
#include <iostream>
using namespace std;
bool const SI = true;
bool const NO = false;

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
	int getn_Poblados();
	struct eslabon_Poblados* Pri();
	bool operator==(Lista_Poblados&);
	Lista_Poblados& operator=(Lista_Poblados&);
	bool Vacio_Poblados();
	void Vaciar_Poblados();
	void operator<<(struct eslabon_Poblados*);
	void Borrar_Poblados(struct eslabon_Poblados*);
	struct eslabon_Poblados* Buscar_Poblados(int d);
	void Mostrar_Poblados();
	void Cargar_Poblados(Lista_Poblados&);
	void Indices_Poblados(Lista_Poblados&);
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
	bool operator==(Lista_Escuelas&);
	Lista_Escuelas& operator=(Lista_Escuelas&);
	bool Vacio_Escuelas();
	void Vaciar_Escuelas();
	void operator<<(struct eslabon_Escuelas*);
	void Borrar_Escuelas(struct eslabon_Escuelas*);
	struct eslabon_Escuelas* Buscar_Escuelas(int d);
	void Mostrar_Escuelas();
	void Cargar_Escuelas(Lista_Escuelas&);
	void Indices_Escuelas(Lista_Escuelas&);
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
	bool operator==(Lista_Colegio&);
	Lista_Colegio& operator=(Lista_Colegio&);
	bool Vacio_Colegio();
	void Vaciar_Colegio();
	void operator<<(struct eslabon_Colegio*);
	void Borrar_Colegio(struct eslabon_Colegio*);
	struct eslabon_Colegio* Buscar_Colegio(int d);
	void Mostrar_Colegio();
	void Cargar_Colegio(Lista_Colegio&);
	void Indices_Colegio(Lista_Colegio&);
};