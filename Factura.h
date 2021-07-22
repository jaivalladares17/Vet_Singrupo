#include <iostream>
	#include <string>
using namespace std;

class Factura{
	private:
		string fecha;
		double subtotal;
		double isv;
		double total;
		string forma_pago;
		string cliente;
	public:
		void setFecha(string fecha){
			this->fecha = fecha;
		}
		void setSubTotal(double subtotal){
			this->total = total;
		}
		void setISV(double isv){
			this->isv = isv;
		}
		void setTotal(double total){
			this->total = total;
		}
		void setFormaPago(string forma){
			this->forma_pago = forma;
		}
		void setCliente(string cliente){
			this->cliente = cliente;
		}
		
		string getFecha(){
			return this->fecha;
		}
		double getSubTotal(){
			return this->subtotal;
		}
		double getISV(){
			return this->isv;
		}
		double getTotal(){
			return this->total;
		}
		string getFormaPago(){
			return this->forma_pago;
		}
		string getCliente(){
			return this->cliente;
		}
		
		void calcularISV(){
			this->isv = this->total * 0.15;
		}
		
		void calcularSubTotal(){
			this->subtotal = this->total - this->isv;
		}
		
		void imprimir(){
			cout<<"Fecha: "<<this->fecha<<" , Forma de Pago: "<<this->forma_pago<<endl;
			cout<<"Subtotal: "<<this->subtotal<<" , ISV: "<<this->isv<<" , Total: "<<this->total<<endl;
		}
		
		string generarCadena(){
			return this->fecha+","+to_string(this->subtotal)+","+to_string(this->isv)+","+to_string(this->total)+","+this->forma_pago+","+this->cliente;
		}
};
