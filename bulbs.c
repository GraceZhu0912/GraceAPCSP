#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
get the message
convert the message to ASCII num
for every character
    get the remainder when divided by 2, 8 times
        directly print the corresponding bulbs by the functions
    change line
light the bulbs using for loop*/

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message:");
    int num = 0;
    int i;
    int j;
    int k;
    int binary[8];

    for (i = 0; i < strlen(message); i++)
    {
        num = message[i];
        //printf("total num = %i\n", num);
        //printf("character = %c\n",message[i]);

        for (j = 0; j < BITS_IN_BYTE; j++)
        {
            binary[i] = num%2;
            num = num/2;
            //printf("current binary = %i\n",binary[8-i]);
            //printf("num = %i",num);
        }

        for (k = 0; k< BITS_IN_BYTE; k++)
        {
            printf("%i ",binary[k]);
            //print_bulb(binary[k]);
        }
        printf("\n\n");
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
