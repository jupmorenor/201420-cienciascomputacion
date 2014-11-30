/*
 * admin.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */


#include <sstream>
#include "admin.h"
#include "listaResultados.h"

template <class T> Administrador<T>::~Administrador() {
	guardarInformacion();
	delete this->agencia;
}

/**
 * Abre el archivo de texto y con la informacion encontrada carga la multilista.
 * Si el archivo no existe, la aplicacion inicia vacia.
 */
template <class T> void Administrador<T>::inicializar() {
	std::stringstream stream;
	string registro = "";
	string separador = ";";
	size_t pos, sig;
	this->archivoActivo.open(this->nombreArchivo, std::ios_base::in);
	while(this->archivoActivo.good()){
		this->afiliado = new T;
		this->afiliado->nacimiento = new Fecha;
		this->archivoActivo >> registro;
		if(!registro.empty()) {
			sig = -1;
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->nombre = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->email = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->ciudad = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->ojos = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->complexion = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->hobbies[0] = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->hobbies[1] = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->nivelAcademico = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->actividadLaboral = registro.substr(pos, sig-pos);
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			stream.str(registro.substr(pos, sig-pos));
			stream >> this->afiliado->nacimiento->dd;
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			stream.str(registro.substr(pos, sig-pos));
			stream >> this->afiliado->nacimiento->mm;
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			stream.str(registro.substr(pos, sig-pos));
			stream >> this->afiliado->nacimiento->aa;
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			this->afiliado->sexo = registro.substr(pos, sig-pos)[0];
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			stream.str(registro.substr(pos, sig-pos));
			stream >> this->afiliado->estatura;
			pos = sig + 1;
			sig = registro.find_first_of(separador, pos);
			stream.str(registro.substr(pos, sig-pos));
			stream >> this->afiliado->hijos;

			this->afiliado->sigPorSexo = this->afiliado->sigPorEdad = NULL;
			this->afiliado->sigPorComplexion = this->afiliado->sigPorEstatura = NULL;
			this->afiliado->sigPorNivelAcademico = NULL;

			registrarNuevoUsuario(this->afiliado);
			registro = "";
			stream.str(registro);
		}
	}
	this->archivoActivo.close();
}

/**
 * Abre el archivo de texto y guarda la informacion conteida en la multilista.
 * Si el archivo no existe, lo crea.
 */
template <class T> void Administrador<T>::guardarInformacion() {
	std::stringstream stream;
	this->archivoActivo.open(this->nombreArchivo, std::ios_base::out);
	string registro;

	for (int i=0; i<TAMS[0]; i++) {
		this->afiliado = this->agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		while (this->afiliado!=NULL) {
			registro = "";
			registro.append(this->afiliado->nombre + ";");
			registro.append(this->afiliado->email + ";");
			registro.append(this->afiliado->ciudad + ";");
			registro.append(this->afiliado->ojos + ";");
			registro.append(this->afiliado->complexion + ";");
			registro.append(this->afiliado->hobbies[0] + ";");
			registro.append(this->afiliado->hobbies[1] + ";");
			registro.append(this->afiliado->nivelAcademico + ";");
			registro.append(this->afiliado->actividadLaboral + ";");
			stream << this->afiliado->nacimiento->dd << ";";
			stream << this->afiliado->nacimiento->mm << ";";
			stream << this->afiliado->nacimiento->aa << ";";
			stream << this->afiliado->sexo << ";";
			stream << this->afiliado->estatura << ";";
			stream << this->afiliado->hijos  << "\n";
			registro.append(stream.str());
			this->archivoActivo << registro;
			this->afiliado = this->afiliado->sigPorSexo;
			stream.str("");
		}
	}
	this->archivoActivo.close();
}

/**
 * Dado un afiliado, lo inserta en cada una de las listas.
 */
template <class T> void Administrador<T>::registrarNuevoUsuario(T *nuevo) {
	this->agencia->insertarPorSexo(nuevo);
	this->agencia->insertarPorEdad(nuevo);
	this->agencia->insertarPorNivelAcademico(nuevo);
	this->agencia->insertarPorComplexion(nuevo);
	this->agencia->insertarPorEstatura(nuevo);
}

/**
 * Elimina un afiliado de cada una de las listas buscandolo por el correo.
 */
template <class T> bool Administrador<T>::eliminarUsuarioRegistrado(string id) {
	for (int i=0; i<TAMS[0]; i++) {
		this->afiliado = this->agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		while(this->afiliado!=NULL) {
			if (this->afiliado->email == id) {
				break;
			}
			this->afiliado = this->afiliado->sigPorSexo;
		}
		if (this->afiliado->email == id) {
			break;
		}
	}
	if (this->afiliado==NULL) {
		return false;
	} else if (this->agencia->eliminarAfiliado(this->afiliado)){
		delete this->afiliado;
	}
	return true;
}

/**
 * 1. Numero total de personas que viven en una ciudad dada clasificandolos por rango de edad
 */
template <class T> void Administrador<T>::mostrarPorEdadesSegunCiudad(string ciudad) {
	int i, cantidad;
	for (i=0; i<TAMS[1]; i++) {
		std::cout << std::endl;
		cantidad = 0;
		this->afiliado = this->agencia->buscarRegistro(LISTAS[1], EDAD[i]);
		while (this->afiliado!=NULL) {
			if (this->afiliado->ciudad == ciudad) {
				cantidad++;
				imprimir(this->afiliado);
			}
			this->afiliado = this->afiliado->sigPorEdad;
		}
		std::cout << cantidad << " personas que viven en "
				<< ciudad << " en el rango " << EDAD[i] << std::endl;
	}
}

/**
 * 2. Llistado de los nombres de aquellos que tienen un numero de hijos dado
 *    agrupandolos por ciudad
 */
template <class T> void Administrador<T>::mostrarPorHijosyCiudad(int hijos) {
	Lista<T> *resultados = new Lista<T>();
	nodoLista<T> *nodo, *aux;
	string ciudad;
	//Inserta en una lista los registros con la cantidad de hijos dada
	for (int i=0; i<TAMS[0]; i++) {
		this->afiliado = this->agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		while (this->afiliado!=NULL) {
			if (this->afiliado->hijos == hijos) {
				resultados->insertarRegistro(this->afiliado);
			}
			this->afiliado = this->afiliado->sigPorSexo;
		}
	}
	//Imprime de la lista de resultados segun la ciudad
	while (!resultados->listaVacia()) {
		nodo = resultados->retornarPrimero();
		ciudad = nodo->registro->ciudad;
		std::cout << ciudad << std::endl;
		while(nodo!=NULL) {
			if (nodo->registro->ciudad == ciudad) {
				imprimir(nodo->registro);
				aux = nodo;
				nodo = nodo->siguiente;
				resultados->eliminarRegistro(aux->registro);
			} else {
				nodo = nodo->siguiente;
			}
		}
	}
	delete resultados;
}

/**
 * 3. Nombre de las personas que pertenecen al sexo dado y tienen edad mayor o igual
 *    a la edad dada
 */
template <class T> void Administrador<T>::mostrarPorSexoyEdad(string sexo, int edad) {
	int i;
	if (edad>=19 && edad<=24) {
		i=0;
	} else if (edad >= 25 && edad <= 35){
		i=1;
	} else if (edad >= 36 && edad <= 45){
		i=2;
	} else if (edad >= 46 && edad <= 60) {
		i=3;
	} else if (edad > 60) {
		i=4;
	}
	for(; i<TAMS[1]; i++) {
		this->afiliado = this->agencia->buscarRegistro(LISTAS[1], EDAD[i]);
		while (this->afiliado!=NULL) {
			if (this->afiliado->sexo == sexo) {
				if (this->agencia->calcularEdad(this->afiliado)>=edad) {
					imprimir(this->afiliado);
				}
			}
			this->afiliado = this->afiliado->sigPorEdad;
		}
	}
}

/**
 * 4. Imprime un listado de los nombres de todos los afiliados de un sexo dado
 *    (hombres o mujeres) que residen en una ciudad dada.
 */
template <class T> void Administrador<T>::mostrarPorSexoyCiudad(string ciudad, string sexo) {
	this->afiliado = this->agencia->buscarRegistro(LISTAS[0], sexo);
	while(this->afiliado!=NULL) {
		if (this->afiliado->ciudad == ciudad) {
			imprimir(this->afiliado);
		}
		this->afiliado = this->afiliado->sigPorSexo;
	}
}

/**
 * Imprime el nombre de un afiliado dado
 */
template <class T> void Administrador<T>::imprimir(T *aff) {
	std::cout << aff->nombre << std::endl;
}


template class Administrador<Afiliado>;
