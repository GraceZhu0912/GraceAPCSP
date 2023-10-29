#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");

    int num;
    //the ascii code of EACH letter, this is in decimal

    int bin[8];
    //the list for the binary code

    int i;
    for (i = 0; i<strlen(message); i++)
    {
        num = message[i];
        //printf("%i ", message[i]);

        int j;
        for (j = 0; j<BITS_IN_BYTE; j++) //decimal to binary conversion
        {
            bin[j] = num%2;
            num = num/2;
            //printf("binary = %i ",bin[j]);

        }

        int k;
        for (k = BITS_IN_BYTE; k>=0 ;k--)
        {
            print_bulb(bin[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}