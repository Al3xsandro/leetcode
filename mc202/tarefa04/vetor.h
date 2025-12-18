typedef struct vetor *p_vetor;

struct vetor
{
    int **dados;
    int linhas;
    int colunas;
};

// Alocar a matriz como vetor de vetores, e não como um único vetor.
p_vetor criar_vetor(int linhas, int colunas);

void destruir_vetor(p_vetor v);
/* adiciona uma nova linha como última da matriz. Se não houver espaço suficiente alocado na matriz atual, a quantidade de linhas alocadas deve ser dobrada; */
void inserir_ap(p_vetor);
void remover_elemento();
void buscar();

void imprimir(p_vetor v);
