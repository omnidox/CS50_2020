#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i < n + 1; i++)
    {
        t[i] = s[i];
    }
    
    for (int i = 0, n = strlen(s); i < n + 1; i++)
    {
        t[i] = toupper(t[i]);
    }

    

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}