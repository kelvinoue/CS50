#include <stdio.h>
#include <cs50.h>

//Credit card verification program
int main(void)
{
    //Gets credit card number from user
    long n;
    n = get_long("Number: ");

    //Calculates checksum
    //Gets digit #1,3,5,7,9,11,13,15 (top to bottom)
    int d01 = n % 10000000000000000 / 1000000000000000;
    int d03 = n % 100000000000000 / 10000000000000;
    int d05 = n % 1000000000000 / 100000000000;
    int d07 = n % 10000000000 / 1000000000;
    int d09 = n % 100000000 / 10000000;
    int d11 = n % 1000000 / 100000;
    int d13 = n % 10000 / 1000;
    int d15 = n % 100 / 10;
    //Gets digit #2,4,6,8,10,12,14,16 (top to bottom)
    int d02 = n % 1000000000000000 / 100000000000000;
    int d04 = n % 10000000000000 / 1000000000000;
    int d06 = n % 100000000000 / 10000000000;
    int d08 = n % 1000000000 / 100000000;
    int d10 = n % 10000000 / 1000000;
    int d12 = n % 100000 / 10000;
    int d14 = n % 1000 / 100;
    int d16 = n % 10;
    //For each digit (#1,3,5,7,9,11,13,15), multiplies it by 2 and gets the sum of the resulting digits
    int a = (d01 * 2 % 10) + (d01 * 2 % 100 / 10);
    int b = (d03 * 2 % 10) + (d03 * 2 % 100 / 10);
    int c = (d05 * 2 % 10) + (d05 * 2 % 100 / 10);
    int d = (d07 * 2 % 10) + (d07 * 2 % 100 / 10);
    int e = (d09 * 2 % 10) + (d09 * 2 % 100 / 10);
    int f = (d11 * 2 % 10) + (d11 * 2 % 100 / 10);
    int g = (d13 * 2 % 10) + (d13 * 2 % 100 / 10);
    int h = (d15 * 2 % 10) + (d15 * 2 % 100 / 10);
    //Gets sum of (a to h) plus the sum of digit #2,4,6,8,10,12,14,16
    int i = a + b + c + d + e + f + g + h;
    int j = d02 + d04 + d06 + d08 + d10 + d12 + d14 + d16;
    int k = i + j;
    int csum = k % 10;

    //Checks for card length, starting digits, and checksum
    //For 16 digit cards
    if (n > 999999999999999 && n < 10000000000000000)
    {
        //For VISA (4)
        if (csum == 0 && d01 == 4)
        {
            printf("VISA\n");
        }
        //For MASTERCARD (51-55)
        else if (csum == 0 && d01 == 5 && d02 > 0 && d02 < 6)
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
        if (csum == 0 && d02 == 3)
        {
            if (d03 == 4 || d03 == 7)
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
        if (csum == 0 && d04 == 4)
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
