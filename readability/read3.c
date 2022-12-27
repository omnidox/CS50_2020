#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to count characters in string
int count_letters(string a);

int main(void)
{
    string s = get_string("Input:  ");

    int letters = count_letters(s);

    printf("Output: ");

    printf("\n");

    printf("%i\n", letters);


}














// my function for counting letters


int count_letters(string a)
{
    int letters = 0;

    for (int i = 0, n = strlen(a); i < n ; i++)
    {
            if (isalpha(a[i]))
            {
                letters++;
            }
            // alternative:  isalpha(a[i]) ? letters++ : letters ;
    }
    return letters;
}