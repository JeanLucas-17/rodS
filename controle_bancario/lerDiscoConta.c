/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: LE OS CADASTROS DAS CONTAS NO DISCO E INSERI NA LISTA
*/

#include "funcoes.h"

void lerDiscoConta(ListaDupla *D)
{
    regConta conta;

    ApontConta p;

    FILE *arq;

    char *nomeArquvio;
    char *modoGravacao;

    modoGravacao = "rb";
    nomeArquvio = "contas.dat";

    arq = fopen(nomeArquvio, modoGravacao);

    if (arq == NULL)
    {
        return;
    }

    system("cls");
    tela();

    gotoxy(28, 2);
    printf("LER CONTAS DO DISCO");

    while (fread(&conta, sizeof(regConta), 1, arq) == 1)
    {
        p = (ApontConta) malloc(sizeof(TipoItemConta));

        if (p != NULL)
        {

            p->conteudo = conta;
            p->prox = NULL;

            if (D->pri == NULL)
            {
                D->pri = p;
                D->ult = p;
                p->ant = NULL;
            }
            else
            {
                D->ult->prox = p;
                p->ant = D->ult;
                D->ult = p;
            }
        }
        else
        {
            limpaMensagem();
            gotoxy(1, 22);
            printf("Alocacao interrompida! Aperte ENTER: ");
            getch();
        }
    }

    fclose(arq);

    limpaMensagem();
    gotoxy(1, 22);
    printf("Dados das contas lidos do arquivo! Aperte ENTER: ");
    getch();
}
