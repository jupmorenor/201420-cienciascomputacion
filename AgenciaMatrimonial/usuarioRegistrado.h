/*
 * usuarioRegistrado.h
 *
 *  Created on: 26/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <string>
#include "usuario.h"
using std::string;

#ifndef USUARIOREGISTRADO_H_
#define USUARIOREGISTRADO_H_

template <class T> class UsuarioRegistrado : public Usuario<T> {
	string sexoUsuario;
public:
	UsuarioRegistrado(string sexo):Usuario(){
		sexoUsuario = sexo;
	};
	~UsuarioRegistrado();
	void mostrarPorOjosyRangoEstatura(string ojos, string estatura);
	void mostrarPorEdadyHobbies(string rangoEdad, string hobbie1, string hobbie2);
	void mostrarPorComplexionyNivelAcademico(string complexion, string nvAcademico);
	void mostrarPorActividadLaborarNivelAcademico(string aLaboral, string nvAcademico);
	void mostrarPorCiudadNumeroHijos(string ciudad, int hijos);
	void mostrarCombinado(string ojos, string estatura, bool hijos, string complexion);
};

#endif /* USUARIOREGISTRADO_H_ */
