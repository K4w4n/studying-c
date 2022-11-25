#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person
{
    char name[50];
    char email[80];
};

typedef struct
{
    char name[50];
    char email[80];
} person2;

struct person3
{
    char name[50];
    char email[80];
} pessoaInstancia;

struct
{
    char name[50];
    char email[80];
} pessoaInstancia2;

typedef struct
{
    unsigned int r : 8;
    unsigned int g : 8;
    unsigned int b : 8;
} color;

void drawPerson(struct person p)
{
    printf("Name: \"%s\"\n", p.name);
    printf("Email: \"%s\"\n", p.email);
}

int main(int argc, char const *argv[])
{
    struct person p1;

    strcpy(p1.name, "Kawan Araujo");
    strcpy(p1.email, "kawanaraujocontato@gmail.com");

    drawPerson(p1);

    color myColor;
    color *myColorp = &myColor;

    myColor.r = 255;
    myColor.g = 255;
    myColor.b = 255;

    printf("\nRGB(%d, %d, %d)\n", myColor.r, myColor.g, myColor.b);
    printf("\nRGB(%d, %d, %d)\n", myColorp->r, myColorp->g, myColorp->b);
    printf("\nRGB(%d, %d, %d)\n", (*myColorp).r, (*myColorp).g, (*myColorp).b);
    return 0;
}
