#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PAL 50 

// Funcion recursiva para verificar si una palabra es un palindromo
bool Buscar_Letras(const char *str, int ini, int fin) {
    
    if (ini >= fin) // Caso base: si los indices se cruzan, es un palíndromo
        return true;
    
    if (str[ini] != str[fin]) // Si los caracteres no coinciden, no es palindromo
        return false;

    return Buscar_Letras(str, ini + 1, fin - 1); // Llamada recursiva con los siguientes caracteres
}

int main(){
    
    char * palabra = (char *)malloc(MAX_PAL*sizeof(char)); // Resrva memoria para la palabra

    if(palabra == NULL){ // Verifica si la memoria fue asignada correctamente
        printf("ERROR\n");
        return EXIT_FAILURE; 
    }

    printf("Introduce una palabra: ");
    scanf("%s", palabra);
    
    int len = strlen(palabra); // Calcula la longitud de la palabra
    
    // Llama a la función para verificar si la palabra es un palíndromo
    if (Buscar_Letras(palabra, 0, len - 1)){
        printf("%s es palindroma.\n", palabra);
    }else{ //Si devuelve verdadero es palindroma si devuelve otra cosa no es palindroma
        printf("%s no es palindroma.\n", palabra);
    }
    
    free(palabra); // Libera la memoria

    return 0;
}

