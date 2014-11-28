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
	delete agencia;
}

/**
 * Abre el archivo de texto y con la informacion encontrada carga la multilista.
 * Si el archivo no existe, la aplicacion inicia vacia.
 */
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

/**
 * Abre el archivo de texto y guarda la informacion conteida en la multilista.
 * Si el archivo no existe, lo crea.
 */
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

/**
 * Dado un afiliado, lo inserta en cada una de las listas.
 */
template <class T> void Administrador<T>::registrarNuevoUsuario(T *nuevo) {
	agencia->insertarPorSexo(nuevo);
	agencia->insertarPorEdad(nuevo);
	agencia->insertarPorNivelAcademico(nuevo);
	agencia->insertarPorComplexion(nuevo);
	agencia->insertarPorEstatura(nuevo);
}

/**
 * Elimina un afiliado de cada una de las listas buscandolo por el correo.
 */
template <class T> bool Administrador<T>::eliminarUsuarioRegistrado(string id) {
	for (int i=0; i<TAMS[0]; i++) {
		afiliado = agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		while(afiliado!=NULL) {
			if (afiliado->email == id) {
				break;
			}
			afiliado = afiliado->sigPorSexo;
		}
		if (afiliado->email == id) {
			break;
		}
	}
	if (afiliado==NULL) {
		return false;
	} else if (agencia->eliminarAfiliado(afiliado)){
		delete afiliado;
	}
	return true;
}

/**
 * 1.
 */
template <class T> void Administrador<T>::mostrarPorEdadesSegunCiudad(string ciudad) {
}

/**
 * 2. Imprime un listado de quienes tienen un numero de hijos dado
 *    agrupandolos por ciudad
 */
template <class T> void Administrador<T>::mostrarPorHijosyCiudad(int hijos) {
	Lista<T> *resultados = new Lista<T>();
	nodoLista<T> *nodo, *aux;
	string ciudad;
	//Inserta en una lista los registros con la cantidad de hijos dada
	for (int i=0; i<TAMS[0]; i++) {
		afiliado = agencia->buscarRegistro(LISTAS[0], SEXO[i]);
		while (afiliado!=NULL) {
			if (afiliado->hijos == hijos) {
				resultados->insertarRegistro(afiliado);
			}
			afiliado = afiliado->sigPorSexo;
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
	delete lista;
}

/**
 * 3.
 */
template <class T> void Administrador<T>::mostrarPorSexoyEdad(char sexo, int edad) {
}

/**
 * 4. Imprime un listado de los nombres de todos los afiliados de un sexo dado que residen en una ciudad dada.
 */
template <class T> void Administrador<T>::mostrarPorSexoyCiudad(string ciudad, char sexo) {
	afiliado = agencia->buscar_registro(LISTAS[0], sexo);
	while(afiliado!=NULL) {
		if (afiliado->ciudad == ciudad) {
			imprimir(afiliado);
		}
		afiliado = afiliado->sigPorSexo;
	}
}

/**
 * Imprime el nombre de un afiliado dado
 */
template <class T> void Administrador<T>::imprimir(T *aff) {
	std::cout << aff->nombre << std::endl;
}
