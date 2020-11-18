/* Autores:
 * Ewerton Lima
 * Henrique Ferreira
 * Matheus Carpeggiane
 * 19/05/2020
 */

#include <stdio.h>
#include <string.h>
#include "covid19.h"

/* Função que lê o nome dos países e guarda num vetor de strings. */
void le_paises(int numPaises, char paises[][TAM_MAX_NOME + 1]) {
    for(int i = 0; i < numPaises; i++) {
        printf("Nome do pais:");
        scanf(" %50[^\n]", paises[i]);
    }
}

/* Função que lê os números de contágios de cada país e guarda numa matriz de inteiro. */
void le_contagios(int numPaises, int numDias, int matNumContagios[][numDias]) {
    int i, j;
    for(i = 0; i < numPaises; i++) {
        printf("Lendo valores do %d pais: ", i+1);
        for(j = 0; j < numDias; j++) {
            scanf("%d", &matNumContagios[i][j]);
        }
    }
}

/* Função que retorna o total de números de contágios de um país. */
int total_contagios_pais(int numDias, int matNumContagios[][numDias], int indice){
    int i;
    int soma = 0;

    for ( i = 0; i < numDias; i++ )
        soma += matNumContagios[indice][i];
    return soma;
}

/* Função que devolve o dia de maior contágios e o número de contágios em um país. */
void dia_maior_contagio_pais (int numDias, int matNumContagios [] [numDias], int paises, 
                                int *diaMaiorContagio, int *maiorContagio) {
    int  j; 
    *maiorContagio = 0;

    // Verifica qual é o maior contágio de um país
    for(j = 0; j < numDias; j++) {
        if(matNumContagios [paises] [j] > *maiorContagio){
            *maiorContagio = matNumContagios[paises] [j]; 
        }
    }
       
    *diaMaiorContagio = 0;
    
    // Verifica qual é o maior dia do número de contágios de um país
    for(j = 0; j < numDias; j++) {
        if(matNumContagios [paises] [j] == *maiorContagio){
            *diaMaiorContagio = j + 1;
        }
    }
}

/* Função que devolve o dia de maior contágios e o número de contágios em todos os países. */
void dia_maior_contagio(int numPaises, int numDias, int matrizContagios [][numDias], 
                        int *diaMaiorContagio, int *maiorContagio){

    // Vetor que guarda o maior número de contágios em um dia de um país.
    int vetMaiorContagio[numDias];

    for(int i = 0; i < numDias; i++){
        vetMaiorContagio[i] = 0;
    }

    // Soma números de contágios por dia.
    for(int i = 0; i < numPaises; i++){
        for(int j = 0; j < numDias; j++){
            vetMaiorContagio[j] = vetMaiorContagio[j] + matrizContagios[i][j];
        }
    }

    // Retorna o maior número e o dia de maior contágios.
    *maiorContagio = 0;
    *diaMaiorContagio = 0;
    for(int i = 0; i < numDias; i++){
        if(vetMaiorContagio[i] > *maiorContagio){
            *maiorContagio = vetMaiorContagio[i];
        }
    }
    for(int i = 0; i < numDias; i++){
        if(vetMaiorContagio[i] == *maiorContagio){
            *diaMaiorContagio = i +1;
        }
    }
}

/*  Função que devolve a maior sequência crescente de dias do número de casos de covid19
   de um país. */

int maior_sequencia_crescente(int d, int contagios[][d], int p) {
    int maior = 1, atual = 1;
    for (int i = 0; i < d - 1; i++) {
        if (contagios[p][i + 1] > contagios[p][i]) {
            atual++;
            if (atual > maior) {
                maior = atual;
            }
        }
        else {
            atual = 1;
        }
    }
    return maior;
}
