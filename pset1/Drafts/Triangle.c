#include <cs50.h>
#include <stdio.h>
#include <math.h>



bool valid_triangle(float l,float w,float h);

int main(void)
{

    // Get sides
    int sides[3];
    for (int i = 0; i < 3; i++)
    {
        sides[i] = get_int("Side %i: ", i + 1);
    }

    // Print average
    printf("Average: %.1f\n", average(n, scores));
    
}


// Prompt user for postive numbers for sides of triangle
bool valid_triangle(float l,float w,float h)
{
    float n;
    int p;
    do
    {
        n = get_float("First Side ");
        p = round(n * 100);
    }
    
    while (p < 1);
    
    
    do
    {
        n = get_float("Secoond Side ");
        p = round(n * 100);
    }
    
    while (p < 1);
    
    
    do
    {
        n = get_float("Third side ");
        p = round(n * 100);
    }
    
    while (p < 1);
    
    return n;
}