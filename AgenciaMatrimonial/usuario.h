/*
 * usuario.h
 *
 *  Created on: 14/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <string.h>

#ifndef USUARIO_H_
#define USUARIO_H_

class User {

public:
	User();
	~User();
	void mostrarPorOjosyRangoEstatura(std::string ojos, std::string estatura);
	void mostrarPorEdadyHobbies(int edad, std::string hobbie1, std::string hobbie2);
	void mostrarPorComplexionyNivelAcademico(std::string complexion, std::string nvAcademico);
	void mostrarPorActividadLaborarNivelAcademico(std::string aLaboral, std::string nvAcademico);
	void mostrarPorCiudadNumeroHijos(std::string ciudad, int hijos);
	void mostrarCombinado(std::string ojos, std::string estatura, bool hijos, std::string complexion);
};

#endif /* USUARIO_H_ */
