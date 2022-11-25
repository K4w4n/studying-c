#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NLINHAS 5
#define NCOLUNAS 3

int main(int argc, char const *argv[])
{

    // Definindo tamanhos da memoria alocada
    int countCelulas = 5, tamanhoStr = 10;
    int countVetores = 10;
    // alocando memoria
    int *vetor = (int *)malloc(countCelulas * sizeof(int));
    char *string = (char *)calloc(tamanhoStr, sizeof(char));

    int **matrix = (int **)malloc(NLINHAS * sizeof(int));

    // Acessando posição 1 do ponteiro e atribuindo o valor 10
    *(vetor + 1) = 10;

    // Mapeando o vetor e exibindo os valores no console
    for (size_t i = 0; i < countCelulas; i++)
    {
        printf("vetor[%ld] = %d\n", i, *(vetor + i));
    }

    // Atribuindo string no ponteiro criado
    strcpy(string, "Hello word");

    // Criando matrix
    for (size_t i = 0; i < NLINHAS; i++)
    {
        matrix[i] = (int *)malloc(NCOLUNAS * sizeof(int));
    }

    printf("\nNLINHAS: %d\nNCOLUNAS: %d\n", NLINHAS, NCOLUNAS);
    // Armazenado dados
    for (size_t i = 0; i < NLINHAS; i++)
    {
        printf("\n%ld[", i);
        for (size_t j = 0; j < NCOLUNAS; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        printf("]\n");
    }

    printf("\n");

    // Exibindo string no console
    printf("\n%s\n", string);

    // obtendo mais memoria para o vetor
    vetor = realloc(vetor, (countCelulas + 5) * sizeof(int));

    // Testando matrix
    /* *(*(matrix + 0) + 0) = 5; */

    // limpando memoria
    free(vetor);
    free(string);
    free(matrix);
    /* free(matrix); */

    return 0;
}
