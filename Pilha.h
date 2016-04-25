
typedef struct pilha Pilha;

Pilha * criar();
void destruir(Pilha * p);
int desempilhar(Pilha * p);
void empilhar(Pilha * p, int x);
int tamanho(Pilha * p);
int topo(Pilha * p);

// Funcoes Extras
void imprimir(Pilha * p);
void inverter1(Pilha * p);
void inverter2(Pilha * p);
void inverter3(Pilha * p);
