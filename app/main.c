#include <stdio.h>

#include "myfunc.h"

int main()
{
    float x1, x2; int flag;
    discriminant(9, 6, 1, &x1, &x2, &flag);
    printf("x1 = %.2f, x2 = %.2f, ошибка = %d\n", x1, x2, flag);
}
