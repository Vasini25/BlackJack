#include "Util.h"

int main () {

    PILHA *pilha;
    CARTA *carta;

    pilha = cria_pilha_vazia();

    //para empilhar as cartas
    for(int i=0; i<TamMax; i++)
    {
        char nome[3];
        char naipe[11];

        scanf(" %s", naipe);
        scanf(" %[^(\r|\n)]s", nome);

        carta = define_nova_carta(nome, naipe);
        empilha_item(pilha, carta);
    }

    //variaveis necessárias para o jogo
    int total = 0;
    int vitoria;  //registra o resultado do jogo
    int contador_de_cartas = 0; //conta o numero de cartas retiradas da pilha

    //para desempilhar as cartas e já apagar as memórias alocadas para cada uma das cartas empilhadas
    for(int i=0; i<TamMax; i++)
    {
        carta = desempilha_item(pilha);
        contador_de_cartas++;

        imprime_carta(carta);

        total += getValorDaCarta(carta);
        apaga_carta(&carta);

        if(total == 21)
        {
            vitoria = TRUE;
            break;
        }
        else if(total > 21)
        {
            vitoria = FALSE;
            break;
        }
    }

    //laço for para dar free em cada uma das cartas alocadas antes de encerrar o programa
    //perceba q o laco for só precisa apagar 52 - numero de cartas desempilhadas (que já foram liberadas)
    for(int i=0; i<(TamMax - contador_de_cartas); i++)
    {
        carta = desempilha_item(pilha);
        apaga_carta(&carta);
    }

    apaga_pilha(&pilha);

    //mensagem de fim de jogo
    if(vitoria == TRUE)
    {
        printf("\nGanhou ;)\n");
    }
    else
    {
        printf("Perdeu :(\nSoma :: %d\n", total);
    }

    //libera a memória alocada na heap
    free(pilha);
    pilha = NULL;
    free(carta);
    carta = NULL;

    return 0;
}