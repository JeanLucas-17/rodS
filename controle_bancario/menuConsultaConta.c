/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 26/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: MENU DE CONSULTA DAS CONTAS
*/

#include "funcoes.h"

void menuConsultaConta(ListaDupla *D)
{
    int opcao;

    do
    {
        system("cls");
        tela();
        telaConsulta();
        
        gotoxy(26, 2);
        printf("MENU CONSULTA CONTA");
        
        limpaMensagem();
        gotoxy(1, 22);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                consultaConta(D, opcao);

                break;
            case 2:
                consultaConta(D, opcao);
            
                break;
            case 3:
                consultaConta(D, opcao);

                break;
            case 4:
                consultaConta(D, opcao);
                
                break;
            case 5:

                break;
            default:
                erro();
                
                break;
        }
    } while (opcao != 5);
    
}
