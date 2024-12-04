
#ifndef _LABIRINTO_H
#define _LABIRINTO_H

#include "genlib.h"
#include "simpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Tipo: pontoT
 * −−−−−−−−−−−−
 * O tipo pontoT é usado para encapsular um par de inteiros que formam as
 * coordenadas x e y de um único ponto que indica uma posição no labirinto. A
 * separação da struct permite que o código seja mais legível e modular.
 */
typedef struct {
  int x;
  int y;
} pontoT;

/**
 * Tipo: direcaoT
 * −−−−−−−−−−−−
 * O tipo direcaoT é uma enumeração que representa as quatro direções
 * principais: Norte, Leste, Sul e Oeste, que são usadas pelo algoritmo de
 * backtracking.
 */
typedef enum { Norte, Leste, Sul, Oeste } direcaoT;

/**
 * Função: ler_mapa
 * Uso: ler_mapa(arquivo);
 * -----------------------
 * Lê o mapa do arquivo especificado e carrega as informações no labirinto.
 */
void ler_mapa(const char *arquivo);

/**
 * Função: pegar_posicao_inicial
 * Uso: pontoT inicio = pegar_posicao_inicial();
 * -------------------------------------------
 * Retorna a posição inicial do labirinto.
 */
pontoT pegar_posicao_inicial(void);

/**
 * Função: resolver_labirinto
 * Uso: if (resolver_labirinto(pt)) ...
 * ------------------------------------
 * Resolve o labirinto a partir do ponto especificado. Usa backtracking para
 * encontrar o caminho até a saída.
 */
bool resolver_labirinto(pontoT pt);

/**
 * Função: imprimir_mapa
 * Uso: imprimir_mapa();
 * ----------------------
 * Imprime o mapa do labirinto, incluindo as marcações de caminho feitas.
 */
void mostrar_mapa(void);

#endif
