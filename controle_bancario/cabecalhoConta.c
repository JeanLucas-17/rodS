/*
    AUTOR......: JEAN LUCAS THOMAZELLI SILVA
    DATA.......: 27/10/2026

    GRUPO......: JEAN LUCAS RA: 438971-2026
                 FELIPE GABRIEL RA: 434906-2026

    OBJETIVO...: CABECALHO DA CONSULTA POR CODIGO E ALFABETICA DAS CONTAS
*/

#include "funcoes.h"

void cabecalhoContas()
{
    gotoxy(1, 4);
    printf("Cd Banco               Agenc Conta    Tipo Conta     Saldo       Limite     St");
    gotoxy(1, 5);
    printf("-- ------------------- ----- -------- -------------- ----------- ----------- -");
}
