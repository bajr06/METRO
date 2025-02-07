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

void Inicializar_Estudiante(Estudiante * Inicializar, const char * Nombre, const char * Apellido, const int Nota); 

void Agregar_Estudiante(Estudiante * Agregar, const int cantidad);

void Imprimir_Clase(Estudiante * Imprimir, int const cantidad);

bool Burbuja(Estudiante * Clase, const int cantidad);

bool Burbuja_Caracteres(Estudiante * Clase, const int cantidad);

int main(){
	int cantidad, control;

	puts("¿Que cantidad de estudiantes quieres procesar?");
	control = scanf("%d", &cantidad);
		if(cantidad <= 0 || control == 0){ // compruebo que el número sea positivo y además, como el scanf me devuelve un 1 si introduzco un número, igualo control a 0 indicando que ese valor no es un nº
			printf("Debes introducir un número positivo\n");
			return EXIT_FAILURE;
		}

	Estudiante * Clase = (Estudiante *)malloc(cantidad * sizeof(Estudiante));
	if(Clase == NULL){ // comprobamos si hay memoria disponible y de no ser así, salir del programa
        printf("Error, no hay memoria");
        return EXIT_FAILURE;
    }

	Agregar_Estudiante(Clase, cantidad); // llamamos a nuestra función para introducir nuestros datos de los alumnos

	puts("Estos son los estudiantes que hay en la clase:");
	Imprimir_Clase(Clase,cantidad); // los imprimimos todos como "clase"

	Burbuja(Clase, cantidad); // hacemos las modificaciones para ordenarlos por nota y por apellido
	
	printf("\n");

	puts("Estos son los estudiantes ordenador por nota:");
	Imprimir_Clase(Clase, cantidad);
	Burbuja_Caracteres(Clase, cantidad);

	puts("");

	puts("Estos son los estudiantes ordenador por apellido:");
	Imprimir_Clase(Clase, cantidad);

	free(Clase);

	return 0;
}


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
		int control = 0;
		
		printf("Nombre: ");
		fgets(nombre, MAX_CARACTERES, stdin); // el problema de esto es que también incluye, aparte del nombre, el \n que hacemos al darle a intro para introducir la nota
		nombre[strlen(nombre)-1] = '\0'; // por lo que aquí restamos ese \n y lo sustituimos por \0 para indicar el final de la cadena de caracteres
		
		printf("Apellido: "); // aquí igual que con el nombre
		fgets(apellido, MAX_CARACTERES, stdin);
		apellido[strlen(apellido)-1] = '\0';
		
		printf("Nota: ");
		control = scanf("%d", &nota);
		if(nota <= 0 || control == 0){ // compruebo que el número sea positivo y además, como el scanf me devuelve un 1 si introduzco un número, igualo control a 0 indicando que ese valor no es un nº
			printf("Debes introducir un número positivo\n");
			exit(EXIT_FAILURE);
		}
		
		Inicializar_Estudiante(&Agregar[i], nombre, apellido, nota);

		puts("");
	}
}

void Imprimir_Clase(Estudiante * Imprimir, int const cantidad){
	for(int i = 0; i < cantidad; i++, Imprimir++){
		printf("%s, %s, %d.\n",Imprimir->nombre, Imprimir->apellido, Imprimir->nota); // apuntamos al puntero que tiene almacenado los datos de los estudiantes con ->
	}
}

bool Burbuja(Estudiante * Clase, const int cantidad){
	int guardado;
	int intercambios = 0;
	
	do{
		intercambios = 0; // reiniciamos el contador en cada vuelta

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
	} while(intercambios != 0);
	return true;
}

bool Burbuja_Caracteres(Estudiante * Clase, const int cantidad){
	Estudiante guardado;
	int intercambios = 0;
	
	do{
		intercambios = 0;
		for(int k = 0; k < cantidad - 1; k++){ // Posicion del estudiante. 
			if(strncmp(Clase[k].apellido, Clase[k+1].apellido, MAX_CARACTERES) > 0){
				memcpy(&guardado, &Clase[k], sizeof(Estudiante));
				memcpy(&Clase[k], &Clase[k+1], sizeof(Estudiante));
				memcpy(&Clase[k+1], &guardado, sizeof(Estudiante));
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
