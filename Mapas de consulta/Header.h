#pragma once
#include <iostream>
using namespace std;
void Clear();
bool const SI = true;
bool const NO = false;

struct eslabon{
public:
	struct eslabon* pro_eslabon;
	struct eslabon* ant_eslabon;
	int dato;
public: 
	eslabon(int);
	eslabon();
	~eslabon();
	struct eslabon* Pro();
	struct eslabon* Ant();
	int& Dato();
};

class Lista{
private:
	struct eslabon* p_Listas;
	struct eslabon* u_Listas;
	int n;
public:
	Lista();
	~Lista();
	int getn();
	struct eslabon* Pri();
	struct eslabon* Ult();
	bool operator==(Lista&);
	Lista& operator=(Lista&);
	bool Vacio();
	void Vaciar();
	void Agregar(int x);
	void Insertar(struct eslabon*);
	void Borrar(struct eslabon*);
	struct eslabon* Buscar(int d);
	void Mostrar();
	void Indices(string f);
};