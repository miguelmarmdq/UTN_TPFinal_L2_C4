#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#include "desafios.h"

#define MIN_DADOS 2
#define MAX_DADOS 12


char pelear(usuario jugador,nodoArbolDesa*desafio){ ///al usuario jugador hay que cambiarlo por nodo*jugador
    int danio;
    char resultPelea=' ';
    int respuesta=0;
    printf("---------------------------------------------------------\n");
    printf("%s\n\n",desafio->desafio.descripcionDesafio);
    printf("---------------------------------------------------------\n");
    while(resultPelea==' '){
        printf("Vida: %d\n",jugador.vidaBaseUsuario);
        printf("Vida Enemigo: %d\n",desafio->desafio.vidaBase);
        printf("\n1.Atacar\n2.Huir\nElige una accion: ");
        fflush(stdin);
        scanf("%d",&respuesta);
        if(respuesta==1){
            /// Ataca Jugador
            danio=calculoDanio(jugador.ataqueBaseUsuario);
            desafio->desafio.vidaBase=desafio->desafio.vidaBase-danio;
            if(desafio->desafio.vidaBase>0){
                printf("\nEs el turno de tu enemigo\n");
                system("pause");
                /// Ataca Enemigo
                danio=calculoDanio(desafio->desafio.ataqueBase);
                jugador.vidaBaseUsuario=jugador.vidaBaseUsuario-danio;
            }
            if(desafio->desafio.vidaBase<=0){
                resultPelea='V';    /// Salio Vivo de la pelea
            }
            if(jugador.vidaBaseUsuario<=0){
                resultPelea='M';    /// Salio Muerto de la paelea
            }
        }else{
            resultPelea='H';    /// Decidio Huir
        }
    }
    return resultPelea;
}

int calculoDanio(int ataqueBase){
    int dados=rand () % (MAX_DADOS-MIN_DADOS+1) + MIN_DADOS;
    printf("\nEl resultado de los dados es: %d\n",dados);
    int total=dados*ataqueBase;
    printf("El danio total es: %d\n\n",total);
    return total;
}

void jugar(usuario jugador,nodoArbolDesa*desafio){
    char resultPelea;
    int camino;
    if(desafio!=NULL){
        switch(desafio->desafio.tipoDesafio){
            case 'P':       ///Pelea
                resultPelea=pelear(jugador,desafio);
                switch(resultPelea){
                    case 'V':    ///Salio vivo
                        if(desafio->derecha!=NULL || desafio->izquierda!=NULL){
                            printf("%s\n",desafio->desafio.preguntaProxDesafio);
                            fflush(stdin);
                            scanf("%d",&camino);
                            if(camino==1){
                                jugar(jugador,desafio->derecha);
                            }else{
                                jugar(jugador,desafio->izquierda);
                            }
                        }
                        break;
                    case 'M':
                        printf("MORISTE\n");
                        return;
                        break;
                    case 'H':
                        printf("Huiste cagon\n");
                        return;
                        break;
                }
                break;
            case 'R':
                printf("Recibiste una recompensa");
                printf("%s\n",desafio->desafio.preguntaProxDesafio);
                fflush(stdin);
                scanf("%d",&camino);
                if(camino==1){
                    jugar(jugador,desafio->derecha);
                }else{
                    jugar(jugador,desafio->izquierda);
                }
                break;
        }
    }else{
        printf("\n\n---------GANASTE---------\n\n");
    }
}


int main()
{
    srand(time(NULL));  /// planto semilla para los dados.
    usuario user;
    STdesafio desafio;
    nodoArbolDesa*arbolDesa=inicArbolDesafio();  ///arbol desafio


    /// --- OJOOO, usuario harcodeado -----
    user.idUsuario=1;
    strcpy(user.nombreUsuario,"user1");
    strcpy(user.contraUsuario,"contra1");
    user.categoriaUsuario='J';
    user.vidaBaseUsuario=1000;
    user.ataqueBaseUsuario=10;
    user.puntajeUsuario=0;
    user.usuarioEliminado=0;

    /// --- OJOOO, desafios harcodeados -----
    desafio.idDesafio=4;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra el socialismo...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=100;
    desafio.ataqueBase=10;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=2;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra el comunismo...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=100;
    desafio.ataqueBase=10;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=1;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra Carlos Menem (Final Boss)...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=200;
    desafio.ataqueBase=12;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=3;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra Carlos Menem (Final Boss)...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=200;
    desafio.ataqueBase=12;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=6;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra el comunismo...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=100;
    desafio.ataqueBase=10;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=5;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra Carlos Menem (Final Boss)...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=200;
    desafio.ataqueBase=12;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    desafio.idDesafio=7;
    desafio.tipoDesafio='P';
    strcpy(desafio.descripcionDesafio,"Te toca pelear contra XXXXXXXXXXXX (Final Boss)...\n");
    desafio.puntosDesafio=50;
    desafio.vidaBase=200;
    desafio.ataqueBase=12;
    strcpy(desafio.preguntaProxDesafio,"1.derecha\n2.izquierda\n\n");
    desafio.desafioEliminado=0;

    arbolDesa=insertarNodoArbolDesafio(arbolDesa,desafio);

    ///listarArbolDesafio(arbolDesa);

    /// ------------------------------------------------------


//    char respuestaPelea=pelear(user,arbolDesa);
//    printf("%c",respuestaPelea);

    jugar(user,arbolDesa);
    return 0;
}
