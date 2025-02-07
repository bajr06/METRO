#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define error(memoria){ \
	if(memoria == NULL){ \
		puts("ERROR: Falta de memoria."); \
		exit(EXIT_FAILURE); \
	} \
} \


void cifrado_cesar (char * clave, const int saltos);

void descifrado_cesar (char * clave, const int saltos);

int main(){
	int cantidad, control;

	puts("¿De cuantos carácteres será tu clave (sumando 2)?");
	control = scanf("%d", &cantidad);
	
	printf("\n");

	if(control == 0){
		printf("Recuerda meter valores enteros, no de otro tipo...\n");
		return EXIT_FAILURE;
	}
	
	char * clave = (char *)malloc(cantidad * sizeof(char));
	error(clave);

	getchar();
	puts("Introduzca la clave:");
	fgets(clave, cantidad, stdin);
	clave[strlen(clave) - 1] = '\0';
	
	puts("");

	int saltos;
	printf("¿De cuantos saltos quieres que sea el cifrado?\n");
	scanf("%d", &saltos);

	printf("\n");

	cifrado_cesar(&clave[0], saltos);

	puts("");

	descifrado_cesar(&clave[0], saltos);

	printf("\n");

	puts("Hasta aqui el cifrado César, ¡Hasta la próxima!");

	free(clave);

	return EXIT_SUCCESS;
}


void cifrado_cesar (char * clave, const int saltos){
	printf("Cadena actual: %s\n", clave);


	for(int i = 0; i < strlen(clave); i++){
		printf("Número [%d]: %d\n", i, clave[i]);
		
		if(clave[i] >= 65 && clave[i] <= 90){
			clave[i] += saltos;
			
			if(clave[i] > 90){
				clave[i] -= 25;
			}
		}
 		else if(clave[i] >= 97 && clave[i] <= 122){
			clave[i] += saltos;

			if(clave[i] > 122){
				clave[i] -= 25;
			}
		}
		else{
			puts("ERROR: No introduzcas cualquier otro caracter que no sea una letra");
			exit(EXIT_FAILURE);	
		}

		printf("Número modificado [%d]: %d\n", i, clave[i]);
	}

	printf("Cadena cifrada: %s\n", clave);
}

void descifrado_cesar (char * clave, const int saltos){
	printf("Cadena actual: %s\n", clave);


	for(int j = 0; j < strlen(clave); j++){
		printf("Número [%d]: %d\n", j, clave[j]);
		
		if(clave[j] >= 65 && clave[j] <= 90){
			clave[j] -= saltos;
			
			if(clave[j] < 65){
				clave[j] += 25;
			}
		}
 		else if(clave[j] >= 97 && clave[j] <= 122){
			clave[j] -= saltos;

			if(clave[j] < 97){
				clave[j] += 25;
			}
		}
		else{
			puts("ERROR: No introduzcas cualquier otro caracter que no sea una letra");
			exit(EXIT_FAILURE);	
		}

		printf("Número modificado [%d]: %d\n", j, clave[j]);
	}

	printf("Cadena descifrada: %s\n", clave);
}
