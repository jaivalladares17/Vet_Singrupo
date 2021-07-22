#include <iostream>
	#include <string>
using namespace std;

class Visita{
	private:
		string fecha;
		string medico;
		int factura;
		string observacion;
		string tipo;
		string paciente;
	public:
		void setFecha(string fecha){
			this->fecha = fecha;
		}
		void setMedico(string medico){
			this->medico = medico;
		}
		void setFactura(int factura){
			this->factura = factura;
		}
		void setObservacion(string obs){
			this->observacion = obs;
		}
		void setTipo(string tipo){
			this->tipo = tipo;
		}
		void setPaciente(string paciente){
			this->paciente = paciente;
		}
		
		string getFecha(){
			return this->fecha;
		}
		string getMedico(){
			return this->medico;
		}
		int getFactura(){
			return this->factura;
		}
		string getObservacion(){
			return this->observacion;
		}
		string getTipo(){
			return this->tipo;
		}
		string getPaciente(){
			return this->paciente;
		}
		
		void imprimirInfoBasica(){
			cout<<"Fecha: "<<this->fecha<<" , Medico: "<<this->medico<<" , Paciente: "<<this->paciente<<endl;
		}
		
		void imprimirDetalle(){
			cout<<"Tipo: "<<this->tipo<<" , Numero Factura: "<<this->factura<<endl;
		}
		
		string generarCadena(){
			return this->fecha+","+this->medico+","+to_string(this->factura)+","+this->observacion+","+this->tipo+","+this->paciente;
		}
};
