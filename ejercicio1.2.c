#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Burbuja(const void * n1, const void * n2){	
	return(*(int *)n1 - *(int *)n2);
}

void Anaidir(int * lista, const int cantidad){
	int control;
	
	printf("Escriba cada número a añadir a la lista\n");
	for(int i = 0; i < cantidad; i++){
		control = scanf("%d", &lista[i]);

		if(control == 0){
			printf("Valor inválido\n");
			
			free(lista);

			exit(EXIT_FAILURE);	
		 }
	}
}

void Mostrar(int * lista, const int cantidad){
	for(int j = 0; j < cantidad; j++){
		printf("Número[%d]: %d\n", j, lista[j]);
	}

}


int main(int argc, char ** argv){
	int cantidad, control;

	if(argc == 1){
		printf("¿Qué cantidad de números quieres procesar?\n");
		control = scanf("%d", &cantidad);
		if(cantidad <= 0 || control == 0){ // compruebo que el número sea positivo y además, como el scanf me devuelve un 1 si introduzco un número, igualo control a 0 indicando que ese valor no es un nº
			printf("Debes introducir un número positivo\n");
			return EXIT_FAILURE;
		}

		int * lista = (int *)malloc(cantidad * sizeof(int));

		if(lista == NULL){
			printf("Error, falta de memoria\n");
			return EXIT_FAILURE;
		}

		Anaidir(&lista[0], cantidad);
	
		qsort(lista, cantidad, sizeof(lista[0]), Burbuja);

		Mostrar(&lista[0], cantidad);
		
		free(lista);

		return 0;
	} else if(argc == 3){
		if(strcmp(argv[1], "comparar") == 0){
			cantidad = atoi(argv[2]);

			int * lista = (int *)malloc(cantidad * sizeof(int));

			if(lista == NULL){
				printf("Error, falta de memoria\n");
				return EXIT_FAILURE;
			}

			Anaidir(&lista[0], cantidad);

			qsort(lista, cantidad, sizeof(lista[0]), Burbuja);

			Mostrar(&lista[0], cantidad);

			free(lista);

			return 0;
		}
	} else {
		printf("Inválido\n");
		return EXIT_SUCCESS;
	}
}
