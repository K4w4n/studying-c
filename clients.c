#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct
{
    unsigned int id;
    char *name;
    unsigned int yearOfBirth;
    float amountOfExpenses;
} client;

typedef struct
{
    unsigned int length;
    client *list;
    unsigned int active : 1;
} clientList;

typedef void (*actionFunc)(clientList *);
void flush_in()
{
    int ch;
    do
    {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void clientListInit(clientList *baseOfClients)
{
    baseOfClients->list = (client *)malloc(0);
    baseOfClients->active = 1;
    baseOfClients->length = 0;
}

void clientListEnd(clientList *baseOfClients)
{
    baseOfClients->active = 0;
    baseOfClients->length = 0;
}

void clientListShow(clientList *baseOfClients)
{
    printf("\nLista de clientes: ");
    printf("\nId\tName\tBirth\tAmount");
    for (size_t i = 0; i < baseOfClients->length; i++)
    {
        client *selectClient = &(baseOfClients->list[i]);
        printf("\n%u\t%s\t%u\t%.2f", selectClient->id, selectClient->name, selectClient->yearOfBirth, selectClient->amountOfExpenses);
    }
    printf("\n");
}

void clientListAdd(clientList *baseOfClients)
{
    baseOfClients->length++;
    baseOfClients->list = (client *)realloc(baseOfClients->list, sizeof(client) * baseOfClients->length);

    client *selectedClient = &(baseOfClients->list[baseOfClients->length - 1]);

    selectedClient->id = baseOfClients->length == 1 ? 1 : baseOfClients->list[baseOfClients->length - 2].id + 1;

    selectedClient->name = (char *)malloc(sizeof(char) * 30);

    printf("\nNome: ");
    scanf("%s", selectedClient->name);

    selectedClient->name = (char *)realloc(selectedClient->name, sizeof(char) * strlen(selectedClient->name));

    printf("\nAno de nacimento: ");
    flush_in();
    scanf("%u", &selectedClient->yearOfBirth);

    printf("\nTotal de gastos: ");
    flush_in();
    scanf("%f", &selectedClient->amountOfExpenses);
}

void clientListUpdate(clientList *baseOfClients)
{
    unsigned int updateId;
    printf("\nQual o id do cliente que será atualizado?\n#");
    scanf("%u", &updateId);

    unsigned int indexId = -1;
    for (size_t i = 0; i < baseOfClients->length; i++)
    {
        if (updateId == baseOfClients->list[i].id)
        {
            indexId = i;
            break;
        }
    }

    if (indexId == -1)
    {
        printf("\n Id não econtrado");
        return;
    }

    client *selectedClient = &baseOfClients->list[indexId];

    selectedClient->name = (char *)realloc(selectedClient->name, sizeof(char) * 30);

    printf("\nNome(%s): ", selectedClient->name);
    scanf("%s", selectedClient->name);

    selectedClient->name = (char *)realloc(selectedClient->name, sizeof(char) * strlen(selectedClient->name));

    printf("\nAno de nacimento(%u): ", selectedClient->yearOfBirth);
    flush_in();
    scanf("%u", &selectedClient->yearOfBirth);

    printf("\nTotal de gastos(%.2f): ", selectedClient->amountOfExpenses);
    flush_in();
    scanf("%f", &selectedClient->amountOfExpenses);
}

void clientListRemove(clientList *baseOfClients)
{
    unsigned int id;
    int removeIndex = -1;

    printf("\nQual o id do cliente para excluir?\n#");
    scanf("%u", &id);

    for (size_t i = 0; i < baseOfClients->length; i++)
    {
        if (id == baseOfClients->list[i].id)
        {
            client *selectClient = &baseOfClients->list[i];
            printf("\nO seguinte cliente vai ser excluido:");
            printf("\nId\tName\tBirth\tAmount");
            printf("\n%u\t%s\t%u\t%.2f", selectClient->id, selectClient->name, selectClient->yearOfBirth, selectClient->amountOfExpenses);

            removeIndex = i;
        }
    }

    if (removeIndex == -1)
    {
        printf("Id não encontrado");
        return;
    }

    baseOfClients->length--;

    for (size_t i = removeIndex; i < baseOfClients->length; i++)
        baseOfClients->list[i] = baseOfClients->list[i - 1];

    baseOfClients->list = (client *)realloc(baseOfClients->list, sizeof(client) * baseOfClients->length);
}

void clientListResetAmount(clientList *baseOfClients)
{
    for (size_t i = 0; i < baseOfClients->length; i++)
        baseOfClients->list[i].amountOfExpenses = 0;

    if (baseOfClients->length == 1)
        printf("\n%u cliente alterado!", baseOfClients->length);
    else
        printf("\n%u clientes alterados!", baseOfClients->length);
}
void clientListShowBestBuyer(clientList *baseOfClients)
{
    client bestBuyers[baseOfClients->length];

    for (size_t i = 0; i < baseOfClients->length; i++)
        bestBuyers[i] = baseOfClients->list[i];

    while (1)
    {
        unsigned int modified = 0;
        for (size_t i = 0; i < (baseOfClients->length - 1); i++)
        {
            if ((bestBuyers[i].amountOfExpenses) < (bestBuyers[i + 1].amountOfExpenses))
            {
                client aux = bestBuyers[i + 1];
                bestBuyers[i + 1] = bestBuyers[i];
                bestBuyers[i] = aux;
                modified++;
            }
        }

        if (modified == 0)
            break;
    }
    printf("\nId\tName\tBirth\tAmount");
    for (size_t i = 0; i < baseOfClients->length; i++)
    {
        client selectClient = (bestBuyers[i]);
        printf("\n%u\t%s\t%u\t%.2f", selectClient.id, selectClient.name, selectClient.yearOfBirth, selectClient.amountOfExpenses);
    }
}

int menuOptions(clientList *baseOfClients)
{
    actionFunc actionOption[] = {
        &clientListAdd,
        &clientListShow,
        &clientListUpdate,
        &clientListShowBestBuyer,
        &clientListResetAmount};
    unsigned int option;
    printf("\nOque gostaria de fazer?");
    printf("\n1) Cadastrar cliente");
    printf("\n2) Vizualizar clientes");
    printf("\n3) Editar cliente");
    printf("\n4) Mostrar melhores clientes");
    printf("\n5) Zerar gastos de todos os clientes");
    printf("\n6) Exit");
    printf("\nR: ");
    scanf("%d", &option);

    if(option==6) return -1;

    actionOption[option - 1](baseOfClients);

    return 0;
}

int main(int argc, char const *argv[])
{
    clientList baseOfClients;

    clientListInit(&baseOfClients);

    int status = 0;
    do
    {
        status = menuOptions(&baseOfClients);
    } while (status != -1);

    clientListEnd(&baseOfClients);

    printf("\n");
    return 0;
}
