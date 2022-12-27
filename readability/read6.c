#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int words = 0;

    string s = get_string("Input:  ");

    printf("Output: ");

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
            if (s[i] == '.' || s[i] == '?' || s[i] == '!' )
            {
                words++;
            }

            // alternative:  isalpha(s[i]) ? letters++ : letters ;
            printf("%c", s[i]);
    }


     printf("\n");

    printf("%i\n", words);

}