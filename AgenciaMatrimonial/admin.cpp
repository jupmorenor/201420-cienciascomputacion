/*
 * admin.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <sstream>
#include "admin.h"

Admin::Admin(string archivo) {
	nombreArchivo = archivo.c_str();
	agencia = new AgenciaMatrimonial<Afiliado>();
	inicializar();
}

Admin::~Admin() {
	guardarInformacion();
	delete afiliado;
	delete agencia;
}

void Admin::inicializar() {
	std::stringstream stream;
	string registro;
	string separador = ",";
	size_t pos, sig;
	archivoActivo.open(nombreArchivo);
	while(archivoActivo.good()){
		afiliado = new Afiliado;
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

void Admin::guardarInformacion() {
	std::stringstream stream;
	archivoActivo.open(nombreArchivo);
	string registro = "";

	for (int i=0; i<TAMS[0]; i++) {
		afiliado = agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		do {
			registro.append(afiliado->nombre + ",");
			registro.append(afiliado->email + ",");
			registro.append(afiliado->ciudad + ",");
			registro.append(afiliado->ojos + ",");
			registro.append(afiliado->complexion + ",");
			registro.append(afiliado->hobbies[0] + ",");
			registro.append(afiliado->hobbies[1] + ",");
			registro.append(afiliado->nivelAcademico + ",");
			registro.append(afiliado->actividadLaboral + ",");
			stream << afiliado->nacimiento.dd << ",";
			stream << afiliado->nacimiento.mm << ",";
			stream << afiliado->nacimiento.aa << ",";
			stream << afiliado->sexo << ",";
			stream << afiliado->estatura << ",";
			stream << afiliado->hijos;
			registro.append(stream.str());
			archivoActivo << registro;
			afiliado = afiliado->sigPorSexo;
		}while (afiliado!=NULL);
	}
	archivoActivo.close();
}

void Admin::registrarNuevoUsuario(Afiliado *nuevo) {
	agencia->insertarPorSexo(nuevo);
	agencia->insertarPorEdad(nuevo);
	agencia->insertarPorNivelAcademico(nuevo);
	agencia->insertarPorComplexion(nuevo);
	agencia->insertarPorEstatura(nuevo);
}

bool Admin::eliminarUsuarioRegistrado() {
}

void Admin::mostrarPorEdadesSegunCiudad(string ciudad) {
}

void Admin::mostrarPorHijosyCiudad(int hijos) {
}

void Admin::mostrarPorSexoyEdad(char sexo, int edad) {
}

void Admin::mostrarTodosPorCiudad(string ciudad) {
}
