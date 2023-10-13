// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string word = get_string();
    int character;
    int length = strlen(word);

    for (character = 0; character < length; character++)
    {
        switch (word[character])
        {
            case 'a':
                word[character] = '6';
                printf("a");
                break;
            case 'e':
                word[character] = '3';
                break;
            case 'i':
                word[character] = '1';
                break;
            case 'o':
                word[character] = '0';
                break;
        }
    }
    printf("%s",word);
}
