#include <iostream>
	#include <string>
using namespace std;

class Paciente : public Animal{
	private:
		string nombre;
		string alergias;
		int edad;
		string id_paciente;
		string ultima_visita;
		
	public:
		Paciente(){}
		~Paciente(){}
		//Setters
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void setAlergias(string alergias){
			this->alergias = alergias;
		}
		void setEdad(int edad){
			this->edad = edad;
		}
		void setIdPaciente(string id){
			this->id_paciente = id;
		}
		void setUltimaVisita(string ultima){
			this->ultima_visita = ultima;
		}
		//Getters
		string getNombre(){
			return this->nombre;
		}
		string getAlergias(){
			return this->alergias;
		}
		int getEdad(){
			return this->edad;
		}
		string getIdPaciente(){
			return this->id_paciente;
		}
		string getUltimaVisita(){
			return this->ultima_visita;
		}
		
		void generarId(){
			this->id_paciente = "Paciente-" + this->nombre;
		}
		
		void imprimirDatos(){
			cout<<"Nombre: "<<this->getNombre()<<" , Color: "<<this->getColor()<<" , Edad: "<<this->getEdad()<<" , Sexo: "<<this->getSexo()<<endl;
		}
		
		void imprimirEspecieRaza(){
			cout<<"Especie y Raza: "<<this->getEspecie()<<" , "<<this->getRaza()<<endl;
		}
		
		string generarCadena(){
			return this->especie+","+this->raza+","+this->sexo+","+to_string(this->peso)+","+this->color+","+this->observaciones+","+this->nombre+","+this->alergias+","+to_string(this->edad)+","+this->id_paciente+","+this->ultima_visita;
		}
};
