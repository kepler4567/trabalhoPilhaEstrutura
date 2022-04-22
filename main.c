#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoesPilha.c"


PILHA p[];

bool digitosEstaoEntreUmECinco(int quantidadeDeNumeros){

    return 3 <= quantidadeDeNumeros && quantidadeDeNumeros <= 5;
}

int receberDigitos() {
    int quantidadeDeNumeros;
    printf("Digite a quantidade de numeros que serao distribuidos entre as pilhas: ");
    scanf("%i", &quantidadeDeNumeros);

    if (digitosEstaoEntreUmECinco(quantidadeDeNumeros)) {
        return quantidadeDeNumeros;
    } else {
        printf("Digite um numero de 3 a 5\n");
        receberDigitos();
    }
}

void formarPilhas(int quantidadeDeNumeros){

    int pilhasQueSeraoFormadas = quantidadeDeNumeros + 2;
    int elementoParaInserirNaPilha;

    for (int i = 1; i <= pilhasQueSeraoFormadas; i++)
    {
        inicializaPilha(&p[i]);
    }

    for (int j = 1; j <= quantidadeDeNumeros; j++)
    {
        for (int i = 1; i <= 4; i++)
        {
            elementoParaInserirNaPilha = (rand() % quantidadeDeNumeros) + 1;
            empilha(&p[j], elementoParaInserirNaPilha);
        }

    }
}

void printarPilhas(int quantidadeDeNumeros) {
    int pilhasQueSeraoPrintadas = quantidadeDeNumeros + 2;
    int elemento;

    for (int j = 1; j <= pilhasQueSeraoPrintadas; j++)
    {
        PILHA p2 = p[j];
        printf("\n--------PILHA %d------ \n\n", j);

        for (int i = 3; i > -1; i--)
        {
            if(p2.pilha[i] != 0) { printf("\t| %d |\n", p2.pilha[i]); }
            else { printf("\t|   |\n"); }
        }
    }
}


void trocarElementosDePilha(int pilhaQueSeraRemovidoElem, int pilhaQueSeraAdicionadoElem){

    int  desempilha(p[pilhaQueSeraRemovidoElem], int n);
    int  empilha(p[pilhaQueSeraAdicionadoElem], int n);
}


bool jogoTerminou(int nDigitadoUsuario) {
    int pilhasQueSeraoVerificadas = nDigitadoUsuario + 2;

    for (int j = 1; j <= pilhasQueSeraoVerificadas; j++)
    {
        PILHA p2 = p[j];

        for (int i = 3; i > -1; i--)
        {
            printf("%i  e  %i", p2.pilha[i], p2.pilha[i-1]);
            if(p2.pilha[i] != p2.pilha[i-1]) return false;
        }
    }
    return true;
}


void iniciarJogo(int nDigitadoUsuario) {
    int pilhaQueSeraRemovidoElem;
    int pilhaQueSeraAdicionadoElem;

    while(!jogoTerminou(nDigitadoUsuario)) {

        printf("Digite a pilha que voce quer remover o elemento");
        scanf("%i", &pilhaQueSeraRemovidoElem);
        printf("Digite a pilha que voce quer adicionar o elemento");
        scanf("%i", &pilhaQueSeraAdicionadoElem);

        trocarElementosDePilha(pilhaQueSeraRemovidoElem, pilhaQueSeraAdicionadoElem);
        printarPilhas(nDigitadoUsuario);
    }

};


void main(){
    int nDigitadoUsuario = receberDigitos();
    formarPilhas(nDigitadoUsuario);
    printarPilhas(nDigitadoUsuario);
    iniciarJogo(nDigitadoUsuario);

    return 0;
}
