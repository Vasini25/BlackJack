#ifndef CARTA_H
#define CARTA_H

typedef struct item_st CARTA;

CARTA* define_nova_carta();
int deleta_carta();
void imprime_carta();
int atribui_valor();
int getValorDaCarta();
void apaga_carta();

#endif //CARTA_H