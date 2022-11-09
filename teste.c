#include <stdio.h>
#include <strings.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    char teste[] = "";

    printf("Iniciando sistema...\n");
    printf("Menu");
    scanf("%s", &teste);
    return 0;
}

/*
    Menu(Opções)
    Calculadora(atalho)

 */