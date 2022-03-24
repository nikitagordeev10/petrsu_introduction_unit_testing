#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "myfunc.h"

int myfunc(int b) {
    char *buffer = malloc(sizeof(char) * 1000);
    buffer [0] = b + 4;
    // здесь должен ругаться sonarcloud, т.к. утечка памяти
    return buffer[0];
}

int val;

int fibonachi(int num) {
    int prev = 1;
    int next = 1;

    if (num < 0)
        return 0;

    if (num <= 2)
        return num;

    int i = 2;
    while (i < num) {
        next += prev;
        prev = next - prev;
        i++;
    }

    return next;
}

void discriminant(float a, float b, float c, float* x1, float* x2, int* flag) {
  float discriminant;
  *flag = 0;

  discriminant = pow(b, 2) - 4 * a * c;
  if (discriminant > 0) {
      *x1 = (-b - sqrt(discriminant)) / (2 * a);
      *x2 = (-b + sqrt(discriminant)) / (2 * a);
  }
  else
    if (discriminant == 0) {
        *x1 = *x2 = -b/(2 * a);
    }
    else
        *flag = 1;
}

void viet(float a, float b, float c, float* vx1, float* vx2, int* vflag) {
    *vflag = 1;
    *vx1 = c / a;
    *vx2 = c / a;
    if (c / a >= 0)
        for (; *vx2 >= -c / a; *vx2 -= 0.1) {
            *vx1= (c / a) / (*vx2);
            if (*vx1 + *vx2 == -b / a) {
                *vflag = 0;
                break;
            }
        }
    else
        for (; *vx2 <= -c / a; *vx2 += 0.1)
        {
            *vx1= (c / a) / (*vx2);
            if (*vx1 + *vx2 == -b / a) {
                *vflag = 0;
                break;
            }
        }
}

void printStdoutMessages() {
    printf("This is a test message from myfunc.c\n");
    printf("Do not disturb\n");
}
