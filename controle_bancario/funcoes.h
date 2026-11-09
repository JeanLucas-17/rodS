/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 24/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: DEFINIR TODAS AS ESTRUTURAS E ASSINATURAS DAS FUNCOES
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct
{
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    int status;
} regConta;

typedef struct TipoItemConta *ApontConta;
typedef struct TipoItemConta
{
    regConta conteudo;

    ApontConta ant;
    ApontConta prox;
} TipoItemConta;

typedef struct
{
    ApontConta pri;
    ApontConta ult;
} ListaDupla;

typedef struct 
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimento[30];
    char ds_favorecido[50];
    double vl_movimento;
    double vl_saldo;
} regMovimentacao;

typedef struct TipoItemMov *ApontMov;

typedef struct TipoItemMov
{
    regMovimentacao conteudo;

    ApontMov prox;
} TipoItemMov;

typedef struct
{
    ApontMov pri;
    ApontMov ult;
} ListaSimples;

void gotoxy(int x, int Y);

void telaCadastrar();

void tela();

void telaPrincipal();

void menuConta(ListaDupla *D, ListaSimples *S);

void cadastrarConta(ListaDupla *D, int opcao);

void telaConta();

void limpaMensagem();

ApontConta pesquisaCodigoConta(ListaDupla *D, int codigo);

int quantidadeContas(ListaDupla *D);

ApontConta posConta(ListaDupla *D, int pos);

void consultaConta(ListaDupla *D, int opcao);

void menuConsultaConta(ListaDupla *D);

void telaConsulta();

void mostraConta(regConta conta, int opcao, int y);

void ordemCodigo(ListaDupla *D);

void cabecalhoContas();

void salvarDiscoConta(ListaDupla *D);

void lerDiscoConta(ListaDupla *D);

void ordemAlfabetica(ListaDupla *D);

void erro();

void alterarConta(ListaDupla *D);

void removerConta(ListaDupla *D, int opcao, ListaSimples *S);

void rodapeConta(double saldoTot, double limiteTot, int y);

void menuMovi(ListaSimples *S, ListaDupla *D);

void telaMovi();

void telaDebitoeCredito();

void moviDebitoeCredito(ListaSimples *S, ListaDupla *D);

void transferenciaConta(ListaDupla *D, ListaSimples *S);

void telaDebitoeCredito();

void lerDiscoMov(ListaSimples *S);

void salvarDiscoMov(ListaSimples *S);

void telaTransferencia();

void consultaMov(ListaDupla *D, ListaSimples *S);

void telaConsultaMovi();

ApontMov pesquisaCodigoMovi(int codigo, ListaSimples *S);

void freeMalloc(ListaDupla *D, ListaSimples *S);

void pegarDataAtual(int *dia, int *mes, int *ano);

#endif
