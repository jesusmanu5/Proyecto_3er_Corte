#include <iostream>

#ifndef Archivo
#define Archivo
using namespace std;

class Cifrar{
	
	public:
		
		void setCifrar();
		void setCadena();
		void setNumero();
		
		string getCadena();
		int getNumero();
		
		void addCadena(string Cadena);
		void addNumero(int Numero);
		
		Cifrar();
		
		~Cifrar();
        		
	private:
		
		string Cadena;
		int Numero;
};
#endif
