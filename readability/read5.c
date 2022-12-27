#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to count words in string
int count_words(string a);

int main(void)
{
    
    string s = get_string("Input:  ");

    int words = count_words(s);


    printf("\n");

    printf("%i\n", words);


}
    




// function to count words in string
int count_words(string a)
{
    int words = 0;
    
    if ((isblank(a[0]) != true))
    {
        words++;
    }
    
    for (int i = 0, n = strlen(a); i < n ; i++)
    {
            if (a[i] == ' ' && isalpha(a[i+ 1]))
            {
                words++;
            }

            printf("%c", a[i]);
    }
    return words;
}