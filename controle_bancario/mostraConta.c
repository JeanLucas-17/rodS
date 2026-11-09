/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: MOTRA AS CONTAS NO MODO DE CONSULTA
*/

#include "funcoes.h"

void mostraConta(regConta conta, int opcao, int y)
{
    if (opcao == 1 || opcao == 2)
    {
        if (conta.status == 1)
        {
            gotoxy(41, 4);
            printf("%d", conta.codigo_conta);
                        
            gotoxy(41, 6);
            printf(conta.banco);
                        
            gotoxy(41, 8);
            printf(conta.agencia);
                        
            gotoxy(41, 10);
            printf(conta.numero_conta);
                        
            gotoxy(41, 12);
            printf(conta.tipo_conta);
                        
            gotoxy(41, 14);
            printf("%.2f", conta.vl_saldo);
                        
            gotoxy(41, 16);
            printf("%.2f", conta.vl_limite);
                        
            gotoxy(41, 18);
            printf("%d", conta.status);
        }
    }
    else
    {
        gotoxy(1, y);
        printf("%d", conta.codigo_conta);

        gotoxy(4, y);
        printf(conta.banco);

        gotoxy(24, y);
        printf(conta.agencia);

        gotoxy(30, y);
        printf(conta.numero_conta);

        gotoxy(39, y);
        printf(conta.tipo_conta);

        gotoxy(54, y);
        printf("R$ %.2f", conta.vl_saldo);

        gotoxy(66, y);
        printf("R$ %.2f", conta.vl_limite);

        gotoxy(78, y);
        printf("%d", conta.status);
    }   
}
