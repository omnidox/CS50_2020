#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


// function to count characters in string
int count_letters(string a);

// function to count words in string
int count_words(string a);

// function to count sentences
int count_sentences(string a);

int main(void)

{
    string s = get_string("Text:  ");

    int letters = count_letters(s);

    int words = count_words(s);

    int sentences = count_sentences(s);

    float L = (((float) letters / (float) words) * 100);

    float S = (((float)sentences / (float) words) * 100);

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

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
        if (a[i] == ' ' && (isblank(a[i + 1]) != true))
        {
            words++;
        }
    }
    return words;
}









// my function for counting sentences


int count_sentences(string a)
{
    int sentences = 0;

    for (int i = 0, n = strlen(a); i < n ; i++)
    {
        if (a[i] == '.' || a[i] == '?' || a[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}

