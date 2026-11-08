//  T4

/*  Grupo 4:
    Ana Beatriz Bernardino Penze
    Caua Kadena Okabayashi
    Kenzo Cavalcante Oshiro
    Liliane de Moraes Pinheiro
    Luis Miguel Willame Silva Lima
*/

/*  Resolva T4 usando modulariza��o. Os dados de execu��o dever�o ser
    recebidos via argumento do programa na linha de comando.

    Exemplos de execu��es

    app 3 GCTTTCGACGAT GATCGAGCTTCGAA GGTCTAGCTAAT TCGA

    SAIDA_2 = Quantidade de bacterias: 3
    SAIDA_3 = Bacteria: GCTTTCGACGAT
    SAIDA_3 = Bacteria: GATCGAGCTTCGAA
    SAIDA_3 = Bacteria: GGTCTAGCTAAT
    SAIDA_4 = Virus: TCGA
    SAIDA_5 = Bacteria infectada: GCTT
    SAIDA_5 = Bacteria infectada: GAGCTA
    SAIDA_5 = Bacteria infectada: GGTCTAGCTAAT
    SAIDA_6 = DNA resultante: GCT

    app 5 AGCT TGC CGCAA TGTC ATGTTC T

    SAIDA_2 = Quantidade de bacterias: 5
    SAIDA_3 = Bacteria: AGCT
    SAIDA_3 = Bacteria: TGC
    SAIDA_3 = Bacteria: CGCAA
    SAIDA_3 = Bacteria: TGTC
    SAIDA_3 = Bacteria: ATGTTC
    SAIDA_4 = Virus: T
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: CGCAA
    SAIDA_5 = Bacteria infectada: GC
    SAIDA_5 = Bacteria infectada: AGC
    SAIDA_6 = DNA resultante: GC

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIMITE_BACTERIAS 10
#define COMPR_BACTERIAS 1000
#define COMPR_VIRUS 1000

#define SAIDA_2 "\nSAIDA_2 = Quantidade de bacterias: %d"
#define SAIDA_3 "\nSAIDA_3 = Bacteria: %s"
#define SAIDA_4 "\nSAIDA_4 = Virus: %s"
#define SAIDA_5 "\nSAIDA_5 = Bacteria infectada: %s"
#define SAIDA_6 "\nSAIDA_6 = DNA resultante: %s"

/*
objetivo: percorre por cada bacteria e remove sequencias iguais a sequencia do virus
parametros: o vetor com o codigo de todas as bacterias, o codigo do virus e o vetor onde serao armazenadas o codigo das bacterias infectadas
retorno: nenhum
*/

void retirarCodigo(char BACTERIAS[COMPR_BACTERIAS], char *VIRUS, char *BACTERIAS_INFECTADAS) {
    int i, j, k; //
    int tamanhoVirus = strlen(VIRUS);
    int tamanhoBacteria = strlen(BACTERIAS);
    int encontrou = 1;

    while (encontrou == 1) {
        encontrou = 0;

        for (i = 0; i <= tamanhoBacteria - tamanhoVirus; i++) { //evita que ele busque fora da string da bacteria
            int igual = 1;

            for (j = 0; j < tamanhoVirus; j++) { //procura a sequencia igual ao virus
                if (BACTERIAS[i + j] != VIRUS[j]) { //se for diferente, atribui 0 a igual
                    igual = 0;
                }
            }
            if (igual == 1) { //se forem iguais, ele remove a sequencia
                encontrou = 1;

                // Remove a sequencia do virus da bacteria
                for (k = i; k < tamanhoBacteria - tamanhoVirus; k++) { //iguala o k ao i, aonde a sequencia comeca
                    BACTERIAS[k] = BACTERIAS[k + tamanhoVirus]; //substitui as letras
                }
                tamanhoBacteria -= tamanhoVirus; //atualiza o tamanho da bacteria
                BACTERIAS[tamanhoBacteria] = '\0'; //indicando o fim da string pra evitar possiveis erros
            }
        }
    }

    strcpy(BACTERIAS_INFECTADAS, BACTERIAS); //passa o codigo final da variavel temporaria para a global
}

/*
objetivo: encontre a maior substring comum a todas as bacterias
parametros: quantidade de bacterias(argc), vetor com os codigos das bacterias infectadas e o vetor onde sera armazenado o dna resultante
retorno: nenhum
*/

void encontrarDNAresultante(int argc, char BACTERIAS_INFECTADAS[COMPR_BACTERIAS][LIMITE_BACTERIAS], char *DNA_RESULTANTE[COMPR_BACTERIAS]) {

    char sequencia_temporaria[COMPR_BACTERIAS];
    int comprimento_maximo = 0;

    for (int i = 0; i < argc - 3; i++) { //Verifica cada bacteria
        for (int j = 0; j < strlen(BACTERIAS_INFECTADAS[i]); j++) {
            for (int k = j + 1; k <= strlen(BACTERIAS_INFECTADAS[i]); k++) {
                strncpy(sequencia_temporaria, BACTERIAS_INFECTADAS[i] + j, k - j); //Copia a sequencia da bactéria para a variável temporaria
                sequencia_temporaria[k - j] = '\0';

                int comum = 1;
                for (int l = 0; l < argc - 3; l++) {  //compara a variavel temporaria com todas as bacterias
                    if (strstr(BACTERIAS_INFECTADAS[l], sequencia_temporaria) == NULL) {
                        comum = 0; //Se a sequencia nao tiver sido encontrada, não comum
                        break;
                    }
                }

                // Se a temporaria é comum a todas e seu comprimento é maior que o máximo, atualiza a variável DNA_RESULTANTE
                if (comum && strlen(sequencia_temporaria) > comprimento_maximo) {
                    comprimento_maximo = strlen(sequencia_temporaria);
                    strcpy(DNA_RESULTANTE, sequencia_temporaria);
                }
            }
        }
    }
}

int main (int argc, char *argv[]){
    //variaveis bacterias
    int nBacterias;
    char BACTERIAS[LIMITE_BACTERIAS][COMPR_BACTERIAS];
    char VIRUS[COMPR_VIRUS];

    nBacterias = atoi(argv[1]); //pega o numero de bacterias
    printf(SAIDA_2,nBacterias); //imprime a quantidade de bacterias

    for(int i=2; i < argc-1;i++) { //pega o codigo de cada bacteria e imprime
        strcpy(BACTERIAS[i-2],argv[i]);
        printf(SAIDA_3,BACTERIAS[i-2]);
    }

    strcpy(VIRUS,argv[argc-1]); //transfere o codigo do virus
    printf(SAIDA_4,VIRUS);

    //implemente a partir daqui sua solu��o

    char BACTERIAS_INFECTADAS[COMPR_BACTERIAS][LIMITE_BACTERIAS];

    //Faz o processo de remocao
    for (int i = 0; i < argc - 3; i++) { //ignora os tres argumentos (nome do app, rna do virus e quantia de bacterias)
        retirarCodigo(BACTERIAS[i], VIRUS, BACTERIAS_INFECTADAS[i]);
        printf(SAIDA_5, BACTERIAS_INFECTADAS[i]);
    }

    //Busca as variaveis em comum:
    char DNA_RESULTANTE[COMPR_BACTERIAS];

    encontrarDNAresultante(argc, BACTERIAS_INFECTADAS, DNA_RESULTANTE);
    printf(SAIDA_6, DNA_RESULTANTE);

    return 0;
}
