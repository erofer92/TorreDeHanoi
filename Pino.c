#include <stdio.h>
#include <stdlib.h>
#include "Pino.h"

#ifndef TAM_MAX
#define TAM_MAX 64
#endif

void criar_Pino_Principal(Pilha **p)
{
	int qtd;

	system("cls");

	printf("Com quantos discos voce deseja jogar? ");
	printf("\nQuantidade minima: 3");
	printf("\nQuantidade maxima: %d", TAM_MAX);
	printf("\nNumero de Discos: ");
	scanf("%d", &qtd);
	fflush(stdin);

	while(qtd == 0 || qtd > TAM_MAX)
	{
		printf("\nEscolha um valor valido: ");
		scanf("%d", &qtd);
		fflush(stdin);
	}

	while(qtd > 0)
	{
		empilhar(*p, qtd--);
	}
}

void menu()
{
	system("cls");

	char c;

	printf("Torre de Hanoi \n");
	printf("1 - Instrucoes \n");
	printf("2 - Iniciar \n");
	printf("3 - Creditos \n");
	printf("4 - Sair \n");

	c = getch();
    fflush(stdin);

	while(c != '1' && c != '2' && c != '3' && c != '4')
    {
        printf("\nDigite uma opcao valida: ");
        c = getch();
        fflush(stdin);
    }
    switch(c)
    {
        case '1':
            instrucoes();
            break;
        case '2':
            return;
        case '3':
            creditos();
            break;
        case '4':
            exit(0);
            break;
        default:
            break;
    }
}

void instrucoes()
{
	system("cls");
	printf("\n\n                    Instrucoes \n\n");
	printf("        Este jogo consiste em mover todos os \n");
	printf("        discos do primeiro pino para o ultimo. \n");
	printf("    So ha 3 pinos, mas quantos discos voce desejar. \n\n");
	printf("       O segundo pino deve ser ultilizado como \n");
	printf("            auxilio para os movimentos.\n\n\n");

	printf("                      Regras \n\n");
	printf("      Um disco maior nao pode ficar em cima de \n");
	printf("                  um disco menor \n\n");


	printf("    Pressione qualquer tecla para voltar ao menu.\n");

	getch();
	fflush(stdin);

	menu();
}

void creditos()
{
    system("cls");

    printf("\n\n    Este jogo foi desenvolvido como projeto da disciplina Estrutuda de Dados 1. \n");
    printf("    O assunto foi Estrutura de Pilha em C, ministrada pelo professor Murilo. \n");
    printf("            Desenvolvedores: Eron Fernandes e Jefferson Santos. \n\n");
    printf("             pressione qualquer tecla para voltar ao menu.");

    getch();
    fflush(stdin);

    menu();
}

void print_pinos(Pilha *p1, Pilha *p2, Pilha *p3)
{

    printf("Pino 1: Base ");
    imprimir(p1);
    printf(" Topo \n");

    printf("Pino 2: Base ");
    imprimir(p2);
    printf(" Topo \n");

    printf("Pino 3: Base ");
    imprimir(p3);
    printf(" Topo \n");

}

void listar_jogadas_possiveis(Pilha *p1, Pilha *p2, Pilha *p3)
{
	int a,b,c;

	if(tamanho(p1) == 0)
        a = 100;
    else
        a = topo(p1);

    if(tamanho(p2) == 0)
        b = 100;
    else
        b = topo(p2);

    if(tamanho(p3) == 0)
        c = 100;
    else
        c = topo(p3);

	printf("\n\nJogadas possiveis: \n");

	if(a < b && a < c)
	{
		printf("[ 1 -> 2 ] \n");
		printf("[ 1 -> 3 ] \n");
		if(tamanho(p2) != 0 || tamanho(p3) != 0)
		{
            if(b < c)
                printf("[ 2 -> 3 ] \n\n");
            else
                printf("[ 3 -> 2 ] \n\n");
        }
	}
	else
	{
		if(b < a && b < c)
		{
			printf("[ 2 -> 1 ] \n");
			printf("[ 2 -> 3 ] \n");
			if(tamanho(p1) != 0 || tamanho(p3) != 0)
            {
                if(a < c)
                    printf("[ 1 -> 3 ] \n\n");
                else
                    printf("[ 3 -> 1 ] \n\n");
            }
		}
		else
		{
			printf("[ 3 -> 1 ] \n");
			printf("[ 3 -> 2 ] \n");
			if(tamanho(p1) != 0 || tamanho(p2) != 0)
            {
                if(a < b)
                    printf("[ 1 -> 2 ] \n\n");
                else
                    printf("[ 2 -> 1 ] \n\n");
            }
		}
	}
}

void mover(Pilha *p_origem, Pilha *p_destino)
{
    int x = 0;
    if(tamanho(p_destino) == 0)
        x = 100;

	if(tamanho(p_origem) > 0 && (x > topo(p_origem) || topo(p_destino) > topo(p_origem)))
	{
		empilhar(p_destino, desempilhar(p_origem));
	}
	else
	{
		if(tamanho(p_origem) == 0)
		{
            printf("\nJogada Ilegal.");
			printf("\nPino de Origem Vazio. \n");
		}
		else
		{
		    printf("\nJogada Ilegal.");
			printf("\nDisco do pino de origem maior que disco do pino de destino.\n");
		}
		getch();
		fflush(stdin);
	}
}

void procurarDisco(Pilha *p_origem, Pilha *p_auxiliar, Pilha *p_destino, int disco)
{
    Pilha *p1 = clonar(p_origem);
    Pilha *p2 = clonar(p_auxiliar);
    Pilha *p3 = clonar(p_destino);

    while(topo(p1) != disco && tamanho(p1) > 0)
        desempilhar(p1);
    if(tamanho(p1) != 0)

}
void resolver(Pilha *p_origem, Pilha *p_auxiliar, Pilha *p_destino, int qtd_discos)
{
    procurarDisco()
    if(qtd_discos>1)
        resolver(p_destino, p_origem, p_auxiliar, qtd_discos-1)
    mover(p_origem, p_auxiliar);





    while(tamanho(p_origem) > 0)
    {
        d = 0;
        a = 0;

        if(tamanho(p_destino) == 0)
            d = TAM_MAX+1;
        if(tamanho(p_auxiliar) == 0)
            a = TAM_MAX+1;

        if((topo(p_destino) > topo(p_origem) || d == TAM_MAX+1) || (topo(p_auxiliar) > topo(p_origem) || a == TAM_MAX+1))
        {
            // SE TODOS OS DISCOS ESTIVEREM NO PRIMEIRO PINO
            // O CODIGO EXECUTARÁ OS DOIS PRIMEIROS MOVIMENTOS BASICOS
            if(baseSecundaria(p_origem) % 2 == 1)
            {
                mover(p_origem, p_destino);
                print_pinos(p_origem, p_auxiliar, p_destino);
                system("pause");
            }
            else
            {
                mover(p_origem, p_auxiliar);
                print_pinos(p_origem, p_auxiliar, p_destino);
                system("pause");
            }
        }
        else
        {

            if(baseSecundaria(p_origem) % 2 == 1)
            {
                printf("resolver sera chamado novamente. Impar \n");
                system("pause");
                resolver(p_destino, p_auxiliar, p_origem, profundidade+1);
            }
            else
            {
                printf("resolver sera chamado novamente. Par \n");
                system("pause");
                resolver(p_auxiliar, p_destino, p_origem, profundidade+1);
            }
        }
    }
}

void resolverDoInicio(Pilha *p_origem, Pilha *p_destino, Pilha *p_auxiliar, int qtd_discos)
{
    if (qtd_discos > 0)
    {
        resolver2(p_origem, p_auxiliar, p_destino, qtd_discos - 1);
        mover(p_origem, p_destino);
        resolver2(p_auxiliar, p_destino, p_origem, qtd_discos - 1);
    }
}

int fim(Pilha *p1, Pilha *p2, Pilha *p3, int qtd)
{
    system("cls");
	if(tamanho(p3) == qtd)
	{
	    print_pinos(p1, p2, p3);
		printf("\nParabens! Voce concluiu o jogo. \n");
		if(qtd < TAM_MAX)
			printf("Proxima vez, tente jogar com %d discos. Boa sorte. \n", (qtd+1));
		return 0;
	}
	return 1;
}


