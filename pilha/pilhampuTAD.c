#include "pilhampuTAD.h"
#include "mpuTAD.h"
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

struct PilhampuTCD {
  MpuTAD dados[TAMANHO];
  int contagem;
};

PilhampuTAD criarPilha() {
  PilhampuTAD T = malloc(sizeof(struct PilhampuTCD));
  if (T == NULL) {
    printf("Erro ao alocar: criarPilha\n");
    exit(1);
  }
  T->contagem = 0;
  return T;
}
int verQuantidade(PilhampuTAD pilha) { return pilha->contagem; }

int cheia(PilhampuTAD pilha) { return pilha->contagem == TAMANHO; }
int vazia(PilhampuTAD pilha) { return !(pilha->contagem); }

MpuTAD verElemento(PilhampuTAD pilha) {
  if (pilha == NULL) {
    printf("pilha null");
    exit(1);
  }
  return pilha->dados[pilha->contagem - 1];
}

MpuTAD pop(PilhampuTAD pilha) {
  if (pilha == NULL) {
    printf("Pilha NULL\n");
    exit(1);
  }
  if (pilha->contagem == 0) {
    printf("Pilha vazia\n");
    return NULL;
  }
  return pilha->dados[--pilha->contagem];
}

void push(PilhampuTAD pilha, MpuTAD mpu) {
  if (pilha == NULL) {
    printf("mpu NULL\n");
    exit(1);
  } else if (cheia(pilha)) {
    printf("pilha cheia\n");
    return;
  }
  pilha->dados[pilha->contagem++] = mpu;
}

void removerPilha(PilhampuTAD *pilha) {
  if (*pilha != NULL) {
    free((*pilha)->dados);
    free(*pilha);
    *pilha = NULL;
  }
}
