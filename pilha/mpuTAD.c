#include "mpuTAD.h"
#include <stdio.h>
#include <stdlib.h>

struct MpuTCD {
  // Valores Brutos aceleração:
  signed short int ax;
  signed short int ay;
  signed short int az;
  // Valores corretos aceleração:
  float ax_final;
  float ay_final;
  float az_final;

  // Valores Brutos rotação:
  signed short int rx;
  signed short int ry;
  signed short int rz;
  // Valores corretos aceleração:
  float rx_final;
  float ry_final;
  float rz_final;

  short int sensibilidadeA;
  short int sensibilidadeR;
};

short int fatorEscalaA(short int sensibilidadeA) {
  sensibilidadeA = abs(sensibilidadeA);
  switch (sensibilidadeA) {
  case 2:
    return 16384;
  case 4:
    return 8192;
  case 8:
    return 4096;
  case 16:
    return 2048;
  default:
    printf("sensibilidadeA Invalida: %d\n", sensibilidadeA);
    exit(1);
  }
}

float fatorEscalaR(short int sensibilidadeR) {
  sensibilidadeR = abs(sensibilidadeR);
  switch (sensibilidadeR) {
  case 250:
    return 131.0;
  case 500:
    return 65.5;
  case 1000:
    return 32.8;
  case 2000:
    return 16.4;
  default:
    printf("sensibilidadeR invalida: %d\n", sensibilidadeR);
    exit(1);
  }
}

void calcularValoresFinais(MpuTAD mpu) {
  float sensiA = fatorEscalaA(mpu->sensibilidadeA);
  float sensiR = fatorEscalaR(mpu->sensibilidadeR);

  // Aceleracao
  mpu->ax_final = mpu->ax / sensiA;
  mpu->ay_final = mpu->ay / sensiA;
  mpu->az_final = mpu->az / sensiA;
  // Rotação
  mpu->rx_final = mpu->rx / sensiR;
  mpu->ry_final = mpu->ry / sensiR;
  mpu->rz_final = mpu->rz / sensiR;
}

MpuTAD criarMpu(short int ax, short int ay, short int az, short int rx,
                short int ry, short int rz, short int sensibilidadeA,
                short int sensibilidadeR) {
  MpuTAD T = malloc(sizeof(struct MpuTCD));
  if (T == NULL) {
    printf("Erro ao alocar: criarMpuTAD()\n");
    exit(1);
  }
  setSensibilidades(T, sensibilidadeA, sensibilidadeR);
  setAceleracao(T, ax, ay, az);
  setRotacao(T, rx, ry, rz);

  return T;
}

short int *getAceleracaoBruta(MpuTAD mpu) {
  short int *array = malloc(3 * sizeof(signed short int));
  if (array == NULL) {
    printf("Erro ao alocar: getAceleracaoBruta()\n");
    exit(1);
  }
  array[0] = mpu->ax;
  array[1] = mpu->ay;
  array[2] = mpu->az;

  return array;
}

short int *getRotacaoBruta(MpuTAD mpu) {
  short int *array = malloc(3 * sizeof(signed short int));
  if (array == NULL) {
    printf("Erro ao alocar: getRotacaoBruta()\n");
    exit(1);
  }
  array[0] = mpu->rx;
  array[1] = mpu->ry;
  array[2] = mpu->rz;

  return array;
}

float *getAceleracaoFinal(MpuTAD mpu) {
  float *array = malloc(3 * sizeof(signed short int));
  if (array == NULL) {
    printf("Erro ao alocar: getAceleracaoFinal()\n");
    exit(1);
  }
  array[0] = mpu->ax_final;
  array[1] = mpu->ay_final;
  array[2] = mpu->az_final;

  return array;
}

float *getRotacaoFinal(MpuTAD mpu) {
  float *array = malloc(3 * sizeof(signed short int));
  if (array == NULL) {
    printf("Erro ao alocar: getRotacaoFinal()\n");
    exit(1);
  }
  array[0] = mpu->rx_final;
  array[1] = mpu->ry_final;
  array[2] = mpu->rz_final;

  return array;
}

short int getSensibilidadeA(MpuTAD mpu) { return mpu->sensibilidadeA; }

short int getSensibilidadeR(MpuTAD mpu) { return mpu->sensibilidadeR; }

void setSensibilidades(MpuTAD mpu, short int sensibilidadeA,
                       short int sensibilidadeR) {

  if (sensibilidadeA != 2 && sensibilidadeA != 4 && sensibilidadeA != 8 &&
      sensibilidadeA != 16) {
    printf("sensibilidadeA invalida, valor deve ser: 2, 4, 8, 16\n");
    return;
  }
  if (sensibilidadeR != 250 && sensibilidadeR != 500 &&
      sensibilidadeR != 1000 && sensibilidadeR != 2000) {
    printf("sensibilidadeR invalida, valor deve ser: 250, 500, 1000, 2000\n");
    return;
  }

  mpu->sensibilidadeA = sensibilidadeA;
  mpu->sensibilidadeR = sensibilidadeR;
  calcularValoresFinais(mpu);
}

void setAceleracao(MpuTAD mpu, short int x, short int y, short int z) {
  mpu->ax = x;
  mpu->ay = y;
  mpu->az = z;
  calcularValoresFinais(mpu);
}

void setRotacao(MpuTAD mpu, short int x, short int y, short int z) {
  mpu->rx = x;
  mpu->ry = y;
  mpu->rz = z;
  calcularValoresFinais(mpu);
}
