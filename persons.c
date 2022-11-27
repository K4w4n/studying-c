#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo estrutura de pessoa
typedef struct
{
    char *name;
    unsigned int age : 7; // Representa um valor de 0 até 126
    unsigned int id;
} person;

// definindo estrutura de lista de pessoas
typedef struct
{
    person *persons;
    unsigned int count;
    unsigned int active : 1; // Tem dois estados possiveis, 0 ou 1
} personList;

// Função para limpar buffer do teclado
void flush_in()
{
    int ch;
    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

// Função para configurar struct da lista de pessoas
void personListInit(personList *baseOfPersons)
{
    baseOfPersons->persons = (person *)malloc(0);
    baseOfPersons->active = 1;
    baseOfPersons->count = 0;
}

// Encerra lista, liberando a memoria utilizada
void personListEnd(personList *baseOfPersons)
{
    free(baseOfPersons->persons);
    baseOfPersons->active = 0;
    baseOfPersons->count = 0;
}

// Adiciona uma pessoa na lista
void personListAdd(personList *baseOfPersons)
{
    if (!baseOfPersons->active)
    {
        printf("\nA lista não esta ativa\n");
        return;
    }

    baseOfPersons->count++;

    baseOfPersons->persons = (person *)realloc(baseOfPersons->persons, sizeof(person) * baseOfPersons->count);

    person *newPerson = &baseOfPersons->persons[baseOfPersons->count - 1];

    newPerson->name = (char *)malloc(sizeof(char) * 100);

    printf("\nName: ");
    scanf("%s", newPerson->name);
    newPerson->name = (char *)realloc(newPerson->name, strlen(newPerson->name) * sizeof(char));
    flush_in();

    unsigned int age;
    printf("\nAge: ");
    scanf("\n%u", &age);
    newPerson->age = age;
    flush_in();

    newPerson->id = baseOfPersons->count == 1 ? 1 : baseOfPersons->persons[baseOfPersons->count - 2].id + 1;
}

// Exibe a lista de pessoas no terminal
void personListShow(personList *baseOfPersons)
{
    printf("\nCount: %d\n", baseOfPersons->count);
    printf("\n#Id\tName\tAge\n");

    for (size_t i = 0; i < baseOfPersons->count; i++)
    {
        printf(
            "#%u\t%s\t%u\n",
            baseOfPersons->persons[i].id,
            baseOfPersons->persons[i].name,
            baseOfPersons->persons[i].age);
    }
}

// Remove pessoa da lista
void personListRemove(personList *baseOfPersons)
{
    printf("\nQual dos itens gostaria de remover?");
    personListShow(baseOfPersons);

    unsigned int idDelete, indexDelete = -1;
    printf("\n#");
    scanf("%u", &idDelete);

    for (size_t i = 0; i < baseOfPersons->count; i++)
        if (baseOfPersons->persons[i].id == idDelete)
            indexDelete = i;

    if (indexDelete == -1)
    {
        printf("Erro, id não encontrado");
        return;
    }

    (baseOfPersons->count)--;

    for (size_t i = indexDelete; i < baseOfPersons->count; i++)
        memcpy(&(baseOfPersons->persons[i]), &(baseOfPersons->persons[i + 1]), sizeof(person));

    baseOfPersons->persons = realloc(baseOfPersons->persons, baseOfPersons->count * sizeof(person));
    personListShow(baseOfPersons);
    printf("\nId deletado: %u\n", idDelete);
}

// Exibe o menu de ações
int menu(personList *baseOfPersons)
{
    printf("\nMenu");
    printf("\nEscolha uma das opções a baixo:");
    printf("\n1) Mostrar todas as pessoas");
    printf("\n2) Cadastrar pessoa");
    printf("\n3) Remover pessoa");
    printf("\n4) Exit");

    while (1)
    {
        unsigned int optionId;
        printf("\nR: ");
        scanf("%u", &optionId);

        if (optionId == 1)
            personListShow(baseOfPersons);

        else if (optionId == 2)
            personListAdd(baseOfPersons);

        else if (optionId == 3)
            personListRemove(baseOfPersons);

        else if (optionId == 4)
            return -1;

        else
        {
            printf("\nOpção incorreta, tente novamente\n");
            continue;
        }

        return 0;
    }
}

// Função principal
int main(int argc, char const *argv[])
{
    personList baseOfPersons;

    personListInit(&baseOfPersons);

    int result = 0;

    while (result != -1)
        result = menu(&baseOfPersons);

    personListEnd(&baseOfPersons);

    return 0;
}
