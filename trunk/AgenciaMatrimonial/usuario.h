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

	string nombreArchivo;
	T *afiliado;
	std::fstream archivoActivo;
public:
	static AgenciaMatrimonial<T> *agencia;
	Usuario() {
		nombreArchivo = "";
		afiliado = NULL;
	}
	Usuario(std::string archivo) {
		nombreArchivo.append(archivo);//new char[archivo.size()+1];
		//std::copy(archivo.begin(), archivo.end(), nombreArchivo);//strcpy(nombreArchivo, archivo.c_str());
		agencia = new AgenciaMatrimonial<T>();
		afiliado = NULL;
	}
	virtual ~Usuario(){};
	virtual void imprimir(T *aff) = 0;
};

#endif /* USUARIO_H_ */
