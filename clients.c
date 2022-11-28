#include <stdlib.h>
typedef struct
{
    unsigned int id;
    char *name;
    unsigned int yearOfBirth : 11;
    float amountOfExpenses;
} client;

typedef struct
{
    unsigned int length;
    client *list;
    unsigned int active : 1;
} clientList;

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

void clientListAdd(clientList *baseOfClients)
{

}

void clientListUpdate(clientList *baseOfClients)
{

}

void clientList (clientList *baseOfClients)
{

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
