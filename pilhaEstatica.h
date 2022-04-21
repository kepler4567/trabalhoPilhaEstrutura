#define MAX 100
#define BASE -1

typedef struct pilha
{
    int pilha[MAX];
    int topo;
} PILHA;

int pilhaCheia (PILHA p);
int pilhaVazia(PILHA p);

void inicializaPilha(PILHA *p);
int  empilha(PILHA *p, int n);
int  desempilha(PILHA *p, int *n);
int  elementoDoTopo(PILHA p);