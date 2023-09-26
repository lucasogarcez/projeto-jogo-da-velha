//========================================================
/*

   Aluno: Lucas Oliveira Garcez
   Curso: Engenharia de Computação
   Período: 1º
   Disciplina: Algoritmos
   Data: 04/07/2023

   DESCRIÇÃO DO ALGORITMO:


*/
//========================================================


//==============================================================
//====== INCLUSAO DAS DIRETIVAS ================================
//==============================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define tam1 4
#define tam2 4

//==============================================================
//========= PROTÓTIPOS DAS FUNÇÕES =============================
//==============================================================
//local para DECLARAR o TIPO, NOME E PARÂMETROS da função//
//==============================================================



//==============================================================
//========== LOCAL PARA CRIAR OS MÓDULOS =======================
//==============================================================



//==============================================================
//========= CODIGO PRINCIPAL ===================================
//==============================================================
int main()
{
    //CRIAR VARS LOCAIS ao CÓDIGO PRINCIPAL
    int A[tam1][tam2];

    int qtd, l, c, cont, lin, col, j, g, t;
    //INICIALIZAR VARS
    qtd = l = c = lin = col = j = g = cont = t = 0;

    for (l = 1; l < tam1; l++)
    {
        for (c = 1; c < tam2; c++)
        {
            A[l][c] = 0;
        }
    }
//    jogada
//    void testar horizontal
//    void testar vertical
//    void testar diagonal
//    void testar diagonal secundaria
//
//    proxima jogada


    //RECEBER DADOS

    while (cont < ((tam1-1) * (tam2-1)))
    {
        //DEFINIR JOGADOR DA VEZ
        if (cont % 2 == 0)
            j = 1;
        else
            j = 2;

        //MOSTRAR POSICIONAMENTO NA MATRIZ
        system("cls");
        printf ("       JOGO DA VELHA   ");
        printf ("\n    =================== \n");


        if (cont != 0)
        {
            printf ("\n MOSTRANDO JOGO DA VELHA \n");
            for (l = 1; l < tam1; l++)
            {
                for (c = 1; c < tam2; c++)
                {
                    if (A[l][c] == 1)
                        printf ("     O");
                    else
                    {
                        if (A[l][c] == -1)
                            printf ("     X");
                        else
                            printf ("     %d", A[l][c]);
                    }
                }
                printf ("\n");
            }
        }

        //JOGADAS
        printf ("\n VEZ DO JOGADOR %d \n", j);
        printf ("\n Digite a linha...: ");
        fflush(stdin);
        scanf("%d", &lin);
        //VALIDAR
        while (lin < 1 || lin > 3)
        {
            printf ("\n Linha invalida ... digite entre 0 e 2...: ");
            fflush(stdin);
            scanf("%d", &lin);
        }

        printf ("\n Digite a coluna...: ");
        fflush(stdin);
        scanf("%d", &col);
        //VALIDAR
        while (col < 1 || col > 3)
        {
            printf ("\n Coluna invalida ... digite entre 0 e 2...: ");
            fflush(stdin);
            scanf("%d", &col);
        }

        //VALIDAR REPETIDO
        while (A[lin][col] == 1 || A[lin][col] == -1)
        {
            printf ("\n Lugar ja ocupado ... digite outro ... \n");
            //LINHA
            printf ("\n Digite a linha...: ");
            fflush(stdin);
            scanf("%d", &lin);
            //VALIDAR
            while (lin < 1 || lin > 3)
            {
                printf ("\n Linha invalida ... digite entre 0 e 2...: ");
                fflush(stdin);
                scanf("%d", &lin);
            }
            //COLUNA
            printf ("\n Digite a coluna...: ");
            fflush(stdin);
            scanf("%d", &col);
            //VALIDAR
            while (col < 1 || col > 3)
            {
                printf ("\n Coluna invalida ... digite entre 0 e 2...: ");
                fflush(stdin);
                scanf("%d", &col);
            }
        }

        //VER QUAL JOGADOR
        if (j == 1)
            A[lin][col] = 1;
        else
            A[lin][col] = -1;


        //VERIFICAÇÕES
        //VERIFICAÇÃO HORIZONTAL
        for (l = 1; l < tam1; l++) //LINHA
        {
            qtd = 0;
            for (c = 1; c < tam2-1; c++) //COLUNA
            {
                if (A[l][c] == A[l][c+1]) //VERIFICA A COLUNA
                    if (A[l][c] != 0)
                        qtd++;
            }
            if(qtd == 2)
            {
                g++;
                cont = tam1 * tam2;
            }
        }

        //VERIFICAÇÃO VERTICAL
        for (c = 1; c < tam2; c++) //COLUNA
        {
            qtd = 0;
            for (l = 1; l < tam1; l++) //LINHA
            {
                if (A[l][c] == A[l+1][c])
                    if (A[l][c] != 0)
                        qtd++;
            }
            if(qtd == 2)
            {
                g++;
                cont = tam1 * tam2;
            }
        }

        //VERIFICAÇÃO DIAGONAL PRINCIPAL
        qtd = 0;
        for (l = 1; l < tam1-1; l++)
        {
            for (c = 1; c < tam2-1; c++)
            {
                if (l == c)
                {
                    if (A[l][c] == A[l+1][c+1])
                    {
                        if (A[l][c] != 0)
                            qtd++;
                    }
                }
            }
            if (qtd == 2)
            {
                g++;
                cont = tam1 * tam2;
            }
        }

        //VERIFICAÇÃO DIAGONAL SECUNDÁRIA
        if (A[1][3] == A[2][2] == A[3][1])
        {
            if (A[1][3] != 0 && A[2][2] != 0 && A[3][1] != 0)
            {
                g++;
                cont = tam1 * tam2;
            }
        }

        //VERIFICAÇÃO PARA VELHA
        t = 0;
        for (l = 1; l < tam1; l++)
        {
            for (c = 1; c < tam2; c++)
            {
                if (A[l][c] != 0)
                {
                    t++;
                }
            }
        }
        if (t == 9)
        {
            if (g == 0)
                printf ("\n ... VELHA! ... ");
        }

        if (g == 1)
        {
            system("cls");
            printf ("    JOGADOR %d VENCEU!  ", j);
            printf ("\n   ===================  ");

            printf ("\n MOSTRANDO JOGO DA VELHA \n");
            for (l = 1; l < tam1; l++)
            {
                for (c = 1; c < tam2; c++)
                {
                    if (A[l][c] == 1)
                        printf ("     O");
                    else
                    {
                        if (A[l][c] == -1)
                            printf ("     X");
                        else
                            printf ("     %d", A[l][c]);
                    }
                }
                printf ("\n");
            }
        }


        cont++;
    }

    printf("\n\n\n tchau  ... Obrigado ... \n\n\n\n");
    return 0;

}//fimalgoritmos
