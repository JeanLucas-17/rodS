/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA O MOLDE DA TELA
*/

#include "funcoes.h"

void tela()
{
    int i;

    printf("+");
    for (i = 0; i < 78; i++)
    {
        printf("-");
    }
    printf("+");

    printf("\n| UNICIVE         SISTEMA DE GERENCIAMENTO BANCARIO         ESTRUTURA DE DADOS |\n");
    printf("|                                                                              |\n");
    printf("+");
    for (i = 0; i < 78; i++)
    {
        printf("-");
    }
    printf("+");

    for (i = 0; i < 17; i++)
    {
        printf("\n|                                                                              |");
    }

    printf("\n+");
    for (i = 0; i < 78; i++)
    {
        printf("-");
    }
    printf("+");

    printf("\n|                                                                              |");

    printf("\n+");
    for (i = 0; i < 78; i++)
    {
        printf("-");
    }
    printf("+");
}