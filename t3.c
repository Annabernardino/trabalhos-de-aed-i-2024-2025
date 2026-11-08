// T3 - Caixa Eletronico

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
#include <time.h>

//-------------------VARIAVEIS GLOBAIS -----------------------------
char cpfClientes[49][15]; // Armazena os cpfs.
char contasCorrentes[49][9]; // Armazena as contas correntes
int clientesCadastrados = 0; // Total de clientes cadastrados
int totalSacadoCliente[49]; // Total sacado por cada cliente
int saquesPorCliente[49]; // Conta quantas vezes um cliente sacou;
int valorSaqueClientes[49][100]; // Armazena o valor de cada saque feito por cada cliente;

//Relacionado a cedulas:

int valor_cedula[8] = {500, 150, 50, 20, 10, 5, 2, 1};
int quantidade_cedulas[8] = {100, 200, 400, 800, 1600, 3200, 6400, 12800};

int saque_ou_cedulas; //Define se sera cedulas ou em reais
int total_sacado; //Define o total sacado ao todo

//total do saldo
int saldoExistente = 0; //saldo disponivel, ele multiplica a quantidade de cedulas pelo seu valor;

//--------------------- SISTEMA CADASTRO ---------------------------

//objetivo:escolhe dentre as letras do alfabeto ('a'..'z') uma letra aleatoriamente
//parametros: nenhum
//retorno:a letra do alfabeto
char geraAlfabeto() {
    int i;
    char letras[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    i=rand()%26;
    return(letras[i]-32);
}

//objetivo:escolhe dentre os numeros ('0'..'9') uma numero aleatoriamente
//parametros: nenhum
//retorno:o numero
char geraNumero() {
    int i;
    char numeros[] = { '0','1','2','3','4','5','6','7','8','9'};

    i=rand()%9;
    return(numeros[i]);
}

//objetivo:insere pontuacao '- ' em uma conta
//parametros: conta_origem a conta a ser recebida no formato 999999x
//retorno: conta_destino a conta com as pontuacoes inseridas no formato 999999-x
void insere_pontuacao_conta_corrente(char conta_origem[], char conta_destino[]) {
    sprintf(conta_origem, "%c%c%c%c%c%c-%c",
    conta_origem[0], conta_origem[1], conta_origem[2],
    conta_origem[3], conta_origem[4], conta_origem[5],
    conta_origem[6], conta_origem[7], conta_origem[8]);
}

//objetivo:gera aleatoriamente um numero de conta corrente no formato 999.999-X
//parametros: c onde armazera a conta gerada
//retorno:nenhum
void geraContaCorrente(char c[]) {
    int i;
    for (i = 0; i < 6; i++) {
        c[i] = geraNumero();
    }
    c[6] = geraAlfabeto();
    c[7] = '\0';
    insere_pontuacao_conta_corrente(c, c);
}

//objetivo:verifica se um cpf no formato 999.999.999-99 e valido
//parametros: cpf a ser verificado
//retorno: 1 se cpf e valido ou 0 se cpf nao e valido
int verifica_cpf_valido(char cpf[]) {
    int valido = 1;
    int i;
    int soma = 0;
    int dv1, dv2;
    int numero_igual = 0;

    // Verifica se o CPF tem 11 d�gitos (sem pontuacao) ou 14 digitos (com pontuacao)
    if (strlen(cpf) == 11) {
        // Verifica se o CPF tem algum caracter que nao seja numero
        for (i = 0; i < 11; i++) {
            if (cpf[i] < '0' || cpf[i] > '9') {
                valido = 0;
                i = 11;
            }

            if (i < 10 && cpf[i] == cpf[i+1]) {
                numero_igual++;
            }
        }

        if (numero_igual == 10) {
            valido = 0;
        }

        // Verifica se o CPF eh valido atraves do calculo oficial do governo
        if (valido == 1) {
            for (i = 0; i < 9; i++) {
                soma += (cpf[i] - '0') * (10 - i);
            }
            dv1 = 11 - (soma % 11);
            if (dv1 > 9) {
                dv1 = 0;
            }
            if (dv1 != cpf[9] - '0') {
                valido = 0;
            } else {
                soma = 0;
                for (i = 0; i < 10; i++) {
                    soma += (cpf[i] - '0') * (11 - i);
                }
                dv2 = 11 - (soma % 11);
                if (dv2 > 9) {
                    dv2 = 0;
                }
                if (dv2 != cpf[10] - '0') {
                    valido = 0;
                }
            }
        }
    } else if (strlen(cpf) == 14) { //com pontuacao

        //Verifica se a pontuacao realmente esta correta:
        if ((cpf[3] == '.') && (cpf[7] == '.') && (cpf[11] == '-')) {

            // Remove a pontua��o do CPF
            char cpf_sem_pontuacao[12];
            int j = 0;
            for (i = 0; i < 14; i++) {
                if (cpf[i] != '.' && cpf[i] != '-') {
                    cpf_sem_pontuacao[j] = cpf[i];
                    j++;
                }
            }
            cpf_sem_pontuacao[11] = '\0';

            // Verifica se o CPF tem algum caracter que nao seja numero
            for (i = 0; i < 11; i++) {
                if (cpf_sem_pontuacao[i] < '0' || cpf_sem_pontuacao[i] > '9') {
                    valido = 0;
                    break;
                }

                //casos como 11111111111
                if (i < 10 && cpf_sem_pontuacao[i] == cpf_sem_pontuacao[i+1]) {
                    numero_igual++;
                }
            }

            if (numero_igual == 10) {
                valido = 0;
            }

            // Verifica se o CPF eh valido atraves do calculo oficial do governo
            if (valido == 1) {
                for (i = 0; i < 9; i++) {
                    soma += (cpf_sem_pontuacao[i] - '0') * (10 - i);
                }
                dv1 = 11 - (soma % 11);
                if (dv1 > 9) {
                    dv1 = 0;
                }
                if (dv1 != cpf_sem_pontuacao[9] - '0') {
                    valido = 0;
                } else {
                    soma = 0;
                    for (i = 0; i < 10; i++) {
                        soma += (cpf_sem_pontuacao[i] - '0') * (11 - i);
                    }
                    dv2 = 11 - (soma % 11);
                    if (dv2 > 9) {
                        dv2 = 0;
                    }
                    if (dv2 != cpf_sem_pontuacao[10] - '0') {
                        valido = 0;
                    }
                }
            }
        } else {
            valido = 0;
        }
    } else {
        valido = 0;
    }
    return(valido);
}

//objetivo:verifica se uma conta no formato 999999-x e valida
//parametros: conta a ser verificado
//retorno: 1 se conta e valida ou 0 se nao e valida
int verifica_conta_valida(char contaCorrente[]) {
    int valido = 1;
    int i;

    if (strlen(contaCorrente) == 7) {
        for (i = 0; i < 6; i++) {
            if (contaCorrente[i] < '0' || contaCorrente[i] > '9') {
                valido = 0;
                i = 7;
            }
        }

        // Verifica se o 7� caractere � uma letra
        if (contaCorrente[6] < 'A' || contaCorrente[6] > 'Z') {
            valido = 0;
        }

    } else if (strlen(contaCorrente) == 8) {
        for (i = 0; i < 6; i++) {
            if (contaCorrente[i] < '0' || contaCorrente[i] > '9') {
                valido = 0;
                i = 7;
            }
        }

        if (contaCorrente[6] != '-') {
            valido = 0;
        }

        // Verifica se o 7� caractere � uma letra
        if (contaCorrente[7] < 'A' || contaCorrente[7] > 'Z') {
            valido = 0;
        }

    } else {
        valido = 0;
    }
    return(valido);
}

//objetivo:insere pontuacoes '.' e '- ' em um cpf
//parametros: cpf_origem o cpf recebido no format 99999999999
//retorno: cpf_destino o cpf com as pontuacoes inseridas no formato 999.999.999-99
void insere_pontuacao_cpf(char cpf_origem[], char cpf_destino[]) {
    sprintf(cpf_destino, "%c%c%c.%c%c%c.%c%c%c-%c%c",
    cpf_origem[0], cpf_origem[1], cpf_origem[2],
    cpf_origem[3], cpf_origem[4], cpf_origem[5],
    cpf_origem[6], cpf_origem[7], cpf_origem[8],
    cpf_origem[9], cpf_origem[10]);
}

//objetivo:calcula o primeiro digito verificador de um cpf no formato 999999999
//parametros: cpf o cpf sem os digitos verificadores
//retorno: o calculo do primeiro digito verificador
int obtem_primeiro_digito_verificador(char cpf[]) {
    int digito;
    int soma = 0;
    int i;

    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }

    digito = 11 - (soma % 11);

    if (digito > 9) {
        digito = 0;
    }

    return(digito);
}

//objetivo:calcula o segundo digito verificador de um cpf no formato 999999999
//parametros: cpf sem os digitos verificadores
//retorno: o calculo do segundo digito verificador
int obtem_segundo_digito_verificador(char cpf[]) {
    int digito;
    int soma = 0;
    int i;

    for (i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }

    digito = 11 - (soma % 11);

    if (digito > 9) {
        digito = 0;
    }

    return(digito);
}

//objetivo:gera aleatoriamente um cpf valido no formato 999.999.999-99
//parametros: cpf onde sera armazenado o cpf valido
//retorno: nenhum
void gera_cpf_valido(char cpf[]) {
    int i;
    do {
        for (i = 0; i < 11; i++) {
            cpf[i] = '0'; // inicializa todos os elementos com zeros
        }
        for (i = 0; i < 9; i++) {
            cpf[i] = geraNumero();
        }
        cpf[9] = obtem_primeiro_digito_verificador(cpf) + '0';
        cpf[10] = obtem_segundo_digito_verificador(cpf) + '0';
        cpf[11] = '\0';
    } while (verifica_cpf_valido(cpf) != 1);
    insere_pontuacao_cpf(cpf, cpf);
}

//objetivo: verifica se o cpf eh cadastrado.
//parametros: cpf em ambos os formatos: 999.999.999-99 ou 99999999999
//Retorno: 0 se for cadastrado, 1 se nao for.
int verifica_cpf_cadastrados(char *cpf) {
    int valido = 1;
    for (int i = 0; i < clientesCadastrados; i++) {
        if (strcmp(cpf, cpfClientes[i]) == 0) {
            valido = 0;
        }
    }
    return (valido);
}

//objetivo: verifica se a conta eh cadastrada.
//parametros: conta em ambos os formatos: 999999-x ou 999999x
//Retorno: 0 se for cadastrada, 1 se nao for.
int verifica_contascorrentes_cadastradas(char *contaCorrente) {
    int valido = 1;
    for (int i = 0; i < clientesCadastrados; i++) {
        if (strcmp(contaCorrente, contasCorrentes[i]) == 0) {
            valido = 0;
        }
    }
    return (valido);
}

//objetivo: cadastra um cliente, seu cpf e conta corrente
//parametros: cpf no formatos: 999.999.999-99 e conta no formato 999999-x
//Retorno: nenhum
void cadastrar_cliente(char cpf[], char contaCorrente[]) {
    int opcaoCadastro;

    do {
        printf("\n\nDeseja cadastrar no sistema?");
        printf("\n1 - Sim");
        printf("\n2 - Nao\n\n");

        scanf("%d", &opcaoCadastro);

        switch (opcaoCadastro) {
        case 1:
            strcpy(cpfClientes[clientesCadastrados], cpf);
            strcpy(contasCorrentes[clientesCadastrados], contaCorrente);

            printf("\nCPF %s e Conta Corrente %s cadastrados com sucesso!\n", cpfClientes[clientesCadastrados], contasCorrentes[clientesCadastrados]);
            clientesCadastrados++;
            break;
        case 2:
            printf("\nOperacao Cancelada\n");
            break;
        default:
            printf("\nOpcao invalida\n\n");
            break;
        }
    } while (opcaoCadastro != 2 && opcaoCadastro != 1);
}

//objetivo: altera conta corrente
//parametros: nenhum
//Retorno: nenhum
void alterar_conta_corrente() {
    char conta_atual[9];
    char conta_nova[9];
    int conta_cadastrada;

    printf("\nDigite sua Conta Corrente atual: \n");
    scanf("%9s", conta_atual);

    if (strlen(conta_atual) == 7) {
        insere_pontuacao_conta_corrente(conta_atual, conta_atual);
    }

    conta_cadastrada = verifica_contascorrentes_cadastradas(conta_atual);

    if (conta_cadastrada == 1) {
        printf("\nConta nao encontrada.\n");
    } else {
        int indice_conta;
        for (int i = 0; i < clientesCadastrados; i++) {
            if (strcmp(conta_atual, contasCorrentes[i]) == 0) {
                indice_conta = i;
                printf("\nConta corrente encontrada!\n");
                printf("CPF: %s\n", cpfClientes[i]);
                printf("Conta Corrente: %s\n", contasCorrentes[i]);
                i = clientesCadastrados + 1;
            }
        }

        if (saquesPorCliente[indice_conta] > 0) {
            printf("\nNao sera possivel alterar conta do cliente.");
            printf("\nCliente ja realizou um saque.\n");
        } else {

            printf("\nDigite a nova conta corrente:\n");
            scanf("%9s", conta_nova);

            if (strlen(conta_nova) == 7) {
                insere_pontuacao_conta_corrente(conta_nova, conta_nova);
            }

            if (verifica_conta_valida(conta_nova) == 0) {
                printf("\nConta Nova Invalida");
                printf("\nOperacao Cancelada\n");
            } else {
                strcpy(contasCorrentes[indice_conta], conta_nova);
                printf("\nConta corrente alterada com sucesso!\n");
            }
        }
    }
}

//objetivo: altera conta cpf
//parametros: nenhum
//Retorno: nenhum
void alterar_cpf() {
    char cpf_atual[15];
    char cpf_novo[15];
    int cpf_cadastrado;

    printf("\nDigite o CPF atual: \n");
    scanf("%15s", cpf_atual);

    if (strlen(cpf_atual) == 11) {
        insere_pontuacao_cpf(cpf_atual, cpf_atual);
    }

    cpf_cadastrado = verifica_cpf_cadastrados(cpf_atual);

    if (cpf_cadastrado == 1) {
        printf("\nCPF nao encontrado.\n");
    } else {
        //verifica se tem saldo nesse cpf:
        int indice_cpf;
        for (int i = 0; i < clientesCadastrados; i++) {
            if (strcmp(cpf_atual, cpfClientes[i]) == 0) {
                indice_cpf = i;
                printf("\nCPF encontrado!\n");
                printf("CPF: %s\n", cpfClientes[i]);
                printf("Conta Corrente: %s\n", contasCorrentes[i]);
                i = clientesCadastrados + 1;
            }
        }

        if (saquesPorCliente[indice_cpf] > 0) {
            printf("\nNao sera possivel alterar cpf do cliente.");
            printf("\nCliente ja realizou um saque.\n");
        } else {
            printf("\nDigite o novo CPF:\n");
            scanf("%15s", cpf_novo);

            if (strlen(cpf_novo) == 11) {
                insere_pontuacao_cpf(cpf_novo, cpf_novo);
            }

            if (verifica_cpf_valido(cpf_novo) == 0) {
                printf("\nCPF Novo Invalido");
                printf("\nOperacao Cancelada\n");
            } else {
                strcpy(cpfClientes[indice_cpf], cpf_novo);
                printf("\nCPF alterado com sucesso!\n");
            }
        }
    }
}

//objetivo: exclui um cliente
//parametros: nenhum
//Retorno: nenhum
void excluir_cliente() {
    char contaCorrente[9];
    int encontrado = 0;
    int opcaoExcluir;

    if (clientesCadastrados > 0) {
        printf("\nDigite a conta corrente do cliente a ser excluido: \n");
        scanf("%s", contaCorrente);

        if (strlen(contaCorrente) == 7) {
            insere_pontuacao_conta_corrente(contaCorrente, contaCorrente);
        }

        for (int i = 0; i < clientesCadastrados; i++) {
            if (strcmp(contaCorrente, contasCorrentes[i]) == 0) {
                encontrado = 1;
                printf("\nCliente encontrado!\n");
                printf("CPF: %s\n", cpfClientes[i]);
                printf("Conta Corrente: %s\n", contasCorrentes[i]);

                if (saquesPorCliente[i] > 0) {
                    printf("\nNao sera possivel excluir cliente.");
                    printf("\nCliente ja realizou um saque.\n");
                } else {
                    printf("\nDeseja excluir?");
                    printf("\n1 - Sim");
                    printf("\n2 - Nao\n\n");
                    scanf("%d", &opcaoExcluir);

                    if (opcaoExcluir == 1) {
                        // Exclui o CPF e a conta corrente do cliente
                        for (int j = i; j < clientesCadastrados - 1; j++) {
                            strcpy(cpfClientes[j], cpfClientes[j + 1]);
                            strcpy(contasCorrentes[j], contasCorrentes[j + 1]);
                        }
                        clientesCadastrados--;
                        printf("\nCliente excluido com sucesso!\n");
                    } else {
                        printf("\nOperacao cancelada.\n");
                    }
                    break;
                }
            }
        }

        if (!encontrado) {
            printf("\nConta corrente nao encontrada.\n");
        }
    } else {
        printf("\nNao ha clientes cadastrados para excluir.\n");
    }
}

//objetivo: exibe o menu incluir
//parametros: nenhum
//Retorno: nenhum
void exibir_menu_incluir() {
    char cpf[15];
    char contaCorrente[9];

    int cpf_cadastrado;
    int conta_cadastrada;

    if (clientesCadastrados < 50) {
        do {
            gera_cpf_valido(cpf);
            geraContaCorrente(contaCorrente);

            cpf_cadastrado = verifica_cpf_cadastrados(cpf);
            conta_cadastrada = verifica_contascorrentes_cadastradas(contaCorrente);
        } while ((conta_cadastrada == 0) || (cpf_cadastrado == 0));

        printf("\nDados gerados com sucesso!");
        printf("\nCPF: %s", cpf);
        printf("\nConta Corrente: %s", contaCorrente);

        cadastrar_cliente(cpf, contaCorrente);

    } else {
        printf("\nNao foi possivel incluir novo cliente.");
        printf("\nLimite de clientes cadastrados atingido!\n");
    }
}

//objetivo: exibe o menu alterar
//parametros: nenhum
//Retorno: nenhum
void exibir_menu_alterar() {
    int opcaoAlterar;

    do {
        printf("\nMENU ALTERAR\n");
        printf("1 - Alterar CPF\n");
        printf("2 - Alterar Conta Corrente\n");
        printf("3 - Voltar\n\n");

        scanf("%d", &opcaoAlterar);

        switch(opcaoAlterar) {
        case 1:
            alterar_cpf();
            break;
        case 2:
            alterar_conta_corrente();
            break;
        case 3:
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }

    } while (opcaoAlterar != 3);
}

//objetivo: exibe os clientes cadastrados no sistema
//parametros: nenhum
//Retorno: nenhum
void exibir_clientes_cadastrados() {
    if (clientesCadastrados > 0) {
        printf("\nCLIENTES CADASTRADOS NO SISTEMA:\n");
        for (int i = 0; i < clientesCadastrados; i++) {

            printf("\nCliente %d:\n", i + 1);
            printf("CPF: %s\n", cpfClientes[i]);
            printf("Conta Corrente: %s\n", contasCorrentes[i]);
        }
    } else {
        printf("\nNao ha clientes cadastrados no momento.\n");
    }
}

//--------------- SISTEMA DE CEDULAS/RELATORIOS ----------------
//objetivo: decompoe um numero por extenso
//parametros: um numero qualquer
//Retorno: o numero e sua versao por extenso
void num_extenso (int num_decomposto){

    //variaveis locais
    char val_Extenso[80]; // o numero por extenso
    char final_extenso[8];   // diferencia real, reais, cedula ou cedulas
    // vai ser settado antes de realizar a chamada da funcao, 0 se for saque e 1 se for cedulas
    int e1, e2, e3, e4, e5, e6;

    // decompoe o numero para a analise
    e6 = num_decomposto % 10;                 // casa da unidade
    e5 = (num_decomposto % 100) / 10;         // dezena
    e4 = (num_decomposto % 1000) / 100;       // centena
    e3 = (num_decomposto % 10000) / 1000;     // unidade milhar
    e2 = (num_decomposto % 100000) / 10000;   // dezena milhar
    e1 = (num_decomposto % 1000000) / 100000; // centena milhar

    strcpy(val_Extenso, ""); // se nao tiver isso, ele mostra o valor de modo incorreto

    if (e1 == 0 && e2 == 0 && e3 == 0 && e4 == 0 && e5 == 0 && e6 == 0){
        strcat (val_Extenso, "zero ");

    }else{
        if (e1 != 0){ // centena milhar
            if (e1 == 1 && e2 == 0 && e3 == 0){ // caso seja 100
                strcat(val_Extenso, "cem ");

            }else{
                strcat(val_Extenso, "cento ");
            }
        }

        if (e2 != 0){ // dezena milhar
            if (e1 != 0 && (e2 != 0 || e3 !=0)){ //verifica se precisa do "e"
                strcat(val_Extenso, "e ");
            }
            if (e2 == 1 && e3 == 0){
                strcat(val_Extenso, "dez ");

            }else if (e2 == 1 && e3 == 1){
                strcat(val_Extenso, "onze ");

            }else if (e2 == 1 && e3 == 2){
                strcat(val_Extenso, "doze ");

            }else if (e2 == 1 && e3 == 3){
                strcat(val_Extenso, "treze ");

            }else if (e2 == 1 && e3 == 4){
                strcat(val_Extenso, "quatorze ");

            }else if (e2 == 1 && e3 == 5){
                strcat(val_Extenso, "quinze ");

            }else if (e2 == 1 && e3 == 6){
                strcat(val_Extenso, "dezesseis ");

            }else if (e2 == 1 && e3 == 7){
                strcat(val_Extenso, "dezessete ");

            }else if (e2 == 1 && e3 == 8){
                strcat(val_Extenso, "dezoito ");

            }else if (e2 == 1 && e3 == 9){
                strcat(val_Extenso, "dezenove ");

            }else if (e2 == 2){
                strcat(val_Extenso, "vinte ");

            }else if (e2 == 3){
                strcat(val_Extenso, "trinta ");

            }else if (e2 == 4){
                strcat(val_Extenso, "quarenta ");

            }else if (e2 == 5){
                strcat(val_Extenso, "cinquenta ");

            }else if (e2 == 6){
                strcat(val_Extenso, "sessenta ");

            }else if (e2 == 7){
                strcat(val_Extenso, "setenta ");

            }else if (e2 == 8){
                strcat(val_Extenso, "oitenta ");

            }else if (e2 == 9){
                strcat(val_Extenso, "noventa ");

            }
        }

        if (e3 != 0 && e2 != 1){
            if (e2 != 0 || e1 != 0){ // verifica se precisa do "e"
                strcat(val_Extenso, "e ");
            }

            if (e3 == 1 && (e2 != 0 || e1 != 0)){
                strcat(val_Extenso, "um ");

            }else if (e3 == 2 && saque_ou_cedulas == 0){ //caso seja saque
                strcat(val_Extenso, "dois ");

            }else if (e3 == 2 && saque_ou_cedulas == 1){ // caso seja cedulas
                strcat(val_Extenso, "duas ");

            }else if (e3 == 3){
                strcat(val_Extenso, "tres ");

            }else if (e3 == 4){
                strcat(val_Extenso, "quatro ");

            }else if (e3 == 5){
                strcat(val_Extenso, "cinco ");

            }else if (e3 == 6){
                strcat(val_Extenso, "seis ");

            }else if (e3 == 7){
                strcat(val_Extenso, "sete ");

            }else if (e3 == 8){
                strcat(val_Extenso, "oito ");

            }else if (e3 == 9){
                strcat(val_Extenso, "nove ");

            }
        }

        if ((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && (e5 == 0 && e6 == 0))){ // verifica se tem numero na casa dos milhares e se a casa das unidades termina com dois 0
            strcat(val_Extenso, "mil e ");

        }else if (e1 != 0 || e2 != 0 || e3 != 0){
            strcat(val_Extenso, "mil ");
        }

        if (e4 != 0){ // casa das centenas das unidades
            if (e4 == 1 && e5 == 0 && e6 == 0){
                strcat(val_Extenso, "cem ");

            }else if (e4 == 1){
                strcat(val_Extenso, "cento ");

            }else if (e4 == 2 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "duzentos ");

            }else if (e4 == 2 && saque_ou_cedulas == 1){ // se for cedulas
                strcat(val_Extenso, "duzentas ");

            }else if (e4 == 3 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "trezentos ");

            }else if (e4 == 3 && saque_ou_cedulas == 1){ // se for cedulas
                strcat(val_Extenso, "trezentas ");

            }else if (e4 == 4 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "quatrocentos ");

            }else if (e4 == 4 && saque_ou_cedulas == 1){ // se for cedulas
                strcat(val_Extenso, "quatrocentas ");

            }else if (e4 == 5 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "quinhentos ");

            }else if (e4 == 5 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "quinhentas ");

            }else if (e4 == 6 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "seiscentos ");

            }else if (e4 == 6 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "seiscentas ");

            }else if (e4 == 7 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "setecentos ");

            }else if (e4 == 7 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "setecentas ");

            }else if (e4 == 8 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "oitocentos ");

            }else if (e4 == 8 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "oitocentas ");

            }else if (e4 == 9 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "novecentos ");

            }else if (e4 == 9 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "novecentas ");
            }
        }

        if (e5 != 0){ // dezena das unidades
            if ((e4 != 0 || e6 != 0) || ((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && (e5 == 0 && e6 == 0)))){
                strcat(val_Extenso, "e ");
            }
            if (e5 == 1 && e6 == 0){
                strcat(val_Extenso, "dez ");

            }else if (e5 == 1 && e6 == 1){
                strcat(val_Extenso, "onze ");

            }else if (e5 == 1 && e6 == 2){
                strcat(val_Extenso, "doze ");

            }else if (e5 == 1 && e6 == 3){
                strcat(val_Extenso, "treze ");

            }else if (e5 == 1 && e6 == 4){
                strcat(val_Extenso, "quatorze ");

            }else if (e5 == 1 && e6 == 5){
                strcat(val_Extenso, "quinze ");

            }else if (e5 == 1 && e6 == 6){
                strcat(val_Extenso, "dezesseis ");

            }else if (e5 == 1 && e6 == 7){
                strcat(val_Extenso, "dezessete ");

            }else if (e5 == 1 && e6 == 8){
                strcat(val_Extenso, "dezoito ");

            }else if (e5 == 1 && e6 == 9){
                strcat(val_Extenso, "dezenove ");

            }else if (e5 == 2){
                strcat(val_Extenso, "vinte ");

            }else if (e5 == 3){
                strcat(val_Extenso, "trinta ");

            }else if (e5 == 4){
                strcat(val_Extenso, "quarenta ");

            }else if (e5 == 5){
                strcat(val_Extenso, "cinquenta ");

            }else if (e5 == 6){
                strcat(val_Extenso, "sessenta ");

            }else if (e5 == 7){
                strcat(val_Extenso, "setenta ");

            }else if (e5 == 8){
                strcat(val_Extenso, "oitenta ");

            }else if (e5 == 9){
                strcat(val_Extenso, "noventa ");

            }
        }


        if (e6 != 0 && e5 != 1){ // unidades
            if (e5 != 0 || e4 != 0){
                strcat(val_Extenso, "e ");

            }else if (e6 != 0 && e1 != 0){
                strcat(val_Extenso, "e ");

            // para caso nao tenha adicionado o "e" antes, em situacoes mais especifica
            // como quando colocado numeros como "3001", sem esse else, sairia como "tres mil um"
            }else if ((e1 != 0 || e2 != 0 || e3 != 0) && (e5 == 0 || e6 == 0)){
                strcat(val_Extenso, "e ");

            }
            if (e6 == 1 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "um ");

            }else if (e6 == 1 && saque_ou_cedulas == 1){ // se for cedula
                strcat (val_Extenso, "uma ");

            }else if (e6 == 2 && saque_ou_cedulas == 0){ // se for saque
                strcat(val_Extenso, "dois ");

            }else if (e6 == 2 && saque_ou_cedulas == 1){ // se for cedula
                strcat(val_Extenso, "duas ");

            }else if (e6 == 3){
                strcat(val_Extenso, "tres ");

            }else if (e6 == 4){
                strcat(val_Extenso, "quatro ");

            }else if (e6 == 5){
                strcat(val_Extenso, "cinco ");

            }else if (e6 == 6){
                strcat(val_Extenso, "seis ");

            }else if (e6 == 7){
                strcat(val_Extenso, "sete ");

            }else if (e6 == 8){
                strcat(val_Extenso, "oito ");

            }else if (e6 == 9){
                strcat(val_Extenso, "nove ");

            }
        }
    }
    // Plural, singular, cedulas ou reais:
    if (saque_ou_cedulas == 0){
        if (num_decomposto == 1){
            strcpy(final_extenso, "real");

        }else{
            strcpy(final_extenso, "reais");
        }

    }else if (saque_ou_cedulas == 1){
        if (num_decomposto == 1){
            strcpy(final_extenso, "cedula");

        }else{
            strcpy(final_extenso, "cedulas");
        }
    }

    printf ("%d (%s%s)\n", num_decomposto, val_Extenso, final_extenso);
}

//objetivo: exibe o relatorio com a quantidade de cedulas disponiveis no sistema
//parametros: nenhum
//Retorno: relatorio com a quantidade de cedulas disponiveis no sistema
void relatorio_quantidade_cedulas(){

    saque_ou_cedulas = 1; // para definir que sao sobre cedulas

    printf("\n--------------------------------------------------------------");
    printf("\nRELATORIO 'QUANTIDADE DE CEDULAS EXISTENTES'");
    printf ("\n--------------------------------------------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf ("Cedulas de %d: ", valor_cedula[i]);
        num_extenso(quantidade_cedulas[i]);
    }
    printf ("--------------------------------------------------------------\n");
}

//objetivo: exibe o relatorio com todos os valores sacados por cada cliente, seus cpfs e contas
//parametros: nenhum
//Retorno: relatorio com todos os valores sacados por cada cliente, seus cpfs e contas
void relatorio_valores_sacados(){
    saque_ou_cedulas = 0; // para definir que sera decomposto em reais

    printf("\n--------------------------------------------------------------");
    printf("\nRELATORIO 'VALORES SACADOS'");
    printf ("\n--------------------------------------------------------------");

    if (clientesCadastrados > 0) {
        for (int i = 0; i < clientesCadastrados; i++) {
            printf("\n%s %s ", contasCorrentes[i], cpfClientes[i]);

            if (totalSacadoCliente[i] == 0) {
                printf("\n                             Nenhum saque realizado.\n");
            } else {
                for (int j = 0; j < saquesPorCliente[i]; j++) {
                    if (j == 0) {
                        printf("     R$: %d", valorSaqueClientes[i][j]);
                    } else {
                        printf("\n                             R$: %d", valorSaqueClientes[i][j]);
                    }
                }

                printf("\n                                       R$: %d", totalSacadoCliente[i]);
            }
        }
    } else {
        printf("\nNao ha clientes cadastrados no momento.");
    }
    printf("\n--------------------------------------------------------------");
    //Valor total sacado;
    printf ("\nR$"); // para mostrar o R$ antes da saldo do procedimento "num_extenso", que printa o numero e ele extenso;
    num_extenso(total_sacado);
    printf ("--------------------------------------------------------------\n");
}

//objetivo: exibe o relatorio com o saldo existente do sistema
//parametros: nenhum
//Retorno: relatorio com o saldo existente do sistema
void relatorio_saldo_existente() {
    saldoExistente = 0;

    for (int i = 0; i < 8; i++) {
        saldoExistente += (valor_cedula[i] * quantidade_cedulas[i]);
    }

    printf("\n--------------------------------------------------------------");
    printf("\nRELATORIO 'VALOR DO SALDO EXISTENTE'");
    printf("\n--------------------------------------------------------------");
    printf("\nRS:");
    num_extenso(saldoExistente);
    printf("--------------------------------------------------------------\n");
}

//------------------------- SISTEMA DO MENU ------------------------

//objetivo: realiza o saque de um valor
//parametros: nenhum
//Retorno: o valor sacado (numero e por extenso) e quantidade de cedulas usadas
void REALIZAR_SAQUE() {
    char CONTA_CORRENTE[9];

    int CLIENTE_INDICE = -1;
    int VALOR_SAQUE;
    int VALOR_RESTANTE;

    int cedulas_usadas[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    //Calcula o saldo existente;
    saldoExistente = 0;

    for (int i = 0; i < 8; i++) {
        saldoExistente += (valor_cedula[i] * quantidade_cedulas[i]);
    }

    // solicitando ao usuario o numero da conta corrente para o saque
    printf("\nDigite o numero da conta corrente para saque:\n");
    scanf("%9s", CONTA_CORRENTE);

    //se o usuario por sem pontuacao ele insere
    if (strlen(CONTA_CORRENTE) == 7) {
        insere_pontuacao_conta_corrente(CONTA_CORRENTE, CONTA_CORRENTE);
    }

    // busca o cliente pelo numero da conta corrente
    for (int i = 0; i < clientesCadastrados; i++) {
        if (strcmp(CONTA_CORRENTE, contasCorrentes[i]) == 0) {
            CLIENTE_INDICE = i;
            break;
        }
    }

    // verifica se a conta foi encontrada
    if (CLIENTE_INDICE == -1) {
        printf("\nConta corrente nao encontrada.\n");
    } else {
        printf("\nCliente encontrado!\n");
        printf("CPF: %s\n", cpfClientes[CLIENTE_INDICE]);

        // solicitando o valor do saque
        printf("\nDigite o valor do saque:\n");
        scanf("%d", &VALOR_SAQUE);

        // verifica se o valor do saque e valido e se ha saldo suficiente na maquina
        if (VALOR_SAQUE <= 0) {
            printf("\nValor invalido.\n");
        } else if (VALOR_SAQUE > saldoExistente) {
            printf("\nSaldo insuficiente.\n");
        } else {
            // inicializa o valor restante com o valor do saque
            VALOR_RESTANTE = VALOR_SAQUE;

            // calcula a quantidade de cedulas que serao usadas para o saque
            for (int i = 0; i < 8; i++) {
                if (VALOR_RESTANTE <= 0) {
                    break;
                }

                // calcula quantas cedulas do tipo atual sao necessarias
                cedulas_usadas[i] = VALOR_RESTANTE / valor_cedula[i];

                // verifica se a quantidade de cedulas disponiveis e suficiente
                if (cedulas_usadas[i] > quantidade_cedulas[i]) {
                    cedulas_usadas[i] = quantidade_cedulas[i];
                }

                // armazena a quantidade de cedulas usadas e ajusta o valor restante
                VALOR_RESTANTE -= cedulas_usadas[i] * valor_cedula[i];
            }

            /* se o valor restante for maior que zero, nao e possivel realizar o saque
            if (VALOR_RESTANTE > 0) {
                printf("\nNao ha cedulas suficientes para completar o saque.\n");
                return;
            }
            */

            // atualiza a quantidade de cedulas e o saldo do cliente apos o saque
            for (int i = 0; i < 8; i++) {
                quantidade_cedulas[i] -= cedulas_usadas[i];
            }

            valorSaqueClientes[CLIENTE_INDICE][saquesPorCliente[CLIENTE_INDICE]] = VALOR_SAQUE;
            saquesPorCliente[CLIENTE_INDICE]++;
            totalSacadoCliente[CLIENTE_INDICE] += VALOR_SAQUE;
            total_sacado += VALOR_SAQUE;

            // mensagem de sucesso
            printf("\nSaque realizado com sucesso.");
            printf("\nValor sacado de R$:");
            num_extenso(VALOR_SAQUE);

            // exibir as cedulas utilizadas no saque
            printf("\nCedulas utilizadas:\n");
            for (int i = 0; i < 8; i++) {
                if (cedulas_usadas[i] > 0) {
                    printf("\Cedula de R$ %d: %d unidade(s)\n", valor_cedula[i], cedulas_usadas[i]);
                }
            }

        }

    }
}

//objetivo: exibe o menu de relatorios
//parametros: nenhum
//Retorno: menu relatorios
void exibir_menu_relatorios() {
    int opcaoRelatorio;
    do {
        printf("\nMENU RELATORIOS\n");
        printf("1 - Valores Sacados\n");
        printf("2 - Valor do Saldo Existente\n");
        printf("3 - Quantidade de Cedulas Existentes\n");
        printf("4 - Voltar ao Menu Principal\n\n");

        scanf("%d", &opcaoRelatorio);
        switch(opcaoRelatorio) {
        case 1:
            relatorio_valores_sacados();
            break;
        case 2:
            relatorio_saldo_existente();
            break;
        case 3:
            relatorio_quantidade_cedulas();
            break;
        case 4:
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }
    } while (opcaoRelatorio != 4);
}

//objetivo: exibe o menu de clientes
//parametros: nenhum
//Retorno: menu clientes
void exibir_menu_cliente() {
    int opcaoCliente;
    do {
        printf("\nMENU CLIENTE\n");
        printf("1 - Incluir\n");
        printf("2 - Mostrar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n\n");

        scanf("%d", &opcaoCliente);
        switch(opcaoCliente) {
        case 1:
            exibir_menu_incluir();
            break;
        case 2:
            exibir_clientes_cadastrados();
            break;
        case 3:
            exibir_menu_alterar();
            break;
        case 4:
            excluir_cliente();
            break;
        case 5:
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }
    } while (opcaoCliente != 5);
}

//objetivo: exibe o menu principal
//parametros: nenhum
//Retorno: menu principal
void exibir_menu_principal() {
    int opcaoPrincipal;

    printf("SEJA BEM VINDO AO CAIXA ELETRONICO\n");
    do {
        printf("\nMENU PRINCIPAL\n");
        printf("1 - Cliente\n");
        printf("2 - Saque\n");
        printf("3 - Relatorios\n");
        printf("4 - Finalizar\n\n");

        scanf("%d", &opcaoPrincipal);

        switch(opcaoPrincipal) {
        case 1:
            exibir_menu_cliente();
            break;
        case 2:
            REALIZAR_SAQUE();
            break;
        case 3:
            exibir_menu_relatorios();
            break;
        case 4:
            printf("\nOperacao Finalizada.");
            printf("\nVolte Sempre. :)\n");
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }
    } while (opcaoPrincipal != 4);
}

//----------------------------MODULO PRINCIPAL ----------------------

//objetivo: Modulo principal
//parametros: nenhum
//Retorno: nenhum
int main() {
    srand(time(NULL));
    exibir_menu_principal();
}
