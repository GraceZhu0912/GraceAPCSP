#include <cs50.h>
#include <stdio.h>
#include <math.h>

// get the credit card number
// plug the numbers in the formula
//  use a for loop to calculate the sum of the ones that are * 2
// add the rest

int main(void)
{
    long number = get_long("Number: ");
    int length = floor(1+log10(number));
    int sum = 0;
    int counter = 0;
    int digit;
    //printf("number = %ld and length = %i\n",number,length);

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
            digit = digit / 10 + digit %10;
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
        int first_digit = number/(int)(pow(10,length-1));
        int second_digit = number/(int)(pow(10,length-2)) % 10;
        //printf("first digit = %i, second digit = %i",first_digit,second_digit);

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