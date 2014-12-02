/*
 * admin.h
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#ifndef ADMIN_H_
#define ADMIN_H_

#include <iostream>
#include "usuario.h"

template <class T> class Administrador : public Usuario<T>{

public:
	Administrador(){};
	Administrador(string archivo):Usuario<T>(archivo) {
		inicializar();
	}
	~Administrador();
	void inicializar();
	void guardarInformacion();
	void registrarNuevoUsuario(T *nuevo);
	bool eliminarUsuarioRegistrado(string id);
	void mostrarPorEdadesSegunCiudad(string ciudad);
	void mostrarPorHijosyCiudad(int hijos);
	void mostrarPorSexoyEdad(string sexo, int edad);
	void mostrarPorSexoyCiudad(string ciudad, string sexo);
	void mostrarPorComplexionNivelAccPorCiudad(string complexion, string nvAcad);
	void imprimir(T *aff);
};

#endif /* ADMIN_H_ */
