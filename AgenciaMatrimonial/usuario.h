/*
 * usuario.h
 *
 *  Created on: 14/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <fstream>
#include "agenciaMatrimonial.h"

#ifndef USUARIO_H_
#define USUARIO_H_

template <class T> class Usuario {
protected:
	static AgenciaMatrimonial<T> *agencia;
	char *nombreArchivo;
	T *afiliado;
	std::fstream archivoActivo;
public:
	Usuario();
	Usuario(std::string archivo) {
		nombreArchivo = archivo.c_str();
		agencia = new AgenciaMatrimonial<T>();//TODO: debe inicializarse en el main
		afiliado = NULL;
	}
	virtual ~Usuario();
	virtual void imprimir(T *aff);
};

#endif /* USUARIO_H_ */
