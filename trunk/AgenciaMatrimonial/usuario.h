/*
 * usuario.h
 *
 *  Created on: 14/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina P�rez P�rez - 20111020069
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <fstream>
#include "agenciaMatrimonial.h"

template <class T> class Usuario {
protected:
	static AgenciaMatrimonial<T> *agencia;
	char *nombreArchivo;
	T *afiliado;
	std::fstream archivoActivo;
public:
	Usuario() {
		nombreArchivo = NULL;
		afiliado = NULL;
	}
	Usuario(std::string archivo) {
		nombreArchivo = archivo.c_str();
		agencia = new AgenciaMatrimonial<T>();
		afiliado = NULL;
	}
	virtual ~Usuario(){};
	virtual void imprimir(T *aff) = 0;
};

#endif /* USUARIO_H_ */
