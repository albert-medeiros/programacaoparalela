#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

//biblioteca OpenMP
#include <omp.h>
#define max 15

void ler(int *fimLeitura){

    // /printf("entrou aqui na função de leitura!\n\n");
    // char *letra[1];
    char carac, palavra[150],todas_letras[2000];
    int tam=0,qnt=0,j=0;
    long int k=0;

    FILE *arquivo,*saida;
    arquivo = fopen("arquivo.txt", "r");
    //saida = fopen("lista.txt", "w");

    if(arquivo == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return 0;
    }         
    else{
         
        do{
            carac=fgetc(arquivo);
            todas_letras[qnt] = tolower(carac);
            //printf("\n-> %c %d -> %d",carac, carac, todas_letras[qnt]);
            
            //if((todas_letras[qnt] == -92)||(todas_letras[qnt] == -93)){
                // LETRAS A com os acentos possiveis de e ter
            if((todas_letras[qnt] == -93 ) || (todas_letras[qnt] == -95 ) || (todas_letras[qnt] == -94 ) || (todas_letras[qnt] == -96 ) || (todas_letras[qnt] == -92 ) || (todas_letras[qnt] == -127 ) || (todas_letras[qnt] == -128 ) || (todas_letras[qnt] == -125 ) || (todas_letras[qnt] == -126 ) || (todas_letras[qnt] == -124 )){
        
                todas_letras[qnt-1] = 97;
                // todas_letras[qnt] = NULL;
                qnt--;
            //   printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }

            // LETRAS E com os acentos possiveis de e ter
            if((todas_letras[qnt] == -85 ) || (todas_letras[qnt] == -86 ) || (todas_letras[qnt] == -87 ) || (todas_letras[qnt] == -88 ) || (todas_letras[qnt] == -119 ) || (todas_letras[qnt] == -120 ) || (todas_letras[qnt] == -118 )){
        
                todas_letras[qnt-1] = 101;
                //todas_letras[qnt] = 32;
                qnt--;
            //    printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }
            
            // LETRAS I com os acentos possiveis de e ter
            if((todas_letras[qnt] == -83 ) || (todas_letras[qnt] == -84 ) || (todas_letras[qnt] == -81 )|| (todas_letras[qnt] == -115 )|| (todas_letras[qnt] == -116 )){
        
                todas_letras[qnt-1] = 105;
                //todas_letras[qnt] = 32;
                qnt--;
            //    printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);    
            }
            // LETRAS O com os acentos possiveis de e ter
            if((todas_letras[qnt] == -109 ) || (todas_letras[qnt] == -110 ) || (todas_letras[qnt] == -107 )|| (todas_letras[qnt] == -108 )|| (todas_letras[qnt] == -77 )|| (todas_letras[qnt] == -78 )|| (todas_letras[qnt] == -75 )|| (todas_letras[qnt] == -76 )){
        
                todas_letras[qnt-1] = 111;
                //todas_letras[qnt] = 32;
                qnt--;
            //    printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);    
            }


            // LETRAS U com os acentos possiveis de e ter
            if((todas_letras[qnt] == -70 ) || (todas_letras[qnt] == -71 ) || (todas_letras[qnt] == -102 ) || (todas_letras[qnt] == -103 ) || (todas_letras[qnt] == -100 )){
        
                todas_letras[qnt-1] = 117;
                //todas_letras[qnt] = 32;
                qnt--;
           //     printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }
            // LETRAS ç 
            if((todas_letras[qnt] == -121 ) || (todas_letras[qnt] == -89)){
        
                todas_letras[qnt-1] = 99;
                //todas_letras[qnt] = 32;
                qnt--;
           //     printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }

            // Outros caracteres
            if((todas_letras[qnt] == 46)  || (todas_letras[qnt] == 45) || (todas_letras[qnt] == 44) || (todas_letras[qnt] == 47) || (todas_letras[qnt] == 41) || (todas_letras[qnt] == 40)  || (todas_letras[qnt] == 123) || (todas_letras[qnt] == 125) || (todas_letras[qnt] == 91) || (todas_letras[qnt] == 93) || (todas_letras[qnt] == 34) || (todas_letras[qnt] == 39) || (todas_letras[qnt] == 61) || (todas_letras[qnt] == 58) || (todas_letras[qnt] == 59) || (todas_letras[qnt] == 33)){
                    todas_letras[qnt] = 32;
            //    printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }

            if((todas_letras[qnt] == -1 ) ){
                //todas_letras[qnt] = 32;
                qnt--;
            //    printf("\n\n\nLETRA - %c",  todas_letras[qnt-1]);
            }
                    
            qnt++;
        }while(carac != EOF);
        qnt--;
        //printf ("\n\nO Arquivo possui %d letras",strlen(todas_letras));

    }
    
    // printf("\n\nMostando letras do arquivo\n\n");
    // for (int p = 0; p < strlen(todas_letras); p++)
    // {
    //     printf("%c", todas_letras[p]);
    // }

    //printf("Tam qnt %d todas_letras %d", qnt,strlen(todas_letras));
    
    saida = fopen("lista1.txt", "w");
    for(int q=0;q<strlen(todas_letras);q++){
        if(isspace(todas_letras[q])){
            //printf("ENTOU NO IF -----------------------------------------------------------");
            fprintf(saida,"\n");
        }
        else{
            fprintf(saida,"%c",todas_letras[q]);
        }
    }

    *fimLeitura=1;
    //printf("\n----->   FimLeitura: %d\n\n", *fimLeitura);
    
    fflush(arquivo);
    fclose(saida);
    fclose(arquivo);
    
}


int contador(char palavra[]){
    FILE *arquivo_final;
    arquivo_final = fopen("lista1.txt", "r");
    int qnt_total=0;
    char pal[30];
    #pragma omp critical
    {
        fscanf(arquivo_final,"%s",pal);
        while (feof(arquivo_final) == 0){            
            
            if(strcmp(palavra,pal)==0){
                qnt_total++;                        
            }
            fscanf(arquivo_final,"%s",pal);
        }                
    }
    fclose(arquivo_final);
    return qnt_total;
}


int main(){
    
    setlocale(LC_ALL, "portuguese");
    
    char palavra[15];
    int numeroDeThreads=4, quantidade=0,numeroDaThread=-1,totalDeThreads=-1, fimLeitura=-1;

    printf("\n\nBem Vindo:\n\n");
    printf("Digite a palavra que deseja buscar no arquivo: ");
    scanf("%s", &palavra);
    printf("\n ----- \n");
    printf("A palavra que você deseja procurar é a: %s\n", palavra);
    
    #pragma omp parallel
    {
        numeroDaThread = omp_get_thread_num();
        totalDeThreads = omp_get_num_threads(); 
   
        if(fimLeitura != 1){
            if(numeroDaThread == 0){            
                ler(&fimLeitura);
            }
        }
        // else
            quantidade=contador(palavra);
        // }        
	}
    printf("\n\t\t\tA palavra ' %s ' apareceu %d vezes no texto",palavra, quantidade);
    printf("\n\n\n- FIM -\n\n");
    return 0;
}