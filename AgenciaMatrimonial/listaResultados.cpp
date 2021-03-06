/*
 * listaResultados.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina P�rez P�rez - 20111020069
 */

#include <stddef.h>
#include "listaResultados.h"
#include "agenciaMatrimonial.h"

template <class T> nodoLista<T> *Lista<T>::crear_nodo(T *reg) {
	nodoLista<T> *nodo = new nodoLista<T>;
	nodo->registro = reg;
	nodo->siguiente = NULL;
	return nodo;
}

template <class T> bool Lista<T>::listaVacia() {
	return (tam == 0);
}

template <class T> Lista<T>::Lista() {
	cabeza = NULL;
	tam = 0;
}

template <class T> Lista<T>::~Lista() {
	nodoLista<T> *aux;
	if (!listaVacia()) {
		for (aux=cabeza->siguiente; aux!=NULL; aux=aux->siguiente) {
			delete cabeza;
			cabeza = aux;
		}
		delete aux;
	}
}

template <class T> void Lista<T>::insertarRegistro(T *reg) {
	nodoLista<T> *aux, *nuevo;
	if (listaVacia()) {
		cabeza = crear_nodo(reg);
	} else {
		for (aux=cabeza; aux->siguiente!=NULL; aux=aux->siguiente);
		nuevo = crear_nodo(reg);
		aux->siguiente = nuevo;
	}
	tam++;
}

template <class T> void Lista<T>::eliminarRegistro(T *reg) {
	nodoLista<T> *aux = cabeza, *anterior;
	while (aux->registro != reg) {
		anterior = aux;
		aux = aux->siguiente;
	}
	if (aux == cabeza) {
		cabeza = aux->siguiente;
	} else {
		anterior->siguiente = aux->siguiente;
	}
	tam--;
	delete aux;
}

template <class T> nodoLista<T> *Lista<T>::retornarPrimero() {
	if (!listaVacia()) {
		return cabeza;
	}
	return NULL;
}

template class Lista<Afiliado>;
