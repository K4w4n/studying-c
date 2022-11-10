#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
    char name[50];
    char email[80];
};

void drawPerson(struct person p){
    printf("Name: \"%s\"\n", p.name);
    printf("Email: \"%s\"\n", p.email);
}

int main(int argc, char const *argv[])
{
    struct person p1;

    strcpy(p1.name, "Kawan Araujo");
    strcpy(p1.email, "kawanaraujocontato@gmail.com");

    drawPerson(p1);

    return 0;
}

