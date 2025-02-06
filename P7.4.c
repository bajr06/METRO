#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PAL 50 

bool Buscar_Letras(const char *str, int ini, int fin) {

    if (ini >= fin) 
        return true;
    
    if (str[ini] != str[fin]) 
        return false;

    return Buscar_Letras(str, ini + 1, fin - 1);
}

int Tamagno_Palabra(const char *str) {
    
    int len = strlen(str);
    return Buscar_Letras(str, 0, len - 1);
}

int main(){
    
    char * palabra = (char *)malloc(MAX_PAL*sizeof(char));

    if(palabra == NULL){ //Verifdicamos que el catalogo no sea nullo
        printf("ERROR\n");
        return EXIT_FAILURE; //en caso de que este sea null, devolvera un error y terminara el programa
    }

    printf("Introduce una palabra:");
    scanf("%s", palabra);

    if (Tamagno_Palabra(palabra)){
        printf("%s es palindroma.\n", palabra);
    }else{
        printf("%s no es palindroma.\n", palabra);
    }
    
    free(palabra);

    return 0;
}
