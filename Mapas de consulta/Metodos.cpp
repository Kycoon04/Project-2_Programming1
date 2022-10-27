#include <iostream>
#include "Header.h"
#include <fstream>
#include <sstream>
using namespace std;
eslabon::eslabon(int x) { pro_eslabon = NULL; ant_eslabon = NULL; dato = x; }
eslabon::eslabon() { pro_eslabon = NULL; ant_eslabon = NULL; dato = 0; }
eslabon::~eslabon() { pro_eslabon = NULL; ant_eslabon = NULL; }
struct eslabon* eslabon::Pro() { return pro_eslabon; };
struct eslabon* eslabon::Ant() { return ant_eslabon; };
int& eslabon::Dato() { return dato; }

Lista::Lista()
{
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
};
Lista::~Lista()
{
	Vaciar();
}

struct eslabon* Lista::Pri() { return p_Listas; }
struct eslabon* Lista::Ult() { return u_Listas; }

bool Lista::operator==(Lista& h) {
	bool resp = false;
	if (n == h.n) {
		struct eslabon* aux1, * aux2, * aux3;
		aux1 = p_Listas; aux2 = h.p_Listas;
		if (aux1 == NULL && aux2 == NULL) {
			resp = true;
		}
		else {
			while ((!resp) && (aux1 != NULL)) {
				resp = true;
				aux3 = aux1;
				while ((resp && (aux2 != NULL)) && (aux3 != NULL)) {
					if ((aux2->dato) == (aux3->dato)) {
						if (aux2 != h.u_Listas) {
							aux2 = aux2->pro_eslabon;
						}
						else {
							aux2 = NULL;
						}
						if (aux3 != aux3->ant_eslabon) {
							aux3 = aux3->pro_eslabon;
						}
						else {
							aux3 = NULL;
						}
					}
					else {
						resp = false;
					}
				}
				if (aux1 == u_Listas) {
					aux1 = NULL;
				}
				else {
					aux1 = aux1->pro_eslabon;
				}
			}
		}
	}
	return resp;
}

int Lista::getn() {
	return n;
}
Lista& Lista::operator=(Lista& k)
{
	struct eslabon* aux1;
	Vaciar();
	aux1 = k.p_Listas;
	while (aux1 != NULL)
	{
		Agregar(aux1->dato);
		if (aux1 != k.u_Listas) aux1 = aux1->pro_eslabon;  else aux1 = NULL;
	};
	return *this;
}
bool Lista::Vacio()
{
	return (p_Listas == NULL && u_Listas == NULL);
}

void Lista::Vaciar()
{
	struct eslabon* aux1, * aux2;
	aux2 = NULL;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		aux2 = aux1;
		if (aux1 != u_Listas) aux1 = aux1->pro_eslabon; else aux1 = NULL;
		delete aux2;
	};
	p_Listas = NULL; u_Listas = NULL;
}

void Lista::Agregar(int x)
{
	struct eslabon* aux1 = new struct eslabon(x);
	Insertar(aux1);
	n++;
}

void Lista::Insertar(struct eslabon* q)
{if (p_Listas ==NULL)
	{q->pro_eslabon =q; q->ant_eslabon =q; p_Listas =u_Listas =q;}
 else
	{q->pro_eslabon =p_Listas;q->ant_eslabon =u_Listas;
	 u_Listas->pro_eslabon =q;
	 u_Listas =q;
	 p_Listas->ant_eslabon =q;}
}
void Lista::Borrar(struct eslabon* aux1)
{
	if (aux1 == p_Listas && aux1 == u_Listas)
	{
		p_Listas = NULL; u_Listas = NULL;
	}
	else
	{
		if (aux1 == p_Listas)
			p_Listas = aux1->pro_eslabon;
		else
			if (aux1 == u_Listas)
				u_Listas = aux1->ant_eslabon;
		aux1->ant_eslabon->pro_eslabon = aux1->pro_eslabon;
		aux1->pro_eslabon->ant_eslabon = aux1->ant_eslabon;
	};
	delete aux1;
}
struct eslabon* Lista::Buscar(int Dato){
	struct eslabon* aux1, * aux2;
	aux2 = NULL;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		if (aux1->dato == Dato)  //a nivel de punteros
		{
			aux2 = aux1; aux1 = NULL;
		}
		else
			if (aux1 != u_Listas) aux1 = aux1->pro_eslabon; else aux1 = NULL;
	};
	return aux2;
}

void Lista::Mostrar()
{
	struct eslabon* aux1;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		cout << aux1->dato << '\n';
		if (aux1 != u_Listas)
			aux1 = aux1->pro_eslabon;
		else
			aux1 = NULL;
	}
}

void Lista::Indices(string f) {
	int cont = 0;
	ifstream handle0;
	string line;
	handle0.open(f, ios::binary);
	bool continuar = true;
	while (continuar)
	{
		getline(handle0, line);
		if (line.find("endsolid exported") == -1) {
			cont++;
		}
		else {
			continuar = false;
		}
	}
	string* Lista = new string[cont];
	for (int i = 0; i < cont; ++i) {
		Lista[i] = "Hola";
	}
	delete[] Lista;
}