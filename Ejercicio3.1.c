#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMENSION 10

// Estructura para almacenar coordenadas del jugador
typedef struct {
    int fila, columna;
} Coordenada;

// Funcion para inicializar el tablero con bordes y colocar al jugador en el centro
void configurarTablero(char **matriz, int alto, int ancho, Coordenada *posicion);

// Funcion para imprimir el tablero en la consola
void mostrarTablero(char **matriz, int alto, int ancho);

// Funcion para mover al jugador en el tablero según la tecla presionada
void desplazar(char **matriz, int alto, int ancho, Coordenada *posicion, char movimiento);

int main() {
    int alto = DIMENSION, ancho = DIMENSION;

    // Asignar memoria para el tablero
    char **matriz = malloc(alto * sizeof(char *));
    if (matriz == NULL) {
        printf("Error de memoria\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < alto; i++) {
        matriz[i] = malloc(ancho * sizeof(char));
        if (matriz[i] == NULL) {
            printf("Error de memoria en la fila %d\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return EXIT_FAILURE;
        }
    }
   
    Coordenada posicion;
    configurarTablero(matriz, alto, ancho, &posicion);

    char tecla;
    do {
        mostrarTablero(matriz, alto, ancho);
        printf("Mueve con 'w', 'a', 's', 'd' o presiona 'x' para salir: ");
        scanf(" %c", &tecla); //Guardamos la tecla dada por el usuario
        desplazar(matriz, alto, ancho, &posicion, tecla);
    } while (tecla != 'x');

    free(matriz);
    return 0;
}

// Funcion para inicializar el tablero con bordes y colocar al jugador en el centro
void configurarTablero(char **matriz, int alto, int ancho, Coordenada *posicion) {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                matriz[i][j] = '#'; // Bordes del tablero
            } else {
                matriz[i][j] = ' '; // Espacios vacíos dentro del tablero
            }
        }
    }
    // Colocar al jugador en el centro del tablero
    posicion->fila = alto / 2;
    posicion->columna = ancho / 2;
    matriz[posicion->fila][posicion->columna] = '@';
}

// Funcion para imprimir el tablero en la consola
void mostrarTablero(char **matriz, int alto, int ancho) {
    for (int i = 0; i < alto; i++) {
        for (int j = 0; j < ancho; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Funcion para mover al jugador en el tablero según la tecla presionada
void desplazar(char **matriz, int alto, int ancho, Coordenada *posicion, char movimiento) {
    int nuevaFila = posicion->fila;
    int nuevaColumna = posicion->columna;

    // Determinar la dirección del movimiento
    switch (movimiento) {
        case 'w': nuevaFila--; break; // Arriba
        case 's': nuevaFila++; break; // Abajo
        case 'a': nuevaColumna--; break; // Izquierda
        case 'd': nuevaColumna++; break; // Derecha
        default: return;
    }
   
    // Verificar que el nuevo movimiento sea valido (dentro de los limites)
    if (nuevaFila > 0 && nuevaFila < alto - 1 && nuevaColumna > 0 && nuevaColumna < ancho - 1) {
        matriz[posicion->fila][posicion->columna] = ' '; // Borrar posicion anterior
        posicion->fila = nuevaFila;
        posicion->columna = nuevaColumna;
        matriz[posicion->fila][posicion->columna] = '@'; // Colocar jugador en nueva posición
    }
}
