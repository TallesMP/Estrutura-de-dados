
#ifndef _MPUTAD_H
#define _MPUTAD_H

typedef struct MpuTCD *MpuTAD;

MpuTAD criarMpu(short int ax, short int ay, short int az, short int rx,
                short int ry, short int rz, short int sensibilidadeA,
                short int sensibilidadeR);
/** Cria e inicializa um objeto MpuTAD com os valores fornecidos para aceleração
 * (ax, ay, az), rotação (rx, ry, rz), e as sensibilidades de aceleração e
 * rotação. Retorna o ponteiro para o novo objeto.
 */

short int *getAceleracaoBruta(MpuTAD mpu);
/** Retorna um array de 3 elementos contendo os valores brutos de aceleração
 * (ax, ay, az). O array é alocado dinamicamente e deve ser liberado pelo
 * usuário após o uso.
 */

short int *getRotacaoBruta(MpuTAD mpu);
/** Retorna um array de 3 elementos contendo os valores brutos de rotação (rx,
 * ry, rz). O array é alocado dinamicamente e deve ser liberado pelo usuário
 * após o uso.
 */

float *getAceleracaoFinal(MpuTAD mpu);
/** Retorna um array de 3 elementos contendo os valores finais de aceleração
 * (ax_final, ay_final, az_final), calculados com base nas sensibilidades
 * configuradas. O array é alocado dinamicamente e deve ser liberado pelo
 * usuário após o uso.
 */

float *getRotacaoFinal(MpuTAD mpu);
/** Retorna um array de 3 elementos contendo os valores finais de rotação
 * (rx_final, ry_final, rz_final), calculados com base nas sensibilidades
 * configuradas. O array é alocado dinamicamente e deve ser liberado pelo
 * usuário após o uso.
 */

short int getSensibilidadeA(MpuTAD mpu);
/** Retorna o valor da sensibilidade de aceleração configurada (sensibilidadeA),
 * que determina o fator de escala para os valores de aceleração brutos.
 */

short int getSensibilidadeR(MpuTAD mpu);
/** Retorna o valor da sensibilidade de rotação configurada (sensibilidadeR),
 * que determina o fator de escala para os valores de rotação brutos.
 */

void setSensibilidades(MpuTAD mpu, short int sensibilidadeA,
                       short int sensibilidadeR);
/** Configura as sensibilidades de aceleração e rotação (sensibilidadeA e
 * sensibilidadeR) e recalcula os valores finais de aceleração e rotação com
 * base nas novas sensibilidades. Se um valor de sensibilidade inválido for
 * passado, a função imprime uma mensagem de erro.
 */

void setAceleracao(MpuTAD mpu, short int x, short int y, short int z);
/** Configura os valores brutos de aceleração (ax, ay, az) e recalcula os
 * valores finais de aceleração com base na sensibilidade configurada. Chama a
 * função de recalcular os valores finais.
 */

void setRotacao(MpuTAD mpu, short int x, short int y, short int z);
/** Configura os valores brutos de rotação (rx, ry, rz) e recalcula os valores
 * finais de rotação com base na sensibilidade configurada. Chama a função de
 * recalcular os valores finais.
 */

#endif
