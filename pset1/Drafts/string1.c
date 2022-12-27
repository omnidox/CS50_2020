#include <cs50.h>
#include <stdio.h>
#include <string.h>

float add(int a,int b,int c);

int main(void)
{
    float x = get_float("first number: ");
    
    float y = get_float("second number: ");
    
    float z = get_float("third number: ");
    
    printf("%.2f\n", add(x,y,z));
    
    printf("%.2f\n", x);
    
    printf("%.2f\n", y);
    
    printf("%.2f\n", z);
}

float add(int a,int b,int c)
{
    return a + b + c;
}