#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <myList.h>

//Objetivo: Verificar se um numero e narcicista
//Parametro: Um numero (inteiro)
//Retorno: 0 se for narcicista e 1 se nao for.
int ehNarcisista(int num) {
    int soma = 0, temp = num, contador = 0;

    //Conta quantos digitos o numero tem
    while (temp > 0) {
        temp /= 10;
        contador++;
    }

    temp = num;

    //Calcular a soma dos digitos elevado a potencia do numero de digitos
    while (temp > 0) {
        int digito = temp % 10;
        soma += pow(digito, contador);
        temp /= 10;
    }

    if (soma == num) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int N;

    inicializa(); //Inicializa a lista

    printf("\nDigite a quantidade maxima de numeros (De 11 a 1 milhão): ");
    scanf("%d", &N);

    //Verifica se eh valido
    if (N <= 10 || N > 1000000) {
        printf("\nValor Invalido. Deve ser maior que 10 e menor ou igual a 1 milhao.\n");
    } else {
        //Encontra e armazena os narcicistas
        for (int i = 10; i <= N; i++) {
            if (ehNarcisista(i) == 0) {
                insereOrdem(i);
            }
        }

        // Imprimir os numeros narcicistas
        printf("\nNumeros narcisistas encontrados entre 10 e %d:\n", N);
        imprime();

        int menuExcluir;

        do {
            printf("\nSelecione uma das opcoes a seguir:");
            printf("\n1 - Excluir Numero");
            printf("\n2 - Finalizar\n");
            scanf("%d", &menuExcluir);
            int numExcluir;
            switch (menuExcluir) {
                case 1:
                   //Excluir o numero
                    printf("\nDigite um numero narcisista para excluir: ");
                    scanf("%d", &numExcluir);

                    if (busca(numExcluir)) {
                        retira(numExcluir);
                        printf("\nNumero %d excluido. Numeros restantes:\n", numExcluir);
                        imprime(); //Imprime os numeros novamente
                    } else {
                        printf("\nNumero %d nao encontrado na lista.\n", numExcluir);
                    }
                    break;
                case 2:
                    printf("\nOperacao Finalizada.");
                    break;
                default:
                    printf("\nOpcao Invalida.");
                    break;
            }
        } while (menuExcluir != 2);

        esvazia(); //Limpa o vetor lista
    }
}
