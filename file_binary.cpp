#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


struct Registro{
	char Nomb[200];
	char Ape[200];
	char FN[11];
	char CI[12];
	float Notas[30];
	char Dir[500];
};

string encapsular(string text,int aux){
    int band=0;
	for(int j=0; j<aux; j++){
        if(text[j]==','){
            band=1;
        }
    }
    if (band==1){
        text="\""+text+"\"";
    }
    return text;
}

int main(int argc, char** argv) {
	Registro datos;
	streampos begin,end, size;
	
	ofstream myfilecsv("datos.csv",ios::trunc);
    ifstream myfile("datos.bin",ios::in|ios::binary|ios::ate);
    end = myfile.tellg();
    myfile.seekg (0, ios::beg);
    size = myfile.tellg();
    if (myfile.is_open()){
        while(size<end){
        	
        	myfile.seekg (size);
            myfile.read (datos.Nomb, sizeof(datos.Nomb));
            myfile.read (datos.Ape, sizeof(datos.Ape));
            myfile.read (datos.FN, sizeof(datos.FN));
            myfile.read (datos.CI, sizeof(datos.CI));
            for (int X = 0; X < 31; X++){
                myfile.read((char *)(&datos.Notas[X]),sizeof(datos.Notas[X]));
            }
            myfile.read (datos.Dir, sizeof(datos.Dir));
            
             if (myfilecsv.is_open()){
                myfilecsv<<datos.Nomb<<",";
                myfilecsv<<datos.Ape<<",";
                myfilecsv<<datos.FN<<",";
                myfilecsv<<datos.CI<<",\"";
                for (int i=0; i<31;i++){
                    myfilecsv<<datos.Notas[i]<<"\",\"";   
                } 
                myfilecsv<<datos.Dir<<"\"\n";
            }else{
                cout<<"Error intente otra vez"<<endl;
            }
            
            size=size+1032;
        }
        myfile.close();
    }else{
       cout<<"error, no se ha abierto el archivo"<<endl;
    }
	
    cout<<"Registro Terminado\n";
    cin.get();
    return 0;
}


