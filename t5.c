//T5 - Formatacao de Texto

/* Grupo 4:
Ana Beatriz Bernardino Penze
Caua Kadena Okabayashi
Kenzo Cavalcante Oshiro
Liliane de Moraes Pinheiro
Luis Miguel Willame Silva Lima
*/

/*

Dado um texto existente no "main.c", construa um programa que
formate o texto em um conjunto de linhas de forma que palavras caibam completamente na linha.
Cada linha pode ter no máximo 80 caracteres. A partir do texto formatado construa um menu de opções para:

a)      Imprimir o texto formatado;
b)      Dado uma palavra informar quantas vezes a palavra aparece e em qual(is) linha(s) e coluna(s) ela está;
c)      Substituir uma palavra do texto por outra fornecida pelo usuário. Apenas a primeira ocorrência da palavra deve ser substituída. Primeira ocorrência é a primeira vez que a palavra aparece no texto a partir do início do texto; Não esqueça de reformatar o texto;
d)      Substituir uma palavra do texto por outra fornecida pelo usuário. Todas as ocorrências da palavra devem ser substituídas; Não esqueça de reformatar o texto;
e)      Colocar o texto em caixa-alta, ou seja, todos seus caracteres em maiúsculo;
f)      Colocar o texto em caixa-baixa, ou seja, todos seus caracteres em minúsculo;
g)      Colocar em caixa-alta o primeiro caracter de cada início de frase;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 80
#define INITIAL_PARAGRAPHS 40

//------ Variaveis ------
enum Alignment {
    LEFT,
    CENTER,
    RIGHT,
    JUSTIFY
};

//------ Inicializacao das funcoes -------
char** formatText(char*, size_t*);
void freeFormattedText(char**, size_t);
void printFormattedText(char**, size_t);
void findWord(char**, size_t);
int replaceFirstOccurrence(char**, size_t);
void replaceAllOccurrences(char**, size_t);
void toUpper(char**, size_t);
void toLower(char**, size_t);
void capitalizeFirstChar(char**, size_t);
void alignLeft(char** formatted_text, size_t paragraph_count);
void alignCenter(char** formatted_text, size_t paragraph_count);
void alignRight(char** formatted_text, size_t paragraph_count);
void justifyText(char** formatted_text, size_t paragraph_count);
void alignText(char** formatted_text, size_t paragraph_count, enum Alignment alignment);

//-------- Funcao Main --------
int main() {
    char text[]="William Henry Gates III KBE GCIH (Seattle, 28 de outubro de 1955) mais conhecido como Bill Gates,\
 e um magnata, empresario, diretor executivo, investidor, filantropo e autor americano, que ficou conhecido por \
 fundar junto com Paul Allen a Microsoft a maior e mais conhecida empresa de software do mundo em termos de valor \
 de mercado. Gates ocupa atualmente o cargo de presidente nao-executivo da Microsoft alem de ser classificado \
 regularmente como a pessoa mais rica do mundo, posicao ocupada por ele de 1995 a 2007, 2009, e de 2014 a 2017. E \
 um dos pioneiros na revolucao do computador pessoal. Gates nasceu em uma familia de classe media de Seattle. Seu \
 pai, William H. Gates, era advogado de grandes empresas, e sua mae, Mary Maxwell Gates, foi professora da \
 Universidade de Washington e diretora de bancos. Bill Gates e as suas duas irmas, Kristanne e Libby, \
 frequentaram as melhores escolas particulares de sua cidade natal, e Bill tambem participou do \
 Movimento Escoteiro ainda quando jovem. Bill Gates, foi admitido na prestigiosa Universidade \
 Harvard, (conseguindo 1590 SATs dos 1600 possiveis) mas abandonou os cursos de Matematica e \
 Direito no terceiro ano para dedicar-se a Microsoft. Trabalhou na Taito com o desenvolvimento de \
 software basico para maquinas de jogos eletronicos (fliperamas) ate seus 16 anos. Tambem \
 trabalhou como pesquisador visitante na University of Massachusetts at Amherst, UMASS, Estados Unidos, quando \
 com 17 anos, desenvolveu junto com Paul Allen um software para leitura de fitas magneticas, com informacoes \
 de trafego de veiculos, em um chip Intel 8008. Com esse produto, Gates e Allen criaram uma empresa, \
 a Traf-o-Data, porem os clientes desistiram do negocio quando descobriram a idade dos donos. Enquanto \
 estudavam em Harvard, os jovens desenvolveram um interpretador da linguagem BASIC para um dos primeiros \
 computadores pessoais a serem lancado nos Estados Unidos - o Altair 8800. Apos um modesto sucesso na \
 comercializa��o deste produto, Gates e Allen fundaram a Microsoft, uma das primeiras empresas no mundo \
 focadas exclusivamente no mercado de programas para computadores pessoais ou PCs. Gates adquiriu ao \
 longo dos anos uma fama de visionario (apostou no mercado de software na epoca em que o hardware era \
 considerado muito mais valioso) e de negociador agressivo, chegando muitas vezes a ser acusado por \
 concorrentes da Microsoft de utilizar praticas comerciais desleais. Nos anos 1980, a IBM, lider \
 no mercado de grandes computadores, resolveu entrar no mercado da microinformatica com o PC, \
 porem faltava o Sistema Operacional. Para isso, fechou contrato com a recem-criada Microsoft. Todavia, \
 a Microsoft nao possuia o software ainda. O jovem Bill Gates foi a uma pequena empresa que havia \
 desenvolvido o sistema para o processador da Intel e decidiu compra-lo, pagou cerca de US$ 50 mil, personalizou \
 o programa e vendeu-o por US$ 8 milhoes, mantendo a licenca do produto. Este viria a ser o MS-DOS. \
 Fonte: https://pt.wikipedia.org/wiki/Bill_Gates";

    size_t paragraph_count = -1;
    char** formatted_text = formatText(text, &paragraph_count);
    char choice;

    do {
        printf("\na) Imprimir o texto formatado\n");
        printf("b) Quantidade de ocorrencias e localizacao de palavra\n");
        printf("c) Substituir a primeira ocorrencia de uma palavra\n");
        printf("d) Substituir todas as ocorrencias de uma palavra\n");
        printf("e) Colocar o texto em caixa-alta\n");
        printf("f) Colocar o texto em caixa-baixa\n");
        printf("g) Colocar em caixa-alta o primeiro caracter de cada início de frase\n");
        printf("h) Alinhar o texto a esquerda\n");
        printf("i) Alinhar o texto a direita\n");
        printf("j) Justificar o texto\n");
        printf("k) Centralizar o texto\n");
        printf("0) Sair\n");
        printf("\nSua escolha: ");

        scanf(" %c", &choice);

        while (getchar() != '\n');

        switch(choice) {
            case 'a':
                printFormattedText(formatted_text, paragraph_count);
                break;
            case 'b':
                findWord(formatted_text, paragraph_count);
                break;
            case 'c':
                replaceFirstOccurrence(formatted_text, paragraph_count);
                break;
            case 'd':
                replaceAllOccurrences(formatted_text, paragraph_count);
                break;
            case 'e':
                toUpper(formatted_text, paragraph_count);
                break;
            case 'f':
                toLower(formatted_text, paragraph_count);
                break;
            case 'g':
                capitalizeFirstChar(formatted_text, paragraph_count);
                break;
            case 'h':
                alignText(formatted_text, paragraph_count, LEFT);
                break;
            case 'i':
                alignText(formatted_text, paragraph_count, RIGHT);
                break;
            case 'j':
                justifyText(formatted_text, paragraph_count);
                break;
            case 'k':
                alignText(formatted_text, paragraph_count, CENTER);
                break;
            case '0':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while(choice != '0');

    freeFormattedText(formatted_text, paragraph_count);

    return 0;
}

//------- Funcoes -------

/*
Objetivo: Formata um texto em um conjunto de linhas de forma que palavras caibam completamente na linha.
Parâmetro: char* text (texto a ser formatado), size_t *formatted_text_counter (contador de linhas formatadas).
Retorno: char** (matriz de linhas formatadas)
*/
char** formatText(char* text, size_t *formatted_text_counter) {

    //aloca a matriz
    char** formatted_text = malloc(sizeof(char*) * INITIAL_PARAGRAPHS);
    if (formatted_text == NULL) { //erro de alocacao
        return NULL;
    }

    //inicializa o primeiro paragrafo
    *formatted_text_counter = 0;
    formatted_text[0] = malloc(sizeof(char) * (MAX_LINE_SIZE + 1));
    if (formatted_text[0] == NULL) { //erro de alocacao
        free(formatted_text);
        return NULL;
    }
    formatted_text[0][0] = '\0';

    char* word = strtok(text, " ");
    while (word != NULL) {
        size_t word_len = strlen(word);
        size_t current_line_len = strlen(formatted_text[*formatted_text_counter]);

        // remover newlines
        while (word_len > 0 && (word[word_len - 1] == '\n' || word[word_len - 1] == '\r')) {
            word[--word_len] = '\0';
        }

        //checagem se cabe na linha
        if (current_line_len + word_len + (current_line_len > 0) <= MAX_LINE_SIZE) {

            //se nao for a primeira palavra da linha, adicionar espaco antes
            if (current_line_len > 0) {
                strcat(formatted_text[*formatted_text_counter], " ");
            }

            strcat(formatted_text[*formatted_text_counter], word);

        }
        else { //novo paragrafo

            (*formatted_text_counter)++;
            if (*formatted_text_counter >= INITIAL_PARAGRAPHS) { //ultrapassou as 40 linhas, precisa realocar para colocar mais
                char** temp = realloc(formatted_text, sizeof(char*) * (*formatted_text_counter + 1));
                if (temp == NULL) { //lidar com a falha de alocacao
                    for (size_t i = 0; i <= *formatted_text_counter; i++) {
                        free(formatted_text[i]);
                    }
                    free(formatted_text);
                    return NULL;
                }
                formatted_text = temp;
            }

            formatted_text[*formatted_text_counter] = malloc(sizeof(char) * (MAX_LINE_SIZE + 1));

            if (formatted_text[*formatted_text_counter] == NULL) { //falha de alocacao
                for (size_t i = 0; i < *formatted_text_counter; i++) {
                    free(formatted_text[i]);
                }
                free(formatted_text);
                return NULL;
            }

            strcpy(formatted_text[*formatted_text_counter], word);
        }

        word = strtok(NULL, " ");
    }

    (*formatted_text_counter)++;

    return formatted_text;
}

/*
Objetivo: Libera a memória alocada pelo texto formatado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t count (número de linhas formatadas)
Retorno: Nenhum
*/
void freeFormattedText(char** formatted_text, size_t count) {
    if (formatted_text == NULL) {
        return;
    }
    for (size_t i = 0; i < count; i++) {
        free(formatted_text[i]);
    }
    free(formatted_text);
}

/*
Objetivo: Imprime o texto formatado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas)
Retorno: Nenhum
*/
void printFormattedText(char** formatted_text, size_t paragraph_count) {
    printf("\nTexto formatado:\n");
    for (size_t i = 0; i < paragraph_count; i++) {
        printf("%s\n", formatted_text[i]);
    }
}

/*
Objetivo: Encontra todas as ocorrências de uma palavra no texto formatado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum
*/
void findWord(char** formatted_text, size_t paragraph_count) {
    char word[100];
    printf("Digite a palavra a ser procurada: ");
    scanf("%99s", word);

    int total_occurrences = 0;
    for (size_t i = 0; i < paragraph_count; i++) {
        char* ptr = formatted_text[i];
        char* lower_ptr = strdup(ptr); // cria uma cópia para comparação
        char* lower_word = strdup(word);
        // converte para minúsculas
        for (size_t j = 0; lower_ptr[j]; j++) lower_ptr[j] = tolower(lower_ptr[j]);
        for (size_t j = 0; lower_word[j]; j++) lower_word[j] = tolower(lower_word[j]);

        char* temp = lower_ptr;
        while ((ptr = strstr(temp, lower_word)) != NULL) {
            total_occurrences++;
            int pos = ptr - lower_ptr; // encontra a posição
            printf("Palavra encontrada na linha %zu, coluna %d\n", i + 1, pos + 1);
            temp = ptr + strlen(lower_word); // atualiza o ponteiro para a próxima ocorrência
        }
        free(lower_ptr);
        free(lower_word);
    }
    printf("Total de ocorrencias: %d\n", total_occurrences);
}

/*
Objetivo: Substitui a primeira ocorrência de uma palavra por outra no texto formatado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: int (1 se a substituição foi realizada, 0 caso contrário).
*/
int replaceFirstOccurrence(char** formatted_text, size_t paragraph_count) {
    char old_word[100];
    char new_word[100];
    printf("Digite a palavra a ser substituida: ");
    scanf("%99s", old_word);
    printf("Digite a nova palavra: ");
    scanf("%99s", new_word);
    size_t new_len = strlen(new_word);
    size_t old_len = strlen(old_word);

    for (size_t i = 0; i < paragraph_count; i++) {
        char* ptr = strstr(formatted_text[i], old_word);
        if (ptr != NULL) {
            if (new_len > old_len) {
                // Verifica se há espaço suficiente
                if (strlen(formatted_text[i]) + (new_len - old_len) >= MAX_LINE_SIZE) {
                    printf("Espaco insuficiente para a substituicao no paragrafo %zu\n", i + 1);
                    return 0;
                }
            }
            int pos = ptr - formatted_text[i]; // encontra a posição
            printf("Palavra encontrada na linha %zu, coluna %d\n", i + 1, pos + 1);
            memmove(ptr + new_len, ptr + old_len, strlen(ptr + old_len) + 1);
            memcpy(ptr, new_word, new_len);
            printf("Substituicao realizada no paragrafo %zu\n", i + 1);
            return 1;
        }
    }
    printf("Palavra nao encontrada.\n");
    return 0;
}

/*
Objetivo: Substitui todas as ocorrências de uma palavra por outra no texto formatado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum.
*/
void replaceAllOccurrences(char** formatted_text, size_t paragraph_count) {
    char old_word[100];
    char new_word[100];
    printf("Digite a palavra a ser substituida: ");
    scanf("%99s", old_word);
    printf("Digite a nova palavra: ");
    scanf("%99s", new_word);
    size_t new_len = strlen(new_word);
    size_t old_len = strlen(old_word);

    int substitutions = 0; // variável para contar o número de substituições

    for (size_t i = 0; i < paragraph_count; i++) {
        char* ptr = formatted_text[i];
        char* temp = strdup(ptr); // cria uma cópia para comparação
        char* lower_ptr = strdup(temp); // cria uma cópia para comparação
        char* lower_word = strdup(old_word);
        // converte para minúsculas
        for (size_t j = 0; lower_ptr[j]; j++) lower_ptr[j] = tolower(lower_ptr[j]);
        for (size_t j = 0; lower_word[j]; j++) lower_word[j] = tolower(lower_word[j]);

        while ((ptr = strstr(lower_ptr, lower_word)) != NULL) {
            if (new_len > old_len) {
                // Verifica se há espaço suficiente
                if (strlen(formatted_text[i]) + (new_len - old_len) >= MAX_LINE_SIZE) {
                    printf("Espaco insuficiente para a substituicao no paragrafo %zu\n", i + 1);
                    free(temp);
                    free(lower_ptr);
 free(lower_word);
                    return;
                }
            }
            int pos = ptr - lower_ptr; // encontra a posição
            printf("Palavra encontrada na linha %zu, coluna %d\n", i + 1, pos + 1);
            memmove(ptr + new_len, ptr + old_len, strlen(ptr + old_len) + 1);
            memcpy(ptr, new_word, new_len);
            substitutions++; // incrementa o contador de substituições
            lower_ptr = ptr + new_len; // atualiza o ponteiro para a próxima ocorrência
        }
        free(temp);
        free(lower_ptr);
        free(lower_word);
    }

    if (substitutions == 0) {
        printf("Palavra nao encontrada.\n");
    } else {
        printf("Substituicao realizada em %d ocorrencias.\n", substitutions);
    }
}

/*
Objetivo: Coloca o texto formatado em caixa-alta.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum.
*/
void toUpper(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        for (size_t j = 0; formatted_text[i][j] != '\0'; j++) {
            formatted_text[i][j] = toupper(formatted_text[i][j]);
        }
    }
}

/*
Objetivo: Coloca o texto formatado em caixa-baixa.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum.
*/
void toLower(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        for (size_t j = 0; formatted_text[i][j] != '\0'; j++) {
            formatted_text[i][j] = tolower(formatted_text[i][j]);
        }
    }
}

/*
Objetivo: Coloca o primeiro caractere de cada frase em caixa-alta.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum
*/
void capitalizeFirstChar(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        char* ptr = formatted_text[i];
        while (*ptr != '\0') {
            if (*ptr == '.' || *ptr == '!' || *ptr == '?') {
                ptr++;
                if (*ptr == ' ') {
                    ptr++;
                    if (*ptr != '\0') {
                        *ptr = toupper(*ptr);
                    }
                }
            }
            ptr++;
        }
    }
}

/*
Objetivo: Alinha o texto formatado à esquerda.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum.
*/
void alignLeft(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        // Remove leading and trailing spaces
        char* p = formatted_text[i];
        while (*p != '\0' && isspace(*p)) {
            p++;
        }
        char* q = p;
        while (*q != '\0') {
            q++;
        }
        while (q > p && isspace(*(q - 1))) {
            *(q - 1) = '\0';
            q--;
        }

        // Move the text to the left
        size_t len = strlen(p);
        memmove(formatted_text[i], p, len + 1);
    }
}

/*
Objetivo: Alinha o texto formatado à direita.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum.
*/
void alignRight(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        // Remove leading and trailing spaces
        char* p = formatted_text[i];
        while (*p != '\0' && isspace(*p)) {
            p++;
        }
        char* q = p;
        while (*q != '\0') {
            q++;
        }
        while (q > p && isspace(*(q - 1))) {
            *(q - 1) = '\0';
            q--;
        }

        // Calculate the number of spaces needed to align to the right
        size_t len = strlen(p);
        size_t spaces_needed = MAX_LINE_SIZE - len;

        // Move the text to the right
        memmove(formatted_text[i] + spaces_needed, p, len + 1);
        memset(formatted_text[i], ' ', spaces_needed);
    }
}

/*
Objetivo: Justifica uma linha de texto, adicionando espaços entre as palavras.
Parâmetro: char* line (linha a ser justificada), size_t max_line_size (tamanho máximo da linha).
Retorno: Nenhum.
*/
void alignJustify(char* line, size_t max_line_size) {
    // Contar o número de palavras e o comprimento total da linha
    char* words[100]; // Supondo que não teremos mais de 100 palavras
    size_t word_count = 0;
    size_t line_length = 0;

    char* token = strtok(line, " ");
    while (token != NULL) {
        words[word_count++] = token;
        line_length += strlen(token);
        token = strtok(NULL, " ");
    }

    // Se houver apenas uma palavra ou a linha já está no tamanho máximo, não precisamos justificar
    if (word_count <= 1 || line_length >= max_line_size) {
        return;
    }

    // Calcular o número de espaços a serem adicionados
    size_t total_spaces = max_line_size - line_length;
    size_t spaces_between_words = total_spaces / (word_count - 1);
    size_t extra_spaces = total_spaces % (word_count - 1);

    // Construir a nova linha justificada
    char justified_line[MAX_LINE_SIZE + 1] = "";
    for (size_t i = 0; i < word_count; i++) {
        strcat(justified_line, words[i]);

        // Adicionar espaços entre as palavras
        if (i < word_count - 1) {
            for (size_t j = 0; j < spaces_between_words; j++) {
                strcat(justified_line, " ");
            }
            // Adicionar um espaço extra nas primeiras 'extra_spaces' palavras
            if (i < extra_spaces) {
                strcat(justified_line, " ");
            }
        }
    }

    // Copiar a linha justificada de volta para a linha original
    strncpy(line, justified_line, max_line_size);
    line[max_line_size] = '\0'; // Garantir que a string esteja terminada
}

/*
Objetivo: Chama a funcao que justifica, linha por linha
Parâmetro: char* str (texto a ser justificado), size_t max_line_size (tamanho máximo da linha).
Retorno: Nenhum.
*/
void justifyText(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        alignJustify(formatted_text[i], MAX_LINE_SIZE);
    }
}

/*
Objetivo: Alinha o texto formatado ao centro.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas).
Retorno: Nenhum
*/
void alignCenter(char** formatted_text, size_t paragraph_count) {
    for (size_t i = 0; i < paragraph_count; i++) {
        // Remove leading and trailing spaces
        char* p = formatted_text[i];
        while (*p != '\0' && isspace(*p)) {
            p++;
        }
        char* q = p;
        while (*q != '\0') {
            q++;
        }
        while (q > p && isspace(*(q - 1))) {
            *(q - 1) = '\0';
            q--;
        }

        // Calculate the number of spaces needed to center
        size_t len = strlen(p);
        size_t spaces_needed = MAX_LINE_SIZE - len;
        size_t left_spaces = spaces_needed / 2;
        size_t right_spaces = spaces_needed - left_spaces;

        // Move the text to the center
        memmove(formatted_text[i] + left_spaces, p, len + 1);
        memset(formatted_text[i], ' ', left_spaces);
        memset(formatted_text[i] + left_spaces + len, ' ', right_spaces);
    }
}

/*
Objetivo: Chama as funcoes de formatacao de acordo com o alinhamento especificado.
Parâmetro: char** formatted_text (matriz de linhas formatadas), size_t paragraph_count (número de linhas formatadas), enum Alignment alignment (alinhamento).
Retorno: Nenhum.
*/
void alignText(char** formatted_text, size_t paragraph_count, enum Alignment alignment) {
    switch (alignment) {
        case LEFT:
            alignLeft(formatted_text, paragraph_count);
            break;
        case CENTER:
            alignCenter(formatted_text, paragraph_count);
            break;
        case RIGHT:
            alignRight(formatted_text, paragraph_count);
            break;
        case JUSTIFY:
            alignJustify(formatted_text, paragraph_count);
            break;
        default:
            printf("Alinhamento invalido.\n");
            break;
    }
}
