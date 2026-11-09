/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 07/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: PESQUISA SE O CODIGO DA CONTA E IGUAL A ALGUM CODIGO DAS MOVIMENTACOES
*/

#include "funcoes.h"

ApontMov pesquisaCodigoMovi(int codigo, ListaSimples *S)
{
    ApontMov x;

    x = S->pri;

    while (x != NULL)
    {
        if (x->conteudo.codigo_conta == codigo)
        {
            return x;
        }
        
        x = x->prox;
    }

    return NULL;
}