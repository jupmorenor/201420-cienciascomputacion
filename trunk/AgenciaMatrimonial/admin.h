/*
 * admin.h
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <string>
using std::string;

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
	void mostrarPorEdadesSegunCiudad(string ciudad);
	void mostrarPorHijosyCiudad(int hijos);
	void mostrarPorSexoyEdad(char sexo, int edad);
	void mostrarTodosPorCiudad(string ciudad);
};

#endif /* ADMIN_H_ */
