#ifndef USUARIOS_H_INCLUDED
#define USUARIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idUsuario;
    char nombreUsuario[30];
    char contraUsuario[15];
    char categoriaUsuario;
    int vidaBaseUsuario;
    int ataqueBaseUsuario;
    int puntajeUsuario;
    int usuarioEliminado;
}usuario;







#endif // USUARIOS_H_INCLUDED
