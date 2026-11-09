/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 09/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: LIMPAR TODAS AS ALOCACOES DAS LISTAS
*/

#include "funcoes.h"

void freeMalloc(ListaDupla *D, ListaSimples *S)
{
    ApontConta j;
    ApontConta x;
 
    ApontMov i;
    ApontMov y;

    i = S->pri;
    
    while (i != NULL)
    {
        y = i;
        i = i->prox;
        free(y);
    }

    S->pri = NULL;
    S->ult = NULL;

    j = D->pri;
    
    while (j != NULL)
    {
        x = j;
        j = j->prox;
        free(x);
    }

    D->pri = NULL;
    D->ult = NULL;   
}
