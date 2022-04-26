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
            elementoParaInserirNaPilha = elementoQueSeraPreenchido(quantidadeDeNumeros);
            empilha(&p[j], elementoParaInserirNaPilha);
        }

    }
}

int elementosJaInseridos[];
int i = 0;
int elementoQueSeraPreenchido(int nDigitados){
    int elementoQSeraInserido = (rand() % nDigitados) + 1;
    elementosJaInseridos[i] = elementoQSeraInserido;
    int quantDoMesmoElementoJaInserido = 0;

    for(int j = 0; j<= i; j++) {
        if(elementosJaInseridos[j] == elementoQSeraInserido) {
            quantDoMesmoElementoJaInserido++;
        }
    }

    if(quantDoMesmoElementoJaInserido > 4) {
        elementoQueSeraPreenchido(nDigitados);
    }
    else {
     i++;
     return elementoQSeraInserido;
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
            if(i <= p2.topo) { printf("\t| %d |\n", p2.pilha[i]); }
            else { printf("\t|   |\n"); }
        }
    }
}


void trocarElementosDePilha(int pilhaQueSeraRemovidoElem, int pilhaQueSeraAdicionadoElem){
    int elem;
    desempilha(&p[pilhaQueSeraRemovidoElem], &elem);
    empilha(&p[pilhaQueSeraAdicionadoElem], elem);
}


bool jogoTerminou(int nDigitadoUsuario) {
    int pilhasQueSeraoVerificadas = nDigitadoUsuario + 2;

    for (int j = 1; j <= pilhasQueSeraoVerificadas; j++)
    {
        PILHA p2 = p[j];

        for (int i = p2.topo; i >= 1; i--)
        {
            printf("%i na pilha %i na posicao %i e %i na posicao %i\n", p2.pilha[i], j, i, p2.pilha[i-1], i-1);
            if(p2.pilha[i] != p2.pilha[i-1] || pilhaCheia(p2) || pilhaVazia(p2)) return false; // verificar tbm se tem pilhas vazias
        }
    }
    return true;
}


bool podeTrocarElementos(int pilhaOrigem, int pilhaDestino, int nDigitadoUsuario) {

    return !pilhaVazia(p[pilhaOrigem]) &&
        !pilhaCheia(p[pilhaDestino]) &&
        pilhaOrigem <= nDigitadoUsuario + 2 &&
        pilhaOrigem > 0 &&
        pilhaDestino <= nDigitadoUsuario + 2 &&
        pilhaDestino > 0;

}

void iniciarJogo(int nDigitadoUsuario) {
    int pilhaOrigem;
    int pilhaDestino;

    while(!jogoTerminou(nDigitadoUsuario)) {

        printf("Digite a pilha que voce quer remover o elemento: ");
        scanf("%i", &pilhaOrigem);
        printf("Digite a pilha que voce quer adicionar o elemento: ");
        scanf("%i", &pilhaDestino);

        if(podeTrocarElementos(pilhaOrigem, pilhaDestino, nDigitadoUsuario)  ) {
            trocarElementosDePilha(pilhaOrigem, pilhaDestino);
            printarPilhas(nDigitadoUsuario);
        }
        else {
            printf("Jogada invalida\n");
            printarPilhas(nDigitadoUsuario);
         }

    }

};


void main(){
    printf("Bem vindo ao jogo, o seu objetivo e deixar todas as pilhas com o mesmo elemento\n\n");
    int nDigitadoUsuario = receberDigitos();
    formarPilhas(nDigitadoUsuario);
    printarPilhas(nDigitadoUsuario);
    iniciarJogo(nDigitadoUsuario);

    return 0;
}
