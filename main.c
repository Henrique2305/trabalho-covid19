/* Autores:
 * Ewerton Lima
 * Henrique Ferreira
 * Matheus Carpeggiane
 * 19/05/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include "covid19.h"

int main() {
    int numPaises, numDias;
    int posicaoMaiorContagio = 0;
    int diaMaiorContagio = 0;
    int maiorContagio = 0;

    printf("Digite o numero de paises:");
    scanf("%d", &numPaises);

    char paises[numPaises][TAM_MAX_NOME + 1];
    le_paises(numPaises, paises);

    printf("Numero de dias: ");
    scanf("%d", &numDias);

    int matNumContagios[numPaises][numDias];

    le_contagios(numPaises, numDias, matNumContagios);
    
    // Vetor que recebe a soma do total de contagios de cada pais.
    int somaPaises[numPaises], i;

    //for utilizado para calcular a soma dos contagios por dia de cada pais.
    for (i = 0; i<numPaises; i++){
        somaPaises[i] = total_contagios_pais(numDias,matNumContagios,i);
    }

    // for utilizado para imprimir cada pais com o valor total de contagios.
    printf("\nNumero total de contagios por pais\n");
    for (i = 0; i<numPaises; i++){
        printf("%s:  %d\n", paises[i], somaPaises[i]);
    }

    printf("\nDia com maior numero de contagios por pais\n");
    for(int indice = 0; indice < numPaises; indice++){
        dia_maior_contagio_pais(numDias, matNumContagios, indice, &diaMaiorContagio, &maiorContagio);
        printf("%s: %d (%d)\n", paises[indice], diaMaiorContagio, maiorContagio);
    }

    dia_maior_contagio(numPaises, numDias, matNumContagios, &diaMaiorContagio, &maiorContagio);
    printf("\nDia com maior numero de contagios\n%d: %d\n", diaMaiorContagio, maiorContagio);

    printf("\nMaior sequencia crescente de contagios por pais\n");
    int seqPaises[numPaises];

    // Guarda a maior sequência crescente de dias de covid19 de cada país.
    for(i = 0; i < numPaises; i++) {
        seqPaises[i] = maior_sequencia_crescente(numDias, matNumContagios, i);
        printf("%s: %d\n", paises[i], seqPaises[i]);
    }
    return 0;
}