#include <stdlib.h>
#include <stdio.h>

//biblioteca OpenMP
#include <omp.h>

void ler(int *fimLeitura){

    printf("entrou aqui!");
    char letra;

    FILE *arquivo;
     printf("entrou aqui e aqui!");
    arquivo = fopen('/Documentos/OpenMp-Albert/arquivo.txt', "r");
    if(arquivo == NULL)
         printf("Erro, nao foi possivel abrir o arquivo\n");
    else
     while(letra=fgetc(arquivo) != EOF){
         if(letra == "á"){
             printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
         }
     };
    
    fimLeitura=1;
    fclose(arquivo);
    
}

main(){

    char palavra[15];
    int numeroDeThreads=4, quantidade=0,numeroDaThread=-1,totalDeThreads=-1, fimLeitura=-1;

    printf("\n\nBem Vindo:\n\n");
    printf("Digite a palavra que deseja buscar no arquivo: ");
    scanf("%s", &palavra);
    printf("\n ----- \n");
    printf("A palavra que você deseja procurar é a: %s\n\n\n", palavra);
    
    #pragma omp parallel
    {
		numeroDaThread = omp_get_thread_num();
 
        if(numeroDaThread == 0){
            if(fimLeitura != 1){
                ler(&fimLeitura);
            }
        }

		totalDeThreads = omp_get_num_threads();

		printf("thread %i de %i threads\n", numeroDaThread, totalDeThreads);	
	}
    

}