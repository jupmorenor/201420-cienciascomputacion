/*
 * admin.h
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include "usuario.h"

#ifndef ADMIN_H_
#define ADMIN_H_

template <class T> class Administrador : public Usuario<T>{

public:
	Administrador();
	Administrador(string archivo):Usuario(archivo) {
		inicializar();
	}
	~Administrador();
	void inicializar();
	void guardarInformacion();
	void registrarNuevoUsuario(T *nuevo);
	bool eliminarUsuarioRegistrado();
	void mostrarPorEdadesSegunCiudad(string ciudad);
	void mostrarPorHijosyCiudad(int hijos);
	void mostrarPorSexoyEdad(char sexo, int edad);
	void mostrarTodosPorCiudad(string ciudad);
};

#endif /* ADMIN_H_ */
