#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "vetor.h"

/*
    Regras:
    - Utilizar alocação dinâmica para representar a matriz.
    - Ajustar a quantidade de memória alocada para a matriz principal da tarefa conforme as regras do enunciado, e não apenas alocar uma matriz grande desde o início.
    - Alocar a matriz como vetor de vetores, e não como um único vetor.
    - Com exceção das funções malloc() e free(), está proibido o uso de outras funções da biblioteca stdlib.h.

*/

int main()
{
    char operacao[30];
    int linhas, colunas;

    scanf("%d %d", &linhas, &colunas);

    p_vetor vetor = criar_vetor(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &vetor->dados[i][j]);
        }
    }

    while (1)
    {
        scanf("%s", operacao);

        /* adicionar personagem (AP) */
        if (strncmp(operacao, "AP", 2) == 0)
        {
            // alocar mais memoria antes de adicionar

            for (int i = 0; i < colunas; i++)
                scanf("%d", &vetor->dados[i][colunas]);

            continue;
        }

        if (strcmp(operacao, "V") == 0)
        {
            printf("MATRIZ ATUAL:\n");
            for (int i = 0; i < vetor->linhas; i++)
            {
                for (int j = 0; j < vetor->colunas; j++)
                {
                    printf("%d ", vetor->dados[i][j]);
                }
                printf("\n");
            }
            continue;
        }

        if (strcmp(operacao, "S") == 0)
        {
            destruir_vetor(vetor);
            break;
        }
    }

    return 0;
}