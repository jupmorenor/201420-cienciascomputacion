/*
 * usuarioRegistrado.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <iostream>
#include "usuarioRegistrado.h"
#include "listaResultados.h"

template <class T> void UsuarioRegistrado<T>::mostrarPorOjosyRangoEstatura(string ojos, string estatura) {
	this->afiliado = this->agencia->buscarRegistro(LISTAS[4], estatura);
	while(this->afiliado!=NULL) {
		if(this->afiliado->sexo != sexoUsuario) {
			if (this->afiliado->ojos == ojos) {
				imprimir(this->afiliado);
			}
		}
		this->afiliado = this->afiliado->sigPorEstatura;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorEdadyHobbies(string rangoEdad, string hobbie1, string hobbie2) {
	this->afiliado = this->agencia->buscarRegistro(LISTAS[1], rangoEdad);
	while(this->afiliado!=NULL) {
		if(this->afiliado->sexo != sexoUsuario) {
			if (this->afiliado->hobbies[0]==hobbie1 || this->afiliado->hobbies[0]==hobbie2
					|| this->afiliado->hobbies[1]==hobbie1 || this->afiliado->hobbies[1]==hobbie2) {
				imprimir(this->afiliado);
			}
		}
		this->afiliado = this->afiliado->sigPorEdad;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorComplexionyNivelAcademico(string complexion, string nvAcademico) {
	this->afiliado = this->agencia->buscarRegistro(LISTAS[2], nvAcademico);
	while(this->afiliado!=NULL) {
		if(this->afiliado->sexo != sexoUsuario) {
			if (this->afiliado->complexion == complexion) {
				imprimir(this->afiliado);
			}
		}
		this->afiliado = this->afiliado->sigPorNivelAcademico;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorActividadLaborarNivelAcademico(string aLaboral, string nvAcademico) {
	this->afiliado = this->agencia->buscarRegistro(LISTAS[2], nvAcademico);
	while(this->afiliado!=NULL) {
		if(this->afiliado->sexo != sexoUsuario) {
			if (this->afiliado->actividadLaboral == aLaboral) {
				imprimir(this->afiliado);
			}
		}
		this->afiliado = this->afiliado->sigPorNivelAcademico;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorCiudadNumeroHijos(string ciudad, int hijos) {
	string sexo;
	sexo = (sexoUsuario == SEXO[0]) ? SEXO[1] : SEXO[0];
	this->afiliado = this->agencia->buscarRegistro(LISTAS[0], sexo);
	while(this->afiliado!=NULL) {
		if (this->afiliado->hijos == hijos && this->afiliado->ciudad == ciudad) {
			imprimir(this->afiliado);
		}
		this->afiliado = this->afiliado->sigPorSexo;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarCombinado(string ojos, string estatura, bool hijos, string complexion) {
	Lista<T> *resultados = new Lista<T>();
	nodoLista<T> *nodo, aux;
	this->afiliado = this->agencia->buscarRegistro(LISTAS[4], estatura);
	while(this->afiliado!=NULL) {
		if(this->afiliado->sexo != sexoUsuario) {
			if(this->afiliado->complexion == complexion) {
				resultados->insertarRegistro(this->afiliado);
			}
		}
		this->afiliado = this->afiliado->sigPorEstatura;
	}
	while(!resultados->listaVacia()) {
		nodo = resultados->retornarPrimero();
		while (nodo!=NULL) {
			if ((nodo->registro->hijos && hijos) || (!nodo->registro->hijos && !hijos)) {
				if (nodo->registro->ojos == ojos) {
					imprimir(nodo->registro);
				}
			}
			nodo = nodo->siguiente;
		}
	}
	delete resultados;
}

template <class T> void UsuarioRegistrado<T>::imprimir(T *aff) {
	std::cout << aff->nombre << "    " << aff->email << "    " << aff->ciudad << "    "
			  << aff->nivelAcademico << "    " << aff->actividadLaboral << std::endl;
}

template class UsuarioRegistrado<Afiliado>;

