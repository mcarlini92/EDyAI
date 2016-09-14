#include <stdio.h>
#include <stdlib.h>

// Originalmente se daran el peso/valor en enteros pero como luego pueden ser particionados, uso float 
typedef struct {
	float peso;
    float valor;
} Objeto;

int CmpFunc(const void *p, const void *q) { // Funcion analiza el valor de un objeto segun la relacion valor/peso del objeto ... el peso nunca puede ser 0 (ni el la Luna)
	Objeto *fst = (Objeto *)p;
	Objeto *snd = (Objeto *)q;
	if ((fst->valor)/fst->peso) > (snd->valor)/snd->peso) 
		return 1;
	else if ((fst->valor)/fst->peso) = (snd->valor)/snd->peso) 
		return 0;
	else ((fst->valor)/fst->peso) < (snd->valor)/snd->peso)
		return -1;
}

Objeto *solve(Objeto *ptr, int sz, int szW){ // ptr = premochila , szT = peso actual en mochila , sz = cant de objetos , szW Resistencia mochila
	int i, szT = 0;
	Objeto *mochila;
	mochila = malloc(szW * sizeof(Objeto));
	qsort(ptr, sz, sizeof(Objeto), CmpFunc);
	for(i=0; szT+(ptr[i].peso)<=szW && i<sz; i++) {	 // mientras el peso actual sea menor al soportado y todavia tenga objetos
		mochila[i] = ptr[i];
		szT+=ptr[i].peso
	} // al terminar este bucle, i representa un objeto que no existe (i>sz) o que no puede ser agregado de forma completa la mochila ((szT+(ptr[i].peso)) > szW)
	if(szT == szW || i = sz) // Si ya me quede sin objetos (i>sz) o ya estoy en el limite de la resist de la mochila 
		return mochila;
		
	/* Parte de codigo para rellenar la mochila con una fraccion del objeto que no entra de forma completa. El peso nuevo sera lo que me falta para completar lo mochila, o sea, szW-szT y el valor sera la resolucion a la una regla de 3 simple que tendra la siguiente forma
	
	ptr[i].peso ----------- ptr[i].valor
	mochila[i].peso ---------------	 X = ((mochila[i].peso)*(ptr[i].valor))/(ptr[i].peso)

	Ejemplo : Si mi mochila es de 100kg, llevo ocupados 90kg (me falta 10kg) y el proximo objeto (segun qsort) a insertar tiene un peso de 50kg y un valor de $20, solamente necesito 10kg de el -> Peso del ultimo objeto: 10kg. Ahora, cuanto es el valor ? Para saberlo, necesitamos resolver la regla de tres simple
	50 kg ------ $20
	10 kg ------  X = $4 
	Por lo tanto, el ultimo objeto que se insertará en la mochila tendra Peso: 10kg y Valor: $4
	*/
	
	mochila[i].peso = szW - szT;
	mochila[i].valor = ((mochila[i].peso)*(ptr[i].valor))/(ptr[i].peso);    
	
	return mochila;
}

int main(void) {
	int cantobj, W, i;
	Objeto *premochila;
	scanf("Cantidad objetos %d", &cantobj);
	scanf("Resistencia mochila (entero>0) %d", &W);
	premochila = malloc(cantobj * sizeof(Objeto));
	for (i = 0; i < cantobj; i++) 
		scanf("Peso %d Valor %d",&premochila[i].peso, &premochila[i].valor);
	solve(premochila, cantobj, W);
	return 0;
}

// No puede ser extendido al problema Mochila 1-0 ya que en este ultimo podemos tomar una fraccion del objeto, con lo cual siempre existira una solucion y en el problema original como siempre deben ser tomados de forma completa, puede ser que no exista solucion (El peso de cualquier objeto es mayor a la resist de la mochila)