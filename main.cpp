#include <iostream>
#include <cstdio>
#include <string>
#include <math.h> 
#include "misfunciones.h"

using namespace std;

int main()
{
  int a, b, sal, sal1;
  float vi, pi, al, cf, rp, pt, vip1, m1, vip2, m2, alt;
  
while(1){
  
  
  //clsRebote.rebote(10);
  
  cout<<"ingrese el proceso fisico que desea realizar:\n"<<
         "si desea realizar un movimiento parabolico ingrese 1\n"<<
         "si desea realizar un choque elastico ingrese 2\n"<<
         "si desea realizar un rebote de particulas ingrese 3\n"<<endl;
         
   cin>> a;
   
   system("cls");
   
   
   if (a==1){
   	while(1){
       cout<<"con influencia de friccion ingrese 1\n"<<
             "sin influencia de friccion ingrese 2\n"<<endl;
       cin>> b; 
       system("cls");
	   		if  (b==1)  {
	   			confriccion();
			}	
			else if (b==2){
				sinfriccion();
           	}
           	else {
				cout<<"opcion incorrecta"<<endl;
			}
			cout<<"presione un numero diferente de 1 para volver o 1 para salir"<<endl;
			cin>> sal1;
			system("cls");
			if (sal1==1){
			break;
			}
	}	
	}
	else if (a==2){
		colision();
	}
	else if (a==3){
		cout<<"ingrese la altura (en metros) de la cual se deja caer la particula:"<<endl;
		cin>> alt;
		rebote(alt);
	}
	else{
		cout<<"opcion incorrecta."<<endl;
		
	}
	cout<<"presione un numero diferente de 1 para volver al menu principal o 1 para salir"<<endl;
	cin>> sal;
	system("cls");
	if (sal==1){
		exit(0);
	}
}
}
