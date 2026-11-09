/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: CADASTRA CONTAS NO INICIO, FIM E NA POSICAO
*/

#include "funcoes.h"

void cadastrarConta(ListaDupla *D, int opcao)
{
    ApontConta result;
    ApontConta posicao;
    ApontConta p;

    regConta conta;

    int tipo;
    int resp;
    int pos;
    int x;

    do
    {
        system("cls");
        tela();
        telaCadastrar();

        if (opcao == 1)
        {    
            gotoxy(22, 2);
            printf("CADASTRAR CONTAS NO FINAL");
        }
        else if (opcao == 2)
        {
            gotoxy(22, 2);
            printf("CADASTRAR CONTAS NO INICIO");
        }
        else
        {
            gotoxy(22, 2);
            printf("CADASTRAR CONTAS NA POSICAO");
        }

        limpaMensagem();

        gotoxy(1, 22);
        printf("Codigo da Conta / OBS (0 para sair): ");

        gotoxy(41, 4);
        scanf("%d", &conta.codigo_conta);

        if (conta.codigo_conta > 0)
        {
            limpaMensagem();

            result = pesquisaCodigoConta(D, conta.codigo_conta);

            if (result == NULL)
            {
                do
                {
                    limpaMensagem();
                    gotoxy(41, 6);
                    fflush(stdin);
                    
                    if( fgets(conta.banco, 50, stdin) != NULL)
                    {
                        conta.banco[strcspn(conta.banco, "\n")] = '\0';
                    }

                    if (conta.banco[0] == '\0')
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Nome do banco obrigatorio! Aperte ENTER: ");
                        getch();
                    }
                } while(conta.banco[0] == '\0');  

                do
                {
                    limpaMensagem();
                    gotoxy(41, 8);
                    fflush(stdin);
                    
                    if ( fgets(conta.agencia, 10, stdin) != NULL)
                    {
                        conta.agencia[strcspn(conta.agencia, "\n")] = '\0';
                    }

                    if (conta.agencia[0] == '\0')
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Numero da agencia obrigatorio! Aperte ENTER: ");
                        getch();
                    }

                } while (conta.agencia[0] == '\0');
                
                do
                {
                    limpaMensagem();
                    gotoxy(41, 10);
                    fflush(stdin);
                    
                    if ( fgets(conta.numero_conta, 20, stdin) != NULL)
                    {
                        conta.numero_conta[strcspn(conta.numero_conta, "\n")] = '\0';
                    }

                    if (conta.numero_conta[0] == '\0')
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Numero da conta obrigatorio! Aperte ENTER: ");
                        getch();
                    }
                } while (conta.numero_conta[0] == '\0');
                
                do
                {
                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Utilizar: 1 - Corrente / 2 - Poupanca / 3 - Cartao Credito");

                    gotoxy(41, 12);
                    scanf("%d", &tipo);

                    if (tipo < 1 || tipo > 3)
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Opcao Invalida! Aperte ENTER: ");
                        getch();

                        gotoxy(41, 12);
                        printf("                                     ");
                    }
                } while (tipo < 1 || tipo > 3);

                if (tipo == 1)
                {
                    strcpy(conta.tipo_conta, "Corrente");

                    gotoxy(42, 12);
                    printf(" - Corrente");
                }
                else if (tipo == 2)
                {
                    strcpy(conta.tipo_conta, "Poupanca");

                    gotoxy(42, 12);
                    printf(" - Poupanca");
                }
                else
                {
                    strcpy(conta.tipo_conta, "Cartao Credito");

                    gotoxy(42, 12);
                    printf(" - Cartao Credito");
                }

                gotoxy(41, 14);
                scanf("%lf", &conta.vl_saldo);

                gotoxy(41, 16);
                scanf("%lf", &conta.vl_limite);

                gotoxy(41, 18);
                printf("1");

                conta.status = 1;

                limpaMensagem();
                gotoxy(1, 22);
                printf("Deseja salvar? (1 - SIM / 2 - NAO): ");
                scanf("%d", &resp);

                if (resp == 1)
                {
                    p = (ApontConta)malloc(sizeof(TipoItemConta));

                    if (p != NULL)
                    {
                        if (D->pri == NULL)
                        {
                            D->pri = p;
                            D->ult = p;
                            D->pri->ant = NULL;
                            D->pri->prox = NULL;
                        }
                        else
                        {
                            if (opcao == 1)
                            {
                                D->ult->prox = p;
                                p->ant = D->ult;
                                p->prox = NULL;
                                D->ult = p;
                            }
                            else if (opcao == 2)
                            {
                                D->pri->ant = p;
                                p->prox = D->pri;
                                p->ant = NULL;
                                D->pri = p;
                            }
                            else
                            {
                                do
                                {
                                    limpaMensagem();
                                    gotoxy(1, 22);
                                    printf("Digite a posicao: ");
                                    scanf("%d", &pos);

                                    x = quantidadeContas(D);

                                    if (pos < 1 || pos > x + 1)
                                    {
                                        limpaMensagem();
                                        gotoxy(1, 22);
                                        printf("Posicao invalida! Aperte ENTER: ");
                                        getch();
                                    }
                                } while (pos < 1 || pos > x + 1);

                                if (pos == 1)
                                {
                                    D->pri->ant = p;
                                    p->prox = D->pri;
                                    p->ant = NULL;
                                    D->pri = p;
                                }
                                else if (pos > x)
                                {
                                    D->ult->prox = p;
                                    p->ant = D->ult;
                                    p->prox = NULL;
                                    D->ult = p;
                                }
                                else
                                {
                                    posicao = posConta(D, pos);

                                    p->ant = posicao->ant;
                                    p->ant->prox = p;
                                    p->prox = posicao;
                                    posicao->ant = p;
                                }
                            }
                        }
                        p->conteudo = conta;
                    }
                    else
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Alocacao interrompida! Aperte ENTER: ");
                        getch();
                    }
                }
            }
            else
            {
                limpaMensagem();
                gotoxy(1, 22);
                printf("Codigo ja cadastrado! Aperte ENTER: ");
                getch();
            }
        }
        else if (conta.codigo_conta < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido! Aperte ENTER: ");
            getch();
        }
    } while(conta.codigo_conta != 0);
}
