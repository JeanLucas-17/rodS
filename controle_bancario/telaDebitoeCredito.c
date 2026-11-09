/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA COM AS OPCOES DE DEPITO E CREDITO
*/
#include "funcoes.h"

void telaDebitoeCredito()
{
    gotoxy(9,5);
    printf("Sequencia de Movimentacao.: ");
    gotoxy(9,6);
    printf("Codigo da Conta...........: ");
    gotoxy(9,7);
    printf("Banco.....................: ");
    gotoxy(9,8);
    printf("Agencia...................: ");
    gotoxy(9,9);
    printf("Numero da conta...........: ");
    gotoxy(9,10);
    printf("Tipo da Conta.............: ");
    gotoxy(9,11);
    printf("Saldo.....................: ");
    gotoxy(9,12);
    printf("Limite....................: ");
    gotoxy(9,13);
    printf("Total Saldo + Limite......: ");
    gotoxy(1,14);
    printf("------------------------------------------------------------------------------");
    gotoxy(9,15);
    printf("1-Data Movimentacao.......: ");
    gotoxy(9,16);
    printf("2-Tipo Movimentacao.......: ");
    gotoxy(9,17);
    printf("3-Favorecido..............: ");
    gotoxy(9,18);
    printf("4-Valor Movimentacao......: ");
    gotoxy(9,19);
    printf("5-Novo Saldo..............: ");
}