#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//get string

// calculate number of sentence, letters, and word --> write a funciton

//go back to main program
//index = 0.0588 * L - 0.296 * S - 15.8
// do roundings

void find(string text);

int letter = 0;
int word = 0;
int sentence = 0;

int main(void)
{
    string text = get_string("Text:");
    find(text);
    //printf("%i,%i,%i",letter,word,sentence);

    float L = (letter/word)*100;
    float S = (sentence/word)*100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("L = %f, S = %f, index = %f",L,S,index);

    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        index = round(index);
        printf("Grade %i",(int)index);
    }
}

void find(string text)
{
    int i = 0;
    for (i = 0; i<strlen(text); i++)
    {
        if (((text[i] >= 65) && (text[i] <= 90)) || ((text[i] >= 97) && (text[i] <= 122)))
            letter += 1;
        else if (text[i] == 32)
            word += 1;
        else if (text[i] == 33 || text[i] == 44 || text[i] == 63)
            sentence += 1;
    }
    word += 1;
}