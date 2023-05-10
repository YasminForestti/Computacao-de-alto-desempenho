#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


int **gerador_matriz(int ROWS, int COLS)
{
    srand(time(NULL));
    int **matriz = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        matriz[i] = (int *)malloc(COLS * sizeof(int));
    }
    
    // Inicializando a matriz com valores arbitrários
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matriz[i][j] = rand()%10;
        }
    }
    return matriz;
}
int *gerador_vetor(int COLS)
{
    srand(time(NULL));
    int *vetor = (int *)malloc(COLS * sizeof(int));
    
    // Inicializando a matriz com valores arbitrários
    for (int i = 0; i < COLS; i++) {
        vetor[i] = rand()%10;
        
    }
    return vetor;
}
int *gerador_vetor_resp(int ROWS)
{
    int *vetor = (int *)calloc(ROWS, sizeof(int));
    return vetor;
}
int main(int argc, char *argv[])
{
    if (argc < 3) {
    printf("Usage: ./program ROWS COLS inverso\n");
    return 1;
}
    FILE *fp;
    fp = fopen("dados.csv", "a");

    int ROWS = atoi(argv[1]);
    int COLS = atoi(argv[2]);
    int inverso = atoi(argv[3]);
    int **A = gerador_matriz(ROWS,COLS);
    int *x = gerador_vetor(COLS);
    int *b = gerador_vetor_resp(ROWS);
    
    clock_t start_time, end_time;
    double elapsed_time;
    start_time = clock();

    // Calculating A*x and storing the result in b
    if (inverso == 1){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            b[i] += A[i][j] * x[j];
        }
    }
    }else{
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            b[i] += A[i][j] * x[j];
        }
    }
    }
    end_time = clock();
    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // printf("Tempo de execução: %.2f segundos.\n", elapsed_time);
    fprintf(fp, "%i;%i;%.5f\n;%i", ROWS, COLS, elapsed_time,inverso); // escreve as variáveis no arquivo
    fclose(fp); // fecha o arquivo

    // Liberando a memória alocada para a matriz
    for (int i = 0; i < ROWS; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    return 0;
}



// Explique como o modo em que os arrays são armazenados nas duas linguagens afetam os resultados.  
  





