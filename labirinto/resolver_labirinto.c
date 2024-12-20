
/**
 * Arquivo: cliente.c
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este é o programa cliente que utiliza a biblioteca "labirinto.h" para
 * encontrar a saída de um labirinto utilizando algoritmos recursivos de
 * backtracking.
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

#include "labirinto.h"

int main(void) {
  ler_mapa("arquivo.txt");

  if (resolver_labirinto(pegar_posicao_inicial())) {
    printf("\nAs posicoes com X marcam o caminho para saida.");
    printf("\nLabirinto resolvido:\n");
    mostrar_mapa();
  } else {
    printf("Não existe saida do labirinto.\n");
  }
}
