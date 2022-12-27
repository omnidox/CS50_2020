// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>

#define BASE (256)

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
//number of words in dictionary
unsigned int num_words = 0;
// Number of buckets in hash table, chose a prime number

//285569 as another working num
const unsigned int N = 17851;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int hash_chk = hash(word);
    for (node *tmp = table[hash_chk]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // hash division method taken from https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29. Sorry Harvard!
    unsigned long h;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) word;

    h = 0;
    while (*us != '\0')
    {
        h = (h * BASE + tolower(*us)) % N;
        us++;
    }

    return h;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    char word[LENGTH + 1];
    FILE *rfile = fopen(dictionary, "r");

    if (!rfile)
    {
        printf("no file found\n");
        return false;
    }



    while ((fscanf(rfile, "%s", word)) != EOF)
    {

        // add total words in dictionary
        num_words++;

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, word);

        int hash_num = hash(word);

        n -> next = table[hash_num];
        table[hash_num] = n ;
    }

    fclose(rfile);

    return true;



}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return num_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }
    return true;
}
