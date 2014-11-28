/**
 * agenciaMatrimonial.cpp
 *
 *  Created on: 9/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <time.h>
#include "agenciaMatrimonial.h"

/**
 * Crea un nodo cabeza de lista
 */
template <class T> Nodo<T>* AgenciaMatrimonial<T>::crear_nodo(string id) {
	Nodo<T> *nodo = new Nodo<T>;
	nodo->ID = id;
	nodo->sublista = NULL;
	nodo->siguiente = NULL;
	return nodo;
}

/**
 * crea un subnodo cabeza de sublista
 */
template <class T> subNodo<T>* AgenciaMatrimonial<T>::crear_subnodo(string id) {
	subNodo<T> *subnodo = new subNodo<T>;
	subnodo->ID = id;
	subnodo->registro = NULL;
	subnodo->siguiente = NULL;
}

/**
 * Busca el nodo con la cabeza de la lista de subnodos correspondiente al id dado
 */
template <class T> Nodo<T> inline *AgenciaMatrimonial<T>::buscar_nodo(string id) {
	Nodo<T> *aux = cabeza;
	while (aux->ID != id) {
		aux = aux->siguiente;
	}
	return aux;
}

/**
 * Busca el subnodo cabeza de la lista correspondiente al id dado
 */
template <class T> subNodo<T> inline *AgenciaMatrimonial<T>::buscar_subnodo(string id, Nodo<T> *nodo) {
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

/**
 * Libera la memoria ocupada por la multilista
 */
template <class T> AgenciaMatrimonial<T>::~AgenciaMatrimonial() {
	Nodo<T> *lista;
	subNodo<T> *sublista;
	T *registro;
	for (lista=cabeza->siguiente; lista!=NULL; lista=lista->siguiente) {
		for (sublista=lista->sublista->siguiente; sublista!=NULL; sublista=sublista->siguiente) {
			for(registro=sublista->registro->siguiente; registro!=NULL; registro=registro->siguiente) {
				delete sublista;
				sublista = registro;
			}
			delete registro;
			delete lista;
			lista = sublista;
		}
		delete sublista;
		delete cabeza;
		cabeza = lista;
	}
	delete lista;
	delete cabeza;
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

/**
 * Inserta un afiliado por orden ascendente (menor a mayor) de edad
 * de forma ordenada en la lista que le corresponde
 */
template <class T> void AgenciaMatrimonial<T>::insertarPorEdad(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[1]);
	subNodo<T> *sublista;
	T *registro;
	int edad, edadAux, e;
	edad = calcularEdad(aff);
	e = 25;
	if (edad >= 19 && edad <= 24) {
		sublista = buscar_subnodo(EDAD[0], lista);
	} else if (edad >= 25 && edad <= 35) {
		sublista = buscar_subnodo(EDAD[1], lista);
	} else if (edad >= 36 && edad <= 45){
		sublista = buscar_subnodo(EDAD[2], lista);
	} else if (edad >= 46 && edad <= 60) {
		sublista = buscar_subnodo(EDAD[3], lista);
	} else if (edad > 60) {
		sublista = buscar_subnodo(EDAD[4], lista);
	}

	if (sublista->registro == NULL) {
		sublista->registro = aff;
	} else {
		registro = sublista->registro;
		edadAux = calcularEdad(registro);
		if (edad < edadAux) {
			aff->sigPorEdad = registro;
			sublista->registro = aff;
		} else {
			while ((edad > edadAux) && (registro->sigPorEdad != NULL)) {
				edadAux = calcularEdad(registro->sigPorEdad);
				if (edad < edadAux) {
					break;
				}
				registro = registro->sigPorEdad;
			}
			if (registro->sigPorEdad != NULL) {
				aff->sigPorEdad = registro->sigPorEdad;
				registro->sigPorEdad = aff;
			} else {
				registro->sigPorEdad = aff;
			}
		}
	}
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
 * Inserta un afiliado por orden descendente (mayor a menor) de estatura
 * de forma ordenada en la lista que le corresponde
 */
template<class T> void AgenciaMatrimonial<T>::insertarPorEstatura(T *aff) {
	Nodo<T> *lista = buscar_nodo(LISTAS[4]);
	subNodo<T> *sublista;
	T *registro;
	int e = 150;
	for (int i = 0; i<TAMS[4]; i++, e+=10) {
		if (aff->estatura <= e || e > 180) {
			sublista = buscar_subnodo(ESTATURA[i], lista);
			break;
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

/*
 * Calcula la edad a partir de la fecha de nacimiento y la fecha actual
 */
template <class T> int AgenciaMatrimonial<T>::calcularEdad(T *aff) {
	int edad;

	/* calculo de la fecha actual */
	struct tm fechaActual;
	time_t fechaSistema;
	time(&fechaSistema);
	fechaActual = localtime(&fechaSistema);

	/* calculo de la edad */
	if (fechaActual.tm_mon+1 > aff->nacimiento->mm) {
		edad = fechaActual.tm_year+1900 - aff->nacimiento->aa;
	} else if (fechaActual.tm_mon+1 < aff->nacimiento->mm) {
		edad = fechaActual.tm_year+1900 - aff->nacimiento->aa - 1;
	} else {
		if (fechaActual.tm_mday >= aff->nacimiento->dd) {
			edad = fechaActual.tm_year+1900 - aff->nacimiento->aa;
		} else {
			edad = fechaActual.tm_year+1900 - aff->nacimiento->aa - 1;
		}
	}
	return edad;
}

/**
 * Elimina a un afiliado de todas las listas
 */
template <class T> bool AgenciaMatrimonial<T>::eliminarAfiliado(T *aff) {
	T *anterior;
	bool encontrado = false;
	int i, j;
	for (i=0; i<CANT; i++) {
		for (j=0; j<TAMS[i]; j++) {
			anterior = buscarRegistro(LISTAS[i], SUBLISTAS[i][j]);
			encontrado = false;
			while (anterior != NULL) {
				switch (i) {
				case 0:
					if (anterior->sigPorSexo == aff) {
						anterior->sigPorSexo = aff->sigPorSexo;
						encontrado = true;
					} else {
						anterior = anterior->sigPorSexo;
					}
					break;
				case 1:
					if (anterior->sigPorEdad == aff) {
						anterior->sigPorEdad = aff->sigPorEdad;
						encontrado = true;
					} else {
						anterior = anterior->sigPorEdad;
					}
					break;
				case 2:
					if (anterior->sigPorNivelAcademico == aff) {
						anterior->sigPorNivelAcademico = aff->sigPorNivelAcademico;
						encontrado = true;
					} else {
						anterior = anterior->sigPorNivelAcademico;
					}
					break;
				case 3:
					if (anterior->sigPorComplexion == aff) {
						anterior->sigPorComplexion = aff->sigPorComplexion;
						encontrado = true;
					} else {
						anterior = anterior->sigPorComplexion;
					}
					break;
				case 4:
					if (anterior->sigPorEstatura == aff) {
						anterior->sigPorEstatura = aff->sigPorEstatura;
						encontrado = true;
					} else {
						anterior = anterior->sigPorEstatura;
					}
					break;
				}
				if (encontrado) {
					break;
				}
			}
			if (encontrado) {
				break;
			}
		}
	}
	if(!encontrado) {
		return false;
	}
	return true;
}

/**
 * Retorna la cabeza de una sublista dado su id
 */
template <class T> T inline *AgenciaMatrimonial<T>::buscarRegistro(string idLista, string idSublista) {
	Nodo<T> lista;
	subNodo<T> sublista;
	T *registro;
	lista = buscar_nodo(idLista);
	sublista = buscar_subnodo(idSublista, lista);
	registro = sublista->registro;
	return registro;
}
