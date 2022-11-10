#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

/* Dependendo do SO a função struper não existe */
char *struper(char *string)
{
    strcpy(string, string);
    for (size_t i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
    return string;
}

/* Dependendo do SO a função strlwe não existe */
char *strlwr(char *string)
{
    strcpy(string, string);
    for (size_t i = 0; i < strlen(string); i++)
    {
        string[i] = tolower(string[i]);
    }
    return string;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    const char text[] = "Banana";
    char textUper[strlen(text)];
    char textLower[strlen(text)];

    strcpy(textUper, text);
    strcpy(textLower, text);

    struper(textUper);
    strlwr(textLower);

    printf("Frase(%ld): \"%s\"\n", strlen(text), text);
    printf("Maiusculo: \"%s\"\n", textUper);
    printf("Minusculo: \"%s\"\n", textLower);
    printf("Compare \"%s\" com \"%s\" = %d\n", "Banana", text, strcmp("Banana", text));
    return 0;
}
