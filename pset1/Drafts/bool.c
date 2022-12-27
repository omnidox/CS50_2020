#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool Divisible(int a, int b);

int main(void)
{

int a = get_int("first number: ");

printf("divided by\n");

int b = get_int("second number: ");

bool x = Divisible(a,b);

printf("%s", x ? "true\n" : "false\n");

}


// alternative print methods


// printf(x ? "true" : "false");


// printf("%s", x ? "true" : "false");

// fputs(x ? "true" : "false", stdout);






bool Divisible(int a, int b)

{
    return (a % b) == 0;
}