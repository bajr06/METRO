#include <stdio.h>
#include <stdlib.h>

// Función para mirar si el número introducido es primo o no
int primo(int numero){
    if(numero < 2) return 0; // no es primo

    for(int i = 2; i < numero; i++){ // miramos a ver si el número es divisible por 2, ya que los primos son impares
        if (numero % i == 0) return 0; // no es primo si el número es divisible por i
    }

    return 1; // los números restantes son primos
}

int main(){
    int numero;
    int recuento = 0; // para contar cuantos números primos hay

    printf("Introduce un número en donde te enseñaré que primos hay menores a él (o si él es un primo se incluirá): ");
    scanf("%d", &numero);

    // Lo hacemos a través de memoria dinámica para almacenar los números primos
    int * memoria = (int*) malloc (numero * sizeof(int));
    if(memoria == NULL){ // comprobamos si hay memoria disponible y de no ser así, salir del programa
        printf("Error, no hay memoria");
        return EXIT_FAILURE;
    }

    for(int i = 2; i <= numero; i++){ 
        if(primo(i)){ // aquí es en donde pasamos "el filtro" llamando a la función de arriba para comprobar los números primos
            memoria[recuento++] = i; // almacenamos en el array los n.p, sumamos 1 por cada primo y lo igualamos 
        }
    }

    // imprimimos los números primos
    printf("Los números primos - o = a %d son: ", numero);
    for (int i = 0; i < recuento; i++) {
        printf("%d ", memoria[i]); // lo imprimimos a través del array para asegurarnos de que se han guardado correctamente
    }
    printf("\n");

    free(memoria);
    return EXIT_SUCCESS;
}