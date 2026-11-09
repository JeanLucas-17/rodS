/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 31/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: TRANSFERENCIA ENTRE CONTAS BANCARIAS
*/

#include "funcoes.h"

void transferenciaConta(ListaDupla *D, ListaSimples *S)
{
    ApontConta resultDestino;
    ApontConta resultOrigem;

    regConta contaOrigem;
    regConta contaDestino;
        
    regMovimentacao movOrigem;
    regMovimentacao movDestino;
    ApontMov o;
    ApontMov d;

    double vl_movimento;
    char dt_movimento[11];

    int resp;

    int dia;
    int mes;
    int ano;

    do
    {
        system("cls");
        tela();
        telaTransferencia();
            
        gotoxy(24, 2);
        printf("TRANSFERENCIA ENTRE CONTAS");

        limpaMensagem();

        gotoxy(1, 22);
        printf("Digite 0 para sair: ");

        gotoxy(19, 7);
        scanf("%d", &movOrigem.codigo_conta);

        if (movOrigem.codigo_conta > 0)
        {
            resultOrigem = pesquisaCodigoConta(D, movOrigem.codigo_conta);

            if (resultOrigem != NULL)
            {
                contaOrigem = resultOrigem->conteudo;

                gotoxy(19, 8);
                printf(contaOrigem.banco);

                gotoxy(19, 9);
                printf(contaOrigem.agencia);

                gotoxy(19, 10);
                printf(contaOrigem.numero_conta);

                gotoxy(19, 11);
                printf(contaOrigem.tipo_conta);

                gotoxy(19, 12);
                printf("R$ %.2f", contaOrigem.vl_saldo);

                gotoxy(19, 13);
                printf("R$ %.2f", contaOrigem.vl_limite);

                gotoxy(19, 14);
                printf("R$ %.2f", contaOrigem.vl_saldo + contaOrigem.vl_limite);

                do
                {
                    gotoxy(59, 7);
                    printf("                    ");

                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Digite 0 para sair");

                    gotoxy(59, 7);
                    scanf("%d", &movDestino.codigo_conta);

                   if (movDestino.codigo_conta > 0)
                   {
                        limpaMensagem();

                        resultDestino = pesquisaCodigoConta(D, movDestino.codigo_conta);

                        if (resultDestino == NULL)
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Codigo nao Cadastrado! Aperte ENTER: ");
                            getch();
                        }
                        else if (movOrigem.codigo_conta == movDestino.codigo_conta)
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Codigo sao iguais! Aperter ENTER: ");
                            getch();
                        }
                   }
                   else if (movDestino.codigo_conta < 0)
                   {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Codigo Invalido! Aperte ENTER: ");
                        getch();
                   }

                } while ((resultDestino == NULL || movOrigem.codigo_conta == movDestino.codigo_conta) && movDestino.codigo_conta != 0);

                if (movDestino.codigo_conta != 0)
                {
                    contaDestino = resultDestino->conteudo;

                    gotoxy(59, 8);
                    printf(contaDestino.banco);

                    gotoxy(59, 9);
                    printf(contaDestino.agencia);

                    gotoxy(59, 10);
                    printf(contaDestino.numero_conta);

                    gotoxy(59, 11);
                    printf(contaDestino.tipo_conta);

                    gotoxy(59, 12);
                    printf("R$ %.2f", contaDestino.vl_saldo);

                    gotoxy(59, 13);
                    printf("R$ %.2f", contaDestino.vl_limite);

                    gotoxy(59, 14);
                    printf("R$ %.2f", contaDestino.vl_saldo + contaDestino.vl_limite);

                    do
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Digite 0 para sair");

                        gotoxy(39, 17);
                        printf("                                     ");

                        gotoxy(39, 17);
                        scanf("%lf", &vl_movimento);

                        if (vl_movimento > (contaOrigem.vl_saldo + contaOrigem.vl_limite) || vl_movimento < 0)
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Valor Invalido ou Saldo Insuficiente! Aperte ENTER: ");
                            getch();
                        }

                        limpaMensagem();

                    } while (vl_movimento > (contaOrigem.vl_saldo + contaOrigem.vl_limite) || vl_movimento < 0);

                    if (vl_movimento != 0)
                    {
                        resultOrigem->conteudo.vl_saldo -= vl_movimento;
                        resultDestino->conteudo.vl_saldo += vl_movimento;

                        gotoxy(19, 15);
                        printf("R$ %.2f", resultOrigem->conteudo.vl_saldo);

                        gotoxy(59, 15);
                        printf("R$ %.2f", resultDestino->conteudo.vl_saldo);

                        pegarDataAtual(&dia, &mes, &ano);

                        sprintf(dt_movimento, "%02d/%02d/%04d", dia, mes, ano);
                        
                        gotoxy(39, 18);
                        printf("%s", dt_movimento);

                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Deseja Salvar? (1 - SIM / 2 - NAO): ");
                        scanf("%d", &resp);

                        if (resp == 1)
                        {
                            o = (ApontMov) malloc(sizeof(TipoItemMov));
                            d = (ApontMov) malloc(sizeof(TipoItemMov));

                            if (S->pri == NULL)
                            {
                                o->conteudo.sequencial = 1;
                                d->conteudo.sequencial = 2;
                            }
                            else
                            {
                                o->conteudo.sequencial = S->ult->conteudo.sequencial + 1;
                                d->conteudo.sequencial = o->conteudo.sequencial + 1;
                            }

                            o->conteudo.codigo_conta = movOrigem.codigo_conta;
                            strcpy(o->conteudo.ds_favorecido, "Transferencia Entre Contas");
                            strcpy(o->conteudo.dt_movimento, dt_movimento);
                            strcpy(o->conteudo.tp_movimento, "Debito");
                            o->conteudo.vl_movimento = vl_movimento;
                            o->conteudo.vl_saldo = resultOrigem->conteudo.vl_saldo;
            
                            d->conteudo.codigo_conta = movDestino.codigo_conta;
                            strcpy(d->conteudo.ds_favorecido, "Transferencia Entre Contas");
                            strcpy(d->conteudo.dt_movimento, dt_movimento);
                            strcpy(d->conteudo.tp_movimento, "Credito");
                            d->conteudo.vl_movimento = vl_movimento;
                            d->conteudo.vl_saldo = resultDestino->conteudo.vl_saldo;

                            if (S->pri == NULL)
                            {
                                S->pri = o;
                                o->prox = d;
                                S->ult = d;
                                d->prox = NULL;
                            }
                            else
                            {
                                S->ult->prox = o;
                                o->prox = d;
                                S->ult = d;
                                d->prox = NULL;
                            }
                        }
                    }
                }
            }
            else
            {
                limpaMensagem();
                gotoxy(1, 22);
                printf("Codigo nao cadastrado! Aperte ENTER: ");
                getch();
            }
        }
        else if (movOrigem.codigo_conta < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido! Aperte ENTER: ");
            getch();
        }
    } while ((movOrigem.codigo_conta != 0 && movDestino.codigo_conta != 0) && vl_movimento != 0);
}
