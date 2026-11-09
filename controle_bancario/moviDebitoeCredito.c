/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CRIA A TELA COM OPCOES DE MOVIMENTAÇÃO
*/

#include "funcoes.h"

void moviDebitoeCredito(ListaSimples *S, ListaDupla *D)
{
    int y;
    ApontConta result;
    regConta conta;
    regMovimentacao movi;
    ApontMov p;

    int resp;

    int dia;
    int mes;
    int ano;

    do
    {
        system("cls");
        tela();
        telaDebitoeCredito();
        
        gotoxy(18, 2);
        printf("MENU MOVIMENTACAO DEBITO E CREDITO");

        if (S->pri == NULL)
        {
            gotoxy(37, 5);
            printf("0");   
        }
        else
        {
            gotoxy(37, 5);
            printf("%d", S->ult->conteudo.sequencial);
        }

        limpaMensagem();
        gotoxy(1,22);
        printf("Digite 0 para sair.: ");
        gotoxy(37,6);
        scanf("%d", &movi.codigo_conta);
        
        if(movi.codigo_conta > 0)
        {
            limpaMensagem();
            result = pesquisaCodigoConta(D, movi.codigo_conta);
            if(result != NULL)
            {
                conta = result->conteudo;

                gotoxy(37,7);
                printf(conta.banco);

                gotoxy(37,8);
                printf(conta.agencia);

                gotoxy(37,9);
                printf(conta.numero_conta);

                gotoxy(37,10);
                printf(conta.tipo_conta);

                gotoxy(37, 11);
                printf("%.2f", conta.vl_saldo);

                gotoxy(37, 12);
                printf("%.2f", conta.vl_limite);

                gotoxy(37, 13);
                printf("%.2f", conta.vl_saldo + conta.vl_limite);
               
                pegarDataAtual(&dia, &mes, &ano);
                
                sprintf(movi.dt_movimento, "%02d/%02d/%04d", dia, mes, ano);

                gotoxy(37, 15);
                printf("%s", movi.dt_movimento);

                do
                {
                    gotoxy(37,16);
                    printf("          ");
                    limpaMensagem();
                    gotoxy(1,22);
                    printf("Utilizar.. 1 - Debito 2 - Credito");
                    gotoxy(37, 16);
                    scanf("%d", &y);
                    if(y < 1 || y > 2)
                    {
                        limpaMensagem();
                        gotoxy(1,22);
                        printf("Opcao invalida.. Aperte ENTER");
                        getch();
                    }
                }while(y < 1 || y > 2);
                if(y == 1)
                {
                    strcpy(movi.tp_movimento, "Debito");
                    gotoxy(39,16);
                    printf("- Debito");
                }
                else
                {
                    strcpy(movi.tp_movimento, "Credito");
                    gotoxy(39,16);
                    printf("- Credito");
                }

                do
                {
                    limpaMensagem();
                    gotoxy(37, 17);
                    fflush(stdin);
                    
                    if ( fgets(movi.ds_favorecido, 50, stdin) != NULL)
                    {
                        movi.ds_favorecido[strcspn(movi.ds_favorecido, "\n")] = '\0';
                    }

                    if (movi.ds_favorecido[0] == '\0')
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Nome do favorecido obrigatorio! Aperte ENTER: ");
                        getch();
                    }
                } while (movi.ds_favorecido[0] == '\0');

                if(y == 1)
                {
                    do
                    {
                        gotoxy(37,18);
                        printf("              ");
                        gotoxy(37, 18);
                        scanf("%lf", &movi.vl_movimento);
                        if(movi.vl_movimento > conta.vl_saldo + conta.vl_limite)
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Saldo e Limite Insuficiente...");
                        }
                    }
                    while(movi.vl_movimento > conta.vl_saldo + conta.vl_limite);
                    conta.vl_saldo = conta.vl_saldo - movi.vl_movimento;
                }
                else
                {
                    gotoxy(37, 18);
                    scanf("%lf", &movi.vl_movimento);
                    conta.vl_saldo = movi.vl_movimento + conta.vl_saldo;
                }

                gotoxy(37, 19);
                printf("%.2f",conta.vl_saldo);
                
                limpaMensagem();
                gotoxy(1,22);
                printf("Deseja Salvar a movimentacao.. 1 - Sim - 2 - Nao....:");
                scanf("%d", &resp);

                if(resp == 1)
                {
                    p = (ApontMov)malloc(sizeof(TipoItemMov));
                    result->conteudo.vl_saldo = conta.vl_saldo;
                    movi.vl_saldo = result->conteudo.vl_saldo;
                    p->conteudo = movi;
                    p->prox = NULL;
                    
                    if(S->pri == NULL)
                    {
                        p->conteudo.sequencial = 1;
                        S->pri = p;
                        S->ult = p;
                    }
                    else 
                    {
                        p->conteudo.sequencial = S->ult->conteudo.sequencial + 1;
                        S->ult->prox = p;
                        S->ult = p;
                    }
                }
            }
            else
            {
                limpaMensagem();
                gotoxy(1,22);
                printf("Codigo nao cadastrado! Aperte ENTER");
                getch();
            }
        }
        else if(movi.codigo_conta < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido! Aperte ENTER: ");
            getch();
        }
        
    }while (movi.codigo_conta != 0);
}
