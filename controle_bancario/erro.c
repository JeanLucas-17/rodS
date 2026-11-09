/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 28/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: MOSTRA ERRO CASO SEJA DIGITADO UMA OPCAO INVALIDA
*/

#include "funcoes.h"

void erro()
{
    limpaMensagem();
    gotoxy(1, 22);
    printf("Opcao Invalida! Aperte ENTER: ");
    getch();
}
