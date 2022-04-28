#include <stdio.h>
#include <stdlib.h>
#include "pilhaEstatica.h"


int pilhaCheia(PILHA p)
{
    return (p.topo == MAX);
}

int pilhaVazia(PILHA p)
{
    return (p.topo == BASE);
}

void inicializaPilha(PILHA *p)
{
    p->topo = BASE;
}

int empilha(PILHA *p, int n)
{
    if (pilhaCheia(*p))
        return 0;
    else
    {
        p->pilha[p->topo] = n;
        p->topo++;
        return 1;
    }
}

int desempilha(PILHA *p, int *n)
{
    if (pilhaVazia(*p))
        return 0;
    else
    {
        *n = p->pilha[p->topo];
        p->topo--;
        return 0;
    }
}

int elementoDoTopo(PILHA p)
{
    return(p.pilha[p.topo]);
}