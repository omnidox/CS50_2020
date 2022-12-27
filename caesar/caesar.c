#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string s = argv[1];

    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if ((isdigit(s[i]) == false))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    

    
    
    string a = get_string("Plaintext: ");
    
    
    string b = a;
    
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (isupper(a[i]))
        {
            b[i] = ((((a[i] - 65) + atoi(argv[1])) % 26) + 65);
        }
        else if (islower(a[i]))
        {
            b[i] = ((((a[i] - 97) + atoi(argv[1])) % 26) + 97);
        }
        else
        {
            b[i] = a[i];
        }
    }    
    
    printf("ciphertext: ");
    for (int i = 0, n = strlen(b); i < n; i++)
    {
        printf("%c", b[i]);
    }
    printf("\n");
    
    
}