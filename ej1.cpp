#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include<stdbool.h>
using namespace std;
const int N=6;
struct pila{
    private:
    int tope=-1;
    int *ptr=&tope; // tope de la pila.
    int arreglo[N]; //arreglo de tipo de dato entero.
    
    public: //metodos para acceder al arreglo de datos de la pila.
    bool pilaVacia(){   //return true si esta vacia.
        return (tope==-1);
    }
    bool pilaLlena(){   //return true si esta llena.
        return(tope==N-1);
    }
    bool push(int var){ //agrega un elemento a la pila.
        if(!pilaLlena()){
            tope++;
            arreglo[tope]=var;
        }
        return(!pilaLlena());
    }
    bool pop(){         //elimina un elemento de la pila.
        if(!pilaVacia()){
            tope--;
        }
        return(!pilaVacia());
    }
    int  verTope(){      //retorna el elemento que esta en el tope de la pila.
        return(arreglo[tope]);
    }
    int obtenerTope(){  //devuelve el indice del tope.
        return tope;
    }
};
//void fun(int *arreglo){
//    *arreglo= *arreglo+2;
//}
struct pilaEnteros{
    public:
    void cargaPila(pila &pA, int var){
        if(!pA.pilaLlena()){
           pA.push(var);
            
        }
    }
    void pasaPila(pila pA, pila &pB){ 
        while(!pA.pilaVacia()){
            pB.push(pA.verTope());
            pA.pop();
        }
    }
    void mostrarPila(pila p){ // testing
        int flag= p.obtenerTope();
        for (int i=0; i<N;i++){
            if(i<=flag){
                cout<<p.verTope()<<endl;
            p.pop();
            }
        }
    }
    bool contieneE(pila &pA, int n){
        pila aux;
        bool flag;
        for(int i=0; i<N;i++){
            aux.push(pA.verTope());
            if(flag==false){
                flag=(pA.verTope()==n);
            }
            pA.pop();
        }
        for (int j=0;j<N;j++){
            pA.push(aux.verTope());
            aux.pop();
        }
        return flag;
    }
    void separaPi(pila &pA, pila &pB, pila &pC){ 
        while (!pA.pilaVacia()){
            if((pA.verTope()%2)==0){
                pB.push(pA.verTope());
                pA.pop();
            }else{
                pC.push(pA.verTope());
                pA.pop();
            }
        }
    }
    void invierte1(pila &pA, pila &pB){
        pila aux;
        int i=0;
        int flag=pA.obtenerTope();
        while(!pA.pilaVacia()){
            i++;
           if(i<=flag){
            aux.push(pA.verTope());
            pA.pop();
           }
        }
        for(int j=0; j<N; j++){
            pB.push(aux.verTope());
            aux.pop();
        }

    }
    void invierte2(){
        
    }

};


int main(){ 
  pila pA;
  pila pB;
  pila pC;
  pilaEnteros p;
  int var, n;
    for(int j=0;j<N;j++){
        cout<<"Ingrese un num."<<endl;
        cin>>var;
         p.cargaPila(pA, var);
    }
    cout<<"Ingrese un valor a buscar en pila A."<<endl;
    cin>>n;
    cout<<"Contiene el valor? "<<endl;
    cout<<p.contieneE(pA, n)<<endl;
    cout<<"Pila A ordenada en orden de recuperacion normal."<<endl;
    p.mostrarPila(pA);
    p.pasaPila(pA, pB);
    cout<<"Pila B con la pila A orden de vaciado de pila A."<<endl;
    p.mostrarPila(pB);
    for(int j=0;j<N;j++){
        cout<<"Ingrese un num."<<endl;
        cin>>var;
         p.cargaPila(pA, var);
    }
    for(int j=0;j<N;j++){   //reinicia pila B
        pB.pop();
    }
    p.separaPi(pA, pB, pC);
    cout<<"Pila B Pares."<<endl;
    p.mostrarPila(pB);
    cout<<"Pila C Impares"<<endl;
    p.mostrarPila(pC);
    for(int j=0;j<N;j++){   //reinicia pila B
        pB.pop();
    }
    for(int j=0;j<N;j++){
        cout<<"Ingrese un num."<<endl;
        cin>>var;
         p.cargaPila(pA, var);
    }
    cout<<"pila B invertida(orden normal de salida.)"<<endl; ///demora en ejecutarse unos segundos.
    p.invierte1(pA, pB);
    p.mostrarPila(pB);

    return 0;
}