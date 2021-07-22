#include <iostream>
	#include<fstream> // Libreria Para manejo de archivos
#include <sstream>
#include <vector>
//Importaciones de las clases
#include "Persona.h"
#include "Animal.h"
#include "Cliente.h"
#include "Medico.h"
#include "Paciente.h"
#include "Visita.h"
#include "Factura.h"
#include "Medicamento.h"
using namespace std;

Persona *personas[100]; // Arreglo que almacenara tanto medicos como clientes
Paciente *pacientes[100];
Visita *visitas[100];
Factura *facturas[100];
Medicamento *medicamentos[100];

int indicePersonas;
int indicePacientes;
int indiceVisitas;
int indiceFacturas;
int indiceMedicamentos;

void imprimirMenu();

void agregarPersona(string);//Ingresa clientes y medicos POLIFORMISMO
void agregarPacientes();
void agregarVisita();
void agregarFactura();
void agregarMedicamento();
void imprimirPersonas(string);
void imprimirPacientes();
void imprimirVisitas();
void imprimirFacturas();
void imprimirMedicamentos();
void eliminarPaciente();
void eliminarVisita();
void eliminarFactura();
void eliminarMedicamento();
//Metodos para inicializacion de los datos
void lecturaArchivos(string, void (*f)(vector<string>));//Funcion especial que recibe otra como parametro
void iniciarPersonas(vector<string>);
void iniciarPacientes(vector<string>);
void iniciarVisitas(vector<string>);
void iniciarFacturas(vector<string>);
void iniciarMedicamentos(vector<string>);
/***********************************************************************
Metodos genericos que permiten trabajar con cualquier tipo de dato
son utiles para reducir y crear un codigo mas limpio y entendible

Por lo cual definimos un template y con una variable typename T,
para especificar que podra recibir cualquier tipo de dato donde
se creen variables tipo T

Se Puede usar cualquier nombre en lugar de T, por estandar se utiliza.
***********************************************************************/
template <typename T>
void escrituraArchivosGenerica(T array[], string archivo, int final){
	string ruta = "archivos_dat/"+archivo+".dat";//Creamos la ruta dinamica
	ofstream data(ruta);//Creamos el flujo de salida (Abrimos el archivo)
	for(int i=0; i<final; i++)
		data<<array[i]->generarCadena()<<endl;//escribimos una nueva linea en el archivo
	data.close();//Cerramos el flujo de salida (Cerramos el archivo)
}
/***********************************************************************
Metodo que se encarga de validar que el tipo de dato ingresado por el
usuario sea del tipo necesario para la propiedad a guardar.
***********************************************************************/
template <typename T>
T validarTipoEntrada(T variable, string texto){
	while (true){
		cout<<texto;
		cin>>variable;
		try {	
			if(cin.fail())
           		throw "error";
			break;
  		}
  		catch (...) {
    		cout<<"Verifique el tipo de dato ingresado..."<<endl;
    		cin.clear();
    		cin.ignore(100,'\n');
  		}
	}
	return variable;
}

/***********************************************************************
Metodo encargado de eliminar elementos de cualquier tipo de arreglo
***********************************************************************/
template <typename T>
void eliminarElementoArreglo(T array[], string texto, int &final, void (*f)()){
	(*f)();//llamamos funcion para imprimir los elementos
	int index;
	index = validarTipoEntrada<int>(index, texto)-1;
	while(index < 0 && index > final){
		cout<<"Ingrese un indice valido..."<<endl;
		index = validarTipoEntrada<int>(index, texto)-1;	
	}
	for(int i=index; i<final; i++){
		array[i] = array[i+1];
	}
	final--;
}
/**********************************************************************/

int main (){
	indicePersonas = 0;
	indicePacientes = 0;
	indiceVisitas = 0;
	indiceFacturas = 0;
	indiceMedicamentos = 0;
	//Procedemos a leer los archivos e iniciar los datos
	lecturaArchivos("personas", iniciarPersonas);
	lecturaArchivos("pacientes", iniciarPacientes);
	lecturaArchivos("visitas", iniciarVisitas);
	lecturaArchivos("facturas", iniciarFacturas);
	lecturaArchivos("medicamentos", iniciarMedicamentos);
	//Finalizado Inicializacion de los datos
	int opc;
	do {
		imprimirMenu();
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		switch(opc) {
			case 1:
				if (indicePersonas < 100)
					agregarPersona("Cliente");
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 2: 
				if (indicePersonas < 100)
					agregarPersona("Medico");
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 3:
				if (indicePacientes < 100)
					agregarPacientes();
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 4:
				imprimirPersonas("Cliente");
				break;
			case 5:
				imprimirPersonas("Medico");
				break;
			case 6:
				imprimirPacientes();
				break;
			case 7:
				if (indiceVisitas < 100)
					agregarVisita();
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 8:
				if (indiceFacturas < 100) 
					agregarFactura();
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 9:
				if (indiceMedicamentos < 100)
					agregarMedicamento();
				else
					cout<<"Memoria llena, no se puede agregar mas registros"<<endl;
				break;
			case 10:
				imprimirVisitas();
				break;
			case 11: 
				imprimirFacturas();
				break;
			case 12: 
				imprimirMedicamentos();
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				eliminarElementoArreglo(pacientes, "Ingrese Indice Paciente a Eliminar: ", indicePacientes, imprimirPacientes);
				break;
			case 16:
				eliminarElementoArreglo(visitas, "Ingrese Indice Visita a Eliminar: ", indiceVisitas, imprimirVisitas);
				break;
			case 17:
				eliminarElementoArreglo(facturas, "Ingrese Indice Factura a Eliminar: ", indiceFacturas, imprimirFacturas);
				break;
			case 18:
				eliminarElementoArreglo(medicamentos, "Ingrese Indice Medicamento a Eliminar: ", indiceMedicamentos, imprimirMedicamentos);
				break;
			default:
				break;
		}
	} while(opc != 0);
	//Procedemos a almacenar los datos
	escrituraArchivosGenerica<Persona*>(personas, "personas", indicePersonas);
	escrituraArchivosGenerica<Paciente*>(pacientes, "pacientes", indicePacientes);
	escrituraArchivosGenerica<Visita*>(visitas, "visitas", indiceVisitas);
	escrituraArchivosGenerica<Factura*>(facturas, "facturas", indiceFacturas);
	escrituraArchivosGenerica<Medicamento*>(medicamentos, "medicamentos", indiceMedicamentos);
	//Finalizamos la escritura de los archivos
	return 0;
}

void lecturaArchivos(string archivo, void (*f)(vector<string>)){
	string ruta = "archivos_dat/"+archivo+".dat";
	string linea;
	ifstream data(ruta);
	if (data.fail())//Verificamos que si no existe el archivo no hacemos nada
		return;
	while (!data.eof()) {
    	data >> linea;
    	if (data.eof())// Compruebo si he leido la marca de final de fichero
        	break;
        
		vector<string> lista;
		stringstream ss(linea);//Permite operar con string lo cual ocupamos al leer archivos
		string auxiliar = "";
		for (char c; ss >> c;) {
			auxiliar+=c; //concatenamos a una variable cada caracter que leamos
	        if (ss.peek() == ','){// vereficamos si el siguiente caracter es una coma
	        	ss.ignore();//omitimos la coma
	        	lista.push_back(auxiliar); // almacenamos la cadena en un vector auxiliar
	        	auxiliar=""; // limpiamos la variable auxliar para volver a empezar
			}
	    }
	    lista.push_back(auxiliar);//Agregamos el ultimo elemento fuera ya que no existe coma al final
	    
    	(*f)(lista);//Invocamos la funcion pasada como parametro
	}
}

void iniciarPersonas(vector<string> lista){
    if (lista[7]=="Cliente"){
		personas[indicePersonas] = new Cliente();	
	}else{
		personas[indicePersonas] = new Medico();
	}
	personas[indicePersonas]->setNombre(lista[0]);
	personas[indicePersonas]->setApellido(lista[1]);
	personas[indicePersonas]->setDireccion(lista[2]);
	personas[indicePersonas]->setTelefono(lista[3]);
	personas[indicePersonas]->setIdentidad(lista[4]);
	personas[indicePersonas]->setCiudad(lista[5]);
	personas[indicePersonas]->setCorreo(lista[6]);
	personas[indicePersonas]->setTipo(lista[7]);
	personas[indicePersonas]->setFecha(lista[8]);
	personas[indicePersonas]->setCodigo(lista[9]);
	indicePersonas++;
}

void iniciarPacientes(vector<string> lista){
    char aux = lista[2][0];// Del elemento del indice 2 tomamos unicamente el primer caracter por eso el [0]
    pacientes[indicePacientes] = new Paciente();
	pacientes[indicePacientes]->setEspecie(lista[0]);
	pacientes[indicePacientes]->setRaza(lista[1]);
	pacientes[indicePacientes]->setSexo(aux);
	pacientes[indicePacientes]->setPeso(stod(lista[3]));//Conversion de string a double con stod -> string to double
	pacientes[indicePacientes]->setColor(lista[4]);
	pacientes[indicePacientes]->setObservaciones(lista[5]);
	pacientes[indicePacientes]->setNombre(lista[6]);
	pacientes[indicePacientes]->setAlergias(lista[7]);
	pacientes[indicePacientes]->setEdad(stoi(lista[8]));//Conversion de string a int con stoi -> string to integer
	pacientes[indicePacientes]->setIdPaciente(lista[9]);
	pacientes[indicePacientes]->setUltimaVisita(lista[10]);
	indicePacientes++;
}

void iniciarVisitas(vector<string> lista){
	visitas[indiceVisitas] = new Visita();
	visitas[indiceVisitas]->setFecha(lista[0]);
	visitas[indiceVisitas]->setMedico(lista[1]);
	visitas[indiceVisitas]->setFactura(stoi(lista[2]));
	visitas[indiceVisitas]->setObservacion(lista[3]);
	visitas[indiceVisitas]->setTipo(lista[4]);
	visitas[indiceVisitas]->setPaciente(lista[5]);
	indiceVisitas++;
}

void iniciarFacturas(vector<string> lista){
	facturas[indiceFacturas] = new Factura();
	facturas[indiceFacturas]->setFecha(lista[0]);
	facturas[indiceFacturas]->setSubTotal(stod(lista[1]));
	facturas[indiceFacturas]->setISV(stod(lista[2]));
	facturas[indiceFacturas]->setTotal(stod(lista[3]));
	facturas[indiceFacturas]->setFormaPago(lista[4]);
	facturas[indiceFacturas]->setCliente(lista[5]);
	indiceFacturas++;
}

void iniciarMedicamentos(vector<string> lista){
	medicamentos[indiceMedicamentos] = new Medicamento();
	medicamentos[indiceMedicamentos]->setFechaFabricaion(lista[0]);
	medicamentos[indiceMedicamentos]->setFechaVencimiento(lista[1]);
	medicamentos[indiceMedicamentos]->setNombre(lista[2]);
	medicamentos[indiceMedicamentos]->setPrecio(stod(lista[3]));
	medicamentos[indiceMedicamentos]->setFarmaceutica(lista[4]);
	medicamentos[indiceMedicamentos]->setPais(lista[5]);
	medicamentos[indiceMedicamentos]->setAplicaDescuento(lista[6]);
	indiceMedicamentos++;
}

void imprimirMenu(){
	cout<<"Menu"<<endl;
	cout<<"1. Agregar Cliente"<<endl;
	cout<<"2. Agregar Medico"<<endl;
	cout<<"3. Agregar Paciente"<<endl;
	cout<<"4. Imprimir Clientes"<<endl;
	cout<<"5. Imprimir Medicos"<<endl;
	cout<<"6. Imprimir Pacientes"<<endl;
	cout<<"7. Agregar Visitas"<<endl;
	cout<<"8. Agregar Facturas"<<endl;
	cout<<"9. Agregar Medicamentos"<<endl;
	cout<<"10. Imprimir Visitas"<<endl;
	cout<<"11. Imprimir Facturas"<<endl;
	cout<<"12. Imprimir Medicamentos"<<endl;
	cout<<"13. Eliminar Clientes(NO IMPLEMENTADO)"<<endl;
	cout<<"14. Eliminar Medicos(NO IMPLEMENTADO)"<<endl;
	cout<<"15. Eliminar Pacientes"<<endl;
	cout<<"16. Eliminar Visitas"<<endl;
	cout<<"17. Eliminar Facturas"<<endl;
	cout<<"18. Eliminar Medicamentos"<<endl;
	cout<<"0. Salir"<<endl;
}

void agregarPersona(string tipo){
	if (tipo=="Cliente"){
		personas[indicePersonas] = new Cliente();	
	}else{
		personas[indicePersonas] = new Medico();
	}
	string auxiliar;
	//Prueba de forma alternativa de acceso a los atributos en lugar de ->
	(*personas[indicePersonas]).setTipo(tipo);
	(*personas[indicePersonas]).setNombre(validarTipoEntrada<string>(auxiliar, "Ingrese Nombre Cliente: "));
	(*personas[indicePersonas]).setApellido(validarTipoEntrada<string>(auxiliar, "Ingrese Apellido Cliente: "));
	(*personas[indicePersonas]).setDireccion(validarTipoEntrada<string>(auxiliar, "Ingrese Direccion Cliente: "));
	(*personas[indicePersonas]).setTelefono(validarTipoEntrada<string>(auxiliar, "Ingrese Telefono Cliente: "));
	(*personas[indicePersonas]).setCorreo(validarTipoEntrada<string>(auxiliar, "Ingrese Correo Cliente: "));
	(*personas[indicePersonas]).setIdentidad(validarTipoEntrada<string>(auxiliar, "Ingrese Identidad Cliente: "));
	(*personas[indicePersonas]).setCiudad(validarTipoEntrada<string>(auxiliar, "Ingrese Ciudad Cliente: "));
	(*personas[indicePersonas]).setFecha(validarTipoEntrada<string>(auxiliar, "Ingrese Fecha Registro Cliente: "));
	(*personas[indicePersonas]).generarCodigo();
	indicePersonas++;
}

void imprimirPersonas(string tipo){
	cout<<"Listado de "<<tipo<<endl;
	for(int i=0;i<indicePersonas;i++) {
		if (personas[i]->getTipo() == tipo){
			personas[i]->imprimirNombre();
			personas[i]->imprimirContacto();
			personas[i]->imprimirDireccion();
			cout<<endl;
		}	
	}
}

void agregarPacientes(){
	pacientes[indicePacientes] = new Paciente();
	string auxiliar;
	char sexo;
	double peso;
	int edad;
	pacientes[indicePacientes]->setEspecie(validarTipoEntrada<string>(auxiliar, "Ingrese Especie: "));
	pacientes[indicePacientes]->setRaza(validarTipoEntrada<string>(auxiliar, "Ingrese Raza: "));
	pacientes[indicePacientes]->setSexo(validarTipoEntrada<char>(sexo, "Ingrese Sexo(M o H): "));
	pacientes[indicePacientes]->setPeso(validarTipoEntrada<double>(peso, "Ingrese Peso(KG): "));
	pacientes[indicePacientes]->setColor(validarTipoEntrada<string>(auxiliar, "Ingrese Color: "));
	pacientes[indicePacientes]->setNombre(validarTipoEntrada<string>(auxiliar, "Ingrese Nombre: "));
	pacientes[indicePacientes]->setAlergias(validarTipoEntrada<string>(auxiliar, "Ingrese Alergias: "));
	pacientes[indicePacientes]->setUltimaVisita (validarTipoEntrada<string>(auxiliar, "Ingrese Fecha Ultima Visita: "));
	pacientes[indicePacientes]->setEdad(validarTipoEntrada<int>(edad, "Ingrese Edad(años cerrados): "));
	pacientes[indicePacientes]->setObservaciones(validarTipoEntrada<string>(auxiliar, "Ingrese Observaciones: "));
	pacientes[indicePacientes]->generarId();
	indicePacientes++;
}

void  imprimirPacientes(){
	cout<<"Listado de Pacientes"<<endl;
	for(int i=0;i<indicePacientes;i++) {
		cout<<i+1<<"> ";
		pacientes[i]->imprimirDatos();
		pacientes[i]->imprimirEspecieRaza();
		cout<<endl;
	}
}

void agregarVisita(){
	visitas[indiceVisitas] = new Visita();
	string auxiliar;
	int factura;
	visitas[indiceVisitas]->setFecha(validarTipoEntrada<string>(auxiliar,  "Ingrese Fecha: "));
	visitas[indiceVisitas]->setTipo(validarTipoEntrada<string>(auxiliar,  "Ingrese Tipo: "));
	visitas[indiceVisitas]->setPaciente(validarTipoEntrada<string>(auxiliar,  "Ingrese Nombre Paciente: "));
	visitas[indiceVisitas]->setFactura(validarTipoEntrada<int>(factura,  "Ingrese Numero Factura: "));
	visitas[indiceVisitas]->setMedico(validarTipoEntrada<string>(auxiliar,  "Ingrese Nombre Medico: "));
	visitas[indiceVisitas]->setObservacion(validarTipoEntrada<string>(auxiliar,  "Ingrese Observaciones: "));
	indiceVisitas++;
}

void imprimirVisitas(){
	cout<<"Listado de Visitas"<<endl;
	for(int i=0;i<indiceVisitas;i++) {
		cout<<i+1<<"> ";
		visitas[i]->imprimirInfoBasica();
		visitas[i]->imprimirDetalle();
		cout<<endl;
	}
}

void agregarFactura(){
	facturas[indiceFacturas] = new Factura();
	string auxiliar;
	double montos;
	facturas[indiceFacturas]->setFecha(validarTipoEntrada<string>(auxiliar,  "Ingrese Fecha: "));
	facturas[indiceFacturas]->setFormaPago(validarTipoEntrada<string>(auxiliar,  "Ingrese Forma de Pago: "));
	facturas[indiceFacturas]->setTotal(validarTipoEntrada<double>(montos,  "Ingrese Total Factura: "));
	facturas[indiceFacturas]->calcularISV();
	facturas[indiceFacturas]->calcularSubTotal();
	indiceFacturas++;
}

void imprimirFacturas(){
	cout<<"Listado de Facturas"<<endl;
	for(int i=0;i<indiceFacturas;i++) {
		cout<<i+1<<"> ";
		facturas[i]->imprimir();
		cout<<endl;
	}
}

void agregarMedicamento(){
	medicamentos[indiceMedicamentos] = new Medicamento();
	string auxiliar;
	double montos;
	medicamentos[indiceMedicamentos]->setFechaFabricaion(validarTipoEntrada<string>(auxiliar, "Ingrese Fecha Fabricacion: "));
	medicamentos[indiceMedicamentos]->setFechaVencimiento(validarTipoEntrada<string>(auxiliar, "Ingrese Fecha Vencimiento: "));
	medicamentos[indiceMedicamentos]->setNombre(validarTipoEntrada<string>(auxiliar, "Ingrese Nombre Medicamento: "));
	medicamentos[indiceMedicamentos]->setFarmaceutica(validarTipoEntrada<string>(auxiliar, "Ingrese Farmaceutica: "));
	medicamentos[indiceMedicamentos]->setAplicaDescuento(validarTipoEntrada<string>(auxiliar, "Aplica Descuento (Si o No): "));
	medicamentos[indiceMedicamentos]->setPais(validarTipoEntrada<string>(auxiliar, "Ingrese Pais Fabricacion: "));
	medicamentos[indiceMedicamentos]->setPrecio(validarTipoEntrada<double>(montos, "Ingrese Precio: "));
	indiceMedicamentos++;
}

void imprimirMedicamentos(){
	cout<<"Listado de Medicamentos"<<endl;
	for(int i=0;i<indiceMedicamentos;i++) {
		cout<<i+1<<"> ";
		medicamentos[i]->imprimirInformacion();
		medicamentos[i]->imprimirInfoFarmaceutica();
		cout<<endl;
	}
}






