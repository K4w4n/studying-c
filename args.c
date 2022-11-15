#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc==1)
        printf("Não tem argumentos\n");
    else
        printf("Tem argumentos\n");
        printf("\nNome do programa chamado: %s",argv[0]);
        printf("\nOutros argumentos: %s",argv[1]);

    printf("\n");

    return 0;
}
