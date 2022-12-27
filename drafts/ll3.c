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

    node *list =  malloc(sizeof(node));
    node *n = NULL;
    node *current = NULL;
    for (int i = 0; i < 3; i++)
    {
     
     current = list;
     
     
 
    
    
     while (current->next != NULL) 
     {
        current = current->next;
     }
     
    current->next = (node *) malloc(sizeof(node));
    current->next->number = i + 1;
    current->next->next = NULL;
    
    
    }
    
   




    // Print list
    for (node *tmp = list->next; tmp != NULL; tmp = tmp->next)
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