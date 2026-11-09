/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: ORDENA AS CONTAS POR ORDEM ALFABETICA
*/

#include "funcoes.h"

void ordemAlfabetica(ListaDupla *D)
{
    ApontConta i;
    ApontConta j;

    regConta aux;

    char l1;
    char l2;

    for (i = D->pri; i != NULL; i = i->prox)
    {
        for (j = i->prox; j != NULL; j = j->prox)
        {
            l1 = tolower(i->conteudo.banco[0]);
            l2 = tolower(j->conteudo.banco[0]);

            if (l1 > l2)
            {
                aux = i->conteudo;
                i->conteudo = j->conteudo;
                j->conteudo = aux;
            }
        }
    }
}
