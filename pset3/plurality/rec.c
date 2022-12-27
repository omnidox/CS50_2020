#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// function for factorials
int fact(int a);

int main(void)

{
    int s = get_int("Integer:  ");

    int result = fact(s);

    printf("%i\n", result);
}






// function for factorials

int fact(int a)
{
   if (a==1)
   return 1;
   else 
   return a * fact(a-1);
}


