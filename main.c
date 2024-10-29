#include <stdio.h>
#include "add.h"

int main()
{
    printf("hello\n");

    int a = 4;
    int b =5;
    int c = add(a,b);
    printf("c : %d\n", c);
}