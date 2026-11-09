/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA PARA O PREEMCHIMENTO DOS DADOS
*/

#include "funcoes.h"

void telaCadastrar()
{
    gotoxy(5, 4);
    printf("    Codigo da Conta...............:");
    gotoxy(5, 6);
    printf("1 - Nome do Banco.................:");
    gotoxy(5, 8);
    printf("2 - Numero da sua agencia.........:");
    gotoxy(5, 10);
    printf("3 - Numero da Conta...............:");
    gotoxy(5, 12);
    printf("4 - Tipo da Conta.................:");
    gotoxy(5, 14);
    printf("5 - Valor do Saldo da Conta.......:");
    gotoxy(5, 16);
    printf("6 - Valor do Limite da Conta......:");
    gotoxy(5, 18);
    printf("7 - Status da Conta...............:");
}
