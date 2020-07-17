#include <stdio.h>
#include <cs50.h>

//Mario pyramid generator program
int main(void)
{
    //Gets height of pyramid from user, prompts user till input is between 1-8 inclusive
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    //Prints n number of rows
    for (int i = 0; i < n; i++)
    {
        //Prints n-i-1 number of spaces at the beginning of each row
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        //Prints i+1 number of #s for left side of pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        //Prints 2 spaces (constant)
        printf("  ");

        //Prints i+1 number of #s for right side of pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}