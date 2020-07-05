#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Declares var of type int, n
    int n;
    //Prompts user for input between 1 to 8 inclusive, repeats until condition met
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //Print n number of rows
    for (int i = 0; i < n; i++)
    {
        //Prints n-i-1 number of spaces at the beginning of each row
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        //Prints i+1 number of #s for left side of pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        //Prints 2 spaces (constant)
        printf("  ");
        //Prints i+1 number of #s for right side of pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}