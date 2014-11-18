/*
 * agenciaMatrimonial.h
 *
 *  Created on: 3/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <string.h>

#ifndef AGENCIAMATRIMONIAL_H_
#define AGENCIAMATRIMONIAL_H_

const std::string LISTAS[] = {"SEXO", "EDAD", "NVACADEMICO", "COMPLEXION", "ESTATURA"};
const std::string SUBLISTAS[][] = {SEXO, EDAD, NVACADEMICO, COMPLEXION, ESTATURA};
const char SEXO[] = {"M", "F"};
const std::string EDAD[] = {"19A24", "25A35", "36A45", "46A60", "60MAS"};
const std::string NVACADEMICO[] = {"BACHILLER", "TECNICO", "PROFESIONAL", "ESPECIALIZACION", "MAESTRIA", "DOCTORADO"};
const std::string COMPLEXION[] = {"GRUESA", "NORMAL", "DELGADA"};
const std::string ESTATURA[] = {"MENOS150", "151A160", "161A170", "171A180", "180MAS"};
const int TAMS = {2, 5, 6, 3, 5};
const int CANT = 5;

struct Fecha {
	int dd, mm, aa;
};

struct Afiliado {
	std::string nombre;
	std::string email;
	std::string ciudad;
	std::string ojos;
	std::string complexion;
	std::string hobbies[2];
	std::string nivelAcademico;
	std::string actividadLaboral;
	Fecha nacimiento;
	char sexo;
	int estatura;
	int hijos;
	Afiliado *sigPorSexo, *sigPorEdad, *sigPorNivelAcademico, *sigPorComplexion, *sigPorEstatura;
};

template <typename S> struct subNodo {
	std::string ID;
	S *registro;
	subNodo<S> *siguiente;
};

template <typename R> struct Nodo {
	std::string ID;
	subNodo<R> *sublista;
	Nodo<R> *siguiente;
};

template <class T> class AgenciaMatrimonial {
	Nodo<T> *cabeza;
	Nodo<T> *crear_nodo(std::string id);
	subNodo<T> *crear_subnodo(std::string id);
	Nodo<T> inline *buscar_nodo(std::string id);
	subNodo<T> inline *buscar_subnodo(std::string id, Nodo<T> *nodo);
public:
	AgenciaMatrimonial();
	~AgenciaMatrimonial();
	void insertarPorSexo(T *aff);
	void insertarPorEdad(T *aff);
	void insertarPorNivelAcademico(T *aff);
	void insertarPorComplexion(T *aff);
	void insertarPorEstatura(T *aff);
	int calcularEdad(T *aff);
	T *buscarRegistro(std::string idLista, std::string idSublista);
	//TODO otros metodos adicionales
};

#endif /* AGENCIAMATRIMONIAL_H_ */
