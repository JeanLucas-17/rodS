/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 04/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: LE AS MOVIMENTACOES DAS CONTAS NO DISCO E INSERI NA LISTA
*/

#include "funcoes.h"

void lerDiscoMov(ListaSimples *S)
{
    regMovimentacao mov;

    ApontMov p;

    FILE *arq;

    char *nomeArquvio;
    char *modoGravacao;

    modoGravacao = "rb";
    nomeArquvio = "movimentacoes.dat";

    arq = fopen(nomeArquvio, modoGravacao);

    if (arq == NULL)
    {
        return;
    }

    system("cls");
    tela();

    gotoxy(28, 2);
    printf("LER MOVIMENTACAO DO DISCO");

    while (fread(&mov, sizeof(regMovimentacao), 1, arq) == 1)
    {
        p = (ApontMov) malloc(sizeof(TipoItemMov));

        if (p != NULL)
        {
            p->conteudo = mov;
            p->prox = NULL;

            if (S->pri == NULL)
            {
                S->pri = p;
                S->ult = p;
            }
            else
            {
                S->ult->prox = p;
                S->ult = p;
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
    printf("Dados das movimentacoes lidos do arquivo! Aperte ENTER: ");
    getch();
}
