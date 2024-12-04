
/**
 * Arquivo: labirinto.c
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este arquivo implementa a interface 'labirinto.h',
 * utilizando procedimentos recursivos de backtracking.
 *
 * Baseado em: Programming Abstractions in C, de Eric S. Roberts.
 * Capítulo 6: Backtracking Algorithms (pg. 235−245).
 *
 * Prof.: Abrantes Araújo Silva Filho
 * Computação Raiz:
 * www.computacaoraiz.com.br
 * www.youtube.com.br/computacaoraiz
 * github.com/computacaoraiz
 * twitter.com/ComputacaoRaiz
 * www.linkedin.com/company/computacaoraiz
 * www.abrantes.pro.br
 */

/* Includes */
#include "labirinto.h"
#include <stdlib.h>
#include <string.h>

/* Defines */
#define MAX_LIN 100
#define MAX_COL 100

/* Criação de variáveis */
char mapa[MAX_LIN][MAX_COL];
bool visitado[MAX_LIN][MAX_COL];
int lin = 0, col = 0;
pontoT posicao_inicial;

/**
 * Procedimento: ler_mapa
 * Uso: ler_mapa(arquivo);
 * -----------------------
 * Este procedimento lê o mapa do labirinto a partir de um arquivo
 * passado como argumento. O mapa é armazenado na variável global `mapa`.
 * Ele também localiza a posição inicial indicada pelo caractere 'I' e
 * armazena suas coordenadas em `posicao_inicial`.
 */
void ler_mapa(const char *arquivo) {
  FILE *file = fopen(arquivo, "r");

  if (!file) {
    printf("Erro ao abrir o arquivo %s\n", arquivo);
    exit(1);
  }

  lin = 0;
  while (fgets(mapa[lin], MAX_COL, file)) {
    mapa[lin][strcspn(mapa[lin], "\n")] = '\0';
    col = strlen(mapa[lin]);
    lin++;
  }
  fclose(file);

  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      if (mapa[i][j] == 'I') {
        posicao_inicial.x = i;
        posicao_inicial.y = j;
        return;
      }
    }
  }
}

/**
 * Função: pegar_posicao_inicial
 * Uso: pontoT inicio = pegar_posicao_inicial();
 * --------------------------------------------
 * Retorna a posição inicial do labirinto, identificada pela leitura do
 * caractere 'I'.
 */
pontoT pegar_posicao_inicial(void) { return posicao_inicial; }

/**
 * Predicado: saiu_do_labirinto
 * Uso: if (saiu_do_labirinto(pt)) ...
 * -----------------------------------
 * Retorna `true` se o ponto especificado está fora dos limites do labirinto.
 */
bool saiu_do_labirinto(pontoT pt) {
  return pt.x < 0 || pt.x >= lin || pt.y < 0 || pt.y >= col;
}

/**
 * Predicado: e_parede
 * Uso: if (e_parede(pt, dir)) ...
 * --------------------------------
 * Retorna `true` se houver uma parede ou obstáculo na direção indicada
 * a partir do ponto especificado.
 */
bool e_parede(pontoT pt, direcaoT dir) {
  pontoT novo_pt = pt;

  switch (dir) {
  case Norte:
    novo_pt.x--;
    break;
  case Leste:
    novo_pt.y++;
    break;
  case Sul:
    novo_pt.x++;
    break;
  case Oeste:
    novo_pt.y--;
    break;
  }

  if (saiu_do_labirinto(novo_pt))
    return true;

  return mapa[novo_pt.x][novo_pt.y] == '#' ||
         mapa[novo_pt.x][novo_pt.y] == '|' ||
         mapa[novo_pt.x][novo_pt.y] == '-' || mapa[novo_pt.x][novo_pt.y] == '+';
}

/**
 * Predicado: esta_marcado
 * Uso: if (esta_marcado(pt)) ...
 * ------------------------------
 * Retorna `true` se o ponto especificado já foi visitado.
 */
bool esta_marcado(pontoT pt) { return visitado[pt.x][pt.y]; }

/**
 * Procedimento: marcar_ponto
 * Uso: marcar_ponto(pt);
 * ----------------------
 * Marca um ponto como visitado e atualiza o mapa para incluir o caractere 'X'
 * na posição especificada, desde que não seja um obstáculo do tipo '+'.
 */
void marcar_ponto(pontoT pt) {
  if (mapa[pt.x][pt.y] != '+') {
    visitado[pt.x][pt.y] = true;
    mapa[pt.x][pt.y] = 'X';
  }
}

/**
 * Procedimento: desmarcar_ponto
 * Uso: desmarcar_ponto(pt);
 * --------------------------
 * Desmarca um ponto, removendo-o da lista de pontos visitados, e restaura
 * o caractere original no mapa.
 */
void desmarcar_ponto(pontoT pt) {
  visitado[pt.x][pt.y] = false;
  mapa[pt.x][pt.y] = ' ';
}

/**
 * Função: resolver_labirinto
 * Uso: if (resolver_labirinto(pt)) ...
 * ------------------------------------
 * Resolve o labirinto recursivamente usando backtracking. Marca os pontos do
 * caminho com 'X' e retorna `true` se o labirinto pode ser resolvido a partir
 * do ponto inicial, ou `false` caso contrário.
 */
bool resolver_labirinto(pontoT pt) {
  if (saiu_do_labirinto(pt))
    return true;
  if (mapa[pt.x][pt.y] == '#' || mapa[pt.x][pt.y] == '|' ||
      mapa[pt.x][pt.y] == '-' || mapa[pt.x][pt.y] == '+' || esta_marcado(pt))
    return false;

  marcar_ponto(pt);

  for (direcaoT dir = Norte; dir <= Oeste; dir++) {
    pontoT novo_pt = pt;

    switch (dir) {
    case Norte:
      novo_pt.x--;
      break;
    case Leste:
      novo_pt.y++;
      break;
    case Sul:
      novo_pt.x++;
      break;
    case Oeste:
      novo_pt.y--;
      break;
    }

    if (resolver_labirinto(novo_pt)) {
      return true;
    }
  }

  desmarcar_ponto(pt);

  return false;
}

/**
 * Procedimento: imprimir_mapa
 * Uso: mostrar_mapa();
 * ----------------------
 * Imprime o mapa do labirinto no estado atual, com as marcações
 * do caminho.
 */
void mostrar_mapa(void) {
  for (int i = 0; i < lin; i++) {
    printf("%s\n", mapa[i]);
  }
}
