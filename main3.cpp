#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "Cifrando.h"
int n=0;
int i=0;
using namespace std;

void codifica(int n, string & cadena) 
{ 
    for (int i = 0; i < cadena.length(); i++) { 
        if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
            if (cadena[i] + n > 'z') { 
                cadena[i] = 'a' - 'z' + cadena[i] + n - 1; 
            } else if (cadena[i] + n < 'a') { 
                cadena[i] = 'z' - 'a' + cadena[i] + n + 1; 
            } else { 
                cadena[i] += n; 
            } 
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') { 
            if (cadena[i] + n > 'Z') { 
                cadena[i] = 'A' - 'Z' + cadena[i] + n - 1; 
            } else if (cadena[i] + n < 'A') { 
                cadena[i] = 'Z' - 'A' + cadena[i] + n + 1; 
            } else { 
                cadena[i] += n; 
            } 
        } 
    } 
} 
//Funcion descodificar 
void descodifica(int n, string & cadena) 
{ 
    codifica(-n, cadena); 
} 
 
//Funcion main
int main() 
{
    
    string cadena; 
    int n, op, tam, aux, cont = 0;
    char texto[50];
    bool continuar;
   	
    while (op !=3) {
	
        cout<<"**"<<setw(14)<<"MENU"<<setw(13)<<"**"<<endl;
		cout <<"**"<<setw(6) <<"Introduzca una opcion: "<<setw(4)<<"**" <<endl;
		cout<<"**1) Codificar texto"<<setw(9)<<"**"<<endl;
		cout<<"**2) Descodificar texto"<<setw(6)<<"**"<<endl;
		cout<<"**3) SALIR"<<setw(19)<<"**"<<endl;
		cout<<"***"<<setw(26)<<"***"<<endl;
		cout<<"*****************************"<<endl<<endl;
		cin>>op;
		system("cls");
		
        switch(op){
                 case 1:
                   cout << "Introduce el mensaje a codificar: " << endl; 
                   cin>> cadena;
                   
                    do {
                        continuar = false;
                        cin.clear();
                        if(cont > 0) cin.ignore(1024, '\n');
                        cout << "Introduce el numero de desplazamiento deseado: "<<endl;
                        cin >> n;
                        for (int i = 0; i < cadena.length(); i++) { 
                            if (cadena[i] >= 'a' && cadena[i] <= 'z') { 
                                          if (cadena[i] + n > 'z') { 
                                              cadena[i] = 'a' - 'z' + cadena[i] + n - 1; 
                                              } else if (cadena[i] + n < 'a') { 
                                                 cadena[i] = 'z' - 'a' + cadena[i] + n + 1; 
                                                 } else { 
                                                    cadena[i] += n; 
                                                 } 
                                          } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') { 
                                             if (cadena[i] + n > 'Z') { 
                                                  cadena[i] = 'A' - 'Z' + cadena[i] + n - 1; 
                                                  } else if (cadena[i] + n < 'A') { 
                                                     cadena[i] = 'Z' - 'A' + cadena[i] + n + 1; 
                                                     } else { 
                                                        cadena[i] += n; 
                                                        } 
                                                        
                                          }
                                          
                            }
                            cout<< cadena<<endl; 
                        
                        cont++;
                        if(cin.fail() && cin.rdstate()){
                                cout << "Fail!! Prueba con un numero" << endl;
                                continuar = true;
                                }
                        } while (continuar);
                        system("PAUSE");
                        system("cls");
                        break;
                        
                 case 2:
                        cout<<"Indique el texto a descodificar"<<endl;
                        gets(texto);
                        cin>>cadena;
                        tam=strlen(texto);
                        for(int i=0;i<tam;i++)
                        {  
                           aux=texto[i];
                           if(aux-n<97)
                           {
                              aux=122-(96-(aux-n));
                           }
                           else
                           {
                              aux=aux-n;
                           } 
                           if(texto[i]!=' ')
                           {
                              texto[i]=aux;             
                           }
                        }
                        cout<<"Texto codificado a: "<<texto<<endl;
                        descodifica(n, cadena); 
                        cout << cadena << endl; 
                        system("PAUSE");
			            system("cls");
                        break;
                case 3: 
                       return 0;
		               break; 
 
                 default: 
		         if(op<1 || op>3 ){
				 system("cls");
				 cout <<"Numero invalido.."<<endl;
 				 system("PAUSE");
			     system("cls");
			   } 
			   break;
        }
     }                

    codifica(n, cadena); 
    cout << cadena << endl; 
    descodifica(n, cadena); 
    cout << cadena << endl; 

    system("PAUSE");
    return EXIT_SUCCESS;
}
