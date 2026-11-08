// T1 - Elevador Espacial

/* Grupo 4:
Ana Beatriz Bernardino Penze
Caua Kadena Okabayashi
Kenzo Cavalcante Oshiro
Liliane de Moraes Pinheiro
Luis Miguel Willame Silva Lima
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int p = 0, verificar = 0, num;
    while (1)
    {
        printf("Digite o numero do andar desejado: ");
        scanf("%d", &num);
        if (num >= 1 && num <= 1000000)
        {
            int n1, n2, n3, n4, n5, n6, n7;
            for (p = 1; p <= num; p = p + 1)
            {
                verificar = verificar + 1;

                while (1)
                {

                    n1 = verificar % 10;
                    n2 = (verificar / 10) % 10;
                    n3 = (verificar / 100) % 10;
                    n4 = (verificar / 1000) % 10;
                    n5 = (verificar / 10000) % 10;
                    n6 = (verificar / 100000) % 10;
                    n7 = (verificar / 1000000) % 10;

                    if ((n1 == 4) || (n2 == 4) || (n3 == 4) || (n4 == 4) || (n5 == 4) || (n6 == 4) || (n7 == 4))
                    {
                        verificar = verificar + 1;
                    }

                    else if (((n1 == 3) && (n2 == 1)) || ((n2 == 3) && (n3 == 1)) || ((n3 == 3) && (n4 == 1)) || ((n4 == 3) && (n5 == 1)) || ((n5 == 3) && (n6 == 1)) || ((n6 == 3) && (n7 == 1)))
                    {
                        verificar = verificar + 1;
                    }

                    else
                    {
                        break;
                    }
                }
            }
            printf("Andar original: %d\n", num);
            printf("Andar apos mudanca: %d", verificar);
            break;
        }
        else
        {
            printf("invalido. Tente Novamente");
        }
    }

    return 0;
}