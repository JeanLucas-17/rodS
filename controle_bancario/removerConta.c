/*
    AUTOR......: FELIPE GABRIEL DA SILVA TRASSI
    DATA.......: 25/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: FUNCAO QUE REMOVE CONTAS DO FIM, INICIO E NA POSIÇAO
*/ 
#include "funcoes.h"

void removerConta(ListaDupla *D, int opcao, ListaSimples *S)
{
    int pos;
    int x;
    int resp;

    ApontConta result;
    regConta conta;
    ApontMov resultado;

    if(D->pri != NULL)
    {
        do
        {
            system("cls");
            tela();
            telaCadastrar();

            if(opcao == 4)
            {        
                gotoxy(22, 2);
                printf("REMOVER CONTAS NO FINAL");

                conta = D->ult->conteudo;
            }
            else if(opcao == 5)
            {
                gotoxy(22, 2);
                printf("REMOVER CONTAS NO INICIO");

                conta = D->pri->conteudo;
            }
            else
            {
                gotoxy(22, 2);
                printf("REMOVER CONTAS NA POSICAO");

                do
                {
                    limpaMensagem();
                    gotoxy(1,22);
                    printf("Digite a Posicao....: ");
                    scanf("%d", &pos);
                    x = quantidadeContas(D);
                    
                    if(pos > x || pos < 1)
                    {
                        limpaMensagem();
                        gotoxy(1,22);
                        printf("Posicao Invalida..... Aperte ENTER: ");
                        getch();
                    }
            
                } while (pos > x || pos < 1);

                result = posConta(D, pos);
                conta = result->conteudo;
            }
            
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

            limpaMensagem();
            gotoxy(1,22);
            printf("Deseja remover.... 1 - Sim | 2 - Nao: ");
            scanf("%d", &resp);

            if(resp == 1)
            {
                resultado = pesquisaCodigoMovi(conta.codigo_conta, S);
            
                if(resultado == NULL)
                {
                    if(D->pri == NULL)
                    {
                        limpaMensagem();
                        gotoxy(1,22);
                        printf("Sem contas cadastradas..... Pressione ENTER: ");
                        getch();
                    }
                    else
                    {
                        if(D->pri == D->ult)
                        {
                            free(D->pri);
                            D->pri == NULL;
                            D->pri == NULL;
                        }
                        else
                        {
                            if(opcao == 4)
                            {
                                D->ult = D->ult->ant;
                                free(D->ult->prox);
                                D->ult->prox = NULL;
                            }
                            else if (opcao ==5)
                            {
                                D->pri = D->pri->prox;
                                free(D->pri->ant);
                                D->pri->ant = NULL;
                            }
                            else
                            {
                                if(pos == 1)
                                {
                                    D->pri = D->pri->prox;
                                    free(D->pri->ant);
                                    D->pri->ant = NULL;
                                }
                                else if(pos == x)
                                {
                                    D->ult = D->ult->ant;
                                    free(D->ult->prox);
                                    D->ult->prox = NULL;
                                }
                                else
                                {
                                    result->prox->ant = result->ant;
                                    result->ant->prox = result->prox;
                                    free(result);
                                }
                                
                            }
                        }
                    }
                }
                else
                {
                    limpaMensagem();
                    gotoxy(1,22);
                    printf("Conta com movimentacao, nao pode ser removida - aperte ENTER");
                    getch();
                }
            }

            limpaMensagem();
            gotoxy(1,22);
            printf("Deseja remover outro cadastro..... 1 - Sim | 2 - Nao: ");
            scanf("%d", &resp);

        }while(resp == 1);
    }else
    {
        limpaMensagem();
        gotoxy(1,22);
        printf("Lista Vazia...... Aperte ENTER: ");
        getch();
    }
}
