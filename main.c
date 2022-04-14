#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcoesPilha.h"



bool digitosEstaoEntreUmECinco(int quantidadeDeNumeros){

    return 3 > quantidadeDeNumeros < 5;
}

int receberDigitos() {
    int quantidadeDeNumeros;
    printf("Digite a quantidade de numeros que serao distribuidos entre as pilhas: ");
    scanf("%i", quantidadeDeNumeros);

    if (digitosEstaoEntreUmECinco) {
        return quantidadeDeNumeros;
    } else { 
        printf("Digite um número de 3 a 5");
        receberDigitos();
    }
}

void formarPilhas(int quantidadeDeNumeros){

    int pilhasQueSeraoFormadas = quantidadeDeNumeros + 2;
    int elementoParaInserirNaPilha;

    for (int i = 0; i <= pilhasQueSeraoFormadas; i++)
    {
    
        inicializaPilha();

    }

    for (int j = 0; j < quantidadeDeNumeros; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            elementoParaInserirNaPilha = (rand() % quantidadeDeNumeros) + 1;
            empilha(PILHA p, elementoParaInserirNaPilha);
        }
        
    }
    
}

void printarPilhas(int quantidadeDeNumeros) {
    int pilhasQueSeraoPrintadas = quantidadeDeNumeros + 2;
    int elemento;

    for (int i = 1; i < pilhasQueSeraoPrintadas; i++)
    {
        for (int i = 0; i < 4; i++)
        {
            elemento = elementoDoTopo(PILHA P);
            printf(elemento);
        }
        printf("|");
    }
    

}


void trocarElementosDeLugar(){

}

void main(){
    int quantidadeDeNumeros = receberDigitos();
    formarPilhas(quantidadeDeNumeros);

    

    return 0;
}