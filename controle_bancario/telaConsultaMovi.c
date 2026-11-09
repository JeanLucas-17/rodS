/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 06/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO PARA CRIAÇÂO DA TELA DO CONSULTAR MOVIMENTAÇAO
*/

#include "funcoes.h"

void telaConsultaMovi()
{
    gotoxy(1,4);
    printf("Codigo:");

    gotoxy(1,5);
    printf("------------------------------------------------------------------------------");

    gotoxy(1, 6);
    printf("Dt.Movim   Favorecido                    TpMovim       Vl.Movim    Saldo");
    
    gotoxy(1, 7);
    printf("---------- ----------------------------- ------------- ----------- -----------");
}