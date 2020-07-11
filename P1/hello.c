#include <stdio.h>
#include <cs50.h>

//Customized "hello, world" program
int main(void)
{
    //Gets name of user
    string name = get_string("What is your name?\n");
    //Prints customized "hello, world"
    printf("hello, %s\n", name);
}