// T1 - Maquina de Cafe

/* Grupo 4:
Ana Beatriz Bernardino Penze
Caua Kadena Okabayashi
Kenzo Cavalcante Oshiro
Liliane de Moraes Pinheiro
Luis Miguel Willame Silva Lima
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Numeros de funcionarios
    int andar1, andar2, andar3;

    // Variaveis de tempo
    int soma1, soma2, soma3;

    printf("Por favor, digite o numero de funcionarios por andar\n");
    printf("Andar 1: ");
    scanf("%d", &andar1);

    // Validacao da variavel andar1
    while (andar1 < 0 || andar1 > 1000)
    {
        printf("Numero Invalido, deve ser maior ou igual a 0 e menor ou igual a 1000\n");
        printf("Andar 1: ");
        scanf("%d", &andar1);
    }

    printf("\nAndar 2: ");
    scanf("%d", &andar2);

    // Valida��o da vari�vel andar2
    while (andar2 < 0 || andar2 > 1000)
    {
        printf("Numero Invalido, deve ser maior ou igual a 0 e menor ou igual a 1000\n");
        printf("Andar 2: ");
        scanf("%d", &andar2);
    }

    printf("\nAndar 3: ");
    scanf("%d", &andar3);

    // Valida��o da vari�vel andar3
    while (andar3 < 0 || andar3 > 1000)
    {
        printf("Numero Invalido, deve ser maior ou igual a 0 e menor ou igual a 1000\n");
        printf("Andar 3: ");
        scanf("%d", &andar3);
    }

    // C�lculo de tempo do andar 1
    soma1 = (andar1 * 0) + (andar2 * 2) + (andar3 * 4);

    // C�lculo de tempo do andar 2
    soma2 = (andar1 * 2) + (andar2 * 0) + (andar3 * 2);

    // C�lculo de tempo do andar 3
    soma3 = (andar1 * 4) + (andar2 * 2) + (andar3 * 0);

    // Verifica��o de possibilidades
    // Caso o tempo seja igual em todos.
    if (soma1 == soma2 && soma2 == soma3)
    {
        printf("\nTempo: %d", soma1);
        printf("\nAndar(es): 1, 2 ou 3");

        // Caso o tempo seja igual somente em dois andares.
    }
    else if (soma1 == soma2)
    {
        if (soma1 < soma3)
        {
            printf("\nTempo: %d", soma1);
            printf("\nAndar(es): 1 ou 2");
        }
        else
        {
            printf("\nTempo: %d", soma3);
            printf("\nAndar(es): 3");
        }
    }
    else if (soma1 == soma3)
    {
        if (soma1 < soma2)
        {
            printf("\nTempo: %d", soma1);
            printf("\nAndar(es): 1 ou 3");
        }
        else
        {
            printf("\nTempo: %d", soma2);
            printf("\nAndar(es): 2");
        }
    }
    else if (soma2 == soma3)
    {
        if (soma2 < soma1)
        {
            printf("\nTempo: %d", soma2);
            printf("\nAndar(es): 2 ou 3");
        }
        else
        {
            printf("\nTempo: %d", soma1);
            printf("\nAndar(es): 1");
        }
    }

    // Caso o tempo seja diferente.
    if (soma1 != soma2 && soma1 != soma3 && soma2 != soma3)
    {
        if (soma1 < soma2 && soma1 < soma3)
        {
            printf("\nTempo: %d", soma1);
            printf("\nAndar(es): 1");
        }
        else if (soma1 > soma2 && soma2 < soma3)
        {
            printf("\nTempo: %d", soma2);
            printf("\nAndar(es): 2");
        }
        else if (soma1 > soma3 && soma2 > soma3)
        {
            printf("Tempo: %d", soma3);
            printf("\nAndar(es): 3");
        }
    }

    return 0;
}
