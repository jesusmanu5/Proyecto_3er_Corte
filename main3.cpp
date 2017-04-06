#include <cstdlib>
#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<string>


int n=0;
int i=0;
using namespace std;
    //Funcion codifica 
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
 
//Programa principal 
int main() 
{
    string cadena; 
    int n, i, cont = 0;
    bool continuar;
    
    do {
      cout << "Introduce el mensaje a codificar: " << endl; 
      getline(cin, cadena);
      i++;
      if(cin.fail() && cin.rdstate()){
         cout << "Fail!! Prueba con escribir letras" << endl;
         continuar = true;
      }  
    } while (continuar);
      
    do {
      continuar = false;
      cin.clear();
      if(cont > 0) cin.ignore(1024, '\n');
      cout << "Introduce el numero de desplazamiento deseado: "<<endl;
      cin >> n;
      cont++;
      if(cin.fail() && cin.rdstate()){
         cout << "Fail!! Prueba con un numero" << endl;
         continuar = true;
      }
    } while (continuar);
 
    codifica(n, cadena); 
    cout << cadena << endl; 
    descodifica(n, cadena); 
    cout << cadena << endl; 

    system("PAUSE");
    return EXIT_SUCCESS;
}
