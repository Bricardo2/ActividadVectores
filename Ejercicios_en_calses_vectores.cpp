#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
void valores_alatorios(double vec[], double tamanio) {

    for (int i = 0; i < tamanio; i++) {
        vec[i] = rand();
    }
}
void imprimir_vector(double vector[],double tamanio)
{
		cout<<"elementos del vector :"<<endl;
	for (int i=0;i<tamanio;i++){
	cout<<vector[i]<<endl;
	}
}
double ma_vector(double vector[],double tamanio){
		double ma =vector[0];
					for(int i=1; i<tamanio; i++){
						if(ma<vector[i]){
							ma = vector[i];
								}
					}
return ma;
}
double mi_vector(double vector[],double tamanio){
	double me = vector[0];
	for(int i=1; i<tamanio; i++){
		if(me>vector[i]){
			me = vector[i];
		}
	}
return me;
}
void maximo_min(double vector[], double tamanio, double &ma, double &mi) {
    ma = ma_vector(vector, tamanio);
    mi = mi_vector(vector, tamanio);
}
void orden_secuencial(double vector[],double tamanio){
		for(int i=1; i<tamanio; i++){
			
				for(int j=i+1;j<tamanio;j++){
					if(vector[i]>vector[i+1]){
						int aux;
							aux=vector[i];
								vector[i]=vector[i+1];
										vector[i+1]=aux;
										}	
									}				
								}
}
//busca un numero entero
bool verdadero_falso(double vector[], double tamanio, double elemento) {
    for (int x = 0; x <tamanio; x++) {
       		 if (vector[x]==elemento) {
        	return false;
        break;
        }
    }
    return true;
}
//Pocision del vector del numero
double pocision(double vector[], double tamanio, double elemento) {
    for (int x = 0; x <tamanio; x++) {
       		 if (vector[x] == elemento) {
        	return x;
        }
    }
    return -1;
}
//ejercicio Jueves
void valores_alatorios1(double vec[], double tamanio) {
    
    for (int i = 0; i < tamanio; i++) {
        vec[i] = rand()%15-1;
    }
}
void imprimir_vectores(double vector[],double tamanio)
{
		
	for (int i=0;i<tamanio;i++){
	cout<<"elementos del vector :"<<endl;
	cout<<vector[i]<<endl;
	}
}
void intercambio(double &num1, double &num2)
{
double aux;
aux = num1;
num1 = num2;
num2 = aux;
}
void decendente(double vector[],double tamanio){
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] < vector[j]) {
                double aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}
double repetido(double vector[], double tamanio, double elemento) {
	double acum;
    for (int x=0; x < tamanio; x++) {
       		 if (vector[x]==elemento) {
       		 	acum=acum+1;     	
        }
    }
    return acum;
}
void nombrevector(string nombres[], int tamanio) {
    for (int k = 0; k < tamanio; k++) {
        cout << endl << nombres[k];
    }
}
void ordenar_nombres(string vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i].compare(vector[j]) < 0) {
                string aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
LARGE_INTEGER freq;
QueryPerformanceFrequency(&freq);
return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
int main (){
	srand(time(NULL));
	LARGE_INTEGER t_ini, t_fin;
    double secs;
	const int max=20;
	double vec[max];
	valores_alatorios(vec,max);
	cout<<"////////////////"<<endl;
	cout<<"el mayor de los numeros es "<<ma_vector(vec,max)<<endl;
	cout<<"el menor de los numeros es "<<mi_vector(vec,max)<<endl;
	cout<<"////////////////"<<endl;
	
	double a, b;
    cout << endl << "Max y min por referencia: "<<endl;
    maximo_min(vec, max, a, b);
	cout<<"Mayor encontrado: "<<a<<endl;
	cout<<"Menor encontrado: "<<b<<endl;
	cout<<"////////////////"<<endl;
	cout<<"Vectores Desordenados: "<<endl;
	imprimir_vector(vec,max);
	cout<<"Orden de Vectores: "<<endl;
	orden_secuencial(vec,max);
	imprimir_vector(vec,max);
	cout<<"////////////////"<<endl;
   	//Buscar elemento en el vector
    int y=vec[11]=23;
    if(verdadero_falso(vec, max, y))
    {
        cout<<endl<<"El elemento "<<y<<" si existe...";
    }
    else
    {
        cout<<endl<<"El elemento "<<y<<" no existe...";
    }
    int pos=pocision(vec,max,y);
    if(pos==-1)
        cout<<endl<<"No existe el elemento "<<y<<" en el vector...";
    else
        cout<<endl<<"El elemento "<<y<<" existe en la posicion: "<<pos<<endl;
    const int maxx=20;
	double num[maxx];
	int rep=12;
	srand(time(NULL));
	valores_alatorios1(num,maxx);
	imprimir_vectores(num,maxx);
	int x=repetido(num,maxx,rep);
    if(x>1)
        cout<<endl<<"El elemento "<<rep<<" se repite "<<x<<" veces"<<endl;
    else
        cout<<endl<<"El elemento "<<rep<<" no se repite mas que 1 vez"<<endl;
    cout<<"odernacion desendente"<<endl;
	decendente(num,maxx);
	imprimir_vectores(num, maxx);
	    QueryPerformanceCounter(&t_ini);
    decendente(num,maxx);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"\nORDENACION SECUENCIAL: Tiempo EJECUCION en ms: "<<(secs*1000.0);   
     int tam=6;

     string nombre[tam] = {"Juan","Antonio","Carlos","Martha","Pedro","Amalia"};
	cout<<endl<<endl<<"Vectore de nombres";
	for (int k=0;k<tam;k++){
		cout<<endl<<nombre[k];
	}
	string nombres[tam] = {"Juan", "Antonio","Carlos","Martha","Pedro","Amalia"};
    cout<<endl<<endl<<"Vector de nombres";
    nombrevector(nombres,tam);
    cout<<endl<<endl<<"Orden de manera descendente"<<endl;
    ordenar_nombres(nombres,tam);
    nombrevector(nombres,tam);
return 0;
}
