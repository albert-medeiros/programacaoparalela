#include <stdlib.h>
#include <stdio.h>

//biblioteca OpenMP
#include <omp.h>

int main(){

    char palavra[15];
    int numeroDeThreads=4, quantidade=0,numeroDaThread=5,totalDeThreads=5;

    printf("\n\nBem Vindo:\n\n");
    printf("Digite a palavra que deseja buscar no arquivo: ");
    scanf("%s", &palavra);
    printf("\n ----- \n");
    printf("A palavra que você deseja procurar é a: %s\n\n\n", palavra);
    
    #pragma omp parallel
    {

		numeroDaThread = omp_get_thread_num();
		totalDeThreads = omp_get_num_threads();

		printf("Olá, mundo! Mensagem da thread %i de %i threads\n", numeroDaThread, totalDeThreads);	
	}
    

}