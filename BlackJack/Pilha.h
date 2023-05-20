#ifndef PILHA_H
#define PILHA_H
#include "Util.h"

typedef struct pilha_st PILHA;

PILHA* cria_pilha_vazia();
int isEmpty();
int isFull();
void empilha_item();
CARTA* desempilha_item();
CARTA* topo_da_pilha();
int tamanho_da_pilha(PILHA *pilha);
void apaga_pilha();

#endif //PILHA_H