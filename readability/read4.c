#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int words = 0;

    string s = get_string("Input:  ");

    printf("Output: ");

   if (isalpha(s[0]))
   {
       words++;
   }

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
            if (s[i] == ' ' && isalpha(s[i+ 1]))
            {
                words++;
            }

            // alternative:  isalpha(s[i]) ? letters++ : letters ;
            printf("%c", s[i]);
    }


     printf("\n");

    printf("%i\n", words);

}