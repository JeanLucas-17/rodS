/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE MOSTRA AS OPCOES DE CONTA
*/

#include "funcoes.h"

void menuConta(ListaDupla *D, ListaSimples *S)
{
    int opcao;

    do
    {
        system("cls");
        tela();
        telaConta();

        gotoxy(30, 2);
        printf("MENU CONTA");

        limpaMensagem();

        gotoxy(1, 22);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                cadastrarConta(D, opcao);

                break;

            case 2:
                cadastrarConta(D, opcao);

                break;

            case 3:
                cadastrarConta(D, opcao);

                break;
            case 4:
                removerConta(D, opcao, S);

                break;

            case 5:
                removerConta(D, opcao, S);

                break;

            case 6:
                removerConta(D, opcao, S);

                break;
                
            case 7:
                alterarConta(D);

                break;

            case 8:
                menuConsultaConta(D);

                break;

            case 9:

                break;
                
            default:
                erro();

                break;
        }
    } while (opcao != 9);
}
