/**
 * Arquivo: queueTAD_cliente.c
 * Versão : 1.0
 * Data   : 2024-11-02 15:26
 * -------------------------
 * Este arquivo implementa um pequeno programa de teste para a interface
 * queueTAD.h. Este teste é independente da implementação, mas deve ser
 * compilado diferentemente para implementações com array ou implementações
 * com lista simplesmente encadeada (ver arquivo Makefile para maiores
 * detalhes).
 *
 * Baseado em: Programming Abstractions in C, de Eric S. Roberts.
 *             Capítulo 10: Linear Structures (pg. 419-436).
 *
 * Prof.: Abrantes Araújo Silva Filho (Computação Raiz)
 *            www.computacaoraiz.com.br
 *            www.youtube.com.br/computacaoraiz
 *            github.com/computacaoraiz
 *            twitter.com/ComputacaoRaiz
 *            www.linkedin.com/company/computacaoraiz
 *            www.abrantes.pro.br
 *            github.com/abrantesasf
 */

/*** Includes ***/

#include "queueTAD.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*** Declarações de Subprogramas ***/

void teste_criar_e_remover (void);
void teste_enqueue_e_dequeue (void);
void teste_vazia (void);
void teste_cheia (void);
void teste_num_elementos (void);
void teste_info (void);
void teste_ver_elemento (void);

/*** Função MAIN ***/

int main (void)
{
    printf("=== Teste da Interface de Fila Genérica ===\n");

    teste_criar_e_remover();
    teste_enqueue_e_dequeue();
    teste_vazia();
    teste_cheia();
    teste_num_elementos();
    teste_info();
    teste_ver_elemento();

    printf("=== Todos os testes foram concluídos ===\n");

    return 0;
}

/*** Definições de Subprogramas ***/

void teste_criar_e_remover (void)
{
    printf("\n--- Teste de criar e remover fila ---\n");
    
    queueTAD queue = criar_queue();
    if (queue != NULL)
    {
        printf("Fila criada com sucesso\n");
    }
    else
    {
        printf("Erro ao criar a fila\n");
    }

    queue_status status = remover_queue(&queue);
    if (status == QUEUE_OK)
    {
        printf("Fila removida com sucesso\n");
    }
    else
    {
        printf("Erro ao remover a fila\n");
    }

    // Teste de erro ao tentar remover uma fila já removida
    status = remover_queue(&queue);
    if (status == QUEUE_ERRO_QUEUE)
    {
        printf("Erro capturado ao tentar remover uma fila nula\n");
    }
}

void teste_enqueue_e_dequeue (void)
{
    printf("\n--- Teste de enfileiramento e desenfileiramento ---\n");
    
    queueTAD queue = criar_queue();
    
    int data1 = 10, data2 = 20, data3 = 30;
    queue_status status;

    status = enqueue(queue, &data1);
    printf("Enfileiramento de data1: %s\n",
           status == QUEUE_OK ? "sucesso" : "falha");

    status = enqueue(queue, &data2);
    printf("Enfileiramento de data2: %s\n",
           status == QUEUE_OK ? "sucesso" : "falha");

    status = enqueue(queue, &data3);
    printf("Enfileiramento de data3: %s\n",
           status == QUEUE_OK ? "sucesso" : "falha");

    // Teste de desenfileiramento
    int *dequeued_data;
    
    status = dequeue(queue, (elementoT *) &dequeued_data);
    printf("Desenfileiramento: %s, valor: %d\n",
           status == QUEUE_OK ? "sucesso" : "falha", *dequeued_data);

    status = dequeue(queue, (elementoT *) &dequeued_data);
    printf("Desenfileiramento: %s, valor: %d\n",
           status == QUEUE_OK ? "sucesso" : "falha", *dequeued_data);

    status = dequeue(queue, (elementoT *) &dequeued_data);
    printf("Desenfileiramento: %s, valor: %d\n",
           status == QUEUE_OK ? "sucesso" : "falha", *dequeued_data);

    // Teste de erro ao desenfileirar de uma fila vazia
    status = dequeue(queue, (elementoT *) &dequeued_data);
    printf("Desenfileiramento de fila vazia: %s\n",
           status == QUEUE_ERRO_VAZIA ? "erro esperado" : "falha");

    remover_queue(&queue);
}

void teste_vazia (void)
{
    printf("\n--- Teste de verificação de fila vazia ---\n");
    
    queueTAD queue = criar_queue();
    bool esta_vazia;

    vazia(queue, &esta_vazia);
    printf("Fila inicialmente vazia: %s\n", esta_vazia ? "sim" : "não");

    int data = 42;
    enqueue(queue, &data);
    vazia(queue, &esta_vazia);
    printf("Fila após enfileiramento: %s\n",
           esta_vazia ? "vazia" : "não vazia");

    remover_queue(&queue);
}

void teste_cheia (void)
{
    printf("\n--- Teste de verificação de fila cheia ---\n");
    
    queueTAD queue = criar_queue();
    bool esta_cheia;
    
    cheia(queue, &esta_cheia);
    printf("Fila inicialmente cheia: %s\n", esta_cheia ? "sim" : "não");

    // Enfileira o número máximo de elementos para testar se fica cheia
    int data = 0, tamax;
    bool din;
    queue_status status;
    
    status = info(queue, &din, &tamax);
    if (status == QUEUE_OK && tamax != -1)
    {
        for (int i = 0; i < tamax; i++)
        {
            enqueue(queue, &data);
        }
    }
    else if (status == QUEUE_OK && tamax == -1)
    {
        for (int i = 0; i < 100; i++)
        {
            enqueue(queue, &data);
        }
    }

    cheia(queue, &esta_cheia);
    printf("Fila após enfileiramento de %d elementos: %s\n",
           tamax, esta_cheia ? "cheia" : "não cheia");

    remover_queue(&queue);
}

void teste_num_elementos (void)
{
    printf("\n--- Teste de contagem de elementos na fila ---\n");
    
    queueTAD queue = criar_queue();
    size_t nelem;

    num_elementos(queue, &nelem);
    printf("Número de elementos na fila (inicial): %zu\n", nelem);

    int data = 5;
    enqueue(queue, &data);
    num_elementos(queue, &nelem);
    printf("Número de elementos na fila após 1 enfileiramento: %zu\n", nelem);

    int data2 = 10;
    enqueue(queue, &data2);
    num_elementos(queue, &nelem);
    printf("Número de elementos na fila após 2 enfileiramentos: %zu\n", nelem);

    remover_queue(&queue);
}

void teste_info (void)
{
    printf("\n--- Teste de obtenção de informações sobre a fila ---\n");
    
    queueTAD queue = criar_queue();
    bool din;
    int tamax;

    queue_status status = info(queue, &din, &tamax);
    if (status == QUEUE_OK)
    {
        printf("Fila dinâmica: %s\n", din ? "sim" : "não");
        printf("Tamanho máximo da fila: %d\n", tamax);
    }
    else
    {
        printf("Erro ao obter informações da fila\n");
    }

    remover_queue(&queue);
}

void teste_ver_elemento (void)
{
    printf("\n--- Teste de ver elemento em posição específica (debug) ---\n");
    
    queueTAD queue = criar_queue();
    int data1 = 1, data2 = 2, data3 = 3;

    enqueue(queue, &data1);
    enqueue(queue, &data2);
    enqueue(queue, &data3);

    #ifdef debug
    int *elemento;
    queue_status status = ver_elemento(queue, 1, (elementoT *) &elemento);
    if (status == QUEUE_OK)
    {
        printf("Elemento na posição 1: %d\n", *elemento);
    }
    else
    {
        printf("Erro ao acessar elemento na posição 1\n");
    }

    status = ver_elemento(queue, 3, (elementoT *) &elemento);
    printf("Acesso a posição inválida (3): %s\n",
           status == QUEUE_ERRO_POSICAO ? "erro esperado" : "falha");
    #else
    printf("Modo debug inativo; teste de ver elemento ignorado.\n");
    #endif

    remover_queue(&queue);
}
