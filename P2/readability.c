#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Readability checker program
int main(void)
{
    //Gets text input from user
    string text = get_string("Text: ");

    //Initializes vars for letters(l), sentences(s) and words(w) to 0
    int l = 0;
    int s = 0;
    int w = 0;

    //Checks if first character in text is a letter, adds 1 to word count
    if (isalpha(text[0]))
    {
        w++;
    }
    //Checks if first character in text is a non-space char followed by a letter, adds 1 to word count
    else if (isgraph(text[0]) && isalpha(text[1]))
    {
        w++;
    }

    //Checks each character and counts the number of letters, sentences and words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //#1 Adds 1 to letter count if the current character is an uppercase or lowercase letter
        if (isalpha(text[i]))
        {
            l++;
        }

        //#2 Adds 1 to sentence count if the current character is a period, exclamation point, or question mark (no exception handling)
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }

        /*
        //#3 Adds 1 to word count if the current character is a space, followed by a non-space character after
        else if (text[i] == ' ' && isgraph(text[i+1]))
        {
            w++;
        }
        */

        //Alt #3 Adds 1 to word count if the current char is a space, followed by A) a letter, or B) a non-space char + letter after
        else if (text[i] == ' ' && isalpha(text[i + 1]))
        {
            w++;
        }
        else if (text[i] == ' ' && isgraph(text[i + 1]) && isalpha(text[i + 2]))
        {
            w++;
        }
    }

    //Calculates letters per 100 words (L), sentences per 100 words (S), index (index), and rounded index (rindex)
    float L = (float) l / (float) w * 100;
    float S = (float) s / (float) w * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rindex = round(index);

    //Prints readability checker results
    //Grades 1-15
    if (rindex > 0 && rindex < 16)
    {
        printf("Grade %i\n", rindex);
    }
    //Before Grade 1
    else if (rindex < 1)
    {
        printf("Before Grade 1\n");
    }
    //Grades 16+
    else if (rindex > 15)
    {
        printf("Grade 16+\n");
    }
}