/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 28/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: ALTERAR OS CADASTROS DAS CONTAS
*/

#include "funcoes.h"

void alterarConta(ListaDupla *D)
{   
    ApontConta result;
    regConta conta;

    int codigo;
    int resp;
    int tipo;

    do
    {
        system("cls");
        tela();
        telaCadastrar();
        
        gotoxy(30, 2);
        printf("ALTERAR CONTAS");

        limpaMensagem();

        gotoxy(1, 22);
        printf("Codigo da Conta / OBS (0 para sair): ");

        gotoxy(41, 4);
        scanf("%d", &codigo);

        if (codigo > 0)
        {
            limpaMensagem();

            result = pesquisaCodigoConta(D, codigo);

            if (result != NULL)
            {
                conta = result->conteudo;

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
                gotoxy(1, 22);
                printf("Deseja alterar algum dado? (1 - SIM / 2 - NAO): ");
                scanf("%d", &resp);

                if (resp == 1)
                {
                    do
                    {
                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Qual Dado?: ");
                        scanf("%d", &resp);

                        switch (resp)
                        {
                            case 1:
                                gotoxy(41, 6);
                                printf("                                     ");

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

                                break;

                            case 2:
                                gotoxy(41, 8);
                                printf("                                     ");

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

                                break;

                            case 3:
                                gotoxy(41, 10);
                                printf("                                     ");

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

                                break;

                            case 4:
                                gotoxy(41, 12);
                                printf("                                     ");

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

                                break;

                            case 5:
                            case 6:
                            case 7:
                                gotoxy(1, 22);
                                printf("Campo nao pode ser alterado! Aperte ENTER: ");
                                getch();

                                break;

                            default:
                                erro();

                                break;
                        }

                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Deseja alterar mais algum dado? (1 - SIM / 2 - NAO): ");
                        scanf("%d", &resp);

                    } while (resp == 1);

                    limpaMensagem();
                    gotoxy(1, 22);
                    printf("Deseja salvar as alteracoes? (1 - SIM / 2 - NAO): ");
                    scanf("%d", &resp);

                    if (resp == 1)
                    {
                        result->conteudo = conta;

                        limpaMensagem();
                        gotoxy(1, 22);
                        printf("Altercaoes salvas! Aperte ENTER: ");
                        getch();
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
        else if (codigo < 0)
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Codigo Invalido! Aperte ENTER: ");
            getch();
        }
    } while(codigo != 0);
}
