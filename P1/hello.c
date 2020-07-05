#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Gets name of user
    string name = get_string("What is your name?\n");
    //Prints customized hello
    printf("hello, %s\n", name);
}