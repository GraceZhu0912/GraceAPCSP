#include <cs50.h>
#include <stdio.h>
#include <math.h>

// get the credit card number
// plug the numbers in the formula
//  use a for loop to calculate the sum of the ones that are * 2
// add the rest

int main(void)
{
    long original = get_long("Number: ");
    int length = floor(1+log10(original));
    //printf("length = %i\n", length);
    int sum = 0;
    int counter = 0;
    int digit;
    //printf("number = %ld and length = %i\n",number,length);
    long number = original;
    //printf("o %ld ",original);
    while (number > 0)
    {
        //digit =(number / (int)(pow(10,counter))) % (int)(pow(10,counter + 1));
        digit = number%10;
        sum = sum + digit;
        number = number / 10;
        counter += 1;
        //printf("sum = %i, digit = %i, number = %ld, counter = %i\n",sum, digit, number, counter);

        //digit = (number / (int)(pow(10,counter))) % (int)(pow(10,counter + 1));
        digit = (number % 10) * 2;
        if(digit>9)
        {
            digit = (digit / 10) + (digit %10);
        }
        sum = sum + digit;
        number = number / 10;
        counter += 1;
        //printf("sum = %i, digit = %i, number = %ld, counter = %i\n",sum, digit, number, counter);
        //printf("\n");
    }

    //printf("sum = %i",sum);
    if (sum % 10 == 0)
    {
        //printf("or = %ld",original);
        long first_digit = original/(long)(pow(10,length-1));
        long second_digit = original/(long)(pow(10,length-2)) % 10;

        //printf("first digit = %ld, second digit = %ld",first_digit,second_digit);

        if (length == 15 && first_digit == 3 && (second_digit == 3 || second_digit == 7))
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