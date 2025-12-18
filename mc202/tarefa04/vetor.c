#include "stdlib.h"
#include "stdio.h"
#include "vetor.h"

// Alocar a matriz como vetor de vetores, e não como um único vetor.
// Ajustar a quantidade de memória alocada para a matriz principal da tarefa conforme as regras do enunciado, e não apenas alocar uma matriz grande desde o início.
p_vetor criar_vetor(int linhas, int colunas)
{
    p_vetor v = malloc(sizeof(struct vetor));
    v->linhas = linhas;
    v->colunas = colunas;

    // aloca vetor de linhas
    v->dados = malloc(linhas * sizeof(int *));

    // aloca cada linha (onde vou colocar os valores)
    for (int i = 0; i < linhas; i++)
    {
        v->dados[i] = malloc(colunas * sizeof(int));
    }

    return v;
}

/*
    Você não precisa alocar todas as linhas novamente ao adicionar uma linha nova na matriz mesmo se precisar aumentar a capacidade, basta atualizar os ponteiros.

    Se você não está seguindo a dica acima e está alocando todas as linhas novamente,
    tome cuidado para alocar elas do tamanho correto (elas devem ter todas as colunas,
    não apenas as colunas usadas). O mesmo vale ao adicionar uma nova coluna,
    que deve ser adicionada em todas as linhas, não só nas sendo de fato usadas.
*/
void adicionar_ap(p_vetor v, int valor)
{
    return;
}

void destruir_vetor(p_vetor v)
{
    for (int i = 0; i < v->linhas; i++)
    {
        free(v->dados[i]);
    }

    free(v->dados);
    free(v);
}