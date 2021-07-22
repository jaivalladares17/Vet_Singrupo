#include <iostream>
	using namespace std;

class Cliente : public Persona{
	private:
		string fecha_registro;
		string codigo;
		
	public:
		Cliente(){}
		~Cliente(){}
		//Setters
		void setFecha(string fecha){
			this->fecha_registro = fecha;
		}
		void setCodigo(string codigo){
			this->codigo = codigo;
		}
		//Getters 
		string getFecha(){
			return this->fecha_registro;
		}
		string getCodigo(){
			return this->codigo;
		}
		
		void generarCodigo(){
			this->codigo = "Cliente-" + this->getIdentidad();
		}
		
		string generarCadena(){
			return this->nombre+","+this->apellido+","+this->direccion+","+this->telefono+","+this->identidad+","+this->ciudad+","+this->correo+","+this->tipo+","+this->fecha_registro+","+this->codigo;
		}
};
