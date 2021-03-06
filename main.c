#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//biblioteca OpenMP
#include <omp.h>

void ler(int *fimLeitura){

    printf("entrou aqui!\n\n");
    char letra;

    FILE *arquivo;
    printf("entrou aqui e aqui!\n\n");
    arquivo = fopen("/home/tebla/Documentos/OpenMp-Albert/arquivo.txt", "r");

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }         
    else{
        //printf("\n\n\t entrou no Else\n");
        while(feof(arquivo) == 0){
            fscanf(arquivo, "%c", &letra);
            printf("\n\t >>>letra: %c", letra);
           // printf("\n\twhile agora que entrou -----------<<<<<\n\n");
                if(letra == "á"){
                    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
                }
        }
    }
    
    
    *fimLeitura=1;
    printf("\n----->   FimLeitura: %d\n\n", *fimLeitura);
    fclose(arquivo);
    
}

main(){

    setlocale(LC_ALL, "Portuguese");

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
        totalDeThreads = omp_get_num_threads();
        

        if(numeroDaThread == 0){
            printf("\n\t\t\tFimLEITURA _ %d\n", fimLeitura);
            if(fimLeitura != 1){
                ler(&fimLeitura);
            }
        }

        printf("thread %i de %i threads\n", numeroDaThread, totalDeThreads);
        
       

		
	}
    //printf("\n\n\n- FimLeitura: ' %d ' -\n\n", fimLeitura);
    printf("\n\n\n- FIM -\n\n");
}