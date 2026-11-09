/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: ORDENA A LISTA DUPLAMENTE POR CODIGO
*/

#include "funcoes.h"

void ordemCodigo(ListaDupla *D)
{
    ApontConta i;
    ApontConta j;

    regConta aux;

    for (i = D->pri; i != NULL; i = i->prox)
    {
        for (j = i->prox; j != NULL; j = j->prox)
        {
            if (i->conteudo.codigo_conta > j->conteudo.codigo_conta)
            {    
                aux = i->conteudo;
                i->conteudo = j->conteudo;
                j->conteudo = aux;
            }
        }
    }
}
