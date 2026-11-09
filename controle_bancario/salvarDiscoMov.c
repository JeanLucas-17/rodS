/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 04/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: SALVA AS MOVIMENTACOES DAS CONTAS NO ARQUIVO
*/

#include "funcoes.h"

void salvarDiscoMov(ListaSimples *S)
{
    regMovimentacao mov;

    ApontMov i;

    FILE *arq;

    char *nomeArquvio;
    char *modoGravacao;

    modoGravacao = "wb";
    nomeArquvio = "movimentacoes.dat";
    
    system("cls");
    tela();

    gotoxy(18, 2);
    printf("SALVAR MOVIMENTACOES NO DISCO");

    arq = fopen(nomeArquvio, modoGravacao);

    if (arq == NULL)
    {
        limpaMensagem();
        gotoxy(1, 22);
        printf("Erro ao abrir o arquivo para gravacao! Aperte ENTER: ");
        getch();

        return;
    }

    i = S->pri;

    while (i != NULL)
    {
        mov = i->conteudo;
        fwrite(&mov, sizeof(regMovimentacao), 1, arq);
        i = i->prox;
    }

    fclose(arq);

    limpaMensagem();
    gotoxy(1, 22);
    printf("Dados das movimentacoes salvos no arquivo! Aperte ENTER: ");
    getch();
}
