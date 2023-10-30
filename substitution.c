#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
check for input
get the text
conver the text to its position in alphabet
find corresponding alphabet in key
swap
print
*/
int main(int argc, string argv[])
{
    if (argc != 2)
    // check input
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    string key = argv[1];
    if (strlen(argv[1]) != 26)
    // check key length
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    int d;
    for (d = 0; d < 26; d++)
    // check if all is aphabet
    {
        if (isalpha(key[d]))
        {
        }

        else
        {
            printf("Key must contain all aphabets.");
            return 1;
        }
    }

    int k;
    int c;
    int count;
    for (k = 0; k < 26; k++)
    // check overlap alphabet
    {
        count = 0;
        for (c = 0; c < 26; c++)
        {
            if (key[c] == key[k])
            {
                count += 1;
            }
        }

        if (count != 1)
        {
            printf("characters in key must not overlap");
            return 1;
        }
    }

    string text = get_string("plaintext: ");
    int position;
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            position = text[i] - 97;
            text[i] = key[position];
            text[i] = tolower(text[i]);
        }

        else if (isupper(text[i]))
        {
            position = text[i] - 65;
            text[i] = key[position];
            text[i] = toupper(text[i]);
        }
    }

    printf("ciphertext: %s\n", text);
}