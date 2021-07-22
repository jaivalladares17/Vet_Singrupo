#include <iostream>
	using namespace std;

class Persona{
	protected:
		string nombre;
		string apellido;
		string direccion;
		string telefono;
		string identidad;
		string ciudad;
		string correo;
		string tipo;
	public:
		Persona(){}//Constructor
		~Persona(){}//Destructor
		virtual void setFecha(string){};
		virtual void setCodigo(string){};
		//Setters
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void setApellido(string apellido){
			this->apellido = apellido;
		}
		void setDireccion(string direccion){
			this->direccion = direccion;
		}
		void setTelefono(string telefono){
			this->telefono = telefono;
		}
		void setIdentidad(string identidad){
			this->identidad = identidad;
		}
		void setCiudad(string ciudad){
			this->ciudad = ciudad;
		}
		void setCorreo(string correo){
			this->correo = correo;
		}
		void setTipo(string tipo){
			this->tipo = tipo;
		}
		//Getters
		virtual string getFecha(){return "";};
		string getNombre(){
			return this->nombre;
		}
		string getApellido(){
			return this->apellido;
		}
		string getDireccion(){
			return this->direccion;
		}
		string getTelefono(){
			return this->telefono;
		}
		string getIdentidad(){
			return this->identidad;
		}
		string getCiudad(){
			return this->ciudad;
		}
		string getCorreo(){
			return this->correo;
		}
		string getTipo(){
			return this->tipo;
		}
		
		void imprimirNombre(){
			cout<<"Nombre: "<<this->nombre<<" "<<this->apellido<<endl;
		}
		
		void imprimirDireccion(){
			cout<<"Direccion: "<<this->direccion<<", "<<this->ciudad<<endl;	
		}
		
		void imprimirContacto(){
			cout<<"Telefono: "<<this->telefono<<" Identidad: "<<this->identidad<<endl;	
		}
		
		virtual void generarCodigo(){};
		virtual string generarCadena(){return "";}
};
