#include <cs50.h>
#include <stdio.h>
#include <math.h>

// get the credit card number
// plug the numbers in the formula
//  use a for loop to calculate the sum of the ones that are * 2
// add the rest

int main(void)
{
    long number = get_int("Number: ");
    int length = floor(1+log10(number));
    int sum = 0;
    int counter = 0;

    while (number > 0)
    {
        sum = sum + ((number / (int)(pow(10,counter))) % (int)(pow(10,counter + 1)));
        number = number / 10;
        counter += 1;
        sum = sum + (((number / (int)(pow(10,counter))) % (int)(pow(10,counter + 1))))*2;
        number = number / 10;
    }

    if (sum % 10 == 0)
    {
        int first_digit = number/(int)(pow(10,length-1));
        int second_digit = number/(int)(pow(10,length-2)) % 10;
        
        if (length == 15)
        {
            printf("AMEX\n");
        }
        else if (length == 16 && first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 14 || length == 15 || length == 16 )&& first_digit == 4)
        {
            printf("VISA\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}