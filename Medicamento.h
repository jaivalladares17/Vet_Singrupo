#include <iostream>
	#include <string>
using namespace std;

class Medicamento{
	private:
		string fecha_fabricacion;
		string fecha_vencimiento;
		string nombre;
		double precio;
		string farmaceutica;
		string pais;
		string aplica_descuento;
	public:
		void setFechaFabricaion(string fecha){
			this->fecha_fabricacion = fecha;
		}
		void setFechaVencimiento(string fecha){
			this->fecha_vencimiento = fecha;
		}
		void setNombre(string nombre){
			this->nombre = nombre;
		}
		void setFarmaceutica(string farmaceutica){
			this->farmaceutica = farmaceutica;
		}
		void setPais(string pais){
			this->pais = pais;
		}
		void setAplicaDescuento(string aplica){
			this->aplica_descuento = aplica;
		}
		void setPrecio(double precio){
			this->precio = precio;
		}
		
		string getFechaFabricacion(){
			return this->fecha_fabricacion;
		}
		string getFechaVencimiento(){
			return this->fecha_vencimiento;
		}
		string getNombre(){
			return this->nombre;
		}
		string getFarmaceutica(){
			return this->farmaceutica;
		}
		string getPais(){
			return this->pais;
		}
		string getAplicaDescuento(){
			return this->aplica_descuento;
		}
		double getPrecio(){
			return this->precio;
		}
		
		void imprimirInfoFarmaceutica(){
			cout<<"Farmaceutica: "<<this->farmaceutica<<" , Pais: "<<this->pais<<endl;
		}
		
		void imprimirInformacion(){
			cout<<"Nombre: "<<this->nombre<<" , Fecha Vencimiento: "<<this->fecha_vencimiento<<" , Precio: "<<this->precio<<endl;
		}
		
		void aplicarDescuento(){
			if(this->aplica_descuento == "Si"){
				this->precio -= this->precio * 0.3; 
			}
		}
		
		string generarCadena(){
			return this->fecha_fabricacion+","+this->fecha_vencimiento+","+this->nombre+","+to_string(this->precio)+","+this->farmaceutica+","+this->pais+","+this->aplica_descuento;
		}
};
