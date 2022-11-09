#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    int age;
    char mensage[15] = "";
    char premio[15] = "";

    printf("Qual a sua idade? ");
    scanf("%d", &age);

    printf("\n");

    if (age < 18)
    {
        strcpy(mensage, "Menor de idade");
        strcpy(premio, "bala");
    }
    else if (age < 50)
    {
        strcpy(premio, "Boletos pagos");
        strcpy(mensage, "Adulto");
    }
    else
    {
        strcpy(premio, "Viajem gratis");
        strcpy(mensage, "Melhor idade");
    }

    printf("\n%s\n", mensage);

    for (size_t i = 0; i < age; i++)
    {
        /* code */
        printf("%ldº %s\n", i + 1, premio);
    }

    return 0;
}

/*
    Menu(Opções)
    Calculadora(atalho)

 */