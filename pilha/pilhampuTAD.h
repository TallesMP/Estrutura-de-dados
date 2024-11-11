
#include "mpuTAD.h"

#ifndef _PILHAMPUTAD_H
#define _PILHAMPUTAD_H

typedef struct PilhampuTCD *PilhampuTAD;

PilhampuTAD criarPilha();
/** Cria e inicializa uma pilha vazia para armazenar elementos do tipo MpuTAD.
 *  Retorna o ponteiro para a pilha criada.
 */

int verQuantidade(PilhampuTAD pilha);
/** Retorna o número de elementos atualmente armazenados na pilha.
 */

int cheia(PilhampuTAD pilha);
/** Retorna 1 se a pilha estiver cheia (com limite definido de elementos) ou 0
 * caso contrário.
 */

int vazia(PilhampuTAD pilha);
/** Retorna 1 se a pilha estiver vazia (sem elementos), ou 0 caso contrário.
 */

MpuTAD pop(PilhampuTAD pilha);
/** Remove e retorna o topo da pilha (último elemento inserido). A pilha é
 * modificada após a remoção. Retorna o ponteiro para o elemento do tipo MpuTAD
 * removido.
 */

void push(PilhampuTAD pilha, MpuTAD mpu);
/** Insere um novo elemento do tipo MpuTAD no topo da pilha. A pilha é
 * modificada após a inserção.
 */

MpuTAD verElemento(PilhampuTAD pilha);
/** Retorna o topo da pilha sem removê-lo, permitindo visualizar o elemento
 * armazenado mais recentemente.
 */

void removerPilha(PilhampuTAD *pilha);
/** Libera a memória alocada para a pilha e todos os seus elementos, destruindo
 * a pilha.
 */

#endif
