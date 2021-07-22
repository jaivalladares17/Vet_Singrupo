#include <iostream>
	using namespace std;

class Animal{
	protected:
		string especie;
		string raza;
		char sexo;
		double peso;
		string color;
		string observaciones;
		
	public:
		Animal(){}
		~Animal(){}
		//Setters
		void setEspecie(string especie){
			this->especie = especie;
		}
		void setRaza(string raza){
			this->raza = raza;
		}
		void setSexo(char sexo){
			this->sexo = sexo;
		}
		void setPeso(double peso){
			this->peso = peso;
		}
		void setColor(string color){
			this->color = color;
		}
		void setObservaciones(string obs){
			this->observaciones = obs;
		}
		//Getters
		string getEspecie(){
			return this->especie;
		}
		string getRaza(){
			return this->raza;
		}
		char getSexo(){
			return this->sexo;
		}
		double getPeso(){
			return this->peso;
		}
		string getColor(){
			return this->color;
		}
		string getObservaciones(){
			return this->observaciones;
		}
};
