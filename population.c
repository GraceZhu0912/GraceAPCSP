#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = get_int("input the initial number of llamas, this has to be equal or bigger than 9: " );
    while (start < 9)
    {
        start = get_int("enter again, the number just inputed was smaller than 9. Try again: ");
    }
    // TODO: Prompt for end size
    int end = get_int("input the final number of llamas wanted, this should be bigger than your initial number of llamas: ");
    while (end <= start)
    {
        end = get_int("the number just inputed was equal or smaller than the initial number of llama. Try again: ");
    }
    // TODO: Calculate number of years until we reach threshold
    int current = start;
    int years = 0;
    while (current < end)
    {
        current = current / 3 + current - current / 4;
        years += 1;

    }
    return years;
    // TODO: Print number of years
    printf("years: %i\n",years);

}
