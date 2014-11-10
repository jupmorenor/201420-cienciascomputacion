/*
 * agenciaMatrimonial.cpp
 *
 *  Created on: 9/11/2014
 *      Author: Juanpa y Yami
 */
#include "agenciaMatrimonial.h"

const std::string LISTAS[] = {"SEXO", "EDAD", "NVACADEMICO", "COMPLEXION", "ESTATURA"};
const std::string SUBLISTAS[][] = {SEXO, EDAD, NVACADEMICO, COMPLEXION, ESTATURA};
const char SEXO[] = {"M", "F"};
const std::string EDAD[] = {"19A24", "25A35", "36A45", "46A60", "60MAS"};
const std::string NVACADEMICO[] = {"BACHILLER", "TECNICO", "PROFESIONAL", "ESPECIALIZACION", "MAESTRIA", "DOCTORADO"};
const std::string COMPLEXION[] = {"GRUESA", "NORMAL", "DELGADA"};
const std::string ESTATURA[] = {"MENOS150", "151A160", "161A170", "171A180", "180MAS"};

template <class T> Nodo<T>* AgenciaMatrimonial<T>::crear_nodo(std::string id) {
	Nodo<T> *nodo = new Nodo<T>;
	nodo->ID = id;
	nodo->sublista = NULL;
	nodo->siguiente = NULL;
	return nodo;
}

template <class T> subNodo<T>* AgenciaMatrimonial<T>::crear_subnodo(std::string id) {
	subNodo<T> *subnodo = new subNodo<T>;
	subnodo->ID = id;
	subnodo->registro = NULL;
	subnodo->siguiente = NULL;
}

template <class T> AgenciaMatrimonial<T>::AgenciaMatrimonial() {
	cabeza = crear_nodo(LISTAS[0]);
	//TODO
}

template <class T> AgenciaMatrimonial<T>::~AgenciaMatrimonial() {
	//TODO
}

template <class T> void AgenciaMatrimonial<T>::insertarPorSexo(T aff) {
	//TODO
}

template <class T> void AgenciaMatrimonial<T>::insertarPorEdad(T aff) {
	//TODO
}

template<class T> void AgenciaMatrimonial<T>::insertarPorNivelAcademico(T aff) {
	//TODO
}

template<class T> void AgenciaMatrimonial<T>::insertarPorComplexion(T aff) {
	//TODO
}

template<class T> void AgenciaMatrimonial<T>::insertarPorEstatura(T aff) {
	//TODO
}
