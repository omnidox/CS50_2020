#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float t = get_positive_float();



    int cents = round(t);
    
    cents = cents % 5;

    printf("%i\n", cents);
    
    
    
    
}



    // Prompt user for positive integer
float get_positive_float(void)
{
    float n;
    do
    {
        n = get_float("Cash Input ");
    }
    while (n < .1);
    return n;
}