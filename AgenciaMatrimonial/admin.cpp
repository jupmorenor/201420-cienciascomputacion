/*
 * admin.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <sstream>
#include "admin.h"

template <class T> Administrador<T>::~Administrador() {
	guardarInformacion();
	delete afiliado;
	delete agencia;
}

template <class T> void Administrador<T>::inicializar() {
	std::stringstream stream;
	string registro;
	string separador = ";";
	size_t pos, sig;
	archivoActivo.open(nombreArchivo);
	while(archivoActivo.good()){
		afiliado = new T;
		archivoActivo >> registro;
		sig = -1;
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->nombre = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->email = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->ciudad = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->ojos = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->complexion = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->hobbies[0] = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->hobbies[1] = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->nivelAcademico = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->actividadLaboral = registro.substr(pos, sig-pos);
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		stream.str(registro.substr(pos, sig-pos));
		stream >> afiliado->nacimiento.dd;
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		stream.str(registro.substr(pos, sig-pos));
		stream >> afiliado->nacimiento.mm;
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		stream.str(registro.substr(pos, sig-pos));
		stream >> afiliado->nacimiento.aa;
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		afiliado->sexo = registro.substr(pos, sig-pos)[0];
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		stream.str(registro.substr(pos, sig-pos));
		stream >> afiliado->estatura;
		pos = sig + 1;
		sig = registro.find_first_of(separador, pos);
		stream.str(registro.substr(pos, sig-pos));
		stream >> afiliado->hijos;

		afiliado->sigPorSexo = afiliado->sigPorEdad = NULL;
		afiliado->sigPorComplexion = afiliado->sigPorEstatura = NULL;
		afiliado->sigPorNivelAcademico = NULL;

		registrarNuevoUsuario(afiliado);
	}
	archivoActivo.close();
}

template <class T> void Administrador<T>::guardarInformacion() {
	std::stringstream stream;
	archivoActivo.open(nombreArchivo);
	string registro = "";

	for (int i=0; i<TAMS[0]; i++) {
		afiliado = agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		do {
			registro.append(afiliado->nombre + ";");
			registro.append(afiliado->email + ";");
			registro.append(afiliado->ciudad + ",;");
			registro.append(afiliado->ojos + ";");
			registro.append(afiliado->complexion + ";");
			registro.append(afiliado->hobbies[0] + ";");
			registro.append(afiliado->hobbies[1] + ";");
			registro.append(afiliado->nivelAcademico + ";");
			registro.append(afiliado->actividadLaboral + ";");
			stream << afiliado->nacimiento.dd << ";";
			stream << afiliado->nacimiento.mm << ";";
			stream << afiliado->nacimiento.aa << ";";
			stream << afiliado->sexo << ";";
			stream << afiliado->estatura << ";";
			stream << afiliado->hijos  << "\n";
			registro.append(stream.str());
			archivoActivo << registro;
			afiliado = afiliado->sigPorSexo;
		}while (afiliado!=NULL);
	}
	archivoActivo.close();
}

template <class T> void Administrador<T>::registrarNuevoUsuario(T *nuevo) {
	agencia->insertarPorSexo(nuevo);
	agencia->insertarPorEdad(nuevo);
	agencia->insertarPorNivelAcademico(nuevo);
	agencia->insertarPorComplexion(nuevo);
	agencia->insertarPorEstatura(nuevo);
}

template <class T> bool Administrador<T>::eliminarUsuarioRegistrado() {
}

template <class T> void Administrador<T>::mostrarPorEdadesSegunCiudad(string ciudad) {
}

template <class T> void Administrador<T>::mostrarPorHijosyCiudad(int hijos) {
}

template <class T> void Administrador<T>::mostrarPorSexoyEdad(char sexo, int edad) {
}

template <class T> void Administrador<T>::mostrarTodosPorCiudad(string ciudad) {
}

template <class T> void Administrador<T>::imprimir();
