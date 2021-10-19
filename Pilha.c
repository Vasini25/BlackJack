#include "Util.h"

struct pilha_st
{
    CARTA *item[TamMax];
    int topo;
};

//aloca dinamicamente a pilha e garante que seu topo seja nulo;
PILHA* cria_pilha_vazia ()
{
    PILHA *pilha;
    pilha = (PILHA *)malloc(sizeof(PILHA));

    if(isEmpty(pilha) != TRUE)
    {
        pilha->topo = 0;
    }

    return pilha;
}

//verifica se há itens na pilha
int isEmpty (PILHA *pilha)
{
    if(pilha != NULL)
    {
        if (pilha->topo == 0)
        {
            return TRUE;
        }

        return FALSE;
    }

    printf("Erro!");
    return FALSE;
}

//verifica se há espaços restantes na pilha
int isFull (PILHA *pilha)
{
    if(pilha != NULL)
    {
        if (pilha->topo >= TamMax)
        {
            return TRUE;
        }

        return FALSE;
    }

    printf("Erro!");
    return FALSE;
}

//empilha um item
void empilha_item (PILHA *pilha, CARTA *item)
{
    if(pilha == NULL || isFull(pilha) == TRUE)
    {
        printf("Erro ao EMPILHAR, pilha inválida");
        return;
    }

    pilha->item[pilha->topo] = item;
    pilha->topo += 1;
}

//desempilha um item
CARTA* desempilha_item (PILHA *pilha)
{
    if(pilha == NULL || pilha->topo <= 0)
    {
        printf("Erro ao DESEMPILHAR, pilha inválida");
        return NULL;
    }

    CARTA *item_desemplihado;

    pilha->topo -= 1;
    item_desemplihado = pilha->item[pilha->topo];
    pilha->item[pilha->topo] = NULL;

    return item_desemplihado;
}

//retorna o item do topo da pilha
CARTA* topo_da_pilha (PILHA *pilha)
{
    if((pilha != NULL) && (isEmpty(pilha) == FALSE))
    {
        return (pilha->item[pilha->topo-1]);
    }

    return NULL;
}

//retorna o tamanho da pilha (seu topo)
int tamanho_da_pilha (PILHA *pilha)
{
    if(pilha != NULL)
    {
        return pilha->topo;
    }

    printf("Erro!");
    return FALSE;
}

//apaga a pilha
void apaga_pilha(PILHA **pilha)
{
    if (*pilha != NULL)
    {
        (*pilha)->topo = 53;

        free (*pilha);
        *pilha = NULL;

        return;
    }

    printf("ERRO!");
    return;
}