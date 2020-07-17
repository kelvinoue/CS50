#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//Substitution cipher encryption program
int main(int argc, string argv[])
{
    //Terminates program if key is not entered correctly via command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution <key>\n");
        return 1;
    }

    //Terminates program if key is not 26 characters long
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //Terminates program if key is not alphabetic
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    //Terminates program if key contains duplicate characters (case insensitive)
    int count[26] = {0};
    for (int i = 0, j = strlen(argv[1]); i < j; i++)
    {
        for (int k = 0; k < 26; k++)
        {
            if (tolower(argv[1][i]) == k + 97)
            {
                count[k]++;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }


    //Gets plaintext input from user
    string text = get_string("plaintext: ");

    //Encrypts plaintext to ciphertext
    //Goes over each char of plaintext
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        //Checks whether it is alphabetical, if yes, encrypts it
        if (isalpha(text[i]) != 0)
        {
            //Checks which # of the alphabet the char is, and replaces it with the #th char in the key
            for (int k = 0; k < 26; k++)
            {
                if (text[i] == k + 65)
                {
                    text[i] = toupper(argv[1][k]);
                    //Breaks out of the loop once original char is replaced, prevents further changes due to the loop
                    break;
                }
                else if (text[i] == k + 97)
                {
                    text[i] = tolower(argv[1][k]);
                    //Breaks out of the loop once original char is replaced, prevents further changes due to the loop
                    break;
                }
            }
        }
    }

    //Prints ciphertext
    printf("ciphertext: %s\n", text);
    return 0;
}