/*
 * usuario.h
 *
 *  Created on: 14/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <string>
using std::string;

#ifndef USUARIO_H_
#define USUARIO_H_

class User {

public:
	User();
	~User();
	void mostrarPorOjosyRangoEstatura(string ojos, string estatura);
	void mostrarPorEdadyHobbies(int edad, string hobbie1, string hobbie2);
	void mostrarPorComplexionyNivelAcademico(string complexion, string nvAcademico);
	void mostrarPorActividadLaborarNivelAcademico(string aLaboral, string nvAcademico);
	void mostrarPorCiudadNumeroHijos(string ciudad, int hijos);
	void mostrarCombinado(string ojos, string estatura, bool hijos, string complexion);
};

#endif /* USUARIO_H_ */
