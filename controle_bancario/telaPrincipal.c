/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA COM AS OPCOES DO MENU PRINCIPAL
*/

#include "funcoes.h"

void telaPrincipal()
{
    gotoxy(26, 9);
    printf("1 - Cadastro de Contas");
    gotoxy(26, 11);
    printf("2 - Movimentacao Financeira ");
    gotoxy(26, 13);
    printf("3 - Sair");
}
