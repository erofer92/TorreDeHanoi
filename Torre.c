
#ifndef Pilha
typedef struct pilha Pilha;
#endif // Pilha

int baseSecundaria(Pilha* p)
{
    Pilha *p_clone = clonar(p);

    int base_secundaria, tam;
    tam = tamanho(p_clone);

    for(base_secundaria = 1; base_secundaria <= tam; base_secundaria++);
    base_secundaria--;

    destruir(p_clone);

    return base_secundaria;
}

