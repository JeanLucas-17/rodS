/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: TELA DAS TRANFERENCIAS BANCARIAS
*/

#include "funcoes.h"

void telaTransferencia()
{
    int i;

    gotoxy(1, 6);
    printf("-------C O N T A  O R I G E M---------+-------C O N T A  D E S T I N O--------");
    
    for (i = 7; i < 16; i++)
    {
        gotoxy(39, i);
        printf("|");
    }

    for (i = 1; i < 79; i++)
    {
        if (i == 39)
        {
            gotoxy(i, 16);
            printf("+");
            i++;
        }
        gotoxy(i, 16);
        printf("-");
    }

    gotoxy(2, 7);
    printf("Conta de Origem: ");
    gotoxy(2, 8);
    printf("Banco..........: ");
    gotoxy(2, 9);
    printf("Agencia........: ");
    gotoxy(2, 10);
    printf("Numero da Conta: ");
    gotoxy(2, 11);
    printf("Tipo da Conta..: ");
    gotoxy(2, 12);
    printf("Saldo..........: ");
    gotoxy(2, 13);
    printf("Limite.........: ");
    gotoxy(2, 14);
    printf("Saldo + Limite.: ");
    gotoxy(2, 15);
    printf("Novo Saldo.....: ");

    gotoxy(41, 7);
    printf("Conta de Destino: ");
    gotoxy(41, 8);
    printf("Banco...........: ");
    gotoxy(41, 9);
    printf("Agencia.........: ");
    gotoxy(41, 10);
    printf("Numero da Conta.: ");
    gotoxy(41, 11);
    printf("Tipo da Conta...: ");
    gotoxy(41, 12);
    printf("Saldo...........: ");
    gotoxy(41, 13);
    printf("Limite..........: ");
    gotoxy(41, 14);
    printf("Saldo + Limite..: ");
    gotoxy(41, 15);
    printf("Novo Saldo......: ");

    gotoxy(13, 17);
    printf("Valor a Ser transferido.: ");
    gotoxy(13, 18);
    printf("Data da Transferencia...: ");
}
