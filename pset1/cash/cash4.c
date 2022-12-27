#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float t = get_positive_float();



    int cents = round(t);

    int quarters = floor(cents / 25);

    printf("%i\n",quarters);



    int rcentsq = cents % 25;

    int dimes = floor(rcentsq / 10);

    printf("%i\n",dimes);


    int rcentsd = rcentsq % 10;

    int nickels = floor(rcentsd / 5);

    printf("%i\n",nickels);



    int rcentsn = rcentsq % 5;

    int pennies = floor(rcentsn / 1);

    printf("%i\n",pennies);



    int totcoins = quarters + dimes + nickels + pennies;

    printf("%i\n",totcoins);




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