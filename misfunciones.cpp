#include <iostream>
#include "misfunciones.h"
#include <math.h>
using namespace std;

void sinfriccion(){
	float periodo,angulo,yi,vi;
	float vx[10];
	float vy[10];
	float x[10];
	float y[10];
	float tiempo[10];
	cout<<"ingrese el periodo de tiempo a analizar(s):"<<endl;
	cin>> periodo;
	system("cls");
	cout<<"ingrese la altura inicial desde la cual se lanza el objeto(m): "<<endl;
	cin>> yi;
	system("cls");
	cout<<"ingrese el angulo de disparo: "<<endl;
	cin>> angulo;
	system("cls");
	cout<<"ingrese la velocidad inicial del objeto(m/s): "<<endl;
	cin>> vi;
	system("cls");
	
	for(int i=0;i<10;i++){
		tiempo[i]=(i*periodo)/10;
		vx[i]=(vi*cos(angulo));
		vy[i]=(vi*sin(angulo))-(9.8*tiempo[i]);
		x[i]=vx[i]*tiempo[i];
		y[i]=yi+(vi*sin(angulo)*tiempo[i])-((9.8*tiempo[i]*tiempo[i])/2);
	}
	
	for(int i=0;i<10;i++){
		cout<<"Para tiempo = "<<tiempo[i]<<endl;
		cout<<"x = "<<x[i]<<"\t y = "<<y[i]<<"\n\n";
	}
}
void confriccion(){
	float periodo,angulo,yi,yi2,vi,ay,b,yaux,j,k,r,m;
	float vx[50];
	float vy[50];
	float x[50];
	float y[50];
	float tiempo[50];
	int taux;
	b=0;
	cout<<"ingrese el periodo de tiempo a analizar(s):"<<endl;
	cin>> periodo;
	system("cls");
	cout<<"ingrese la altura inicial desde la cual se lanza el objeto(m): "<<endl;
	cin>> yi;
	system("cls");
	cout<<"ingrese el angulo de disparo: "<<endl;
	cin>> angulo;
	system("cls");
	cout<<"ingrese la velocidad inicial del objeto(m/s): "<<endl;
	cin>> vi;
	system("cls");
	cout<<"ingrese la constante de friccion:"<<endl;
	cin>> k;
	system("cls");
	cout<<"ingrese el radio del objeto(m): "<<endl;
	cin>> r;
	system("cls");
	cout<<"ingrese la masa del objeto(gr): "<<endl;
	cin>> m;
	system("cls");
	
	for(int i=0;i<50;i++){
		tiempo[i]=(i*periodo)/50;
		vx[i]=(vi*cos(angulo))-((((k*(vi*vi)*(r*r))/m)*cos(angulo))*tiempo[i]);
		ay=9.8-(((k*(vi*vi)*(r*r))/m)*sin(angulo));
		vy[i]=(vi*sin(angulo))-(9.8*tiempo[i]);
		if(vx[i]<=0){
			x[i]=x[i-1];
		}
		else{
			x[i]=(vi*cos(angulo)*tiempo[i])-(((((k*(vi*vi)*(r*r))/m)*cos(angulo))*(tiempo[i]*tiempo[i]))/2);
		}
		if(b==0){
		
			y[i]=yi+(vi*sin(angulo)*tiempo[i])+((((((-1)*k*(vi*vi)*(r*r))/m)*(tiempo[i]*tiempo[i]))-(9.8*(tiempo[i]*tiempo[i])))/2);
		}
		
		if((y[i]<y[i-1])&&(b==0)){
			b=1;
			yi2=y[i-1];
			taux=i-1;
			
		}
		
		if(b==0){
		
			y[i]=yi+(vi*sin(angulo)*tiempo[i])+((((((-1)*k*(vi*vi)*(r*r))/m)*(tiempo[i]*tiempo[i]))-(9.8*(tiempo[i]*tiempo[i])))/2);
		}
		else{
			if(ay<=0){
				y[i]=y[i-1];
			}
			else{
				y[i]=yi2-(ay*(tiempo[(i-taux)]*tiempo[(i-taux)]));
			}
		}
	}
	for(int i=0;i<50;i=i+5){
		cout<<"Para tiempo = "<<tiempo[i]<<endl;
		cout<<"vx = "<<vx[i]<<"\t vy = "<<vy[i]<<endl;
		cout<<"x = "<<x[i]<<"\t y = "<<y[i]<<"\n\n";
	}
}
void rebote(float h){
	float u1, v1, e= 0, g=9.8;
	int r = 0; //cantidad de rebote

    cout<<"Altura inicial: ";
	cout<<h<<endl; 

	while( h > 0.001)
	{		
		cout<<"_______"""<<endl;
		u1= sqrt(2*g*h);		
		e = e + 0.1;		
		v1 = e * u1;		
		h = e*e*h; //nueva altura
		r = r +1;
		
		cout<<"Altura en el rebote "<<r<<":   ";
		cout<<h; 
		cout<<" metros"<<endl;  
		cout<<"Rebote: ";	
		cout<<r<<endl;		
		cout<<"_______"""<<endl;
		
	}
}
void colision(){
	float vf1,vf2,m1,m2,v1,v2;
	cout<<"ingrese la masa 1(gr):"<<endl;
	cin>> m1;
	system("cls");
	cout<<"ingrese la masa 2(gr): "<<endl;
	cin>> m2;
	system("cls");
	cout<<"ingrese la velocidad de m1(m/s) "<<endl;
	cin>> v1;
	system("cls");
	cout<<"ingrese la velocidad de m2(m/s): "<<endl;
	cin>> v2;
	system("cls");
	vf1=(((m1-m2)/(m1+m2))*v1)+(((2*m2)/(m1+m2))*v2);
	vf2=(((m1-m2)/(m1+m2))*v2)+(((2*m1)/(m1+m2))*v1);
	cout<<"La velocidad final de la masa 1 es: "<<vf1<<endl;
	cout<<"La velocidad final de la masa 2 es: "<<vf2<<endl;
}
