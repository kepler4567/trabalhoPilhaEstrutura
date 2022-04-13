#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    for (int i = 0; i < pilhasQueSeraoFormadas; i++)
    {
    
      void inicializaPilha();

    }
}

void printarPilhas() {

}


void trocarElementosDeLugar(){

}

void main(){
    int quantidadeDeNumeros = receberDigitos();
    formarPilhas(quantidadeDeNumeros);

    

    return 0;
}