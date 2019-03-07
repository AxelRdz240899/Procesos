#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char *argv){

	int MR[2][2];
	printf("%d\n",MR[0][0]);
	int resultadoRetorno;
	printf("Hola");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			MR[i][j] = fork();
			if(MR[i][j] < 0){
				perror ("No se pudo crear el proceso");
			}
			if(MR[i][j] == 0){
				char is [10], ir[10];
				sprintf(is,"%d", i);
				sprintf(ir,"%d", j);
				char *argumentos = {"MMatr", "M1.txt", "M2.txt", "2" , "2", is,ir,NULL};
				execv(argumentos[0], argumentos);
			}		
		}
	}
	for(int  i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			resultadoRetorno = 0;
			waitpid(MR[i][j],&resultadoRetorno,0);
			MR[i][j] = WEXITSTATUS(resultadoRetorno);
			printf("%d\t",MR[i][j]);
		}
	printf("\n");	
	}
	return 0;
}
