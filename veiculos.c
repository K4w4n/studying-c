#include <stdio.h>
#include <string.h>
struct Veiculo
{
    char marca[25];
    int modelo;
    char placa[8];
};

struct Veiculo *listarVeiculos(struct Veiculo *veiculos, int quantidade)
{
    if (quantidade == 0)
    {
        printf("Nenhum veiculo cadastrado, para cadastrar um veiculo selecione a opção 2 no menu.\n");
        return veiculos;
    }

    printf("\n Quantidade de veiculos: %d \n", quantidade);
    for (size_t i = 0; i < quantidade; i++)
    {
        printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");
        printf("\nMarca: %s\n", veiculos[i].marca);
        printf("\nModelo: %d\n", veiculos[i].modelo);
        printf("\nPlaca: %s\n", veiculos[i].placa);
        printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");
    }
    return veiculos;
}
struct Veiculo *inserirVeiculo(struct Veiculo *veiculos, int quantidade)
{
    printf("\nCadastrar veiculo");

    printf("\nMarca: ");
    scanf("%s", veiculos[quantidade].marca);

    printf("\nModelo: ");
    scanf("%d", &veiculos[quantidade].modelo);

    printf("\nPlaca: ");
    scanf("%s", veiculos[quantidade].placa);

    printf("\n Veiculo cadastrado com sucesso!\n");
    return veiculos;
}
struct Veiculo *filtrarPorAno(struct Veiculo *veiculos, int quantidade)
{
    int anoPesquisa;
    printf("\nPesquisa por ano\n");
    printf("\nAno do veiculo: ");
    scanf("%d", &anoPesquisa);

    if (quantidade == 0)
    {
        printf("Nenhum veiculo cadastrado, para cadastrar um veiculo selecione a opção 2 no menu.\n");
        return veiculos;
    }

    int quantidadeResultados = 0;
    for (size_t i = 0; i < quantidade; i++)
    {
        if (veiculos[i].modelo == anoPesquisa)
        {
            printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");
            printf("\nMarca: %s\n", veiculos[i].marca);
            printf("\nModelo: %d\n", veiculos[i].modelo);
            printf("\nPlaca: %s\n", veiculos[i].placa);
            printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");

            quantidadeResultados++;
        }
    }

    if (quantidadeResultados == 0)
        printf("Nenhum veiculo encontrado com esse ano\n");
}
struct Veiculo *filtrarAPartirDoAno(struct Veiculo *veiculos, int quantidade)
{
    int anoPesquisa;
    printf("\nPesquisa a partir do ano\n");
    printf("\nAno do veiculo: ");
    scanf("%d", &anoPesquisa);

    if (quantidade == 0)
    {
        printf("Nenhum veiculo cadastrado, para cadastrar um veiculo selecione a opção 2 no menu.\n");
        return veiculos;
    }

    int quantidadeResultados = 0;
    for (size_t i = 0; i < quantidade; i++)
    {
        if (veiculos[i].modelo >= anoPesquisa)
        {
            printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");
            printf("\nMarca: %s\n", veiculos[i].marca);
            printf("\nModelo: %d\n", veiculos[i].modelo);
            printf("\nPlaca: %s\n", veiculos[i].placa);
            printf("\n-_-_-_-_-_-_-_-_-_-_-_-_\n");

            quantidadeResultados++;
        }
    }

    if (quantidadeResultados == 0)
        printf("Nenhum veiculo encontrado com esse ano\n");
}
struct Veiculo *filtrarPorModelo(struct Veiculo *veiculos, int quantidade)
{
    printf("filtrarPorModelo");
}
int main(int argc, char const *argv[])
{
    // Gerando lista de veiculos
    struct Veiculo listaVeiculos[20];

    const char opcoesMenu[4][60] = {
        "Listar veículos cadastrados",
        "Inserir um novo veículo",
        "Listar os veículos filtrado por ano de fabricação",
        "Listar os veículos com o ano de fabricação acima de..."};

    const int quantidadeOpcoes = sizeof(opcoesMenu) / sizeof(opcoesMenu[0]);

    int quantidadeVeiculos = 0;

    printf("Bem vindo ao carSys!\n");

    while (1)
    {

        printf("Oque gostaria de fazer?\n");

        for (size_t i = 0; i < quantidadeOpcoes; i++)
        {
            printf("%ld) %s\n", i + 1, opcoesMenu[i]);
        }

        int opcao;

        while (1)
        {
            printf("\nR: ");
            scanf("%d", &opcao);

            if ((opcao > 0) && (opcao <= quantidadeOpcoes))
                break;
            else
                printf("\nOpção invalida, escolha um dos numeros listados\n");
        }

        switch (opcao)
        {
        case 1:
            listarVeiculos(listaVeiculos, quantidadeVeiculos);
            break;
        case 2:
            inserirVeiculo(listaVeiculos, quantidadeVeiculos);
            quantidadeVeiculos++;
            break;
        case 3:
            filtrarPorAno(listaVeiculos, quantidadeVeiculos);
            break;
        case 4:
            filtrarAPartirDoAno(listaVeiculos, quantidadeVeiculos);
            break;
        case 5:
            filtrarPorModelo(listaVeiculos, quantidadeVeiculos);
            break;
        }
    }
    return 0;
}
