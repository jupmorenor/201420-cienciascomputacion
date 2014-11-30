/*
 * agenciaMatrimonial.h
 *
 *  Created on: 3/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <string>
using std::string;

#ifndef AGENCIAMATRIMONIAL_H_
#define AGENCIAMATRIMONIAL_H_

const string SEXO[] = {"M", "F"};
const string EDAD[] = {"19A24", "25A35", "36A45", "46A60", "60MAS"};
const string NVACADEMICO[] = {"BACHILLER", "TECNICO", "PROFESIONAL", "ESPECIALIZACION", "MAESTRIA", "DOCTORADO"};
const string COMPLEXION[] = {"GRUESA", "NORMAL", "DELGADA"};
const string ESTATURA[] = {"MENOS150", "151A160", "161A170", "171A180", "180MAS"};
const string LISTAS[] = {"SEXO", "EDAD", "NVACADEMICO", "COMPLEXION", "ESTATURA"};
static const string *SUBLISTAS[5] = {SEXO, EDAD, NVACADEMICO, COMPLEXION, ESTATURA};
const int TAMS[] = {2, 5, 6, 3, 5};
const int CANT = 5;

struct Fecha {
	int dd, mm, aa;
};

struct Afiliado {
	string nombre;
	string email;
	string ciudad;
	string ojos;
	string complexion;
	string hobbies[2];
	string nivelAcademico;
	string actividadLaboral;
	Fecha *nacimiento = new Fecha;
	string sexo;
	int estatura;
	int hijos;
	Afiliado *sigPorSexo, *sigPorEdad, *sigPorNivelAcademico, *sigPorComplexion, *sigPorEstatura;
};

template <typename S> struct subNodo {
	string ID;
	S *registro;
	subNodo<S> *siguiente;
};

template <typename R> struct Nodo {
	string ID;
	subNodo<R> *sublista;
	Nodo<R> *siguiente;
};

template <class T> class AgenciaMatrimonial {
	Nodo<T> *cabeza;
	Nodo<T> *crear_nodo(string id);
	subNodo<T> *crear_subnodo(string id);
	Nodo<T> inline *buscar_nodo(string id);
	subNodo<T> inline *buscar_subnodo(string id, Nodo<T> *nodo);
public:
	AgenciaMatrimonial();
	~AgenciaMatrimonial();
	void insertarPorSexo(T *aff);
	void insertarPorEdad(T *aff);
	void insertarPorNivelAcademico(T *aff);
	void insertarPorComplexion(T *aff);
	void insertarPorEstatura(T *aff);
	bool eliminarAfiliado(T *aff);
	int calcularEdad(T *aff);
	T *buscarRegistro(string idLista, string idSublista);
};

#endif /* AGENCIAMATRIMONIAL_H_ */
