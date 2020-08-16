#include <stdio.h>
#include <cs50.h>

//Mario pyramid generator program

//Prototype for 'draw'
void draw(int h);

//Initializes n (for height) and i (for row no.) to 0
int n = 0;
int i = 0;


int main(void)
{
    //Gets height of pyramid from user, prompts user till input is between 1-8 inclusive
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    draw(n);
}


void draw(int h)
{
    //Breaks when h reaches 0s
    if (h == 0)
    {
        return;
    }

    //Recursion
    draw(h - 1);

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
    i++;

}