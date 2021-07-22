#include <iostream>
	using namespace std;

class Medico : public Persona{
	private:
		string fecha_ingreso;
		string codigo;
		
	public:
		Medico(){}
		~Medico(){}
		//Setters
		void setFecha(string fecha){
			this->fecha_ingreso = fecha;
		}
		void setCodigo(string codigo){
			this->codigo = codigo;
		}
		//Getters
		string getFecha(){
			return this->fecha_ingreso;
		}
		string getCodigo(){
			return this->codigo;
		}
		
		void generarCodigo(){
			this->codigo = "Medico-" + this->getIdentidad();
		}
		
		string generarCadena(){
			return this->nombre+","+this->apellido+","+this->direccion+","+this->telefono+","+this->identidad+","+this->ciudad+","+this->correo+","+this->tipo+","+this->fecha_ingreso+","+this->codigo;
		}
};
