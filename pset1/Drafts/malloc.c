#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 



int main(void)
{
    int *px = NULL;

    int *py = NULL;
    
    int *y = malloc(sizeof(int));

    *y = 1;

    int *x = y;

    int m = 4 ;

    x = &m;

    printf("x is %i\n y is %i\n ", *x, *y);
}

