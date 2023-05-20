#include "Util.h"

struct item_st
{
    char nome[3];
    char naipe[11];
    int valor;
};

//cria uma nova carta
CARTA* define_nova_carta (char *nome, char *naipe)
{
    CARTA *carta;
    carta = (CARTA *)malloc(sizeof(CARTA));

    if(carta != NULL)
    {
        strcpy(carta->nome, nome);
        strcpy(carta->naipe, naipe);
        carta->valor = atribui_valor(carta->nome);

        return carta;
    }

    return NULL;
}

//deleta uma carta
int deleta_carta (CARTA **carta)
{
    if (*carta != NULL)
    {
        free (*carta);
        *carta = NULL;

        return TRUE;
    }

    printf("ERRO! carta não liberada");
    return FALSE;
}

//printa os atributos de uma carta desejada
void imprime_carta (CARTA *carta)
{
    if (carta != NULL)
    {
        printf("\nA carta é um %s de %s e seu valor é de %d\n", carta->nome, carta->naipe, carta->valor);
    }
}

//retorna o valor da carta recebida
int getValorDaCarta (CARTA *carta)
{
    return carta->valor;
}

void apaga_carta(CARTA **carta)
{
    if (*carta != NULL)
    {
        free (*carta);
        *carta = NULL;

        return;
    }

    printf("ERRO! carta não liberada");
    return;
}

//atribui valor (de uma forma bem feia) à carta para o jogo
int atribui_valor (char *nome)
{
    int valor_da_carta;

    if(strcmp(nome, "1") == 0)
    {
        valor_da_carta = 1;
    }
    else if(strcmp(nome, "2") == 0)
    {
        valor_da_carta = 2;
    }
    else if(strcmp(nome, "3") == 0)
    {
        valor_da_carta = 3;
    }
    else if(strcmp(nome, "4") == 0)
    {
        valor_da_carta = 4;
    }
    else if(strcmp(nome, "5") == 0)
    {
        valor_da_carta = 5;
    }
    else if(strcmp(nome, "6") == 0)
    {
        valor_da_carta = 6;
    }
    else if(strcmp(nome, "7") == 0)
    {
        valor_da_carta = 7;
    }
    else if(strcmp(nome, "8") == 0)
    {
        valor_da_carta = 8;
    }
    else if(strcmp(nome, "9") == 0)
    {
        valor_da_carta = 9;
    }
    else if(strcmp(nome, "10") == 0)
    {
        valor_da_carta = 10;
    }
    else if(strcmp(nome, "V") == 0)
    {
        valor_da_carta = 10;
    }
    else if(strcmp(nome, "D") == 0)
    {
        valor_da_carta = 10;
    }
    else if(strcmp(nome, "R") == 0)
    {
        valor_da_carta = 10;
    }

    return valor_da_carta;
}