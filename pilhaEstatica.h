#define MAX 3
#define BASE -1

typedef struct
{
    int pilha[MAX];
    int topo;
} PILHA;

int pilhaCheia (PILHA p);
int pilhaVazia(PILHA p);

void inicializaPilha(PILHA *p);
void empilha(PILHA *p, int n);
int  desempilha(PILHA *p, int *n);
int  elementoDoTopo(PILHA p);
