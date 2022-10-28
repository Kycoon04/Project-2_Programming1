#include <iostream>
#include "Header.h"
#include <fstream>
#include <sstream>
using namespace std;

//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//Metodos Lista Poblaciones
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
eslabon_Poblados::eslabon_Poblados(string a, string b, string xs, string ys) {
	pro_eslabon = NULL; NombrePoblacion = a; Habitantes = b; x = xs; y = ys;
}
eslabon_Poblados::~eslabon_Poblados() { pro_eslabon = NULL; }
struct eslabon_Poblados* eslabon_Poblados::Pro() { return pro_eslabon; };

Lista_Poblados::Lista_Poblados()
{
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
};
Lista_Poblados::~Lista_Poblados()
{
	Vaciar_Poblados();
}
struct eslabon_Poblados* Lista_Poblados::Pri() { return p_Listas; }

int Lista_Poblados::getn_Poblados() {
	return n;
}

bool Lista_Poblados::Vacio_Poblados()
{
	return (p_Listas == NULL && u_Listas == NULL);
}

void Lista_Poblados::Vaciar_Poblados()
{
	struct eslabon_Poblados* aux1, * aux2;
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

void Lista_Poblados::Cargar_Poblados(Lista_Poblados& h) {
	string fil_nam3 = "poblados2.txt";
	ifstream handle0;
	string line, aux[4];
	string a, b, x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true; 
	while (continuar) {
		getline(handle0, line);
		if (line.find("endsolid exported") == -1) {
			for (int i = 0; i < 4; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q + 1);
				line = line.substr(q + 1, -1);
			}
		}
		else {
			continuar = false;
		}
		a = aux[0], b = aux[1], x = aux[2], y = aux[3];
		struct eslabon_Poblados* aux1 = new struct eslabon_Poblados(a, b, x, y);
		h << aux1;
		n++;
	}
}

void Lista_Poblados::operator<<(struct eslabon_Poblados* q)
{
	if (p_Listas == NULL)
	{
		q->pro_eslabon = q; p_Listas = u_Listas = q;
	}
	else
	{
		q->pro_eslabon = p_Listas;
		u_Listas->pro_eslabon = q;
		u_Listas = q;
	}
}
void Lista_Poblados::Borrar_Poblados(struct eslabon_Poblados* aux1)
{
	if (aux1 == p_Listas && aux1 == u_Listas)
	{
		p_Listas = NULL; u_Listas = NULL;
	}
	else
	{
		if (aux1 == p_Listas)
			p_Listas = aux1->pro_eslabon;
	};
	delete aux1;
}

void Lista_Poblados::Mostrar_Poblados()
{
	struct eslabon_Poblados* aux1;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		cout << "Nombre de Poblacion: " << aux1->NombrePoblacion << " / Numero de Habitantes: " << aux1->Habitantes << " / X: " << aux1->x << " / Y: " << aux1->y << '\n';
		if (aux1 != u_Listas)
			aux1 = aux1->pro_eslabon;
		else
			aux1 = NULL;
	}
}

void Lista_Poblados::Indices_Poblados(Lista_Poblados& h) {
	struct eslabon_Poblados** Lista = new eslabon_Poblados*[n];
	struct eslabon_Poblados* aux1;
	aux1 = h.p_Listas;
	for (int i = 0; i < n; ++i) {
		Lista[i]= aux1;
		aux1 = aux1->pro_eslabon;
	}
	for (int i = 0; i < n; ++i) {
		cout << Lista[i]->NombrePoblacion << endl;
	}
	delete[] Lista;
}
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//Metodos Lista Escuelas
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
eslabon_Escuelas::eslabon_Escuelas(string a, string b, string c, string d, string e, string xs, string ys) {
pro_eslabon = NULL; NombreIntitucion=a;Estudiantes=b;Provincia=c;Canton=d;Distrito=e;x=xs;y=ys;
}
eslabon_Escuelas::~eslabon_Escuelas() { pro_eslabon = NULL; }
struct eslabon_Escuelas* eslabon_Escuelas::Pro() { return pro_eslabon; };

Lista_Escuelas::Lista_Escuelas()
{
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
};
Lista_Escuelas::~Lista_Escuelas()
{
	Vaciar_Escuelas();
}
struct eslabon_Escuelas* Lista_Escuelas::Pri() { return p_Listas; }

int Lista_Escuelas::getn_Escuelas() {
	return n;
}

bool Lista_Escuelas::Vacio_Escuelas()
{
	return (p_Listas == NULL && u_Listas == NULL);
}

void Lista_Escuelas::Vaciar_Escuelas()
{
	struct eslabon_Escuelas* aux1, * aux2;
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

void Lista_Escuelas::Cargar_Escuelas(Lista_Escuelas& h) {
	string fil_nam3 = "escuelas2.txt";
	ifstream handle0;
	string line,aux[7];
	string a,b,c,d,e,x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true;
	while (continuar) {
		getline(handle0, line);
		if (line.find("endsolid exported") == -1) {
			for (int i = 0; i < 7; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q + 1);
				line = line.substr(q + 1, -1);
			}
		}
		else{
			continuar = false;
		}
		a = aux[0], b = aux[1], c = aux[2], d = aux[3], e = aux[4], x = aux[5], y= aux[6];
		struct eslabon_Escuelas* aux1 = new struct eslabon_Escuelas(a, b, c, d, e, x, y);
		h << aux1;
		n++;
	}
}

void Lista_Escuelas::operator<<(struct eslabon_Escuelas* q)
{
	if (p_Listas == NULL)
	{
		q->pro_eslabon = q; p_Listas = u_Listas = q;
	}
	else
	{
		q->pro_eslabon = p_Listas;
		u_Listas->pro_eslabon = q;
		u_Listas = q;
	}
}
void Lista_Escuelas::Borrar_Escuelas(struct eslabon_Escuelas* aux1)
{
	if (aux1 == p_Listas && aux1 == u_Listas)
	{
		p_Listas = NULL; u_Listas = NULL;
	}
	else
	{
		if (aux1 == p_Listas)
			p_Listas = aux1->pro_eslabon;
	};
	delete aux1;
}

void Lista_Escuelas::Mostrar_Escuelas()
{
	struct eslabon_Escuelas* aux1;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		cout <<"Nombre de Institucion: " << aux1->NombreIntitucion << " / Numero de estudiantes: " << aux1->Estudiantes <<" / Provincia: " << aux1->Provincia <<
" / Canton: " << aux1->Canton <<" / Distrito: " << aux1->Distrito << " / X: " << aux1->x <<" / Y: " << aux1->y << '\n';
		if (aux1 != u_Listas)
			aux1 = aux1->pro_eslabon;
		else
			aux1 = NULL;
	}
}

void Lista_Escuelas::Indices_Escuelas(Lista_Escuelas& h) {
	struct eslabon_Escuelas** Lista = new eslabon_Escuelas * [n];
	struct eslabon_Escuelas* aux1;
	aux1 = h.p_Listas;
	for (int i = 0; i < n; ++i) {
		Lista[i] = aux1;
		aux1 = aux1->pro_eslabon;
	}
	for (int i = 0; i < n; ++i) {
		cout << Lista[i]->NombreIntitucion << endl;
	}
	delete[] Lista;
}
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
//Metodos Lista Colegio
//_____________________________________________________________________________________________________________________________________
//_____________________________________________________________________________________________________________________________________
eslabon_Colegio::eslabon_Colegio(string a, string b, string c, string d, string e, string xs, string ys) {
	pro_eslabon = NULL; NombreIntitucion = a; Estudiantes = b; Provincia = c; Canton = d; Distrito = e; x = xs; y = ys;
}
eslabon_Colegio::~eslabon_Colegio() { pro_eslabon = NULL; }
struct eslabon_Colegio* eslabon_Colegio::Pro() { return pro_eslabon; };

Lista_Colegio::Lista_Colegio()
{
	p_Listas = NULL; u_Listas = NULL;
	n = 0;
};
Lista_Colegio::~Lista_Colegio()
{
	Vaciar_Colegio();
}
struct eslabon_Colegio* Lista_Colegio::Pri() { return p_Listas; }

int Lista_Colegio::getn_Colegio() {
	return n;
}

bool Lista_Colegio::Vacio_Colegio()
{
	return (p_Listas == NULL && u_Listas == NULL);
}

void Lista_Colegio::Vaciar_Colegio()
{
	struct eslabon_Colegio* aux1, * aux2;
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

void Lista_Colegio::Cargar_Colegio(Lista_Colegio&h) {
	string fil_nam3 = "colegios2.txt";
	ifstream handle0;
	string line, aux[7];
	string a, b, c, d, e, x, y;
	int m, q;
	handle0.open(fil_nam3, ios::binary);
	bool continuar = true;
	while (continuar) {
		getline(handle0, line);
		if (line.find("endsolid exported") == -1) {
			for (int i = 0; i < 7; i++) {
				m = line.find("");
				q = line.find(";");
				aux[i] = line.substr(m, q + 1);
				line = line.substr(q + 1, -1);
			}
		}
		else {
			continuar = false;
		}
		a = aux[0], b = aux[1], c = aux[2], d = aux[3], e = aux[4], x = aux[5], y = aux[6];
		struct eslabon_Colegio* aux1 = new struct eslabon_Colegio(a, b, c, d, e, x, y);
		h << aux1;
		n++;
	}
}

void Lista_Colegio::operator<<(struct eslabon_Colegio* q)
{
	if (p_Listas == NULL)
	{
		q->pro_eslabon = q; p_Listas = u_Listas = q;
	}
	else
	{
		q->pro_eslabon = p_Listas;
		u_Listas->pro_eslabon = q;
		u_Listas = q;
	}
}
void Lista_Colegio::Borrar_Colegio(struct eslabon_Colegio* aux1)
{
	if (aux1 == p_Listas && aux1 == u_Listas)
	{
		p_Listas = NULL; u_Listas = NULL;
	}
	else
	{
		if (aux1 == p_Listas)
			p_Listas = aux1->pro_eslabon;
	};
	delete aux1;
}

void Lista_Colegio::Mostrar_Colegio()
{
	struct eslabon_Colegio* aux1;
	aux1 = p_Listas;
	while (aux1 != NULL)
	{
		cout << "Nombre de Institucion: " << aux1->NombreIntitucion << " / Numero de estudiantes: " << aux1->Estudiantes << " / Provincia: " << aux1->Provincia <<
			" / Canton: " << aux1->Canton << " / Distrito: " << aux1->Distrito << " / X: " << aux1->x << " / Y: " << aux1->y << '\n';
		if (aux1 != u_Listas)
			aux1 = aux1->pro_eslabon;
		else
			aux1 = NULL;
	}
}

void Lista_Colegio::Indices_Colegio(Lista_Colegio& h) {
	struct eslabon_Colegio** Lista = new eslabon_Colegio * [n];
	struct eslabon_Colegio* aux1;
	aux1 = h.p_Listas;
	for (int i = 0; i < n; ++i) {
		Lista[i] = aux1;
		aux1 = aux1->pro_eslabon;
	}
	for (int i = 0; i < n; ++i) {
		cout << Lista[i]->NombreIntitucion << endl;
	}
	delete[] Lista;
}