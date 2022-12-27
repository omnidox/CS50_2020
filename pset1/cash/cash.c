#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float dollars = get_positive_float();



    int cents = round(dollars * 100);

    int quarters = floor(cents / 25);




    int rcentsq = cents % 25;

    int dimes = floor(rcentsq / 10);



    int rcentsd = rcentsq % 10;

    int nickels = floor(rcentsd / 5);





    int rcentsn = rcentsq % 5;

    int pennies = floor(rcentsn / 1);




    int totcoins = quarters + dimes + nickels + pennies;

    printf("%i\n", totcoins);




}


// Prompt user for positive integer
float get_positive_float(void)
{
    float n;
    int p;
    do
    {
        n = get_float("Cash Input ");
        p = round(n * 100);
    }
    
    while (p < 1);
    
    return n;
}