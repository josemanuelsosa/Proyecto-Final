#include<iostream>
#include<string>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<locale.h>


using namespace std;
int menu, salida, e, f, stratamiento, editar, edipre; // f es eliminar
int i = 0, n;
int esp = 0, l = 0, x, num = 0, arroba = 0, rn = 0, espd = 0;


// Estructuras
struct clientes {
	string tratamientost;
	char nombre[100], correo[60], tratamiento[100], descripcion[500];
	int presiounitario, hora, fecha, ocosto, subtotal, total, iva;
}datos[10];

int main() {

	// Menu
	cout << "Bienvenido a las citas odontologicas" << endl << endl;
	cout << "1.- Agendar cita" << endl;
	cout << "2.- Modificar cita" << endl;
	cout << "3.- Eliminar cita" << endl;
	cout << "4.- Lista de citas programadas" << endl;
	cout << "5.- Limpiar pantalla" << endl;
	cout << "6.- Salir" << endl << endl;
	cin >> menu;

	// Primer switch (Para el menu)
	switch (menu) {
	case 1:
		system("cls");

		i = i + 1;
		cout << "Favor de llenar los siguientes datos" << endl << endl;
		// ==== Preguntar Nombre ====
		while (rn == 0) {

			cin.ignore(); // = 
			cout << "Nombre Completo: " << endl;
			cin.getline(datos[i].nombre, 100, '\n');
			cout << endl;


			// Validacion del Nombre (Que no contenga numeros)
			l = strlen(datos[i].nombre);
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '0') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '1') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '2') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '3') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '4') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '5') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '6') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '7') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '8') {
					num++;
				}
			}
			for (x = 0; x <= l; x++) {
				if (datos[i].nombre[x] == '9') {
					num++;
				}
			}

			if (num != 0) {
				cout << "== No se pueden colocar numeros en el nombre ==" << endl;
				system("pause");
				system("cls");

			}
			if (rn == num) {
				rn = 1;
			}
			num = 0;
		}
		system("cls");
		rn = 0;

		// Fecha del tratamiento
		cout << "Inserte la fecha para el tratamiento\n" << endl;
		cout << "Ejemplo: 260522 (Dia/Mes/Año)" << endl;
		cin >> datos[i].fecha;
		cout << endl;
		system("cls");

		// ==== Hora del tratamiento ====
		cout << "Escriba el hora (Horario 24hrs): " << endl;
		cin >> datos[i].hora;


		// Validar que no pase de 24 hrs
		do {
			if (datos[i].hora > 24) {
				cout << "La hora escrita no es valida, favor de señalar horario en formato de 24hrs" << endl;
				cin >> datos[i].hora;
				rn = 1;
			}
			else {
				rn = 0;
			}

		} while (rn == 1);

		system("cls");

		cin.ignore();
		// ==== Tratamiento ====
		cout << "Eliga el tipo de tratamiento" << endl;
		cout << "1.- Brackets" << endl;
		cout << "2.- Limpieza dental" << endl;
		cout << "3.- Extraccion de algun diente o muela" << endl;
		cout << "4.- Caries" << endl;
		cin >> stratamiento;
		system("cls");

		//Aqui empieza otro switch para el tratamiento

		switch (stratamiento)
		{
		case 1:
			datos[i].presiounitario = 5000;
			datos[i].tratamientost = "Brackets";
			break;
		case 2:
			datos[i].presiounitario = 500;
			datos[i].tratamientost = "Limpieza dental";
			break;
		case 3:
			datos[i].presiounitario = 1500;
			datos[i].tratamientost = "Extraccion de algun diente o muela";
			break;
		case 4:
			datos[i].presiounitario = 3500;
			datos[i].tratamientost = "Caries";
		default:
			cout << "Dato no valido" << endl;
		}
		system("cls");
		// ==== Descripcion ====
		cout << "Alguna descripcion: " << endl;
		cin.ignore();
		cin.getline(datos[i].descripcion, 500, '\n');
		l = strlen(datos[i].descripcion);
		if (l < 10) {
			datos[i].ocosto = 50;
		}
		if (l >= 10) {
			if (l <= 50) {
				datos[i].ocosto = 100;
			}
		}
		if (l > 50) {
			datos[i].ocosto = 200;
		}
		cout << endl;
		system("cls");

		// Imprimir los datos recopilados
		cout << "=== Cita numero " << i << " ===" << endl;
		cout << "Nombre del paciente: ";
		cout << datos[i].nombre << endl;
		cout << "Fecha de la cita (Dia/Mes/Año): ";
		cout << datos[i].fecha << endl;
		cout << "Hora de la cita: ";
		cout << datos[i].hora << " hrs" << endl;
		cout << "Tratamiento: ";
		cout << datos[i].tratamientost << endl;
		cout << "Descripcion: ";
		cout << datos[i].descripcion << endl;
		cout << "Costo unitario de la cita: ";
		cout << "$" << datos[i].presiounitario << endl;
		cout << "Subtotal: ";
		datos[i].subtotal = datos[i].presiounitario + datos[i].ocosto;
		cout << "$" << datos[i].subtotal << endl;
		cout << "Total: ";
		datos[i].iva = datos[i].subtotal * 0.16;
		datos[i].total = datos[i].subtotal + datos[i].iva;
		cout << "$" << datos[i].total << endl;
		cout << "===========================" << endl;

		system("pause");
		system("cls");
		return main();
		break;

		// Editar cita

	case 2:

		system("cls");
		if (i == 0) {
			cout << "No hay citas programadas" << endl;
			system("pause");
			system("cls");
			return main();
		}

		cout << "Que cita desea editar?" << endl << endl;

		// Elegir el numero de cita a editar
		cout << "==== Elija el numero de cita que quiera editar ====" << endl;
		cout << " Las citas existentes son del 1 hasta " << i << endl;
		cin >> e;

		if (e <= i) {
			cout << "¿Que desea editar de la cita?" << endl << endl;
			cout << "1.- Toda la cita" << endl;
			cout << "2.- Solo una pregunta de la cita" << endl;
			cout << "3.- Volver al menu" << endl;
			cin >> editar;

			switch (editar)
			{
			case 1:
				system("cls");
				cout << "A continuacion, se mostraran nuevamente las preguntas" << endl << endl;

				cout << "Favor de llenar los siguientes datos" << endl << endl;
				// ==== Preguntar Nombre ====
				while (rn == 0) {

					cin.ignore(); // = 
					cout << "Nombre Completo" << endl;
					cin.getline(datos[e].nombre, 100, '\n');
					cout << endl;


					// Validar Nombre (Que no contenga numeros)
					l = strlen(datos[e].nombre);
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '0') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '1') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '2') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '3') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '4') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '5') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '6') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '7') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '8') {
							num++;
						}
					}
					for (x = 0; x <= l; x++) {
						if (datos[e].nombre[x] == '9') {
							num++;
						}
					}

					if (num != 0) {
						cout << "== No se pueden colocar numeros en el nombre ==" << endl;
						system("pause");
						system("cls");

					}
					if (rn == num) {
						rn = 1;
					}
					num = 0;
				}
				system("cls");
				rn = 0;

				// ==== Fecha del tratamiento (Dia/Mes/Año) ====
				cout << "Escriba la fecha" << endl;
				cout << "Ejemplo: 260522 (Dia/Mes/Año)" << endl;
				cin >> datos[e].fecha;
				cout << endl;
				system("cls");

				// ==== Hora del tratamiento ====
				cout << "Escriba el hora (Horario 24hrs)" << endl;
				cin >> datos[e].hora;

				// Validar que no pase de 24 hrs
				do {
					if (datos[e].hora > 24) {
						cout << "La hora escrita no es valida, favor de señalar horario en formato de 24hrs" << endl;
						cin >> datos[e].hora;
						rn = 1;
					}
					else {
						rn = 0;
					}

				} while (rn == 1);

				system("cls");

				cin.ignore();
				// ==== Tratamiento ====
				cout << "Eliga el tipo de tratamiento" << endl;
				cout << "1.- Brackets" << endl;
				cout << "2.- Limpieza dental" << endl;
				cout << "3.- Extraccion de algun diente o muela" << endl;
				cout << "4.- Caries" << endl;
				cin >> stratamiento;

				switch (stratamiento)
				{
				case 1:
					datos[e].presiounitario = 500;
					datos[e].tratamientost = "Chequeo";
					break;
				case 2:
					datos[e].presiounitario = 500;
					datos[e].tratamientost = "Limpieza total";
					break;
				case 3:
					datos[e].presiounitario = 1500;
					datos[e].tratamientost = "Extraccion de algun diente o muela o reparacion del mismo";
					break;
				case 4:
					datos[e].presiounitario = 3500;
					datos[e].tratamientost = "Brackets";
				default:
					cout << "Dato no valido" << endl;
				}
				system("cls");
				// ==== Descripcion ====
				cout << "Alguna descripcion: " << endl;
				cin.ignore();
				cin.getline(datos[i].descripcion, 500, '\n');
				l = strlen(datos[i].descripcion);
				if (l < 10) {
					datos[e].ocosto = 50;
				}
				if (l >= 10) {
					if (l <= 50) {
						datos[e].ocosto = 100;
					}
				}
				if (l > 50) {
					datos[e].ocosto = 200;
				}
				cout << endl;
				system("cls");

				// Imprimir los datos recopilados
				cout << "=== Cita numero editado " << e << " ===" << endl;
				cout << "Nombre del paciente: ";
				cout << datos[e].nombre << endl;
				cout << "Fecha de la cita (Dia/Mes/Año): ";
				cout << datos[e].fecha << endl;
				cout << "Hora de la cita: ";
				cout << datos[e].hora << " hrs" << endl;
				cout << "Tratamiento: ";
				cout << datos[e].tratamientost << endl;
				cout << "Descripcion: ";
				cout << datos[e].descripcion << endl;
				cout << "Costo unitario de la cita: ";
				cout << "$" << datos[e].presiounitario << endl;
				cout << "Subtotal: ";
				datos[e].subtotal = datos[e].presiounitario + datos[e].ocosto;
				cout << "$" << datos[e].subtotal << endl;
				cout << "Total: ";
				datos[e].iva = datos[e].subtotal * 0.16;
				datos[e].total = datos[e].subtotal + datos[e].iva;
				cout << "$" << datos[e].total << endl;
				cout << "===========================" << endl;

				system("pause");
				system("cls");
				return main();
				break;

			case 2:
				cout << "==== Eliga la pregunta que quiera modificar de la cita elegida ====" << endl;
				cout << "1.- Nombre del paciente" << endl;
				cout << "2.- Fecha de la cita" << endl;
				cout << "3.- Hora de la cita" << endl;
				cout << "4.- Tratamiento" << endl;
				cout << "5.- Descripcion" << endl;
				cout << "6.- Volver al inicio" << endl;
				cin >> edipre;

				switch (edipre)
				{
				case 1:
					// ==== Preguntar Nombre ====
					while (rn == 0) {

						cin.ignore(); // = 
						cout << "Ingresar nuevo nombre completo" << endl;
						cin.getline(datos[e].nombre, 100, '\n');
						cout << endl;


						// Validar Nombre (Que no contenga numeros)
						l = strlen(datos[e].nombre);
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '0') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '1') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '2') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '3') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '4') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '5') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '6') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '7') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '8') {
								num++;
							}
						}
						for (x = 0; x <= l; x++) {
							if (datos[e].nombre[x] == '9') {
								num++;
							}
						}

						if (num != 0) {
							cout << "== No se pueden colocar numeros en el nombre ==" << endl;
							system("pause");
							system("cls");

						}
						if (rn == num) {
							rn = 1;
						}
						num = 0;
					} // <-- Fin del While (Nombre)

					cout << "==== Se ha modificado la cita ====" << endl;
					cout << "Si desea ver los resultados, dirijase en el apartado de 'ver listas programas del menu'" << endl;
					system("pause");
					rn = 0;
					system("cls");
					return main();

					break;

				case 2:

					// ==== Fecha del tratamiento (Dia/Mes/Año) ====
					cout << "Escriba la fecha" << endl;
					cout << "Ejemplo: 260522 (Dia/Mes/Año)" << endl;
					cin >> datos[e].fecha;
					cout << endl;

					cout << "==== Se ha modificado la cita ====" << endl;
					cout << "Si desea ver los resultados, dirijase en el apartado de 'ver listas programas del menu'" << endl;
					system("pause");
					system("cls");
					return main();

					break;

				case 3:

					// ==== Hora del tratamiento ====
					cout << "Escriba el hora (Horario 24hrs)" << endl;
					cin >> datos[e].hora;

					// Validar que no pase de 24 hrs
					do {
						if (datos[e].hora > 24) {
							cout << "La hora escrita no es valida, favor de señalar horario 24hrs" << endl;
							cin >> datos[e].hora;
							rn = 1;
						}
						else {
							rn = 0;
						}

					} while (rn == 1);

					cout << "==== Se ha modificado la cita ====" << endl;
					cout << "Si desea ver los resultados, dirijase en el apartado de 'ver listas programas del menu'" << endl;
					system("pause");
					system("cls");
					return main();

					break;

				case 4:
					cin.ignore();
					// ==== Tratamiento ====
					cout << "Eliga el tipo de tratamiento" << endl;
					cout << "1.- Brackets" << endl;
					cout << "2.- Limpieza dental" << endl;
					cout << "3.- Extraccion de algun diente o muela" << endl;
					cout << "4.- Caries" << endl;
					cin >> stratamiento;

					switch (stratamiento)
					{
					case 1:
						datos[e].presiounitario = 500;
						datos[e].tratamientost = "Brackets";
						break;
					case 2:
						datos[e].presiounitario = 500;
						datos[e].tratamientost = "Limpieza dental";
						break;
					case 3:
						datos[e].presiounitario = 1500;
						datos[e].tratamientost = "Extraccion de algun diente o muela";
						break;
					case 4:
						datos[e].presiounitario = 3500;
						datos[e].tratamientost = "Caries";
					default:
						cout << "Dato no valido" << endl;
					}

					cout << "==== Se ha modificado la cita ====" << endl;
					cout << "Si desea ver los resultados, dirijase en el apartado de 'ver listas programas del menu'" << endl;
					system("pause");
					system("cls");
					return main();

					break;

				case 5:
					// ==== Descripcion ====
					cout << "Alguna descripcion: " << endl;
					cin.ignore();
					cin.getline(datos[i].descripcion, 500, '\n');
					l = strlen(datos[i].descripcion);
					if (l < 10) {
						datos[e].ocosto = 50;
					}
					if (l >= 10) {
						if (l <= 50) {
							datos[e].ocosto = 100;
						}
					}
					if (l > 50) {
						datos[e].ocosto = 200;
					}
					cout << endl;

					cout << "==== Se ha modificado la cita ====" << endl;
					cout << "Si desea ver los resultados, dirijase en el apartado de 'ver listas programas del menu'" << endl;
					system("pause");
					system("cls");
					return main();
					break;

				case 6:

					system("cls");
					return main();

					break;
				case 7:
				default:
					cout << "Favor de ingresar una de las siguientes opciones " << endl;
					break;
				}

			case 3:
				system("cls");
				return main();
				break;

			default:
				cout << "Favor de ingresar una de las siguientes opciones " << endl;
				break;
			}

		}
		else {
			cout << "La cita numero " << e << " no existe" << endl;
		}

		return main();
		// Tercer switch (eliminar)
	case 3:
		system("cls");
		if (i == 0) {
			cout << "No se han programado citas" << endl;
			system("pause");
			system("cls");
			return main();
		}
		system("cls");
		cout << "==== ¿Que cita desea borrar? ====" << endl << endl;
		cout << "==== Elija el numero de cita que quiera eliminar ====" << endl;
		cout << "     Las citas existentes son del 1 hasta " << i << endl;
		cin >> f;

		if (f > i) {
			cout << "La cita numero " << f << " no existe" << endl;
			system("pause");
			system("cls");
			return main();
		}

		n = 1;
		datos[f] = {};

		do {
			datos[i - 1] = datos[i];


		} while (n < i);



		cout << "Se ha eliminado la cita numero " << f << endl;
		system("pause");
		system("cls");
		return main();
		break;

	case 4:
		system("cls");

		if (i == 0) {
			cout << "No se han programado citas" << endl;
			system("pause");
			system("cls");
			return main();
		}


		cout << "A continuacion se mostraran las citas programadas" << endl << endl << endl;
		n = 1;

		do {
			cout << "=== Cita numero " << n << " ===" << endl;
			cout << "Nombre del paciente: ";
			cout << datos[n].nombre << endl;
			cout << "Fecha de la cita: ";
			cout << datos[n].fecha << endl;
			cout << "Hora de la cita: ";
			cout << datos[n].hora << " hrs" << endl;
			cout << "Tratamiento: ";
			cout << datos[n].tratamientost << endl;
			cout << "Descripcion: ";
			cout << datos[n].descripcion << endl;
			cout << "Costo unitario de la cita: ";
			cout << "$" << datos[n].presiounitario << endl;
			cout << "Subtotal: ";
			cout << "$" << datos[n].subtotal << endl;
			cout << "Total: ";
			cout << "$" << datos[n].total << endl;
			cout << "===========================" << endl;
			n++;
		} while (n <= i);



		system("pause");
		system("cls");
		return main();
		break;

	case 5: {
		
		system("cls");
		break;

	case 6:
		system("cls");
		cout << "Esta seguro que desea salir?" << endl << endl;
		cout << "1.- Si" << endl;
		cout << "2.- No" << endl;
		cin >> salida;


		if (salida == 1) {
			system("cls");
			cout << "Adios, vuelva pronto :p" << endl;

			ofstream archivo;
			archivo.open("Citas guardadas.txt", ios::out);
			if (archivo.fail()) {
				cout << "No se pudo crear el archivo" << endl;
				exit(1);
			}

			archivo << "A continuacion se mostraran las citas programadas" << endl << endl << endl;
			n = 1;
			do {

				archivo << "=== Cita numero " << n << " ===" << endl;
				archivo << "Nombre del paciente: ";
				archivo << datos[n].nombre << endl;
				archivo << "Fecha de la cita: ";
				archivo << datos[n].fecha << endl;
				archivo << "Hora de la cita: ";
				archivo << datos[n].hora << " hrs" << endl;
				archivo << "Tratamiento: ";
				archivo << datos[n].tratamientost << endl;
				archivo << "Descripcion: ";
				archivo << datos[n].descripcion << endl;
				archivo << "Costo unitario de la cita: ";
				archivo << "$" << datos[n].presiounitario << endl;
				archivo << "Subtotal: ";
				archivo << "$" << datos[n].subtotal << endl;
				archivo << "Total: ";
				archivo << "$" << datos[n].total << endl;
				archivo << "===========================" << endl;
				n++;
			} while (n <= i);
			archivo.close();

			exit(EXIT_SUCCESS);
		}
		else {
			system("cls");
			return main();

		}
		break;

	default:
		system("cls");
		cout << "Favor de ingresar una de las siguientes opciones" << endl;
		system("pause");
		system("cls");
		return main();

	}

		  return 0;
	}
}