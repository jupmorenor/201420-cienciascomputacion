/*
 * admin.h
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina P�rez P�rez - 20111020069
 */

#include <fstream>
#include <string>
#include "agenciaMatrimonial.h"
using std::string;
using std::fstream;

#ifndef ADMIN_H_
#define ADMIN_H_

class Admin {
	const char *nombreArchivo;
	AgenciaMatrimonial<Afiliado> *agencia;
	Afiliado *afiliado;
	fstream archivoActivo;
public:
	Admin(string archivo);
	~Admin();
	void inicializar();
	void guardarInformacion();
	void registrarNuevoUsuario(Afiliado *nuevo);
	bool eliminarUsuarioRegistrado();
	void mostrarPorEdadesSegunCiudad(string ciudad);
	void mostrarPorHijosyCiudad(int hijos);
	void mostrarPorSexoyEdad(char sexo, int edad);
	void mostrarTodosPorCiudad(string ciudad);
};

#endif /* ADMIN_H_ */
