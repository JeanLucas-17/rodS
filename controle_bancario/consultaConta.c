/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE CONSULTA AS CONTAS CADASTRADAS
*/

#include "funcoes.h"

void consultaConta(ListaDupla *D, int opcao)
{
    regConta conta;

    ApontConta result;
    ApontConta i;

    double saldoTot;
    double limiteTot;

    int codigo;
    int resp;

    int y;

    i = D->pri;

    if (i == NULL)
    {
        system("cls");

        tela();
        telaCadastrar();
        
        limpaMensagem();
        gotoxy(1, 22);
        printf("Nenhuma conta Cadastrada! Aperte ENTER: ");
        getch();
    }
    else
    {
        if (opcao == 1)
        {
            do
            {
                if (i->conteudo.status == 1)
                {
                    system("cls");

                    tela();
                    telaCadastrar();

                    gotoxy(22, 2);
                    printf("CONSULTA GERAL DE CONTAS");

                    conta = i->conteudo;

                    mostraConta(conta, opcao, 0);

                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Deseja continuar? (1 - SIM / 2 - NAO): ");
                    scanf("%d", &resp);
                    
                    while (resp != 1 && resp != 2)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Opcao Invalida! Deseja continuar? (1 - SIM / 2 - NAO): ");
                        scanf("%d", &resp);
                    }
                }

                i = i->prox;

            } while (i != NULL && resp == 1);

            if (resp == 1)
            {
                limpaMensagem();
                gotoxy(1, 22);
                printf("Fim das contas! Aperte ENTER: ");
                getch();
            }
        }
        else if (opcao == 2)
        {
            do
            {
                system("cls");

                tela();
                telaCadastrar();
        
                gotoxy(20, 2);
                printf("CONSULTA POR CODIGO DE CONTAS");

                limpaMensagem();
                gotoxy(1, 22);
                printf("Codigo da conta / OBS (0 para sair): ");

                gotoxy(41, 4);
                scanf("%d", &codigo);

                if (codigo > 0)
                {
                    result = pesquisaCodigoConta(D, codigo);

                    if (result != NULL)
                    {
                        if (result->conteudo.status == 1)
                        {
                            conta = result->conteudo;
                        
                            mostraConta(conta, opcao, 0);

                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Aperte ENTER: ");
                            getch();
                        }
                        else
                        {
                            limpaMensagem();
                            gotoxy(1, 22);
                            printf("Conta desativada! Aperte ENTER: ");
                            getch();
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
                else if (codigo < 0)
                {
                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Codigo Invalido! Aperte ENTER: ");
                    getch();
                }
            } while(codigo != 0);
        }
        else
        {
            saldoTot = 0;
            limiteTot = 0;

            system("cls");
            tela();
            cabecalhoContas();

            if (opcao == 3)
            {
                gotoxy(20, 2);
                printf("CONSULTA POR ORDEM DE CODIGO");

                ordemCodigo(D);
            }
            else
            {
                gotoxy(20, 2);
                printf("CONSULTA POR ORDEM ALFABETICA");

                ordemAlfabetica(D);
            }

            i = D->pri;

            y = 6;

            do
            {
                conta = i->conteudo;

                if (conta.status == 1)
                {
                    saldoTot += conta.vl_saldo;
                    limiteTot += conta.vl_limite;

                    if (y == 21)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Aperte ENTER para proxima tela: ");
                        getch();

                        system("cls");
                        tela();

                        y = 6;

                        mostraConta(conta, opcao, y);
                        y++;

                        cabecalhoContas();

                        if (opcao == 3)
                        {
                            gotoxy(20, 2);
                            printf("CONSULTA POR ORDEM DE CODIGO");
                        }
                        else
                        {
                            gotoxy(20, 2);
                            printf("CONSULTA POR ORDEM ALFABETICA");
                        }
                    }
                    else
                    {
                        mostraConta(conta, opcao, y);
                        y++;
                    }
                }

                i = i->prox;

            } while (i != NULL);

            if (y > 19)
            {
                limpaMensagem();
                gotoxy(1, 22);
                printf("Aperte ENTER para proxima tela: ");
                getch();

                system("cls");
                tela();

                y = 6;

                cabecalhoContas();
                rodapeConta(saldoTot, limiteTot, y);
            }
            else
            {
                cabecalhoContas();
                rodapeConta(saldoTot, limiteTot, y);
            }

            if (opcao == 3)
            {
                gotoxy(20, 2);
                printf("CONSULTA POR ORDEM DE CODIGO");
            }
            else
            {
                gotoxy(20, 2);
                printf("CONSULTA POR ORDEM ALFABETICA");
            }

            limpaMensagem();
            gotoxy(1, 22);
            printf("Aperte ENTER: ");
            getch();
        }
    }
}
