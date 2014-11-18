/*
 * listaResultados.h
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#ifndef LISTARESULTADOS_H_
#define LISTARESULTADOS_H_

template <typename T> struct nodoLista {
	T *registro;
	nodoLista<T> *siguiente;
};

template <class T> class Lista {
	nodoLista<T> *cabeza;
	int tam;
	nodoLista<T> *crear_nodo(T *reg);
	bool listaVacia();
public:
	Lista();
	~Lista();
	void insertarRegistro(T *reg);
	T *retornatPrimero();
};

#endif /* LISTARESULTADOS_H_ */
