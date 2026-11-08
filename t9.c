// T9 - Decifrador de Codigos

/* Grupo 4:
Ana Beatriz Bernardino Penze
Caua Kadena Okabayashi
Kenzo Cavalcante Oshiro
Liliane de Moraes Pinheiro
Luis Miguel Willame Silva Lima
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------PROTOTIPOS DAS FUNCOES--------
void exibirMenu();
void decifrarArquivo();
void gravarNumero();
void imprimirLinhas();
void imprimirMaiorLinha();
void procurarPalavra();

//------------PRINCIPAL-------------
void main() {
  exibirMenu();
  return 0;
}

//------------FUNCOES--------------

//Objetivo: Exibe as opcoes do menu principal
//Parametro e Retorno: Nenhum
void exibirMenu() {
    int opcaoMenu, validacao = 0;

    printf("\nMENU DE OPCOES\n");
    do {
        printf("\n1 - Decifra arquivo");
        printf("\n2 - Grava numero linha em arquivo");
        printf("\n3 - Quantas linhas o arquivo tem");
        printf("\n4 - Qual a maior linha");
        printf("\n5 - Pesquisar uma palavra");
        printf("\n0 - Encerrar\n");
        printf("\nQual opcao: ");
        scanf("%d", &opcaoMenu);

        switch(opcaoMenu) {
        case 1:
            decifrarArquivo();
            break;
        case 2:
            gravarNumero();
            break;
        case 3:
            imprimirLinhas();
            break;
        case 4:
            imprimirMaiorLinha();
            break;
        case 5:
            procurarPalavra();
            break;
        case 0:
            printf("\nOperacao finalizada\n");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opcaoMenu != 0);

    return;
}

//Objetivo: Decifra o arquivo texto e cria um arquivo com o codigo decifrado
//Parametro e Retorno: Nenhum
void decifrarArquivo() {
    FILE *arquivoTexto;
    FILE *arquivoDecifrado;

    arquivoTexto = fopen("readme.code.txt", "r"); //le o arquivo
    arquivoDecifrado = fopen("readme.decifra.txt", "w"); //cria o arquivo

    int numero, quantidade = 0;

    //verifica se o arquivo existe
    if (arquivoTexto == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    if (arquivoDecifrado == NULL) {
        printf("\nErro ao criar arquivo.\n");
        fclose(arquivoTexto);
        return;
    }

    //procura pelos numeros ignorando os colchetes e os converte em ASCII
    while(fscanf(arquivoTexto, "[%d]", &numero) == 1) {
        char caractere = (char)numero;
        fputc(caractere, arquivoDecifrado);
        quantidade++;
    }

    //fecha os arquivos
    fclose(arquivoTexto);
    fclose(arquivoDecifrado);

    printf("\nArquivo decifrado com sucesso!\n");

    return;
}

//Objetivo: Cria um arquivo com o codigo decifrado junto com a contagem de linhas
//Parametro e Retorno: Nenhum
void gravarNumero() {
    FILE *arquivoDecifrado;
    FILE *arquivoLinha;

    arquivoDecifrado = fopen("readme.decifra.txt", "r"); //apenas le o arquivo
    arquivoLinha = fopen("readme.nlines.txt", "w"); //cria o arquivo

    char linha[500];
    int numeroLinha = 0;

    //verifica se o arquivo existe
    if (arquivoDecifrado == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    if (arquivoLinha == NULL) {
        printf("\nErro ao criar arquivo.\n");
        fclose(arquivoDecifrado);
        return;
    }

    //le linha por linha e as imprime no novo arquivo com o numero das linhas
    while(fgets(linha, sizeof(linha), arquivoDecifrado) != NULL) {
        numeroLinha++;
        fprintf(arquivoLinha, "[linha:%d]%s", numeroLinha, linha);
    }

    fclose(arquivoDecifrado);
    fclose(arquivoLinha);

    printf("\nNumeros e linhas gravados com sucesso!\n");

    return;
}

//Objetivo: Imprime o total de linhas do arquivo decifrado
//Parametro e Retorno: Nenhum
void imprimirLinhas() {
    FILE *arquivoDecifrado;
    arquivoDecifrado = fopen("readme.decifra.txt", "r"); //apenas le o arquivo

    //verifica se o arquivo existe
    if (arquivoDecifrado == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    char linha[500];
    int quantidadeLinhas = 0;

    //conta quantas linhas tem
    while(fgets(linha, sizeof(linha), arquivoDecifrado) != NULL) {
        quantidadeLinhas++;
    }

    fclose(arquivoDecifrado); //fecha arquivo

    printf("\nO arquivo readme.decifra.txt tem (%d) linhas.\n", quantidadeLinhas);
    return;
}

//Objetivo: Imprime quantos caracteres tem a maior linha e o numero dessa linha.
//Parametro e Retorno: Nenhum
void imprimirMaiorLinha() {
    FILE *arquivoLinha;

    arquivoLinha = fopen("readme.decifra.txt", "r"); //le arquivo

    //verifica se o arquivo existe
    if (arquivoLinha == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    int numeroLinha = 0, maiorLinha = 0, numeroMaiorLinha;
    char linha[500];

    //le linha por linha
    while(fgets(linha, sizeof(linha), arquivoLinha) != NULL) {
        numeroLinha++; //conta em qual linha esta

        //armazena a primeira linha pra comparacao
        if (maiorLinha == 0) {
            maiorLinha = strlen(linha); //conta os caracteres, incluindo o "\n"
        }

        //se a linha atual for maior que a maiorLinha
        if (maiorLinha <= strlen(linha)) {
            maiorLinha = strlen(linha); //substitui pelo quantidade atual
            numeroMaiorLinha = numeroLinha; //salva o numero da linha atual
        }
    }

    fclose(arquivoLinha);

    printf("\nA linha [%d] eh a maior com (%d) caracteres.\n", numeroMaiorLinha, maiorLinha);
    return;
}

//Objetivo: Procura uma palavra, imprime quantas vezes ela aparece no codigo e as linhas em que ela aparece
//Parametro e Retorno: Nenhum
void procurarPalavra() {
    FILE *arquivoLinha;
    arquivoLinha = fopen("readme.nlines.txt", "r"); //le o arquivo

    //verifica se o arquivo existe
    if (arquivoLinha == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    int ocorrencias = 0;
    char linha[500], palavra[50];

    //scaneia a palavra
    printf("\nQual palavra pesquisar: ");
    scanf("%s", palavra);

    //apenas conta as ocorrencias da palavra
    while(fgets(linha, sizeof(linha), arquivoLinha) != NULL) {
        if (strstr(linha, palavra) != NULL) {
            ocorrencias++;
        }
    }

    //se tiver 0 ocorrencias
    if (ocorrencias == 0) {
        printf("\nNao ha ocorrencias dessa palavra\n");

    } else { //se tiver mais de zero ocorrencias
        printf("\nAs linhas em que a palavra \"%s\" ocorre:\n\n", palavra);

        fseek(arquivoLinha, 0, SEEK_SET); //volta pro inicio do arquivo

        //imprime as linhas em que a palavra aparece
        while(fgets(linha, sizeof(linha), arquivoLinha) != NULL) {
            if (strstr(linha, palavra) != NULL) {
                printf("%s", linha);
            }
        }

        //imprime a quantidade de ocorrencias
        printf("\ne tem %d ocorrencias.\n", ocorrencias);
    }

    fclose(arquivoLinha);
    return;
}
