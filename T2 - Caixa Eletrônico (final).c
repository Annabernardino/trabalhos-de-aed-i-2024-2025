// T2 - Caixa Eletr�nico

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

int main()
{
    // Variaveis do menu:
    int opcaoMenu = 0, opcaoGerente, opcaoAbastecer, quantiaAbastecer;

    // Digitos do cpf:
    char cpfCliente[12];
    int tamanhoCPF, primeiroDigito, digitoCPF, validacao1Digito, validacao2Digito;
    int segundoDigito, digitoMultiplo, numerosIguais;

    // Variaveis do saque:
    int valorSaque, valorDisponivel, auxiliarSaque, totalSacado = 0;

    // Variaveis com a quantidade de cedulas:
    int total350 = 100, total300 = 200, total150 = 400, total50 = 800;
    int total20 = 1600, total5 = 3200, total2 = 6400, total1 = 12800, notasRestantes;

    // Variaveis pra contar cedulas a serem sacadas:
    int quantia350, quantia300, quantia150, quantia50;
    int quantia20, quantia5, quantia2, quantia1;

    // Variaveis para os numeros extensos
    int e0, e1, e2, e3, e4, e5, e6;
    char val_Extenso[80];
    char flexaoReal[7];

    // Inicio do algoritmo:
    printf("SEJA BEM VINDO AO CAIXA ELETRONICO.");

    // Esse while far� o menu repetir at� que a operacao seja finalizada:
    while (opcaoMenu != 3)
    {
        valorDisponivel = (350 * total350) + (300 * total300) + (150 * total150) + (50 * total50) + (20 * total20) + (5 * total5) + (2 * total2) + (1 * total1);

        // Impressao do Menu Principal
        printf("\n\nSelecione uma das opcoes do menu principal:\n");

        printf("1 - Saque\n");
        printf("2 - Gerente\n");
        printf("3 - Finalizar\n\n");
        scanf("%d", &opcaoMenu);

        // Validacao de opcoes do Menu Principal;
        while (opcaoMenu < 1 || opcaoMenu > 3)
        {
            printf("\nNumero invalido. Deve ser uma das opcoes a seguir:\n");
            printf("1 - Saque\n");
            printf("2 - Gerente\n");
            printf("3 - Finalizar\n\n");
            scanf("%d", &opcaoMenu);
        }

        switch (opcaoMenu)
        {
        case 1: // Opcao Saque:
            primeiroDigito = 0;
            segundoDigito = 0;

            printf("\nDigite seu CPF. Somente numeros:\n");
            scanf("%s", cpfCliente);

            // Validacao da quantidade de digitos do CPF:
            while (((tamanhoCPF = strlen(cpfCliente)) != 11))
            {
                printf("\nCPF Invalido. Numero inserido nao possui 11 digitos.");
                printf("\nTente Novamente:\n");
                scanf("%s", cpfCliente);
            }

            // Verificar se os numeros sao iguais:
            numerosIguais = 0;

            for (int k = 0; k <= 9; k++)
            {
                if ((cpfCliente[k]) == (cpfCliente[k + 1]))
                {
                    numerosIguais++;
                }
            }

            // Calculo - 1 Digito do CPf:
            for (int i = 0; i <= 8; i++)
            {
                digitoCPF = cpfCliente[i] - '0';
                digitoMultiplo = digitoCPF * (10 - i);
                primeiroDigito += digitoMultiplo;
            }

            primeiroDigito = ((primeiroDigito * 10) % 11);

            if (primeiroDigito == 10)
            {
                primeiroDigito = 0;
            }

            // Calculo - 2 digito do CPf:
            for (int j = 0; j <= 9; j++)
            {
                digitoCPF = cpfCliente[j] - '0';
                digitoMultiplo = digitoCPF * (11 - j);
                segundoDigito += digitoMultiplo;
            }

            segundoDigito = ((segundoDigito * 10) % 11);

            if (segundoDigito == 10)
            {
                segundoDigito = 0;
            }

            validacao1Digito = cpfCliente[9] - '0';
            validacao2Digito = cpfCliente[10] - '0';

            // Validacao do CPF:
            while ((primeiroDigito != validacao1Digito) || (segundoDigito != validacao2Digito) || (numerosIguais == 10))
            {
                primeiroDigito = 0;
                segundoDigito = 0;

                printf("\nCPF Invalido. Tente Novamente:\n");
                scanf("%s", cpfCliente);

                while (((tamanhoCPF = strlen(cpfCliente)) != 11))
                {
                    printf("\nCPF Invalido. Numero inserido nao possui 11 digitos.");
                    printf("\nTente Novamente\n");
                    scanf("%s", cpfCliente);
                }

                numerosIguais = 0;

                for (int k = 0; k <= 9; k++)
                {
                    if (cpfCliente[k] == cpfCliente[k + 1])
                    {
                        numerosIguais++;
                    }
                }

                for (int i = 0; i <= 8; i++)
                {
                    digitoCPF = cpfCliente[i] - '0';
                    digitoMultiplo = digitoCPF * (10 - i);
                    primeiroDigito += digitoMultiplo;
                }

                primeiroDigito = ((primeiroDigito * 10) % 11);

                if (primeiroDigito == 10)
                {
                    primeiroDigito = 0;
                }

                for (int j = 0; j <= 9; j++)
                {
                    digitoCPF = cpfCliente[j] - '0';
                    digitoMultiplo = digitoCPF * (11 - j);
                    segundoDigito += digitoMultiplo;
                }

                segundoDigito = ((segundoDigito * 10) % 11);

                if (segundoDigito == 10)
                {
                    segundoDigito = 0;
                }

                validacao1Digito = cpfCliente[9] - '0';
                validacao2Digito = cpfCliente[10] - '0';
            }

            // Saque:
            valorDisponivel = (350 * total350) + (300 * total300) + (150 * total150) + (50 * total50) + (20 * total20) + (5 * total5) + (2 * total2) + (1 * total1);
            printf("\nDigite o valor do saque. Sendo um valor inteiro e maior que 0:\n");
            scanf("%d", &valorSaque);

            // Validacao do Saque:
            while (valorSaque < 1 || valorSaque > valorDisponivel)
            {
                if (valorSaque < 1)
                {
                    printf("\nValor invalido. Deve ser maior que 0. Tente novamente:\n");
                }

                if (valorSaque > valorDisponivel)
                {
                    printf("\nValor indisponivel. Tente um valor menor:\n");
                }

                scanf("%d", &valorSaque);
            }

            totalSacado += valorSaque;

            //Algoritmo pra realizar numeros extensos;
            strcpy(val_Extenso, ""); //Reseta o numero extenso
            e6 = valorSaque % 10;
            e5 = (valorSaque % 100) / 10;
            e4 = (valorSaque % 1000) / 100;
            e3 = (valorSaque % 10000) / 1000;
            e2 = (valorSaque % 100000) / 10000;
            e1 = (valorSaque % 1000000) / 100000;

            //Primeiro digito:
            if (e1 == 1 && e2 != 0 && e3 != 0) {
                strcat(val_Extenso, "cento e ");
            } else if (e1 == 1 && e2 == 0 && e3 == 0) {
                strcat(val_Extenso, "cem ");
            } else if (e1 == 2 && e2 == 0 && e3 ==0) {
                strcat(val_Extenso, "duzentos ");
            } else if (e1 == 2 && e2 !=0 && e3 !=0) {
                strcat (val_Extenso, "duzentos e ");
            }

            //Segundo digito:
            if(e2 != 0) { //segundo dígito 0 [0] 0 0 0 0
                if(e2 == 1 && e3 == 0) { //onze, doze, etc
                    strcat(val_Extenso, "dez ");
                } else if(e2 == 1 && e3 == 1) {
                    strcat(val_Extenso, "onze ");
                }else if(e2 == 1 && e3 == 2) {
                    strcat(val_Extenso, "doze ");
                }else if(e2 == 1 && e3 == 3) {
                    strcat(val_Extenso, "treze ");
                }else if(e2 == 1 && e3 == 4) {
                    strcat(val_Extenso, "quatorze ");
                }else if(e2 == 1 && e3 == 5) {
                    strcat(val_Extenso, "quinze ");
                }else if(e2 == 1 && e3 == 6) {
                    strcat(val_Extenso, "dezesseis ");
                }else if(e2 == 1 && e3 == 7) {
                    strcat(val_Extenso, "dezessete ");
                }else if(e2 == 1 && e3 == 8) {
                    strcat(val_Extenso, "dezoito ");
                }else if(e2 == 1 && e3 == 9) {
                    strcat(val_Extenso, "dezenove ");
                }else if (e2 == 2) {
                    strcat(val_Extenso, "vinte ");
                }else if (e2 == 3) {
                    strcat(val_Extenso, "trinta ");
                }else if (e2 == 4) {
                    strcat(val_Extenso, "quarenta ");
                }else if (e2 == 5) {
                    strcat(val_Extenso, "cinquenta ");
                }else if (e2 == 6) {
                    strcat(val_Extenso, "sessenta ");
                }else if (e2 == 7) {
                    strcat(val_Extenso, "setenta ");
                }else if (e2 == 8) {
                    strcat(val_Extenso, "oitenta ");
                } else if (e2 == 9) {
                    strcat(val_Extenso, "noventa ");
                }
            }

            //Terceiro digito:
            if(e3 != 0 && e2 != 1) {
                if(e2 != 0 || e1 != 0) {
                    strcat(val_Extenso, "e ");
                }
                if(e3 == 1 && (e2 != 0 || e1 != 0)) {
                    strcat(val_Extenso, "um ");
                }else if(e3 == 2) {
                    strcat(val_Extenso, "dois ");
                }else if(e3 == 3) {
                    strcat(val_Extenso, "tres ");
                }else if(e3 == 4) {
                    strcat(val_Extenso, "quatro ");
                }else if(e3 == 5) {
                    strcat(val_Extenso, "cinco ");
                }else if(e3 == 6) {
                    strcat(val_Extenso, "seis ");
                }else if(e3 == 7) {
                    strcat(val_Extenso, "sete ");
                }else if(e3 == 8) {
                    strcat(val_Extenso, "oito ");
                }else if(e3 == 9) {
                    strcat(val_Extenso, "nove ");
                }
            }

            //Caso termine em uma centena com dois zeros:
            if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0))) {
                strcat(val_Extenso, "mil e ");
            }else if(e1 != 0 || e2 != 0 || e3 != 0){
                strcat(val_Extenso, "mil ");
            }

            //Quarto digito:
            if (e4 != 0){
                if(e4 == 1 && e5 == 0 && e6 == 0) {
                    strcat(val_Extenso, "cem ");
                }else if(e4 == 1) {
                    strcat(val_Extenso, "cento ");
                }else if(e4 == 2) {
                    strcat(val_Extenso, "duzentos ");
                }else if(e4 == 3) {
                    strcat(val_Extenso, "trezentos ");
                }else if(e4 == 4) {
                    strcat(val_Extenso, "quatrocentos ");
                }else if(e4 == 5) {
                    strcat(val_Extenso, "quinhentos ");
                }else if(e4 == 6) {
                    strcat(val_Extenso, "seiscentos ");
                }else if(e4 == 7) {
                    strcat(val_Extenso, "setecentos ");
                }else if(e4 == 8) {
                    strcat(val_Extenso, "oitocentos ");
                }else if(e4 == 9) {
                    strcat(val_Extenso, "novecentos ");
                }
            }

            //Quinto digito:
            if(e5 != 0) {
                if (e4 != 0) {
                   strcat(val_Extenso, "e ");
                }
                if(e5 == 1 && e6 == 0) {
                    strcat(val_Extenso, "dez ");
                }else if(e5 == 1 && e6 == 1) {
                    strcat(val_Extenso, "onze ");
                }else if(e5 == 1 && e6 == 2) {
                    strcat(val_Extenso, "doze ");
                }else if(e5 == 1 && e6 == 3) {
                    strcat(val_Extenso, "treze ");
                }else if(e5 == 1 && e6 == 4) {
                    strcat(val_Extenso, "quatorze ");
                }else if(e5 == 1 && e6 == 5) {
                    strcat(val_Extenso, "quinze ");
                }else if(e5 == 1 && e6 == 6) {
                    strcat(val_Extenso, "dezesseis ");
                }else if(e5 == 1 && e6 == 7) {
                    strcat(val_Extenso, "dezessete ");
                }else if(e5 == 1 && e6 == 8) {
                    strcat(val_Extenso, "dezoito ");
                }else if(e5 == 1 && e6 == 9) {
                    strcat(val_Extenso, "dezenove ");
                }else if (e5 == 2) {
                    strcat(val_Extenso, "vinte ");
                }else if (e5 == 3) {
                    strcat(val_Extenso, "trinta ");
                }else if (e5 == 4) {
                    strcat(val_Extenso, "quarenta ");
                }else if (e5 == 5) {
                    strcat(val_Extenso, "cinquenta ");
                }else if (e5 == 6) {
                    strcat(val_Extenso, "sessenta ");
                }else if (e5 == 7) {
                    strcat(val_Extenso, "setenta ");
                }else if (e5 == 8) {
                    strcat(val_Extenso, "oitenta ");
                }else if (e5 == 9) {
                    strcat(val_Extenso, "noventa ");
                }
            }

            //Sexto digito:
            if(e6 != 0 && e5 != 1) {
                if(e5 != 0 || e4 != 0) {
                    strcat(val_Extenso, "e ");
                }
                if (e6 != 0 && e1 != 0) {
                    strcat (val_Extenso, "e ");
                }
                if(e6 == 1) {
                    strcat(val_Extenso, "um ");
                }else if(e6 == 2) {
                    strcat(val_Extenso, "dois ");
                }else if(e6 == 3) {
                    strcat(val_Extenso, "tres ");
                }else if(e6 == 4) {
                    strcat(val_Extenso, "quatro ");
                }else if(e6 == 5) {
                    strcat(val_Extenso, "cinco ");
                }else if(e6 == 6) {
                    strcat(val_Extenso, "seis ");
                }else if(e6 == 7) {
                    strcat(val_Extenso, "sete ");
                }else if(e6 == 8) {
                    strcat(val_Extenso, "oito ");
                }else if(e6 == 9) {
                    strcat(val_Extenso, "nove ");
                }
            }

            //Plural e singular:
            strcpy(flexaoReal, "real");
            if(valorSaque > 1) {
                strcpy(flexaoReal, "reais");
            }

            printf("\nSaque de R$%d (%s %s) realizado com sucesso. Voce retirou:", valorSaque, val_Extenso, flexaoReal);

            // Calculo da quantidade de cedulas a ser sacada:
            if (valorSaque >= 350)
            {
                quantia350 = 0;
                auxiliarSaque = 0;

                quantia350 = valorSaque / 350;

                if (quantia350 > total350) {
                    auxiliarSaque = quantia350 - total350;
                    quantia350 = quantia350 - auxiliarSaque;
                }

                total350 -= quantia350;
                valorSaque -= quantia350 * 350;
                printf("\n%d cedula(s) de R$350.", quantia350);
            }

            if (valorSaque >= 300)
            {
                quantia300 = 0;
                auxiliarSaque = 0;

                quantia300 = valorSaque / 300;

                if (quantia300 > total300) {
                    auxiliarSaque = quantia300 - total300;
                    quantia300 = quantia300 - auxiliarSaque;
                }

                total300 -= quantia300;
                valorSaque -= quantia300 * 300;
                printf("\n%d cedula(s) de R$300.", quantia300);
            }

            if (valorSaque >= 150)
            {
                quantia150 = 0;
                auxiliarSaque = 0;

                quantia150 = valorSaque / 150;

                if (quantia150 > total150) {
                    auxiliarSaque = quantia150 - total150;
                    quantia150 = quantia150 - auxiliarSaque;
                }

                total150 -= quantia150;
                valorSaque -= quantia150 * 150;
                printf("\n%d cedula(s) de R$150.", quantia150);
            }

            if (valorSaque >= 50)
            {
                quantia50 = 0;
                auxiliarSaque = 0;

                quantia50 = valorSaque / 50;

                if (quantia50 > total50) {
                    auxiliarSaque = quantia50 - total50;
                    quantia50 = quantia50 - auxiliarSaque;
                }

                total50 -= quantia50;
                valorSaque -= quantia50 * 50;
                printf("\n%d cedula(s) de R$50.", quantia50);
            }

            if (valorSaque >= 20)
            {
                quantia20 = 0;
                auxiliarSaque = 0;

                quantia20 = valorSaque / 20;

                if (quantia20 > total20) {
                    auxiliarSaque = quantia20 - total20;
                    quantia20 = quantia20 - auxiliarSaque;
                }

                total20 -= quantia20;
                valorSaque -= quantia20 * 20;
                printf("\n%d cedula(s) de R$20.", quantia20);
            }

            if (valorSaque >= 5)
            {
                quantia5 = 0;
                auxiliarSaque = 0;

                quantia5 = valorSaque / 5;

                if (quantia5 > total5) {
                    auxiliarSaque = quantia5 - total5;
                    quantia5 = quantia5 - auxiliarSaque;
                }

                total5 -= quantia5;
                valorSaque -= quantia5 * 5;
                printf("\n%d cedula(s) de R$5.", quantia5);
            }

            if (valorSaque >= 2)
            {
                quantia2 = 0;
                auxiliarSaque = 0;

                quantia2 = valorSaque / 2;

                if (quantia2 > total2) {
                    auxiliarSaque = quantia2 - total2;
                    quantia2 = quantia2 - auxiliarSaque;
                }

                total2 -= quantia2;
                valorSaque -= quantia2 * 2;
                printf("\n%d cedula(s) de R$2.", quantia2);
            }

            if (valorSaque >= 1)
            {
                quantia1 = 0;
                auxiliarSaque = 0;

                quantia1 = valorSaque / 1;

                if (quantia1 > total1) {
                    auxiliarSaque = quantia1 - total1;
                    quantia1 = quantia1 - auxiliarSaque;
                }

                total1 -= quantia1;
                valorSaque -= quantia1 * 1;
                printf("\n%d cedula(s) de R$1.", quantia1);
            }

            opcaoMenu = 0;
            break;

        case 2: // Menu do gerente:
            opcaoGerente = 0;
            while (opcaoGerente != 5)
            {
                printf("\nSelecione uma das opcoes do menu gerente:\n");

                printf("1 - Valor total sacado\n");
                printf("2 - Valor do saldo existente\n");
                printf("3 - Quantidade de cedulas existentes\n");
                printf("4 - Abastecer o caixa eletronico\n");
                printf("5 - Voltar ao menu principal\n\n");

                scanf("%d", &opcaoGerente);

                // Validacao de op��es do menu gerente
                while (opcaoGerente < 1 || opcaoGerente > 5)
                {
                    printf("\nNumero invalido. Deve ser uma das opcoes a seguir:\n");

                    printf("1 - Valor total sacado\n");
                    printf("2 - Valor do saldo existente\n");
                    printf("3 - Quantidade de cedulas existentes\n");
                    printf("4 - Abastecer o caixa eletronico\n");
                    printf("5 - Voltar ao menu principal\n\n");

                    scanf("%d", &opcaoGerente);
                }

                switch (opcaoGerente)
                {
                case 1: // Mostra o valor total sacado:
                    strcpy(val_Extenso, ""); //Reseta o numero extenso
                    e6 = totalSacado % 10;
                    e5 = (totalSacado % 100) / 10;
                    e4 = (totalSacado % 1000) / 100;
                    e3 = (totalSacado % 10000) / 1000;
                    e2 = (totalSacado % 100000) / 10000;
                    e1 = (totalSacado % 1000000) / 100000;
                    e0 = (totalSacado % 10000000) / 1000000;
                    
                    if (e0 != 0) {
                        if (e0 == 1) {
                            strcat (val_Extenso, "um milhao");
                        } else if (e0 == 2) {
                            strcat(val_Extenso, "dois milhoes");
                        } else if (e0 == 3) {
                            strcat(val_Extenso, "tres milhoes");
                        } else if (e0 == 4) {
                            strcat(val_Extenso, "quatro milhoes");
                        } else if (e0 == 5) {
                            strcat(val_Extenso, "cinco milhoes");
                        } else if (e0 == 6) {
                            strcat(val_Extenso, "seis milhoes");
                        } else if (e0 == 7) {
                            strcat(val_Extenso, "sete milhoes");
                        } else if (e0 == 8) {
                            strcat(val_Extenso, "oito milhoes");
                        } else if (e0 == 9) {
                            strcat(val_Extenso, "nove milhoes");
                        }
                    }

                    if (e1 == 1 && e2 != 0 && e3 != 0) {
                        strcat(val_Extenso, "cento e ");
                    } else if (e1 == 1 && e2 == 0 && e3 == 0) {
                        strcat(val_Extenso, "cem ");
                    } else if (e1 == 2 && e2 == 0 && e3 ==0) {
                        strcat(val_Extenso, "duzentos ");
                    } else if (e1 == 2 && e2 !=0 && e3 !=0) {
                        strcat (val_Extenso, "duzentos e ");
                    }
                    
                    if(e2 != 0) { 
                        if(e2 == 1 && e3 == 0) { 
                            strcat(val_Extenso, "dez ");
                        } else if(e2 == 1 && e3 == 1) {
                            strcat(val_Extenso, "onze ");
                        }else if(e2 == 1 && e3 == 2) {
                            strcat(val_Extenso, "doze ");
                        }else if(e2 == 1 && e3 == 3) {
                            strcat(val_Extenso, "treze ");
                        }else if(e2 == 1 && e3 == 4) {
                            strcat(val_Extenso, "quatorze ");
                        }else if(e2 == 1 && e3 == 5) {
                            strcat(val_Extenso, "quinze ");
                        }else if(e2 == 1 && e3 == 6) {
                            strcat(val_Extenso, "dezesseis ");
                        }else if(e2 == 1 && e3 == 7) {
                            strcat(val_Extenso, "dezessete ");
                        }else if(e2 == 1 && e3 == 8) {
                            strcat(val_Extenso, "dezoito ");
                        }else if(e2 == 1 && e3 == 9) {
                            strcat(val_Extenso, "dezenove ");
                        }else if (e2 == 2) {
                            strcat(val_Extenso, "vinte ");
                        }else if (e2 == 3) {
                            strcat(val_Extenso, "trinta ");
                        }else if (e2 == 4) {
                            strcat(val_Extenso, "quarenta ");
                        }else if (e2 == 5) {
                            strcat(val_Extenso, "cinquenta ");
                        }else if (e2 == 6) {
                            strcat(val_Extenso, "sessenta ");
                        }else if (e2 == 7) {
                            strcat(val_Extenso, "setenta ");
                        }else if (e2 == 8) {
                            strcat(val_Extenso, "oitenta ");
                        } else if (e2 == 9) {
                            strcat(val_Extenso, "noventa ");
                        }
                    }

                    if(e3 != 0 && e2 != 1) {
                        if(e2 != 0 || e1 != 0) {
                            strcat(val_Extenso, "e ");
                        }
                        if(e3 == 1 && (e2 != 0 || e1 != 0)) {
                            strcat(val_Extenso, "um ");
                        }else if(e3 == 2) {
                            strcat(val_Extenso, "dois ");
                        }else if(e3 == 3) {
                            strcat(val_Extenso, "tres ");
                        }else if(e3 == 4) {
                            strcat(val_Extenso, "quatro ");
                        }else if(e3 == 5) {
                            strcat(val_Extenso, "cinco ");
                        }else if(e3 == 6) {
                            strcat(val_Extenso, "seis ");
                        }else if(e3 == 7) {
                            strcat(val_Extenso, "sete ");
                        }else if(e3 == 8) {
                            strcat(val_Extenso, "oito ");
                        }else if(e3 == 9) {
                            strcat(val_Extenso, "nove ");
                        }
                    }

                    if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0))) {
                        strcat(val_Extenso, "mil e ");
                    }else if(e1 != 0 || e2 != 0 || e3 != 0){
                        strcat(val_Extenso, "mil ");
                    }

                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0) {
                            strcat(val_Extenso, "cem ");
                        }else if(e4 == 1) {
                            strcat(val_Extenso, "cento ");
                        }else if(e4 == 2) {
                            strcat(val_Extenso, "duzentos ");
                        }else if(e4 == 3) {
                            strcat(val_Extenso, "trezentos ");
                        }else if(e4 == 4) {
                            strcat(val_Extenso, "quatrocentos ");
                        }else if(e4 == 5) {
                            strcat(val_Extenso, "quinhentos ");
                        }else if(e4 == 6) {
                            strcat(val_Extenso, "seiscentos ");
                        }else if(e4 == 7) {
                            strcat(val_Extenso, "setecentos ");
                        }else if(e4 == 8) {
                            strcat(val_Extenso, "oitocentos ");
                        }else if(e4 == 9) {
                            strcat(val_Extenso, "novecentos ");
                        }
                    }

                    if(e5 != 0) {
                        if (e4 != 0) {
                           strcat(val_Extenso, "e ");
                        }
                        if(e5 == 1 && e6 == 0) {
                            strcat(val_Extenso, "dez ");
                        }else if(e5 == 1 && e6 == 1) {
                            strcat(val_Extenso, "onze ");
                        }else if(e5 == 1 && e6 == 2) {
                            strcat(val_Extenso, "doze ");
                        }else if(e5 == 1 && e6 == 3) {
                            strcat(val_Extenso, "treze ");
                        }else if(e5 == 1 && e6 == 4) {
                            strcat(val_Extenso, "quatorze ");
                        }else if(e5 == 1 && e6 == 5) {
                            strcat(val_Extenso, "quinze ");
                        }else if(e5 == 1 && e6 == 6) {
                            strcat(val_Extenso, "dezesseis ");
                        }else if(e5 == 1 && e6 == 7) {
                            strcat(val_Extenso, "dezessete ");
                        }else if(e5 == 1 && e6 == 8) {
                            strcat(val_Extenso, "dezoito ");
                        }else if(e5 == 1 && e6 == 9) {
                            strcat(val_Extenso, "dezenove ");
                        }else if (e5 == 2) {
                            strcat(val_Extenso, "vinte ");
                        }else if (e5 == 3) {
                            strcat(val_Extenso, "trinta ");
                        }else if (e5 == 4) {
                            strcat(val_Extenso, "quarenta ");
                        }else if (e5 == 5) {
                            strcat(val_Extenso, "cinquenta ");
                        }else if (e5 == 6) {
                            strcat(val_Extenso, "sessenta ");
                        }else if (e5 == 7) {
                            strcat(val_Extenso, "setenta ");
                        }else if (e5 == 8) {
                            strcat(val_Extenso, "oitenta ");
                        }else if (e5 == 9) {
                            strcat(val_Extenso, "noventa ");
                        }
                    }


                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0) {
                            strcat(val_Extenso, "e ");
                        }
                        if (e6 != 0 && e1 != 0) {
                            strcat (val_Extenso, "e ");
                        }
                        if(e6 == 1) {
                            strcat(val_Extenso, "um ");
                        }else if(e6 == 2) {
                            strcat(val_Extenso, "dois ");
                        }else if(e6 == 3) {
                            strcat(val_Extenso, "tres ");
                        }else if(e6 == 4) {
                            strcat(val_Extenso, "quatro ");
                        }else if(e6 == 5) {
                            strcat(val_Extenso, "cinco ");
                        }else if(e6 == 6) {
                            strcat(val_Extenso, "seis ");
                        }else if(e6 == 7) {
                            strcat(val_Extenso, "sete ");
                        }else if(e6 == 8) {
                            strcat(val_Extenso, "oito ");
                        }else if(e6 == 9) {
                            strcat(val_Extenso, "nove ");
                        }
                    }

                    //Plural e singular:
                    strcpy(flexaoReal, "real");
                    if(totalSacado > 1) {
                        strcpy(flexaoReal, "reais");
                    }
                    if (totalSacado > 0){
                        printf("\nValor total sacado: R$%d (%s %s)\n", totalSacado, val_Extenso, flexaoReal);
                    } else if (totalSacado == 0){
                        printf ("\nNada foi sacado ainda\n");
                    }
                    opcaoGerente = 0;
                    break;

                case 2: // Mostra o valor do saldo disponivel:
                    valorDisponivel = (350 * total350) + (300 * total300) + (150 * total150) + (50 * total50) + (20 * total20) + (5 * total5) + (2 * total2) + (1 * total1);

                    //Algoritmo pra realizar numeros extensos;
                    strcpy(val_Extenso, ""); //Reseta o numero extenso
                    e6 = valorDisponivel % 10;
                    e5 = (valorDisponivel % 100) / 10;
                    e4 = (valorDisponivel % 1000) / 100;
                    e3 = (valorDisponivel % 10000) / 1000;
                    e2 = (valorDisponivel % 100000) / 10000;
                    e1 = (valorDisponivel % 1000000) / 100000;

                    if (e1 == 1 && e2 != 0 && e3 != 0) {
                        strcat(val_Extenso, "cento e ");
                    } else if (e1 == 1 && e2 == 0 && e3 == 0) {
                        strcat(val_Extenso, "cem ");
                    } else if (e1 == 2 && e2 == 0 && e3 ==0) {
                        strcat(val_Extenso, "duzentos ");
                    } else if (e1 == 2 && e2 !=0 && e3 !=0) {
                        strcat (val_Extenso, "duzentos e ");
                    }


                    if(e2 != 0) { 
                        if(e2 == 1 && e3 == 0) { 
                            strcat(val_Extenso, "dez ");
                        } else if(e2 == 1 && e3 == 1) {
                            strcat(val_Extenso, "onze ");
                        }else if(e2 == 1 && e3 == 2) {
                            strcat(val_Extenso, "doze ");
                        }else if(e2 == 1 && e3 == 3) {
                            strcat(val_Extenso, "treze ");
                        }else if(e2 == 1 && e3 == 4) {
                            strcat(val_Extenso, "quatorze ");
                        }else if(e2 == 1 && e3 == 5) {
                            strcat(val_Extenso, "quinze ");
                        }else if(e2 == 1 && e3 == 6) {
                            strcat(val_Extenso, "dezesseis ");
                        }else if(e2 == 1 && e3 == 7) {
                            strcat(val_Extenso, "dezessete ");
                        }else if(e2 == 1 && e3 == 8) {
                            strcat(val_Extenso, "dezoito ");
                        }else if(e2 == 1 && e3 == 9) {
                            strcat(val_Extenso, "dezenove ");
                        }else if (e2 == 2) {
                            strcat(val_Extenso, "vinte ");
                        }else if (e2 == 3) {
                            strcat(val_Extenso, "trinta ");
                        }else if (e2 == 4) {
                            strcat(val_Extenso, "quarenta ");
                        }else if (e2 == 5) {
                            strcat(val_Extenso, "cinquenta ");
                        }else if (e2 == 6) {
                            strcat(val_Extenso, "sessenta ");
                        }else if (e2 == 7) {
                            strcat(val_Extenso, "setenta ");
                        }else if (e2 == 8) {
                            strcat(val_Extenso, "oitenta ");
                        } else if (e2 == 9) {
                            strcat(val_Extenso, "noventa ");
                        }
                    }

                    if(e3 != 0 && e2 != 1) {
                        if(e2 != 0 || e1 != 0) {
                            strcat(val_Extenso, "e ");
                        }
                        if(e3 == 1 && (e2 != 0 || e1 != 0)) {
                            strcat(val_Extenso, "um ");
                        }else if(e3 == 2) {
                            strcat(val_Extenso, "dois ");
                        }else if(e3 == 3) {
                            strcat(val_Extenso, "tres ");
                        }else if(e3 == 4) {
                            strcat(val_Extenso, "quatro ");
                        }else if(e3 == 5) {
                            strcat(val_Extenso, "cinco ");
                        }else if(e3 == 6) {
                            strcat(val_Extenso, "seis ");
                        }else if(e3 == 7) {
                            strcat(val_Extenso, "sete ");
                        }else if(e3 == 8) {
                            strcat(val_Extenso, "oito ");
                        }else if(e3 == 9) {
                            strcat(val_Extenso, "nove ");
                        }
                    }

                    if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0))) {
                        strcat(val_Extenso, "mil e ");
                    }else if(e1 != 0 || e2 != 0 || e3 != 0){
                        strcat(val_Extenso, "mil ");
                    }

                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0) {
                            strcat(val_Extenso, "cem ");
                        }else if(e4 == 1) {
                            strcat(val_Extenso, "cento ");
                        }else if(e4 == 2) {
                            strcat(val_Extenso, "duzentos ");
                        }else if(e4 == 3) {
                            strcat(val_Extenso, "trezentos ");
                        }else if(e4 == 4) {
                            strcat(val_Extenso, "quatrocentos ");
                        }else if(e4 == 5) {
                            strcat(val_Extenso, "quinhentos ");
                        }else if(e4 == 6) {
                            strcat(val_Extenso, "seiscentos ");
                        }else if(e4 == 7) {
                            strcat(val_Extenso, "setecentos ");
                        }else if(e4 == 8) {
                            strcat(val_Extenso, "oitocentos ");
                        }else if(e4 == 9) {
                            strcat(val_Extenso, "novecentos ");
                        }
                    }

                    if(e5 != 0) {
                        if (e4 != 0) {
                           strcat(val_Extenso, "e ");
                        }
                        if(e5 == 1 && e6 == 0) {
                            strcat(val_Extenso, "dez ");
                        }else if(e5 == 1 && e6 == 1) {
                            strcat(val_Extenso, "onze ");
                        }else if(e5 == 1 && e6 == 2) {
                            strcat(val_Extenso, "doze ");
                        }else if(e5 == 1 && e6 == 3) {
                            strcat(val_Extenso, "treze ");
                        }else if(e5 == 1 && e6 == 4) {
                            strcat(val_Extenso, "quatorze ");
                        }else if(e5 == 1 && e6 == 5) {
                            strcat(val_Extenso, "quinze ");
                        }else if(e5 == 1 && e6 == 6) {
                            strcat(val_Extenso, "dezesseis ");
                        }else if(e5 == 1 && e6 == 7) {
                            strcat(val_Extenso, "dezessete ");
                        }else if(e5 == 1 && e6 == 8) {
                            strcat(val_Extenso, "dezoito ");
                        }else if(e5 == 1 && e6 == 9) {
                            strcat(val_Extenso, "dezenove ");
                        }else if (e5 == 2) {
                            strcat(val_Extenso, "vinte ");
                        }else if (e5 == 3) {
                            strcat(val_Extenso, "trinta ");
                        }else if (e5 == 4) {
                            strcat(val_Extenso, "quarenta ");
                        }else if (e5 == 5) {
                            strcat(val_Extenso, "cinquenta ");
                        }else if (e5 == 6) {
                            strcat(val_Extenso, "sessenta ");
                        }else if (e5 == 7) {
                            strcat(val_Extenso, "setenta ");
                        }else if (e5 == 8) {
                            strcat(val_Extenso, "oitenta ");
                        }else if (e5 == 9) {
                            strcat(val_Extenso, "noventa ");
                        }
                    }

                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0) {
                            strcat(val_Extenso, "e ");
                        }
                        if (e6 != 0 && e1 != 0) {
                            strcat (val_Extenso, "e ");
                        }
                        if(e6 == 1) {
                            strcat(val_Extenso, "um ");
                        }else if(e6 == 2) {
                            strcat(val_Extenso, "dois ");
                        }else if(e6 == 3) {
                            strcat(val_Extenso, "tres ");
                        }else if(e6 == 4) {
                            strcat(val_Extenso, "quatro ");
                        }else if(e6 == 5) {
                            strcat(val_Extenso, "cinco ");
                        }else if(e6 == 6) {
                            strcat(val_Extenso, "seis ");
                        }else if(e6 == 7) {
                            strcat(val_Extenso, "sete ");
                        }else if(e6 == 8) {
                            strcat(val_Extenso, "oito ");
                        }else if(e6 == 9) {
                            strcat(val_Extenso, "nove ");
                        }
                    }

                    strcpy(flexaoReal, "real");
                    if(valorDisponivel > 1) {
                        strcpy(flexaoReal, "reais");
                    }

                    printf("\nValor do saldo disponivel: R$%d (%s %s\n)", valorDisponivel, val_Extenso, flexaoReal);
                    opcaoGerente = 0;
                    break;

                   case 3: // Mostra a quantidade de cedulas disponiveis:
                
                    printf("\nQuantidade de cedulas disponiveis:");
                    //notas 350
                    strcpy(val_Extenso, "");
                    e6 = total350 % 10; 
                    e5 = (total350 % 100) / 10;
                    e4 = (total350 % 1000) / 100;
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");
                        if (e6 != 0 && e1 != 0)
                            strcat (val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total350 > 0){
                        printf("\nCedulas de R$350: %s (%d) cedula(s).", val_Extenso, total350);
                    } else if (total350 == 0) {
                        printf ("\nCedulas de R$350: Zero (0) cedulas");
                    }

                    //notas de 300
                    strcpy(val_Extenso, "");
                    e6 = total300 % 10; 
                    e5 = (total300 % 100) / 10;
                    e4 = (total300 % 1000) / 100;
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0) 
                            strcat(val_Extenso, " duzentas"); 
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");
                        if (e6 != 0 && e1 != 0)
                            strcat (val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");
                    }
                    if  (total300 > 0){
                        printf("\nCedulas de R$300: %s (%d) cedula(s).", val_Extenso, total300);
                    } else if (total300 == 0){
                        printf ("\nCedulas de R$300: Zero (0) cedulas");
                    }
                    //notas de 150
                    strcpy(val_Extenso, "");
                    e6 = total150 % 10; 
                    e5 = (total150 % 100) / 10;
                    e4 = (total150 % 1000) / 100;
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if(e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");  
                        else if(e4 ==2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if(e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ");  
                            else if (e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos ");
                        else if(e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas "); 
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");
                        if (e6 != 0 && e1 != 0)
                            strcat (val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total150 > 0){
                        printf("\nCedulas de R$150: %s (%d) cedula(s).", val_Extenso, total150);
                    } else if (total150 == 0) {
                        printf ("\nCedulas de R$150: Zero (0) cedulas");
                    }

                    //notas 50
                    strcpy(val_Extenso, "");
                    e6 = total50 % 10; 
                    e5 = (total50 % 100) / 10;
                    e4 = (total50 % 1000) / 100;
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");
                        else if(e4 == 2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if (e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ") ; 
                        else if(e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos "); 
                        else if (e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas ") ;
                        else if(e4 == 4 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quatrocentos "); 
                        else if (e4 == 5 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quinhentas ");
                        else if(e4 == 5 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quinhentos ");
                        else if (e4 == 6 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "seiscentas");
                        else if(e4 == 6 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "seiscentos ");
                        else if (e4 == 7 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "setecentas ");
                        else if(e4 == 7 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "setecentos ");
                        else if(e4 == 8 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "oitocentas "); 
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");
                        if (e6 != 0 && e1 != 0)
                            strcat (val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total50 > 0){
                        printf("\nCedulas de R$50: %s (%d) cedula(s).", val_Extenso, total50);
                        } else if (total50 == 0) {
                        printf ("\nCedulas de R$50: Zero (0) cedulas");
                        }

                    //notas 20
                    strcpy(val_Extenso, "");
                    e6 = total20 % 10; 
                    e5 = (total20 % 100) / 10;
                    e4 = (total20 % 1000) / 100;
                    e3 = (total20 % 10000)/ 1000;
                        if(e3 == 1)
                            strcat(val_Extenso, "mil ");
                        if (e3 ==1 && e4!=0 || e5!=0 || e6 !=0)
                            strcat(val_Extenso, "e ");
                        
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");
                        else if(e4 == 2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if (e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ") ; 
                        else if(e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos "); 
                        else if (e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas ") ;
                        else if(e4 == 4 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quatrocentos "); 
                        else if (e4 == 5 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quinhentas ");
                        else if(e4 == 5 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quinhentos ");
                        else if (e4 == 6 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "seiscentas");
                        else if(e4 == 6 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "seiscentos ");
                        else if (e4 == 7 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "setecentas ");
                        else if(e4 == 7 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "setecentos ");
                        else if(e4 == 8 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "oitocentas ");
                        else if (e4 == 9 && e5 == 0 && e6 == 0) 
                            strcat(val_Extenso, "novecentas ");
                        else if (e4 == 9 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "novecentos ");
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total20>0){
                    printf("\nCedulas de R$20: %s (%d) cedula(s).", val_Extenso, total20);
                    } else if (total20 == 0) {
                        printf ("\nCedulas de R$20: Zero (0) cedulas");
                    }

                    //notas 5
                    strcpy(val_Extenso, "");
                    e6 = total5 % 10; 
                    e5 = (total5 % 100) / 10;
                    e4 = (total5 % 1000) / 100;
                    e3 = (total5 % 10000)/ 1000;


                        if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                            strcat(val_Extenso, "um ");
                        else if(e3 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e3 == 3) 
                            strcat(val_Extenso, "tres "); 
                    

                    if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                        strcat(val_Extenso, "mil e ");
                    else if(e1 != 0 || e2 != 0 || e3 != 0)
                        strcat(val_Extenso, "mil ");
                    
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");
                        else if(e4 == 2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if (e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ") ; 
                        else if(e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos "); 
                        else if (e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas ") ;
                        else if(e4 == 4 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quatrocentos "); 
                        else if (e4 == 5 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quinhentas ");
                        else if(e4 == 5 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quinhentos ");
                        else if (e4 == 6 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "seiscentas");
                        else if(e4 == 6 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "seiscentos ");
                        else if (e4 == 7 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "setecentas ");
                        else if(e4 == 7 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "setecentos ");
                        else if(e4 == 8 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "oitocentas ");
                        else if (e4 == 9 && e5 == 0 && e6 == 0) 
                            strcat(val_Extenso, "novecentas ");
                        else if (e4 == 9 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "novecentos ");
                    }

                    if(e5 != 0){  
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");
                
                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total5 > 0){
                        printf("\nCedulas de R$5: %s (%d) cedula(s).", val_Extenso, total5);
                    } else if (total5 == 0) {
                        printf ("\nCedulas de R$5: Zero (0) cedulas");
                    }

                    //notas 2
                    strcpy(val_Extenso, "");
                    e6 = total2 % 10; 
                    e5 = (total2 % 100) / 10;
                    e4 = (total2 % 1000) / 100;
                    e3 = (total2 % 10000) / 1000;

                        if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                            strcat(val_Extenso, "um ");
                        else if(e3 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e3 == 3) 
                            strcat(val_Extenso, "tres ");
                        else if(e3 == 4) 
                            strcat(val_Extenso, "quatro ");
                        else if(e3 == 5) 
                            strcat(val_Extenso, "cinco ");
                        else if(e3 == 6) 
                            strcat(val_Extenso, "seis "); 

                    if((e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                        strcat(val_Extenso, "mil e ");
                    else if(e1 != 0 || e2 != 0 || e3 != 0)
                        strcat(val_Extenso, "mil ");
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");
                        else if(e4 == 2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if (e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ") ; 
                        else if(e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos "); 
                        else if (e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas ") ;
                        else if(e4 == 4 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quatrocentos "); 
                        else if (e4 == 5 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quinhentas ");
                        else if(e4 == 5 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quinhentos ");
                        else if (e4 == 6 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "seiscentas");
                        else if(e4 == 6 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "seiscentos ");
                        else if (e4 == 7 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "setecentas ");
                        else if(e4 == 7 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "setecentos ");
                        else if(e4 == 8 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "oitocentas ");
                        else if (e4 == 9 && e5 == 0 && e6 == 0) 
                            strcat(val_Extenso, "novecentas ");
                        else if (e4 == 9 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "novecentos ");
                    }

                    if(e5 != 0) {
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");
                    
                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa "); 
                    }            
                    
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total2 > 0){
                        printf("\nCedulas de R$2: %s (%d) cedula(s).", val_Extenso, total2);
                    } else if (total2 == 0) {
                        printf ("\nCedulas de R$2: Zero (0) cedulas");
                    }

                    //notas 1
                    strcpy(val_Extenso, "");
                    e6 = total1 % 10; 
                    e5 = (total1 % 100) / 10;
                    e4 = (total1 % 1000) / 100;
                    e3 = (total1 % 10000)/ 1000;
                    e2 = (total1 % 100000)/ 10000;
                    if(e2 != 0) {
                        if(e2 == 1 && e3 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e2 == 1 && e3 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e2 == 1 && e3 == 2) 
                            strcat(val_Extenso, "doze ");
                    }
                    if(e3 != 0 && e2 != 1) {
                        if(e2 != 0 || e1 != 0)
                            strcat(val_Extenso, "e ");

                        if(e3 == 1 && (e2 != 0 || e1 != 0)) 
                            strcat(val_Extenso, "um ");
                        else if(e3 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e3 == 3) 
                            strcat(val_Extenso, "tres ");
                        else if(e3 == 4) 
                            strcat(val_Extenso, "quatro ");
                        else if(e3 == 5) 
                            strcat(val_Extenso, "cinco ");
                        else if(e3 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e3 == 7) 
                            strcat(val_Extenso, "sete ");
                        else if(e3 == 8) 
                            strcat(val_Extenso, "oito ");
                        else if(e3 == 9) 
                            strcat(val_Extenso, "nove ");
                    }

                    if((e1 != 0 || e2 != 0 || e3 != 0) && (e4 != 0 && ( e5 == 0 || e6 == 0)))
                        strcat(val_Extenso, "mil e ");
                    else if(e1 != 0 || e2 != 0 || e3 != 0)
                        strcat(val_Extenso, "mil ");
                    
                    if (e4 != 0){
                        if(e4 == 1 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "cem ");
                        else if(e4 == 1 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "cento ");
                        else if (e4 == 2 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "duzentas ");
                        else if(e4 == 2 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "duzentos ");
                        else if (e4 == 3 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "trezentas ") ; 
                        else if(e4 == 3 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "trezentos "); 
                        else if (e4 == 4 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quatrocentas ") ;
                        else if(e4 == 4 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quatrocentos "); 
                        else if (e4 == 5 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "quinhentas ");
                        else if(e4 == 5 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "quinhentos ");
                        else if (e4 == 6 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "seiscentas");
                        else if(e4 == 6 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "seiscentos ");
                        else if (e4 == 7 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "setecentas ");
                        else if(e4 == 7 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "setecentos ");
                        else if(e4 == 8 && e5 == 0 && e6 == 0)
                            strcat(val_Extenso, "oitocentas ");
                        else if (e4 == 9 && e5 == 0 && e6 == 0) 
                            strcat(val_Extenso, "novecentas ");
                        else if (e4 == 9 && (e5 != 0 || e6 != 0))
                            strcat(val_Extenso, "novecentos ");
                    }

                    if(e5 != 0) { 
                        if (e4 != 0)
                           strcat(val_Extenso, "e ");

                        if(e5 == 1 && e6 == 0) 
                            strcat(val_Extenso, "dez ");
                        else if(e5 == 1 && e6 == 1) 
                            strcat(val_Extenso, "onze ");
                        else if(e5 == 1 && e6 == 2) 
                            strcat(val_Extenso, "doze ");
                        else if(e5 == 1 && e6 == 3) 
                            strcat(val_Extenso, "treze "); 
                        else if(e5 == 1 && e6 == 4) 
                            strcat(val_Extenso, "quatorze "); 
                        else if(e5 == 1 && e6 == 5) 
                            strcat(val_Extenso, "quinze "); 
                        else if(e5 == 1 && e6 == 6) 
                            strcat(val_Extenso, "dezesseis "); 
                        else if(e5 == 1 && e6 == 7) 
                            strcat(val_Extenso, "dezessete "); 
                        else if(e5 == 1 && e6 == 8) 
                            strcat(val_Extenso, "dezoito "); 
                        else if(e5 == 1 && e6 == 9) 
                            strcat(val_Extenso, "dezenove "); 
                        else if (e5 == 2)
                            strcat(val_Extenso, "vinte ");
                        else if (e5 == 3)
                            strcat(val_Extenso, "trinta ");
                        else if (e5 == 4)
                            strcat(val_Extenso, "quarenta ");
                        else if (e5 == 5)
                            strcat(val_Extenso, "cinquenta ");
                        else if (e5 == 6)
                            strcat(val_Extenso, "sessenta ");
                        else if (e5 == 7)
                            strcat(val_Extenso, "setenta ");
                        else if (e5 == 8)
                            strcat(val_Extenso, "oitenta ");
                        else if (e5 == 9)
                            strcat(val_Extenso, "noventa ");             
                    }
                    if(e6 != 0 && e5 != 1) {
                        if(e5 != 0 || e4 != 0)
                            strcat(val_Extenso, "e ");

                        if(e6 == 1) 
                            strcat(val_Extenso, "um ");
                        else if(e6 == 2) 
                            strcat(val_Extenso, "dois ");
                        else if(e6 == 3) 
                            strcat(val_Extenso, "tres "); 
                        else if(e6 == 4) 
                            strcat(val_Extenso, "quatro "); 
                        else if(e6 == 5) 
                            strcat(val_Extenso, "cinco "); 
                        else if(e6 == 6) 
                            strcat(val_Extenso, "seis "); 
                        else if(e6 == 7) 
                            strcat(val_Extenso, "sete "); 
                        else if(e6 == 8) 
                            strcat(val_Extenso, "oito "); 
                        else if(e6 == 9) 
                            strcat(val_Extenso, "nove ");  
                    }
                    if (total1 > 0 ){
                        printf("\nCedulas de R$1: %s (%d) cedula(s).\n", val_Extenso, total1);
                    } else if (total1 == 0) {
                        printf ("\nCedulas de R$1: Zero (0) cedulas");
                    }
                    
                    opcaoGerente = 0;
                    break;
                
                case 4: // Abre o menu de abastecimento:
                    opcaoAbastecer = 1;

                    // Esse while mantem o menu rodando ate que o usuario volte ao menu anterior:
                    while (opcaoAbastecer != 0)
                    {
                        printf("\nSelecione uma das opcoes a seguir:\n");
                        printf("350 - Cedulas de 350\n");
                        printf("300 - Cedulas de 300\n");
                        printf("150 - Cedulas de 150\n");
                        printf("50 - Cedulas de 50\n");
                        printf("20 - Cedulas de 20\n");
                        printf("5 - Cedulas de 5\n");
                        printf("2 - Cedulas de 2\n");
                        printf("1 - Cedulas de 1\n");
                        printf("0 - Voltar ao menu gerente\n\n");

                        scanf("%d", &opcaoAbastecer);

                        // Validacao de opcoes do menu abastecer:
                        while (opcaoAbastecer != 350 && opcaoAbastecer != 300 && opcaoAbastecer != 150 && opcaoAbastecer != 50 && opcaoAbastecer != 20 && opcaoAbastecer != 5 && opcaoAbastecer != 2 && opcaoAbastecer != 1 && opcaoAbastecer != 0)
                        {
                            printf("\nOpcao invalida. Selecione uma das opcoes a seguir:\n");
                            printf("350 - Cedulas de 350\n");
                            printf("300 - Cedulas de 300\n");
                            printf("150 - Cedulas de 150\n");
                            printf("50 - Cedulas de 50\n");
                            printf("20 - Cedulas de 20\n");
                            printf("5 - Cedulas de 5\n");
                            printf("2 - Cedulas de 2\n");
                            printf("1 - Cedulas de 1\n");
                            printf("0 - Voltar ao menu gerente\n\n");

                            scanf("%d", &opcaoAbastecer);
                        }

                        // Selecao das opcoes:
                        switch (opcaoAbastecer)
                        {
                        case 350: // Abastecer 350 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 100 - total350;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total350 += quantiaAbastecer;
                                printf("\n%d cedulas de R$350 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 300: // Abastecer 300 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 200 - total300;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total300 += quantiaAbastecer;
                                printf("\n%d cedulas de R$300 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 150: // Abastecer 150 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 400 - total150;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total150 += quantiaAbastecer;
                                printf("\n%d cedulas de R$150 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 50: // Abastecer 50 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 800 - total50;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total50 += quantiaAbastecer;
                                printf("\n%d cedulas de R$50 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 20: // Abastecer 20 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 1600 - total20;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total20 += quantiaAbastecer;
                                printf("\n%d cedulas de R$20 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 5: // Abastecer 5 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 3200 - total5;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total5 += quantiaAbastecer;
                                printf("\n%d cedulas de R$5 abastecidos com sucesso.\n", quantiaAbastecer);
                            }
                            opcaoAbastecer = 1;
                            break;

                        case 2: // Abastecer 2 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 6400 - total2;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total2 += quantiaAbastecer;
                                printf("\n%d cedulas de R$2 abastecidos com sucesso.\n", quantiaAbastecer);
                            }

                            opcaoAbastecer = 1;
                            break;

                        case 1: // Abastecer 1 e validacao da quantia;
                            quantiaAbastecer = 0;
                            notasRestantes = 12800 - total1;

                            printf("\nInsira quantas cedulas deseja abastecer:\n");
                            scanf("%d", &quantiaAbastecer);

                            if (notasRestantes == 0)
                            {
                                printf("\nO caixa ja esta cheio.\n");
                            }
                            else
                            {
                                while (quantiaAbastecer < 1 || quantiaAbastecer > notasRestantes)
                                {
                                    printf("\nQuantia invalida. ");

                                    if (quantiaAbastecer < 1)
                                    {
                                        printf("Insira um valor maior ou igual a 1:\n");
                                        scanf("%d", &quantiaAbastecer);
                                    }

                                    if (quantiaAbastecer > notasRestantes)
                                    {
                                        printf("So ha espaco para mais %d cedulas.\n Insira um valor menor ou igual a %d:", notasRestantes, notasRestantes);
                                        scanf("%d", &quantiaAbastecer);
                                    }
                                }
                                total1 += quantiaAbastecer;
                                printf("\n%d cedulas de R$1 abastecidos com sucesso.\n", quantiaAbastecer);
                            }

                            opcaoAbastecer = 1;
                            break;
                        }
                    }

                    opcaoGerente = 0;
                    break;

                case 5:
                    opcaoAbastecer = 0;
                    opcaoGerente = 5;
                    break;
                }
            }

            opcaoMenu = 0;
            break;

        case 3: // Finaliza�ao do caixa:
            printf("\nOperacao finalizada. Volte sempre! :)\n");
            break;
        }
    }
    return 0;
}
