/*
 * usuarioRegistrado.cpp
 *
 *  Created on: 18/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include "usuarioRegistrado.h"
#include "listaResultados.h"

template <class T> void UsuarioRegistrado<T>::mostrarPorOjosyRangoEstatura(string ojos, string estatura) {
	afiliado = agencia->buscarRegistro(LISTAS[4], estatura);
	while(afiliado!=NULL) {
		if(afiliado->sexo != sexoUsuario) {
			if (afiliado->ojos == ojos) {
				imprimir(afiliado);
			}
		}
		afiliado = afiliado->sigPorEstatura;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorEdadyHobbies(string rangoEdad, string hobbie1, string hobbie2) {
	afiliado = agencia->buscarRegistro(LISTAS[1], rangoEdad);
	while(afiliado!=NULL) {
		if(afiliado->sexo != sexoUsuario) {
			if (afiliado->hobbies[0]==hobbie1 || afiliado->hobbies[0]==hobbie2
					|| afiliado->hobbies[1]==hobbie1 || afiliado->hobbies[1]==hobbie2) {
				imprimir(afiliado);
			}
		}
		afiliado = afiliado->sigPorEdad;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorComplexionyNivelAcademico(string complexion, string nvAcademico) {
	afiliado = agencia->buscarRegistro(LISTAS[2], nvAcademico);
	while(afiliado!=NULL) {
		if(afiliado->sexo != sexoUsuario) {
			if (afiliado->complexion == complexion) {
				imprimir(afiliado);
			}
		}
		afiliado = afiliado->sigPorNivelAcademico;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorActividadLaborarNivelAcademico(string aLaboral, string nvAcademico) {
	afiliado = agencia->buscarRegistro(LISTAS[2], nvAcademico);
	while(afiliado!=NULL) {
		if(afiliado->sexo != sexoUsuario) {
			if (afiliado->actividadLaboral == aLaboral) {
				imprimir(afiliado);
			}
		}
		afiliado = afiliado->sigPorNivelAcademico;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarPorCiudadNumeroHijos(string ciudad, int hijos) {
	string sexo;
	sexo = (sexoUsuario == SEXO[0]) ? SEXO[1] : SEXO[0];
	afiliado = agencia->buscarRegistro(LISTAS[0], sexo);
	while(afiliado!=NULL) {
		if (afiliado->hijos == hijos && afiliado->ciudad == ciudad) {
			imprimir(afiliado);
		}
		afiliado = afiliado->sigPorSexo;
	}
}

template <class T> void UsuarioRegistrado<T>::mostrarCombinado(string ojos, string estatura, bool hijos, string complexion) {
	Lista<T> *resultados = new Lista<T>();
	nodoLista<T> *nodo, aux;
	afiliado = agencia->buscarRegistro(LISTAS[4], estatura);
	while(afiliado!=NULL) {
		if(afiliado->sexo != sexoUsuario) {
			if(afiliado->complexion == complexion) {
				resultados->insertarRegistro(afiliado);
			}
		}
		afiliado = afiliado->sigPorEstatura;
	}
	while(!resultados->listaVacia()) {
		nodo = resultados->retornarPrimero();
		while (nodo!=NULL) {
			if ((nodo->registro->hijos && hijos) || (!nodo->registro->hijos && !hijos)) {
				if (nodo->registro->ojos == ojos) {
					imprimir(afiliado);
				}
			}
			nodo = nodo->siguiente;
		}
	}
	delete lista;
}

template <class T> void UsuarioRegistrado<T>::imprimir(T *aff) {
	std::cout << aff->nombre << "    " << aff->email << "    " << aff->ciudad << "    "
			  << aff->nivelAcademico << "    " << aff->actividadLaboral << std::endl;
}
