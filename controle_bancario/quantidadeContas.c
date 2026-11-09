/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: RETORNA A QUANTIDADE DE CONTAS CADASTRADAS
*/

#include "funcoes.h"

int quantidadeContas(ListaDupla *D)
{
    ApontConta i;

    int x;

    i = D->pri;
    x = 0;

    while (i != NULL)
    {
        x++;

        i = i->prox;
    }

    return x;
}
