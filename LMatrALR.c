#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv){

	FILE *archivo;
	int ren = atoi(argv[5]); // Numero del renglón
	int col = atoi(argv[6]); // Numero de la columna 
	int Res[atoi(argv[3])][atoi(argv[4])]; // Matriz de resultados de 2 * 2
	int MatrizAuxiliar1[atoi(argv[3])][atoi(argv[4])]; // Matriz de 2  * 2 
	int MatrizAuxiliar2[atoi(argv[3])][atoi(argv[4])]; // Matriz de 2 * 2
	int tamR = atoi(argv[3]);
	int tamC = atoi(argv[4]);

	printf("%d\n", ren);
	printf("%d\n", col);
	printf("%d\n", tamR);
	printf("%d\n", tamC);



	archivo = fopen(argv[1] , "r"); // Abrimos el archivo en modo lectura;
	char f;
	char salto = '\n';

	if(archivo == NULL){
		printf("Lo sentimos, el archivo no ha sido encontrado");
	}
	
	int i = 0, j = 0;
	while(1){
		f = fgetc(archivo);
		if(f == EOF){
			break;
		}
		else if(f == ' '){
			continue;
		}
		else if(f == salto){
			continue;
		}
		else if(f < '0'){
			continue;
		}
		if(j == ren){
			j = 0;
			i++;
		}
		printf("%c", f);
		MatrizAuxiliar1[i][j] = (f - '0');
		j++;
	}

	archivo = fopen(argv[2], "r");
	if(archivo == NULL){
                printf("Lo sentimos, el archivo no ha sido encontrado");
       	 }
	 i = 0;
	 j = 0;
	while(1){
	 f = fgetc(archivo);
	 if(f == EOF){
		 break;
	 } 
	 else if(f == ' '){
		 continue;
	 }
	 else if(f == salto){
		 continue;
	 }
	 else if(f < '0'){
		 continue;
	 }
	 if(j == ren){
		 j = 0;
		 i++;
	 }

	 MatrizAuxiliar2[i][j] = (f - '0');
	 j++;
	}
	int res;
	for(i = 0 ; i < tamC ; i++){
		for(j = 0; j < tamR; j++){
		
			Res[i][j] += MatrizAuxiliar1[col][j] * MatrizAuxiliar2[i][ren];
			res = Res[i][j];
		}
	}
	exit(res);

}
