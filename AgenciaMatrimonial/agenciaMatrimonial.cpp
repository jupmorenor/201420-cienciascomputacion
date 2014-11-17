/**
 * agenciaMatrimonial.cpp
 *
 *  Created on: 9/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include "agenciaMatrimonial.h"

const std::string LISTAS[] = {"SEXO", "EDAD", "NVACADEMICO", "COMPLEXION", "ESTATURA"};
const std::string SUBLISTAS[][] = {SEXO, EDAD, NVACADEMICO, COMPLEXION, ESTATURA};
const char SEXO[] = {"M", "F"};
const std::string EDAD[] = {"19A24", "25A35", "36A45", "46A60", "60MAS"};
const std::string NVACADEMICO[] = {"BACHILLER", "TECNICO", "PROFESIONAL", "ESPECIALIZACION", "MAESTRIA", "DOCTORADO"};
const std::string COMPLEXION[] = {"GRUESA", "NORMAL", "DELGADA"};
const std::string ESTATURA[] = {"MENOS150", "151A160", "161A170", "171A180", "180MAS"};
const int TAMS = {2, 5, 6, 3, 5};
const int CANT = 5;

/**
 * Crea un nodo cabeza de lista
 */
template <class T> Nodo<T>* AgenciaMatrimonial<T>::crear_nodo(std::string id) {
	Nodo<T> *nodo = new Nodo<T>;
	nodo->ID = id;
	nodo->sublista = NULL;
	nodo->siguiente = NULL;
	return nodo;
}

/**
 * crea un subnodo cabeza de sublista
 */
template <class T> subNodo<T>* AgenciaMatrimonial<T>::crear_subnodo(std::string id) {
	subNodo<T> *subnodo = new subNodo<T>;
	subnodo->ID = id;
	subnodo->registro = NULL;
	subnodo->siguiente = NULL;
}

/**
 * Busca el nodo con la cabeza de la lista de subnodos correspondiente al id dado
 */
template <class T> Nodo<T> inline *AgenciaMatrimonial<T>::buscar_nodo(std::string id) {
	Nodo<T> *aux = cabeza;
	while (aux->ID != id) {
		aux = aux->siguiente;
	}
	return aux;
}

/**
 * Busca el subnodo cabeza de la lista correspondiente al id dado
 */
template <class T> subNodo<T> inline *AgenciaMatrimonial<T>::buscar_subnodo(std::string id, Nodo<T> *nodo) {
	subNodo<T> *aux = nodo->sublista;
	while (aux->ID != id) {
		aux = aux->siguiente;
	}
	return aux;
}

/**
 * Crea la estructura de la multilista
 */
template <class T> AgenciaMatrimonial<T>::AgenciaMatrimonial() {
	cabeza = crear_nodo(LISTAS[0]);
	Nodo<T> *aux1 = cabeza;
	subNodo<T> *aux2;
	for (int i=1; i<CANT; i++) {

		aux1->sublista = crear_subnodo(SUBLISTAS[i-1][0]);
		aux2 = aux1->sublista;
		for (int j=1; j<TAMS[i]; j++) {
			aux2->siguiente = crear_subnodo(SUBLISTAS[i-1][j]);
			aux2 = aux2->siguiente;
		}
		aux1->siguiente = crear_nodo(LISTAS[i]);
		aux1 = aux1->siguiente;
	}
}

template <class T> AgenciaMatrimonial<T>::~AgenciaMatrimonial() {
	//TODO
}

/**
 * Inserta un afiliado en la lista por sexo en la ultima posicion
 */
template <class T> void AgenciaMatrimonial<T>::insertarPorSexo(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[0]);
	subNodo<T> *sublista = buscar_subnodo(aff->sexo, lista);
	T *registro;
	if (sublista->registro == NULL) {
		sublista->registro = aff;
	} else {
		registro = sublista->registro;
		while (registro->sigPorSexo != NULL) {
			registro = registro->sigPorSexo;
		}
		registro->sigPorSexo = aff;
	}
}

template <class T> void AgenciaMatrimonial<T>::insertarPorEdad(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[1]);
	subNodo<T> *sublista;
	T *registro;
	//cuando se calcula la edad?
	//TODO
}

/**
 * Inserta un afiliado en la lista por nivel academico en la ultima posicion
 */
template<class T> void AgenciaMatrimonial<T>::insertarPorNivelAcademico(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[2]);
	subNodo<T> *sublista = buscar_subnodo(aff->nivelAcademico, lista);
	T *registro;
	if (sublista->registro == NULL) {
		sublista->registro = aff;
	} else {
		registro = sublista->registro;
		while (registro->sigPorNivelAcademico != NULL) {
			registro = registro->sigPorNivelAcademico;
		}
		registro->sigPorNivelAcademico = aff;
	}
}

/**
 * Inserta un afiliado en la lista por complexion en la ultima posicion
 */
template<class T> void AgenciaMatrimonial<T>::insertarPorComplexion(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[3]);
	subNodo<T> *sublista = buscar_subnodo(aff->complexion, lista);
	T *registro;
	if (sublista->registro == NULL) {
		sublista->registro = aff;
	} else {
		registro = sublista->registro;
		while (registro->sigPorComplexion != NULL) {
			registro = registro->sigPorComplexion;
		}
		registro->sigPorComplexion = aff;
	}
}

/**
 * Inserta un afiliado por orden descendente de estatura de forma ordenada
 * en la lista que le corresponde
 */
template<class T> void AgenciaMatrimonial<T>::insertarPorEstatura(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[1]);
	subNodo<T> *sublista;
	T *registro;
	int e = 150;
	for (int i = 0; i<TAMS[4]; i++, e+=10) {
		if (aff->estatura <= e || e > 180) {
			sublista = buscar_subnodo(ESTATURA[i], lista);
		}
	}
	if (sublista->registro == NULL) {
		sublista->registro = aff;
	} else {
		registro = sublista->registro;
		if (aff->estatura > registro->estatura) {
			aff->sigPorEstatura = registro;
			sublista->registro = aff;
		} else {
			while ((aff->estatura < registro->estatura) && (registro->sigPorEstatura!=NULL)) {
				if (aff->estatura > registro->sigPorEstatura->estatura) {
					break;
				}
				registro = registro->sigPorEstatura;
			}
			if (registro->sigPorEstatura != NULL) {
				aff->sigPorEstatura = registro->sigPorEstatura;
				registro->sigPorEstatura = aff;
			} else {
				registro->sigPorEstatura = aff;
			}
		}
	}
}

template <class T> int AgenciaMatrimonial<T>::calcularEdad(T *aff) {

	//TODO aqui???
}
