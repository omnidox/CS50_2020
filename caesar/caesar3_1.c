#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void)
{

char c = get_char("put in a letter: ");

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
    printf("This is the letter %c\n", c);
    }
    else
    {
        printf("you did not type a letter!\n");
    }


}

