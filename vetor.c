#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quantidadeBimestre;
    int quantidadeAluno;

    printf("Quantidade de bimestres: ");
    scanf("%d", &quantidadeBimestre);

    printf("Quantidade de alunos: ");
    scanf("%d", &quantidadeAluno);

    float alunos[quantidadeAluno][quantidadeBimestre];
    char cadastrarAluno = 's';

    for (size_t i = 0; i < quantidadeAluno; i++)
    {
        float soma = 0;

        for (size_t j = 0; j < quantidadeBimestre; j++)
        {
            printf("\nNota(%ld): ", j + 1);
            scanf("%f", &alunos[i][j]);
            soma += alunos[i][j];
        }

        float media = soma / quantidadeBimestre;

        printf("\nSoma: %f \nMedia: %f\n", soma, media);

        printf("\n");
    }

    return 0;
}
