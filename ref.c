#include <stdio.h>

int soma(int *n1, int *n2)
{
    return *n1 + *n2;
}

int main(int argc, char const *argv[])
{
    int n1 = 5, n2 = 7;
    printf("%d", soma(&n1, &n2));
    return 0;
}
