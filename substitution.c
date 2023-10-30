#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
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
    {
        printf("you need both program name and key");
        return 1;
    }
    string key = argv[1];
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
        }

    }
    printf("ciphertext: %s", text);
}