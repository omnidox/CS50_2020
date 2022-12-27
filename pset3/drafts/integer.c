#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    float a = get_float("first number: ");
    float b = get_float("second number: ");
    int c = round(a/b);
    printf("%f divided by %f is %i \n", a,b,c);
}