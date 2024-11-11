#include "mpuTAD.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Teste 1: Criar MpuTAD\n");
  MpuTAD mpu = criarMpu(1000, 2000, 3000, 100, 200, 300, 4, 500);

  printf("Valores brutos de Aceleracao: \n");
  short int *acel = getAceleracaoBruta(mpu);
  printf("ax: %d, ay: %d, az: %d\n", acel[0], acel[1], acel[2]);

  printf("Valores brutos de Rotacao: \n");
  short int *rot = getRotacaoBruta(mpu);
  printf("rx: %d, ry: %d, rz: %d\n", rot[0], rot[1], rot[2]);

  printf("Valores finais de Aceleracao: \n");
  float *acel_final = getAceleracaoFinal(mpu);
  printf("ax_final: %f, ay_final: %f, az_final: %f\n", acel_final[0],
         acel_final[1], acel_final[2]);

  printf("Valores finais de Rotacao: \n");
  float *rot_final = getRotacaoFinal(mpu);
  printf("rx_final: %f, ry_final: %f, rz_final: %f\n", rot_final[0],
         rot_final[1], rot_final[2]);

  printf("\nTeste 2: Alterar sensibilidades\n");
  setSensibilidades(mpu, 8, 1000);

  acel_final = getAceleracaoFinal(mpu);
  rot_final = getRotacaoFinal(mpu);
  printf("Novos valores finais de Aceleracao: \n");
  printf("ax_final: %f, ay_final: %f, az_final: %f\n", acel_final[0],
         acel_final[1], acel_final[2]);

  printf("Novos valores finais de Rotacao: \n");
  printf("rx_final: %f, ry_final: %f, rz_final: %f\n", rot_final[0],
         rot_final[1], rot_final[2]);

  printf("\nTeste 3: Alterar valores de Aceleracao e Rotacao\n");
  setAceleracao(mpu, 4000, 5000, 6000);
  setRotacao(mpu, 50, 75, 100);

  acel_final = getAceleracaoFinal(mpu);
  rot_final = getRotacaoFinal(mpu);
  printf("Novos valores de Aceleracao: \n");
  printf("ax_final: %f, ay_final: %f, az_final: %f\n", acel_final[0],
         acel_final[1], acel_final[2]);

  printf("Novos valores de Rotacao:\n");
  printf("rx_final: %f, ry_final: %f, rz_final: %f\n", rot_final[0],
         rot_final[1], rot_final[2]);

  printf("\nTeste 4: Recuperar as sensibilidades\n");
  short int sensA = getSensibilidadeA(mpu);
  short int sensR = getSensibilidadeR(mpu);
  printf("Sensibilidade de Aceleracao: %d\n", sensA);
  printf("Sensibilidade de Rotacao: %d\n", sensR);

  free(acel);
  free(rot);
  free(acel_final);
  free(rot_final);
  free(mpu);

  return 0;
}
