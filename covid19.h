/* covid19.h
* Protótipo das funções para receber e processar as informações
* a respeito do contágio por Covid-19 em um conjunto de países.
* Ciro Cirne Trindade
* 13/05/2020
*/
#ifndef _COVID19_H
#define _COVID19_H
#define TAM_MAX_NOME 50
/* Função que lê os nomes dos países. O 1º argumento da
função é o número de países e o segundo é o vetor de
de strings (matriz de caracteres) onde os nomes dos
países devem ser armazenados. */
void le_paises(int, char [][TAM_MAX_NOME + 1]);
/* Função que lê a matriz de contágios. O 1º argumento da
função é o número de países, o 2º argumento é o número
de dias, e o terceiro argumento é a matriz onde os
números de contágios serão armazenados. */
void le_contagios(int, int, int [][*]);
/* Função que devolve o número total de contágios em um
país. O 1º argumeto da função é o número de dias, o 2º
argumento é a matriz de contágios e o 3º argumento é
o índice na matriz de contágios que representa o país
cujo total de contágios deseja-se obter. */
int total_contagios_pais(int, int [][*], int);
/* Função que devolve o dia de maior contágios e o número
de contágios em um país. O 1º argumeto da função é o
número de dias, o 2º argumento é a matriz de contágios,
o 3º argumento é o índice na matriz de contágios que
representa o país dia de maior contágio e o número de
contágio deseja-se obter, o 4º argumento é um parâmetro de
saída usado para devolver o dia com maior número de contágios
e o 5º argumento é outro parâmetro de saída usado para
devolver o maior número de contágios. */
void dia_maior_contagio_pais(int, int [][*], int, int *, int *);
/* Função que devolve o dia de maior contágios e o número
de contágios em todos os países. O 1º argumeto da função
é o número de países, o 2º argumento é o número de dias,
o 3º argumento é a matriz de contágios, o 4º argumento
é um parâmetro de saída usado para devolver o dia com maior
número de contágios e o 5º argumento é outro parâmetro de
saída usado para devolver o número de contágios. */
void dia_maior_contagio(int, int, int [][*], int *, int *);
/* Função que devolve o tamanho da maior sequência crescente
de contágios em um país. O 1º argumeto da função é o número
de dias, o 2º argumento é a matriz de contágios e o 3º argumento
é o índice na matriz de contágios que representa o país cuja
maior sequência crescente de contágios deseja-se obter. */
int maior_sequencia_crescente(int, int [][*], int);
#endif