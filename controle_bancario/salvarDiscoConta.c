/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: SALVA OS CADASTROS DAS CONTAS NO ARQUIVO
*/

#include "funcoes.h"

void salvarDiscoConta(ListaDupla *D)
{
    regConta conta;

    ApontConta i;

    FILE *arq;

    char *nomeArquvio;
    char *modoGravacao;

    modoGravacao = "wb";
    nomeArquvio = "contas.dat";

    system("cls");
    tela();

    gotoxy(24, 2);
    printf("SALVAR CONTAS NO DISCO");

    arq = fopen(nomeArquvio, modoGravacao);

    if (arq == NULL)
    {
        limpaMensagem();
        gotoxy(1, 22);
        printf("Erro ao abrir o arquivo para gravacao! Aperte ENTER: ");
        getch();

        return;
    }

    i = D->pri;

    while (i != NULL)
    {
        conta = i->conteudo;
        fwrite(&conta, sizeof(regConta), 1, arq);
        i = i->prox;
    }

    fclose(arq);

    limpaMensagem();
    gotoxy(1, 22);
    printf("Dados das contas salvos no arquivo! Aperte ENTER: ");
    getch();
}
