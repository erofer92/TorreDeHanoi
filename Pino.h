
#ifndef Pilha
typedef struct pilha Pilha;
#endif

void criar_Pino_Principal(Pilha **p);
void menu();
void instrucoes();
void creditos();
void print_pinos(Pilha *p1, Pilha *p2, Pilha *p3);
void listar_jogadas_possiveis(Pilha *p1, Pilha *p2, Pilha *p3);
void mover(Pilha *p_origem, Pilha *p_destino);
void resolver(Pilha *p_origem, Pilha *p_destino, Pilha *p_auxiliar, int profundidade);
void resolver2(Pilha *p_origem, Pilha *p_destino, Pilha *p_auxiliar, int qtd_discos);
int fim(Pilha *p1, Pilha *p2, Pilha *p3, int qtd);
