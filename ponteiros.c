#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef float (*fnMath)(float, float);

float soma(float numberA, float numberB)
{
    return numberA + numberB;
}

float subtracao(float numberA, float numberB)
{
    return numberA - numberB;
}

float divisao(float numberA, float numberB)
{
    return numberA / numberB;
}

float multiplicacao(float numberA, float numberB)
{
    return numberA * numberB;
}
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    /* Niveis de ponteiro */

    int number = 5;

    int *pNumber1 = &number;
    int **pNumber2 = &pNumber1;
    int ***pNumber3 = &pNumber2;

    printf("\n____________________");

    // Exibindo dados no console
    printf("\nnumber = %d", number);
    printf("\n*pNumber1 = %d", *pNumber1);

    // alterando dados via ponteiro
    ***pNumber3 = 8;

    // Exibindo modificação no console
    printf("\nnumber = %d", number);
    printf("\n*pNumber1 = %d", *pNumber1);

    printf("\n____________________\n");

    int op;

    printf("Qual das operações voce quer realizar?\n");
    printf("1) Soma\n");
    printf("2) Divisão\n");
    printf("3) Subtração\n");
    printf("4) Multiplicação\n");
    scanf(" %d", &op);

    fnMath operacao = op == 1 ? &soma : (op == 2 ? &divisao : (op == 3 ? &subtracao : &multiplicacao));
    printf("\n %f", (*operacao)(8, 7));
/* 
    int vet[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int *pvet = vet;

    *(pvet + 4) = 888;
    
    for (size_t i = 0; i < 10; i++)
    {
        printf("\nvet[%ld] = %d\n", i, vet[i]);
        printf("pvet[%ld] = %d\n", i, *(pvet + i));
    }

 */
    return 0;
}
