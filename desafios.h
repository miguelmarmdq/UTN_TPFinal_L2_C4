#ifndef DESAFIOS_H_INCLUDED
#define DESAFIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idDesafio;
    char tipoDesafio;
    char descripcionDesafio[100];
    int puntosDesafio;
    int vidaBase;
    int ataqueBase;
    char preguntaProxDesafio[100];
    int desafioEliminado;
}STdesafio;

typedef struct{
    STdesafio desafio;
    struct nodoArbolDesa*izquierda;
    struct nodoArbolDesa*derecha;
}nodoArbolDesa;


nodoArbolDesa*inicArbolDesafio();
nodoArbolDesa*crearNodoArbolDesafio(STdesafio desafio);
nodoArbolDesa*insertarNodoArbolDesafio(nodoArbolDesa*arbol,STdesafio desafio);
void mostrarNodoArbolDesafio(nodoArbolDesa*arbol);
void listarArbolDesafio(nodoArbolDesa*arbol);


#endif // DESAFIOS_H_INCLUDED
