//T8 - Carros 2 

/*
_______________________________________________________________________________________________

Grupo 4:
Ana Beatriz Bernardino Penze
Caua Kadena Okabayashi
Kenzo Cavalcante Oshiro
Liliane de Moraes Pinheiro
Luis Miguel Willame Silva Lima
________________________________________________________________________________________________

Desenvolva um programa em C/C++ usando módulos com um menu de opções para:
1. Informar quantos registros tem “carro.dbf”.
2. Ordenar os registros de “carro.dbf” de forma crescente pelo campo “placa” e armazená-los
no arquivo “carro.ord”.
3. Mostrar os registros de “carro.ord”.
4. Para cada tipo de combustível informar a quantidade de carros.
5. Para cada tipo de opcional informar a quantidade de carros.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct {
 long int id_reg;
 char placa[9];
 char modelo[TAM];
 char fabricante[TAM];
 int ano_fabricacao;
 int ano_modelo;
 char combustivel[TAM];
 char cor[TAM];
 int opcional[8];
 float preco_compra;
} CARRO;

char opcionais[][TAM]={
{"4.portas"},
{"cambio.automatico"},
{"vidros.eletricos"},
{"abs"},
{"air.bag"},
{"ar.condicionado"},
 {"banco.couro"},
{"sensor.estacionamento"}};

//prototipos
void chama_menu();//feito
int qtd_registros();//feito
void ord_qtd_placa();//
void mostrar_ord();//feito +-
void qtd_combustivel();//com erro
void qtd_opcionais();//

//menu

//função: MENU PRINCIPAL
//objetivo: mostra o menu e permite a escolha
//retorna: nada
void chama_menu() {
    CARRO carro;
    int opcao_menu = 0;

    do{
        
        printf("1- Informar quantos registros\n");
        printf("2- Ordenar crescentemente os registros pela placa\n");
        printf("3- Mostrar os registros ordenados\n");
        printf("4- informar a quantidade de carros para o tipo de combustivel\n");
        printf("5- informar a quantidade de carros para o tipo de opcionais\n");
        printf("6- Sair\n");
        
            printf("Escolha uma opcao: ");
            scanf("%d",&opcao_menu);
            
            switch(opcao_menu){
            case 1:
                printf("|------------------------------------------------------|\n");
                printf ("   Quantidade de arquivos no registro = %d\n",qtd_registros(&carro, "carro.dbf") );
                printf("|------------------------------------------------------|\n");
                break;
            case 2:
                ord_qtd_placa(&carro, "carro.dbf");
                break;
            case 3:
                mostrar_ord(&carro, "carro.ord");
                break;
            case 4:
                qtd_combustivel(&carro, "carro.dbf");
                break;
            case 5:
                qtd_opcionais(&carro, "carro.dbf");
                break;
            case 6:
                printf("saindo...");
                break;
            default:
                printf("|------------------------------------------------------|\n");
                printf("    Opcao invalida\n");
                printf("|------------------------------------------------------|\n");
                break;
            }
    }while (opcao_menu!=6);
}

// ---------- fim do menu

// funcoes que sao chamadas no menu:

//funcao: 1.quantidade de registros
//objetivo: conta os registros do arquivo
//parametro: ponteiro para a variavel carro e o nome do arquivo
//retorna: a quantidade de registros
int qtd_registros(CARRO *ptr, char *nomeArq){  //conta_registros(CARRO, "carro.dbf")
    FILE *file;
    int registros = 0;
    file = fopen(nomeArq, "rb");//abre um arquivo para leitura

    if(file == NULL){                       //
        printf("Erro ao abrir o arquivo %s, tente inserir o arquivo na pasta output\n", nomeArq);; //para caso o arquivo nao consiga abrir
        exit(100);                          //
    }

    while( !feof(file) ){
        if (fread(&ptr, sizeof(CARRO), 1, file) > 0)
        registros++;
    }
    fclose(file);

    return (registros);
} 
//funcao: 2.ordena e armazena crescentemente as placas
//objetivo: ordena as placas crescentemente e as armazena no carro.ord
//parametro: ponteiro pra variavel carro e o nome do arquivo
//retono: nada
void ord_qtd_placa(CARRO *ptr, char *nomeArq){ //ord_qtd_placa(CARRO, "carro.dbf")
    int total_registros;
    FILE *file = fopen(nomeArq, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s, tente inserir o arquivo na pasta output\n", nomeArq);
        return;
    }

    // contar registros
    total_registros = qtd_registros(ptr, nomeArq);

    // alocar memória para os registros
    CARRO *carros = (CARRO *)malloc(total_registros * sizeof(CARRO));
    if (carros == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(file);
        return;
    }

    // ler os registros
    fread(carros, sizeof(CARRO), total_registros, file);
    fclose(file);

    // ordenar os registros pela placa
    for (int i = 0; i < total_registros - 1; i++) {
        for (int j = 0; j < total_registros - i - 1; j++) {
            if (strcmp(carros[j].placa, carros[j + 1].placa) > 0) {
                // trocar os registros
                CARRO temp = carros[j];
                carros[j] = carros[j + 1];
                carros[j + 1] = temp;
            }
        }
    }

    // gravar os registros ordenados em um novo arquivo
    file = fopen("carro.ord", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de saída %s\n", "carro.ord");
        free(carros);
        return;
    }
    fwrite(carros, sizeof(CARRO), total_registros, file);
    fclose(file);
    free(carros);
    printf("|------------------------------------------------------|\n");
    printf("    Registros ordenados e salvos em %s\n", "carro.ord");
    printf("|------------------------------------------------------|\n");
}
    

//3. mostrar os carros ordenados
//funcao: mostrar ordenados (mostrar_ord)
//objetivo: exibir os carros ordenados pelas placas
//parametro: ponteiro para a variavel carro e o nome do arquivo
//retono: nada

void mostrar_ord(CARRO *ptr, char *nomeArq){ //mostrar_ord(&carro, "carro.dbf");
    FILE *file; 
    file = fopen(nomeArq, "rb");
    if (file == NULL) {
        printf("|---------------------------------------------------------------------|\n");                       
        printf("    Erro ao abrir arquivo, tente escolher a opcao 2 primeiro!\n"); // para caso o arquivo não consiga abrir
        printf("|---------------------------------------------------------------------|\n");
        return;
    }

    // primeiro conta o número de registros
    int registros = 0;
    while (fread(ptr, sizeof(CARRO), 1, file) > 0) {
        registros++;
    }

    // alocar memória para os registros
    CARRO *carros = (CARRO *)malloc(registros * sizeof(CARRO));
    if (carros == NULL) {
        printf("Erro ao alocar memória\n");
        fclose(file);
        return;
    }

    // voltar ao início do arquivo e ler os registros
    rewind(file);
    fread(carros, sizeof(CARRO), registros, file);
    fclose(file);

    //exib os registros
    printf("|------------------------------------------------------|\n");
    for (int i = 0; i < registros; i++) {
        printf("    Carro %d\n", i + 1);
        printf("    ID: %ld\n", carros[i].id_reg);
        printf("    Placa: %s\n", carros[i].placa);
        printf("    Modelo: %s\n", carros[i].modelo);
        printf("    Fabricante: %s\n", carros[i].fabricante);
        printf("    Ano de Fabricacao: %d\n", carros[i].ano_fabricacao);
        printf("    Combustivel: %s\n", carros[i].combustivel);
        printf("    Opcionais:\n");
            for (int i = 0; i < 8; i++){
                if (carros[i].opcional)
                printf("    %s\n", opcionais[i]);
            }
    printf("|------------------------------------------------------|\n");
    }

    free(carros); // liberar a memória alocada

}


//funcao: 4. quantidade de carros por combustivel
//objetivo: exibir a quantidade de carros por combustivel
//parametro: ponteiro para a variavel carro e o nome do arquivo
//retono: nada
void qtd_combustivel(CARRO *ptr, char *nomeArq){ //mostrar_ord(&carro, "carro.dbf");
    int num_gasolina = 0;
    int num_alcool = 0;
    int num_flex = 0;
    int num_diesel = 0;

    FILE *file; 
    file = fopen(nomeArq, "rb");
    if(file == NULL){                       
        printf("Erro ao abrir o arquivo %s, tente inserir o arquivo na pasta output\n", nomeArq);
        exit(100);
    }
      while( !feof(file) ){
        if (fread(ptr, sizeof(CARRO), 1, file) > 0){
            if ( (strcmp(ptr->combustivel, "Gasolina") == 0) || (strcmp(ptr->combustivel, "gasolina") == 0) )
                num_gasolina++;
            else if ( (strcmp(ptr->combustivel, "Alcool") == 0) || (strcmp(ptr->combustivel, "alcool") == 0) )
                num_alcool++;
            else if ( (strcmp(ptr->combustivel, "Flex") == 0) || (strcmp(ptr->combustivel, "flex") == 0) )
                num_flex++;
            else if ( (strcmp(ptr->combustivel, "Diesel") == 0) || (strcmp(ptr->combustivel, "diesel") == 0) )
                num_diesel++;
        }
    }
    fclose(file);
    printf("|------------------------------------------------------|\n");
    printf("    Quantidade de carros por combustivel:\n");
    printf("    Alcool: %d\n", num_alcool);
    printf("    Gasolina: %d\n", num_gasolina);
    printf("    Flex: %d\n", num_flex);
    printf("    Diesel: %d\n", num_diesel);
    printf("|------------------------------------------------------|\n");
}


//funcao: 5.qtd por opcional
//objetivo: exibe a quantidade de carros com respectivas opcionais
//parametro: ponteiro para a variavel carro e o nome do arquivo
//retono: nada
void qtd_opcionais (CARRO *ptr, char *nomeArq){

    int contar[8];
    for (int i = 0; i < 8; i++){
        contar[i] = 0;
    }   

    FILE *file;
    file= fopen(nomeArq,"rb"); //abre para ler o arqv
    
    if(file == NULL){                         
        printf("Erro ao abrir o arquivo %s, tente inserir o arquivo na pasta output\n", nomeArq);
        exit(100);
    }

    while( !feof(file) ){
        if (fread(ptr, sizeof(CARRO), 1, file) > 0){
            for (int i = 0;i < 8; i++){
                if(ptr->opcional[i] == 1){
                      contar[i]++; 
                }
            }
        }
    }
    
    fclose(file);
    printf("|------------------------------------------------------|\n");
    
    for(int i=0; i<8; i++){
        printf("    %s:  %d\n",opcionais[i], contar[i]);// exibir a quantidade para cada opcional
    }
    printf("|------------------------------------------------------|\n");
}

//-------------------------//


int main ()
{
    chama_menu();
    return 0;
}
