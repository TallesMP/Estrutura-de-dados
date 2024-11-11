#include "mpuTAD.h"
#include "pilhampuTAD.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  PilhampuTAD pilha = criarPilha();
  for (int i = 0; i < 100; i++) {
    MpuTAD mpu = criarMpu(i * 100, i * 100, i * 100, i * 100, i * 100, i * 100,
                          16, 2000);
    push(pilha, mpu);
  }
  for (int i = 0; i < 100; i++) {
    printf("x:%f\n", getAceleracaoFinal(verElemento(pilha))[0]);
    printf("y:%f\n", getAceleracaoFinal(verElemento(pilha))[1]);
    printf("z:%f\n", getAceleracaoFinal(verElemento(pilha))[2]);
    printf("Numero atual da stack: %d\n", verQuantidade(pilha));
    printf("==========================\n");
    pop(pilha);
  }
  return 0;
}
