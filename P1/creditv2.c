#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Credit card verification program
int main(void)
{
    //Gets credit card number from user
    long n;
    n = get_long("Number: ");

    //Calculates checksum
    //Gets digits (#1-16)
    int digit[16] = {0};
    for (int i = 0; i < 16; i++)
    {
        digit[i] = n % (long) pow(10, (16 - i)) / (long) pow(10, (15 - i));
    }

    //For each digit (#1,3,5,7,9,11,13,15), multiplies it by 2 and gets the sum of the resulting digits
    int ddigit[8] = {0};
    for (int j = 0; j < 8; j++)
    {
        ddigit[j] = (digit[j * 2] * 2 % 10) + (digit[j * 2] * 2 % 100 / 10);
    }

    //Gets sum of multiplied digits (#1,3,5,7,9,11,13,15) plus the sum of digits #2,4,6,8,10,12,14,16
    int sum = 0;
    for (int k = 0; k < 8; k++)
    {
        sum = sum + digit[k * 2 + 1] + ddigit[k];
    }

    //Final step of checksum
    int csum = sum % 10;

    //Checks for card length, starting digits, and checksum
    //For 16 digit cards
    if (n > 999999999999999 && n < 10000000000000000)
    {
        //For VISA (4)
        if (csum == 0 && digit[0] == 4)
        {
            printf("VISA\n");
        }
        //For MASTERCARD (51-55)
        else if (csum == 0 && digit[0] == 5 && digit[1] > 0 && digit[1] < 6)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //For 15 digit cards
    else if (n > 99999999999999 && n < 1000000000000000)
    {
        //For AMEX (34,37)
        if (csum == 0 && digit[1] == 3)
        {
            if (digit[2] == 4 || digit[2] == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //For 13 digit cards
    else if (n > 999999999999 && n < 10000000000000)
    {
        //For VISA (4)
        if (csum == 0 && digit[3] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}