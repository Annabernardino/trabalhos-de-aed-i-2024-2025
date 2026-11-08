// T1 - Azulejos

//grupo 6

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int totalAzulejos, primeiroInteiro, segundoInteiro;
    int totalPintados = 0;

    // Quantidade de azulejos e validacao:
    printf("Insira a quantidade de azulejos:\n");
    scanf("%d", &totalAzulejos);

    while (totalAzulejos < 3 || totalAzulejos > 10000)
    {
        printf("\nDeve ser maior igual a 3 ou menor igual a 10000.");
        printf("\nTente novamente:\n");
        scanf("%d", &totalAzulejos);
    }

    // Valor do primeiro inteiro e validacao:
    printf("\nInsira o valor do primeiro inteiro:\n");
    scanf("%d", &primeiroInteiro);

    while (primeiroInteiro < 2 || primeiroInteiro > totalAzulejos)
    {
        printf("\nDeve ser maior ou igual a 2 e menor ou igual a quantidade de azulejos.");
        printf("\nTente novamente:\n");
        scanf("%d", &primeiroInteiro);
    }

    // Valor do segundo inteiro e validacao:
    printf("\nInsira o valor do segundo inteiro:\n");
    scanf("%d", &segundoInteiro);

    while (segundoInteiro < 2 || segundoInteiro > totalAzulejos)
    {
        printf("\nDeve ser maior ou igual a 2 e menor ou igual a quantidade de azulejos.");
        printf("\nTente novamente:\n");
        scanf("%d", &segundoInteiro);
    }

    // Validacao do caso onde todos sao iguais:
    if ((primeiroInteiro == segundoInteiro) && (segundoInteiro == totalAzulejos))
    {
        printf("\nValores iguais sao invalidos. Tente com outros valores.\n");
    }
    else
    {
        for (int i = 1; i <= totalAzulejos; i++)
        {
            if (i % primeiroInteiro == 0 || i % segundoInteiro == 0)
            {
                totalPintados++;
            }
        }
        printf("\nO total de azulejos a ser pintado e: %d\n", totalPintados);
    }
}
