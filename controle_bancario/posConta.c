/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: RETORNA 
*/

#include "funcoes.h"

ApontConta posConta(ListaDupla *D, int pos)
{
    ApontConta i;
    int x;

    i = D->pri;
    x = 1;  

    while (x != pos)
    {
        x++;
        i = i->prox;
    }

    return i;
}
