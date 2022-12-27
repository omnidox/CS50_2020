// Implements a list of numbers with linked list

#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // List of size 0

    node *list = NULL;
    node *n = NULL;
    for (int i = 0; i < 3; i++)
    {

         // Add number to list
      n = malloc(sizeof(node));
      if (n == NULL)
      {
          return 1;
      }
      n->number = i + 1;
      n->next = NULL;
      
      n->next = list;
      list = n;

    }




    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}