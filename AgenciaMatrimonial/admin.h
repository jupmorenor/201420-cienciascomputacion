/*
 * admin.h
 *
 *  Created on: 18/11/2014
 *      Author: -
 */

#include <string.h>

#ifndef ADMIN_H_
#define ADMIN_H_

class Admin {

public:
	Admin();
	~Admin();
	void inicializar();
	void guardarInformacion();
	bool registrarNuevoUsuario();
	bool eliminarUsuarioRegistrado();
	void mostrarPorEdadesSegunCiudad(std::string ciudad);
	void mostrarPorHijosyCiudad(int hijos);
	void mostrarPorSexoyEdad(char sexo, int edad);
	void mostrarTodosPorCiudad(std::string ciudad);
};

#endif /* ADMIN_H_ */
