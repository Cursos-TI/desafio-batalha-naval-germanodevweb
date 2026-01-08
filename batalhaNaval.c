#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0

int main()
{

    // Tabuleiro 10x10 inicializado com água (0)
    int tabuleiro[TAM][TAM] = {0};

    // Vetores unidimensionais representando os navios (tamanho fixo 3)
    int navioHorizontal[NAVIO] = {3, 3, 3};
    int navioVertical[NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas no código)
    int linhaH = 2, colunaH = 2; // navio horizontal
    int linhaV = 5, colunaV = 6; // navio vertical

    int i, valido = 1;

    // Validação do navio horizontal (limites)
    if (colunaH + NAVIO > TAM)
    {
        valido = 0;
    }

    // Validação do navio vertical (limites)
    if (linhaV + NAVIO > TAM)
    {
        valido = 0;
    }

    // Verificação de sobreposição
    for (i = 0; i < NAVIO; i++)
    {
        if (tabuleiro[linhaH][colunaH + i] != AGUA ||
            tabuleiro[linhaV + i][colunaV] != AGUA)
        {
            valido = 0;
        }
    }

    // Posicionamento dos navios, se tudo for válido
    if (valido)
    {

        // Posiciona navio horizontal
        for (i = 0; i < NAVIO; i++)
        {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }

        // Posiciona navio vertical
        for (i = 0; i < NAVIO; i++)
        {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }
    else
    {
        printf("Erro no posicionamento dos navios.\n");
        return 1;
    }

    // Exibição do tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int linha = 0; linha < TAM; linha++)
    {
        for (int coluna = 0; coluna < TAM; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
