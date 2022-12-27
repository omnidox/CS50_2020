#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to count sentences
int count_sentences(string a);

int main(void)
{
    string s = get_string("Input:  ");

    int sentences = count_sentences(s);

    printf("Output: ");

    printf("\n");

    printf("%i\n", sentences);


}














// my function for counting sentences


int count_sentences(string a)
{
    int sentences = 0;

    for (int i = 0, n = strlen(a); i < n ; i++)
    {
            if (a[i] == '.' || a[i] == '?' || a[i] == '!' )
            {
                sentences++;
            }
    }
    return sentences;
}