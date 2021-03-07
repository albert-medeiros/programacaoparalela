#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//biblioteca OpenMP
#include <omp.h>
#define max 15

typedef struct TipoPalavra{
    char palavra_salva[max];
}pal;



// int verifica_quantidade_palavras(){


//     printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOi");
//     FILE *arquivo;
//     arquivo = fopen("/home/tebla/Documentos/OpenMp-Albert/arquivo.txt", "r");
//     char palavra;
//     int qnt;
    
//     while(feof(arquivo) == 0){   
//         fscanf(arquivo,"%s",palavra);
//         qnt++;
//     }
    
//     fclose(arquivo);
//     return qnt; 
// }


void ler(int *fimLeitura){

    printf("entrou aqui na função de leitura!\n\n");
    // char *letra[1];
    char carac, palavra[max];

    int tam=0,qnt,j;
    FILE *arquivo,*saida;
    arquivo = fopen("arquivo.txt", "r");
    saida = fopen("lista.txt", "w");
    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }         
    else{
        printf("\nArquivo aberto!\n");
        // while(feof(arquivo) == 0){
        //     fscanf(arquivo, "%c", &letra);
        //     printf("\n\t >>>letra: %s", letra);
        //    // printf("\n\twhile agora que entrou -----------<<<<<\n\n");
        //         if(strcmp(letra,"ã") == 0){
        //             printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        //         }

        // ------------ verificando letras maiúsculas
      
        
        while(feof(arquivo) == 0){   
            j++;   
            // rewind(arquivo);
            fscanf(arquivo,"%s",palavra);
            printf("\nA palavra lida foi a: %s ", palavra);
            for (int i = 0; i < strlen(palavra); i++){
                palavra[i] = tolower(palavra[i]);                
                // if(strcmp(palavra,"á")==0){
                //     printf("\t\t\tAchou um caracter especial");
                // } 
            }
            printf("\nA palavra lida com os carateres minusculo foram foi a: %s ", palavra);
            fprintf(saida,"%s\n",palavra);
            //palvs[j]->palavra_salva = palavra;
            // carac=tolower(palavra);               
            //  printf("\n\t%s",carac);
        }
    }
    
    
    *fimLeitura=1;
    printf("\n----->   FimLeitura: %d\n\n", *fimLeitura);
    // fclose(saida);
    // fclose(arquivo);
    
}

int main(){
    
    setlocale(LC_ALL, "portuguese");
    int qnt=0;    
    
    char palavra[15];
    int numeroDeThreads=4, quantidade=0,numeroDaThread=-1,totalDeThreads=-1, fimLeitura=-1;

    printf("\n\nBem Vindo:\n\n");
    printf("Digite a palavra que deseja buscar no arquivo: ");
    scanf("%s", &palavra);
    printf("\n ----- \n");
    printf("A palavra que você deseja procurar é a: %s\n\n\n", palavra);

   // verifica_quantidade_palavras();
    printf("O arquivo tem %d palavras",qnt);
    
    #pragma omp parallel
    {
		
        numeroDaThread = omp_get_thread_num();
        totalDeThreads = omp_get_num_threads();
        

        if(numeroDaThread == 0){
            //'printf("\n\t\t\tFimLEITURA _ %d\n", fimLeitura);
            if(fimLeitura != 1){
                ler(&fimLeitura);
            }
        }

        printf("thread %i de %i threads\n", numeroDaThread, totalDeThreads);
        
       

		
	}
    //printf("\n\n\n- FimLeitura: ' %d ' -\n\n", fimLeitura);
    printf("\n\n\n- FIM -\n\n");
    return 0;
}