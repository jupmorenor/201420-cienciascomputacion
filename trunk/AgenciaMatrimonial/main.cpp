/*
 * main.cpp
 *
 *  Created on: 30/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

# include <iostream>
#
#include "admin.h"
#include "usuarioRegistrado.h"
using std::cin;
using std::cout;
using std::endl;

Administrador<Afiliado> *adm;
UsuarioRegistrado<Afiliado> *usr;
Afiliado *afil;

const string OJOS[] = {"CLAROS", "OSCUROS"};
const string ACTVLAB[] = {"ARTES", "SOCIALES", "INGENIERIA", "SALUD", "COMUNICACION", "DISEÑO", "OTROS"};
const string HOBBIES[] = {"MUSICA", "DEPORTES", "LECTURAS", "VIAJES", "CINE", "MANUALIDADES"};

string mail, ciudad, correo;

string elegirColorOjos() {
	int i;
	do {
		cout << "Elija un color de ojos" << endl;
		for(i=0; i<2; i++) {
			cout << i+1  << ". " << OJOS[i] << endl;
		}
		cin >> i;
	}while(i!=1 && i!=2);
	return OJOS[i-1];
}

string elegirComplexion() {
	int i;
	do {
		cout << "Elija una complexion" << endl;
		for(i=0; i<TAMS[3]; i++) {
			cout << i+1  << ". " << COMPLEXION[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>TAMS[3]);
	return COMPLEXION[i-1];
}

string elegirNvAcademico() {
	int i;
	do {
		cout << "Elija un nivel academico" << endl;
		for(i=0; i<TAMS[2]; i++) {
			cout << i+1  << ". " << NVACADEMICO[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>TAMS[2]);
	return NVACADEMICO[i-1];
}

string elegirSexo() {
	int i;
	do {
		cout << "Elija un genero" << endl;
		for(i=0; i<TAMS[0]; i++) {
			cout << i+1  << ". " << SEXO[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>TAMS[0]);
	return SEXO[i-1];
}

string elegirEdad() {
	int i;
	do {
		cout << "Elija un rango de edad" << endl;
		for(i=0; i<TAMS[1]; i++) {
			cout << i+1  << ". " << EDAD[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>TAMS[1]);
	return EDAD[i-1];
}

string elegirEstatura() {
	int i;
	do {
		cout << "Elija un rango de estatura" << endl;
		for(i=0; i<TAMS[4]; i++) {
			cout << i+1  << ". " << ESTATURA[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>TAMS[4]);
	return ESTATURA[i-1];
}

string elegirActvLaboral() {
	int i;
	do {
		cout << "Elija una actividad laboral" << endl;
		for(i=0; i<7; i++) {
			cout << i+1 << ". " << ACTVLAB[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>7);
	return ACTVLAB[i-1];
}

string elegirHobbie() {
	int i;
	do {
		cout << "Elija un hobbie de la lista" << endl;
		for(i=0; i<6; i++) {
			cout << i+1 << ". " << HOBBIES[i] << endl;
		}
		cin >> i;
	}while(i<=0 && i>6);
	return HOBBIES[i-1];
}

bool elegirOtroHobbie() {
	bool i;
	do {
		cout << "Desea elegir otro hobbie?" << endl;
		cout << "1. Si\n0. No" << endl;
		cin >> i;
	}while(i!=1 && i!=0);
	return i;
}

bool elegirSiHijos() {
	bool i;
	do {
		cout << "Con hijos?" << endl;
		cout << "1. Si\n0. No" << endl;
		cin >> i;
	}while(i!=1 && i!=0);
	return i;
}

Afiliado *crearNuevoAfiliado(){
	Afiliado *aff = new Afiliado;
	aff->nacimiento = new Fecha;
	cout << "Ingrese el nombre sin espacios: ";
	cin >> aff->nombre;
	cout << "Ingrese el correo electronico: ";
	cin >> aff->email;
	cout << "ingrese la ciuda de residencia: ";
	cin >> aff->ciudad;
	aff->ojos = elegirColorOjos();
	aff->complexion = elegirComplexion();
	aff->hobbies[0] = elegirHobbie();
	if(elegirOtroHobbie()) {
		aff->hobbies[1] = elegirHobbie();
	} else {
		aff->hobbies[1] = "";
	}
	aff->nivelAcademico = elegirNvAcademico();
	aff->actividadLaboral = elegirActvLaboral();
	cout << "Ingrese la fecha de nacimiento" << endl;
	cout << "Dia: ";
	cin >> aff->nacimiento->dd;
	cout << "Mes: ";
	cin >> aff->nacimiento->mm;
	cout << "Año: ";
	cin >> aff->nacimiento->aa;
	aff->sexo = elegirSexo();
	cout << "Ingrese la estatura: ";
	cin >> aff->estatura;
	cout << "Ingrese el numero de hijos: ";
	cin >> aff->hijos;
	aff->sigPorSexo = aff->sigPorEdad = aff->sigPorComplexion = aff->sigPorNivelAcademico = aff->sigPorEstatura = NULL;
	return aff;
}

int main() {
	adm = new Administrador<Afiliado>("db.csv");
	int acceso;
	do {
		cout << " ______________________________________________________"<<endl;
		cout<<"  +                 MENU DE MULTILISTA                  +"<<endl;
		cout<<"  +            1. Ingresar como administrador           +"<<endl;
		cout<<"  +            2. Ingresar como un usuario registrado   +"<<endl;
		cout<<"  +            0. Salir                                 +"<<endl;
		cout << " ______________________________________________________"<<endl;
		cout<<"Digite la opcion que desea realizar:";
		cin >> acceso;
		switch (acceso) {
		case 1:
			int opcionAdm;
			do {
				cout<<"             ______________________________________________________"<<endl;
				cout<<"                               MENU DE ADMINISTRADOR                      "<<endl;
				cout<<"				1. Agregar Usuario"<<endl;
				cout<<"				2. Eliminar Usuario"<<endl;
				cout<<"				3. Consultar Edad-Ciudad"<<endl;
				cout<<"				4. Consultar Hijos-Ciudad"<<endl;
				cout<<"				5. Consultar Sexo-Ciudad"<<endl;
				cout<<"				6. Consultar Sexo-Edad"<<endl;
				cout<<"             7. Consulta adicional**************************************"<<endl;
				cout<<"				0. Salir"<<endl;
				cout<<"             ______________________________________________________"<<endl;
				cout<<"Seleccione la opcion la opcion que desea realizar==> ";
				cin >> opcionAdm;
				switch(opcionAdm) {
				case 1:
					adm->registrarNuevoUsuario(crearNuevoAfiliado());
					break;
				case 2:
					cout << "ingrese el correo electronico del usuario a eliminar: ";
					cin >> mail;
					cout << (adm->eliminarUsuarioRegistrado(mail) ? "Usuario eliminado correctamente":"Usuario no encontrado")<< endl;
					break;
				case 3:
					cout << "ingrese la ciudad a consultar: ";
					cin >> ciudad;
					adm->mostrarPorEdadesSegunCiudad(ciudad);
					break;
				case 4:
					int hijos;
					cout << "Ingrese la cantidad de hijos: ";
					cin >> hijos;
					adm->mostrarPorHijosyCiudad(hijos);
					break;
				case 5:
					cout << "ingrese la ciudad a consultar: ";
					cin >> ciudad;
					adm->mostrarPorSexoyCiudad(ciudad, elegirSexo());
					break;
				case 6:
					int edad;
					cout << "Ingrese la edad a consultar: ";
					cin >> edad;
					adm->mostrarPorSexoyEdad(elegirSexo(), edad);
					break;
				case 7:
					adm->mostrarPorComplexionNivelAccPorCiudad(elegirComplexion(), elegirNvAcademico());
					break;
				case 0:
					break;
				default:
					cout << "ingrese una opcion valida" << endl;
					break;
				}
			}while(opcionAdm!=0);
			break;
		case 2:
			cout << "Ingrese nombre de usuario (correo): ";
			cin >> correo;
			for(int i=0; i<TAMS[0]; i++) {
				afil = (Usuario<Afiliado>::agencia)->buscarRegistro(LISTAS[0], SEXO[i]);
				while(afil!=NULL) {
					if(afil->email == correo) {
						break;
					}
					afil = afil->sigPorSexo;
				}
				if (afil!=NULL) {
					if(afil->email == correo) {
						break;
					}
				}
			}
			if (afil!=NULL) {
				usr = new UsuarioRegistrado<Afiliado>(afil->sexo);
			} else {
				cout << "Usuario no encontrado" << endl;
				break;
			}
			int opcionUser;
			do {
				cout<<"             ______________________________________________________"<<endl;
				cout<<"                               MENU DE USUARIO REGISTRADO          "<<endl;
				cout<<"				1. Consultar Actividad Laboral-Nivel Academico"<<endl;
				cout<<"				2. Consultar Hijos-Ciudad"<<endl;
				cout<<"				3. Consultar Complexion-Nivel Academico"<<endl;
				cout<<"				4. Consultar Edad-Hobbies"<<endl;
				cout<<"				5. Consultar Ojos-Estatura"<<endl;
				cout<<"				6. Consultar general (Ojos, estatura, hijos, complexion)"<<endl;
				cout<<"				0. Salir"<<endl;
				cout<<"             ______________________________________________________"<<endl;
				cout<<"Seleccione la opcion la opcion que desea realizar==> ";
				cin >> opcionUser;
				switch(opcionUser) {
				case 1:
					usr->mostrarPorActividadLaborarNivelAcademico(elegirActvLaboral(), elegirNvAcademico());
					break;
				case 2:
					int hijos;
					cout << "Ingrese la cantidad de hijos: ";
					cin >> hijos;
					cout << "ingrese la ciudad a consultar: ";
					cin >> ciudad;
					usr->mostrarPorCiudadNumeroHijos(ciudad, hijos);
					break;
				case 3:
					usr->mostrarPorComplexionyNivelAcademico(elegirComplexion(), elegirNvAcademico());
					break;
				case 4:
					usr->mostrarPorEdadyHobbies(elegirEdad(), elegirHobbie(), elegirHobbie());
					break;
				case 5:
					usr->mostrarPorOjosyRangoEstatura(elegirColorOjos(), elegirEstatura());
					break;
				case 6:
					usr->mostrarCombinado(elegirColorOjos(), elegirEstatura(), elegirSiHijos(), elegirComplexion());
					break;
				case 0:
					break;
				default:
					cout << "ingrese una opcion valida" << endl;
					break;
				}

			}while(opcionUser!=0);
			break;
		case 0:
			break;
		default:
			cout << "ingrese una opcion valida" << endl;
			break;
		}
		//system("PAUSE");
		//system("CLS");
	}while(acceso!=0);
	delete adm;
	return 0;
}


