/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 09/11/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: PEGA A DATA ATUAL DO SISTEMA
*/

#include "funcoes.h"

void pegarDataAtual(int *dia, int *mes, int *ano) 
{
    time_t t;
    struct tm *data_atual;

    t = time(NULL);
    data_atual = localtime(&t);

    *dia = data_atual->tm_mday;
    *mes = data_atual->tm_mon + 1;       
    *ano = data_atual->tm_year + 1900;
}
