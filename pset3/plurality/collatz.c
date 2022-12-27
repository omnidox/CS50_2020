#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// function for collatz
int collatz(int a);

int main(void)

{
    int s = get_int("Integer:  ");

    int result = collatz(s);

    printf("number of steps for collatz is %i\n", result);
}






// function for factorials

int collatz(int a)
{
   if (a==1)
   return 0;

   else if ( (a % 2 ) == 0 )

   return 1 + collatz(a/2);

   else

   return 1 + collatz(3 * a + 1) ;

}


