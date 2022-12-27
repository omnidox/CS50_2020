#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

int main(void)
{
    int t = get_positive_int();
    printf("%i\n", t);
}



  for (int i = 0; i < t; i++)
  {
      for (int j = 0; j < t; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}


// Prompt user for positive integer
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Positive Integer, between 1 to 8 inclusive: ");
    }
    while (n < 1 || n > 8);
    return n;
}