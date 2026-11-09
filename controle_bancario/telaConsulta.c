/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 26/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: TELA DE CONSULTA DAS CONTAS
*/

#include "funcoes.h"

void telaConsulta()
{
    gotoxy(20, 7);
    printf("1 - Consulta Geral Contas Bancarias");
    gotoxy(20, 9);
    printf("2 - Consulta Por Codigo Contas Bancarias");
    gotoxy(20, 11);
    printf("3 - Consulta Ordem Codigo Contas Bancarias");
    gotoxy(20, 13);
    printf("4 - Consulta Ordem Alfabetica Contas Bancarias");
    gotoxy(20, 15);
    printf("5 - Retornar ao Menu Anterior");
}
