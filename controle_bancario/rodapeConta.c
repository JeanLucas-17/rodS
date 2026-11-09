/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 29/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: MOSTRA O SALDO TOTAL E LIMITE TOTAL DAS CONTAS
*/

#include "funcoes.h"

void rodapeConta(double saldoTot, double limiteTot, int y)
{
    gotoxy(41, y);
    printf("------------ ----------- -----------");
    gotoxy(41, y + 1);
    printf("Saldo Total: R$ %.2f", saldoTot);
    gotoxy(66, y + 1);
    printf("R$ %.2f", limiteTot);
}
