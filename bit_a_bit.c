#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = -0b11111110;

    printf("x = %d", x);
    printf("\n");
    printf("~x = %d", ~x);
    printf("\n");

    x = (x >> 1);
    printf("x >> 1 = %d", x);
    printf("\n");
    printf("~x = %d", ~x);
    printf("\n");

    x = (x >> 1);
    printf("x >> 1 = %d", x);
    printf("\n");
    printf("~x = %d", ~x);
    printf("\n");

    x = (x >> 1);
    printf("x >> 1 = %d", x);
    printf("\n");
    printf("~x = %d", ~x);
    printf("\n");

    int value1 = 0b011, value2 = 0b101;
    printf("Or: %d | %d = %d\n", value1, value2, value1 | value2);

    printf("And: %d & %d = %d\n", value1, value2, value1 & value2);

    printf("Or exclusivo: %d ^ %d = %d\n", value1, value2, value1 ^ value2);

    /*
    No caso de estarmos trabalhando com portas em um circuito,
    em que cada porta é um bit, podemos usar a logica do and
    para detectar se essa porta esta ligada ou não */

    const int ports = 0b10100001;
    if (ports & (1 << 0))
        printf("A primeira porta esta ativada\n");

    if (ports & (1 << 1))
        printf("A segunda porta esta ativada\n");

    if (ports & (1 << 2))
        printf("A terceira porta esta ativada\n");

    if (ports & (1 << 3))
        printf("A quarta porta esta ativada\n");

    if (ports & (1 << 4))
        printf("A quinta porta esta ativada\n");

    if (ports & (1 << 5))
        printf("A sexta porta esta ativada\n");

    if (ports & (1 << 6))
        printf("A setima porta esta ativada\n");

    if (ports & (1 << 7))
        printf("A oitava porta esta ativada\n");

    0 == 0b000;
    1 == 0b001;
    2 == 0b010;
    3 == 0b011;
    4 == 0b100;
    5 == 0b101;
    6 == 0b110;
    7 == 0b111;

    return 0;
}
