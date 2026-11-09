/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 06/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO PARA CONSULTAR AS MOVIMENTAÇOES DAS CONTAS
*/

#include "funcoes.h"

void consultaMov(ListaDupla *D, ListaSimples *S)
{
    ApontConta result;
    regMovimentacao movi;
    ApontMov i;
    regConta conta;
    int y;
    
    do
    {
        system("cls");
        tela();
        telaConsultaMovi();
        limpaMensagem();
        
        gotoxy(26, 2);
        printf("CONSULTA MOVIMENTACAO");

        gotoxy(1,22);
        printf("Digite 0 para sair....");

        gotoxy(9, 4);
        scanf("%d", &conta.codigo_conta);

        if(conta.codigo_conta > 0)
        {
            limpaMensagem();
            result = pesquisaCodigoConta(D, conta.codigo_conta);
            if(result != NULL)
            {
                conta = result->conteudo;
                
                gotoxy(11, 4);
                printf("-");

                gotoxy(13, 4);
                printf(conta.banco);

                gotoxy(30, 4);
                printf("Agencia: %s", conta.agencia);

                gotoxy(45,4);
                printf("Cta: %s", conta.numero_conta);

                gotoxy(60,4);
                printf("Tp: %s", conta.tipo_conta);

                i = S->pri;
                y = 8;

                while (i != NULL)
                {
                    if(y == 21)
                    {
                        gotoxy(1,22);
                        printf("Aperte ENTER para avancar....");
                        getch();
                        system("cls");
                        tela();
                        telaConsultaMovi();
                                        
                        gotoxy(26, 2);
                        printf("CONSULTA MOVIMENTACAO");
                        
                        y = 8;

                        gotoxy(11, 4);
                        printf("-");

                        gotoxy(13, 4);
                        printf(conta.banco);

                        gotoxy(30, 4);
                        printf("Agencia: %s", conta.agencia);

                        gotoxy(45,4);
                        printf("Cta: %s", conta.numero_conta);

                        gotoxy(60,4);
                        printf("Tp: %s", conta.tipo_conta);
                    }
                    movi = i->conteudo;
                    if(conta.codigo_conta == movi.codigo_conta)
                    {

                        gotoxy(1, y);
                        printf(movi.dt_movimento);

                        gotoxy(12, y);
                        printf(movi.ds_favorecido);

                        gotoxy(42, y);
                        printf(movi.tp_movimento);

                        gotoxy(56, y);
                        printf("R$ %.2f", movi.vl_movimento);

                        gotoxy(68, y);
                        printf("R$ %.2f", movi.vl_saldo);
                        y++;
                    }
                    i = i->prox;
                }
                gotoxy(1,22);
                printf("Aperte ENTER......");
                getch();
            }
            else
            {
                limpaMensagem();
                gotoxy(1,22);
                printf("Codigo nao cadastrado - Aperte ENTER");
                getch();
            }
        }else if(conta.codigo_conta < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido - Aperte ENTER: ");
            getch();
        }
    } while (conta.codigo_conta != 0);
    
}