/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 29/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA COM OPCOES DE MOVIMENTAÇÃO
*/

#include "funcoes.h"

void telaMovi()
{
    gotoxy(24, 9);
    printf("1 - Movimentacao do Debito e Credito");
    gotoxy(24, 11);
    printf("2 - Trasferencia entre Contas Bancarias");
    gotoxy(24, 13);
    printf("3 - Consultar Movimentacoes Bancarias");
    gotoxy(24, 15);
    printf("4 - Retornar ao Menu Anterior");
}
