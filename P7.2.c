#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CARACTERES 50

typedef struct {
	char nombre[MAX_CARACTERES];
	char apellido[MAX_CARACTERES];
	int nota;
} Estudiante;

void Inicializar_Estudiante(Estudiante * Inicializar, const char * Nombre, const char * Apellido, const int Nota){
	strcpy(Inicializar -> nombre, Nombre);
	strcpy(Inicializar -> apellido, Apellido);
	Inicializar -> nota = Nota;
}

void Agregar_Estudiante(Estudiante * Agregar, const int cantidad){
	int nota;
	char nombre[MAX_CARACTERES], apellido[MAX_CARACTERES];
	
	for (int i = 0; i < cantidad; ++i){
		getchar();
		
		printf("Nombre: ");
		fgets(nombre, MAX_CARACTERES, stdin);
		nombre[strlen(nombre)-1] = '\0';
		
		printf("Apellido: ");
		fgets(apellido, MAX_CARACTERES, stdin);
		apellido[strlen(apellido)-1] = '\0';
		
		printf("Nota: ");
		scanf("%d", &nota);
		
		Inicializar_Estudiante(&Agregar[i], nombre, apellido, nota);

		puts("");
	}
}

void Imprimir_Clase(Estudiante * Imprimir, int const cantidad){
	for(int i = 0; i < cantidad; i++, Imprimir++){
		printf("%s, %s, %d.\n",Imprimir->nombre, Imprimir->apellido, Imprimir->nota);
	}
}

bool Burbuja(Estudiante * Clase, const int cantidad){
	int guardado;
	int intercambios = 0;
	
	do{
		intercambios = 0;

		for(int k = 0; k < cantidad - 1; k++){
			if(Clase[k].nota > Clase[k+1].nota){
				guardado = Clase[k].nota;
				Clase[k].nota = Clase[k+1].nota;
				Clase[k+1].nota = guardado;
				intercambios++;
			}
			else{
				continue;
			}
		}
	}
	while(intercambios != 0);

	return true;
}

bool Burbuja_Caracteres(Estudiante * Clase, const int cantidad){
	Estudiante guardado;
	int intercambios = 0;
	
	do{
		intercambios = 0;

		for(int k = 0; k < cantidad - 1; k++){
			for(int l = 0; l < MAX_CARACTERES; l++){
				if(strncmp((*(&Clase[k] -> apellido)) + l, (*(&Clase[k+1].apellido)) + l, MAX_CARACTERES) != 0){
					memcpy(&guardado, &Clase[k+1], sizeof(Estudiante)); // Esto no funciona guardado[0] = Clase[0];. Hay que usar memcpy. TODO: 
					memcpy(&Clase[k], &Clase[k+1], sizeof(Estudiante));
					memcpy(&Clase[k+1], &guardado, sizeof(Estudiante));
					intercambios++;
				}
				else{
					continue;
				}
			}
		}

	}
	while(intercambios != 0);

	return true;
}

int main(){
	
	int cantidad;

	puts("¿Que cantidad de estudiantes quieres procesar?");
	scanf("%d", &cantidad);

	Estudiante * Clase = (Estudiante *)malloc(cantidad * sizeof(Estudiante));

	Agregar_Estudiante(Clase, cantidad);

/*
	puts("Estos son los estudiantes que hay en la clase:");
	Imprimir_Clase(Clase,cantidad);

	Burbuja(Clase, cantidad);
	
	printf("\n");

	puts("Estos son los estudiantes ordenador por nota:");
	Imprimir_Clase(Clase, cantidad);
*/
	Burbuja_Caracteres(Clase, cantidad);

	puts("Estos son los estudiantes ordenador por apellido:");
	Imprimir_Clase(Clase, cantidad);

	free(Clase);

	return 0;
}
