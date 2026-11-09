/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA COM OPCOES DE CONTA
*/

#include "funcoes.h"

void telaConta()
{
    gotoxy(22, 8);
    printf("1 - Cadastrar Contas Bancarias no Final");
    gotoxy(22, 9);
    printf("2 - Cadastrar Contas Bancarias no Inicio");
    gotoxy(22, 10);
    printf("3 - Cadastrar Contas Bancarias na Posicao");
    gotoxy(22, 11);
    printf("4 - Remover Contas Bancarias no Final");
    gotoxy(22, 12);
    printf("5 - Remover Contas Bancarias no Inicio");
    gotoxy(22, 13);
    printf("6 - Remover Contas Bancarias na Posicao");
    gotoxy(22, 14);
    printf("7 - Alteracao de Contas Bancarias");
    gotoxy(22, 15);
    printf("8 - Consultar Contas Bancarias");
    gotoxy(22, 16);
    printf("9 - Retornar ao Menu Anterior");
}
