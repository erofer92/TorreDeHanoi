#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Pino.h"
#include "Torre.h"

int main()
{
	Pilha *p1;
	Pilha *p2;
	Pilha *p3;
	int qtd, a, b;

	p1 = criar();
	p2 = criar();
	p3 = criar();

	menu();

	criar_Pino_Principal(&p1);
	qtd = tamanho(p1);

	while(fim(p1, p2, p3, qtd))
	{
	    system("cls");
		print_pinos(p1, p2, p3);
		listar_jogadas_possiveis(p1, p2, p3);

        printf("\nEscolha dois pinos para mover os discos (escolha zero/zero para desistir): ");
        printf("\nOrigem: ");
        scanf("%d", &a);
        fflush(stdin);
        printf("Destino: ");
        scanf("%d", &b);
        fflush(stdin);

        while((a>3 || a<0) || (b>3 || b<0))
        {
            printf("Escolha pinos validos: ");
            printf("\nOrigem: ");
            scanf("%d", &a);
            fflush(stdin);
            printf("Destino: ");
            scanf("%d", &b);
            fflush(stdin);
        }
        if(a == 0 || b == 0)
        {
            //resolver2(p1, p3, p2, qtd);
        }

        else
        {
            if(a == 1 && b == 2)
                mover(p1,p2);
            else
            {
                if(a == 1 && b == 3)
                    mover(p1,p3);
                else
                {
                    if(a == 2 && b == 1)
                        mover(p2,p1);
                    else
                    {
                        if(a == 2 && b == 3)
                            mover(p2,p3);
                        else
                        {
                            if(a == 3 && b == 1)
                                mover(p3,p1);
                            else
                                mover(p3,p2);
                        }
                    }
                }
            }
        }
    }
    getch();
	destruir(p1);
	destruir(p2);
	destruir(p3);

	return 0;
}
