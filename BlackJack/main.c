#include "Util.h"

void Sleep (int time);

int main () {

    PILHA *pilha;
    PILHA *SegundaPilha;
    CARTA *carta;

    pilha = cria_pilha_vazia();

    //pilha para embaralhar
    SegundaPilha = cria_pilha_vazia();

    srand(time(NULL));

    //para empilhar as cartas
    for(int i=0; i<TamMax; i++)
    {
        char nome[3];
        char naipe[11];

        scanf(" %s", naipe);
        scanf(" %[^(\r|\n)]s", nome);

        carta = define_nova_carta(nome, naipe);
        int random = rand()%2;

        //empilha na segunda aleatoriamente
        if(random == 0)
        {
            empilha_item(pilha, carta);
        }
        else
        {
            empilha_item(SegundaPilha, carta);
        }
    }

    //para desempilhar a segunda pilha no topo da primeira:
    while(tamanho_da_pilha(SegundaPilha) != 0)
    {
        carta = desempilha_item(SegundaPilha);
        empilha_item(pilha, carta);
    }
    apaga_pilha(&SegundaPilha);

    //primeira interação com o usuário
    printf("\n\n Embaralhando as cartas... \n\n");
    Sleep(2);

    //variaveis necessárias para o jogo
    int total = 0;
    int vitoria;  //registra o resultado do jogo
    int contador_de_cartas = 0; //conta o numero de cartas retiradas da pilha

    //para desempilhar as cartas e já apagar as memórias alocadas para cada uma das cartas empilhadas
    while(total < 21)
    {
        carta = desempilha_item(pilha);
        contador_de_cartas++;

        imprime_carta(carta);

        total += getValorDaCarta(carta);
        apaga_carta(&carta);

        if(total == 21)
        {
            vitoria = TRUE;
        }
        else
        {
            vitoria = FALSE;
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
        printf("\nPerdeu :(\nSoma :: %d\n", total);
    }

    //libera a memória alocada na heap
    free(pilha);
    pilha = NULL;
    free(carta);
    carta = NULL;

    return 0;
}

void Sleep (int time)
{
    time = time*1000000000;
    while(time != 0)
    {
        time--;
    }
}