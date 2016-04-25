#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define TAM_MAX 64

struct pilha
{
	int itens[TAM_MAX];
	int tp;
};

Pilha * criar()
{
	Pilha * p = (Pilha *)malloc(sizeof(Pilha));
	p->tp = 0;
	return p;
}

void destruir(Pilha * p)
{
	if (p != NULL)
		free(p);
}

int desempilhar(Pilha * p)
{
	if (p->tp == 0)
		return -1;
	return p->itens[--p->tp];
}

void empilhar(Pilha * p, int x)
{
	if (p->tp == TAM_MAX)
		return;
	p->itens[p->tp++] = x;
}

int tamanho(Pilha * p)
{
	return p->tp;
}

int topo(Pilha * p)
{
	if (p->tp == 0)
		return -1;
	return p->itens[p->tp-1];
}

void imprimir(Pilha * p)
{
	int i;

	printf("[ ");
	for(i=0; i<p->tp; i++)
    {
		printf("%d ", p->itens[i]);
	}
	printf("]");
}

Pilha* clonar(Pilha *p)
{
    Pilha *aux = criar();
    Pilha *clone = criar();
    int i, x, tam;

    tam = tamanho(p);

    for(i=0; i<tam; i++)
    {
        empilhar(aux, desempilhar(p));
    }
    for(i=0; i<tam; i++)
    {
        x = desempilhar(aux);
        empilhar(p, x);
        empilhar(clone, x);
    }
    destruir(aux);

    return clone;
}

void inverter1(Pilha * p)
{
	Pilha * aux1 = criar();
	Pilha * aux2 = criar();

	while(tamanho(p) != 0)
    {
		empilhar(aux1, desempilhar(p));
	}
	while(tamanho(aux1) != 0)
    {
		empilhar(aux2, desempilhar(aux1));
	}
	while(tamanho(aux2) != 0)
	{
		empilhar(p, desempilhar(aux2));
	}

	destruir(aux1);
	destruir(aux2);
}

void inverter2(Pilha * p)
{
	int i = 0, tam;
	int * itens = (int *)malloc(tamanho(p)*sizeof(int));

	while(tamanho(p) != 0)
    {
		itens[i++] = desempilhar(p);
	}

	tam = i;
	for(i=0; i<tam; i++)
	{
		empilhar(p, itens[i]);
	}

	free(itens);
}

void inverter3(Pilha * p)
{
	int i, f, tmp;

	for (i = 0, f = p->tp-1; i < f; i++, f--)
    {
		tmp = p->itens[i];
		p->itens[i] = p->itens[f];
		p->itens[f] = tmp;
	}
}
