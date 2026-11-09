/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 29/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE MOSTRA AS OPCOES DA MOVIMENTAÇÃO
*/
#include "funcoes.h"

void menuMovi(ListaSimples *S, ListaDupla *D)
{
    int opcao;

    do
    {
        system("cls");
        tela();        
        telaMovi();

        gotoxy(26, 2);
        printf("MENU MOVIMENTACAO");

        limpaMensagem();

        gotoxy(1,22);
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:     
                moviDebitoeCredito(S,D);

                break;
        
            case 2:
                transferenciaConta(D, S);

                break;

            case 3:
                consultaMov(D,S);
                break;

            case 4:
            
                break;
            default:
                erro();
                
                break;
        }
    }while (opcao != 4);
}
