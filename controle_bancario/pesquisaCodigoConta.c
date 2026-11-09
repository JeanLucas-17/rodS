/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: VERIFICAR SE O CODIGO DA CONTA JA EXISTE
*/

#include "funcoes.h"

ApontConta pesquisaCodigoConta(ListaDupla *D, int codigo)
{
    ApontConta i;

    i = D->pri;

    while (i != NULL)
    {
        if (i->conteudo.codigo_conta == codigo)
        {
            return i;
        }
        
        i = i->prox;
    }

    return NULL;
}
