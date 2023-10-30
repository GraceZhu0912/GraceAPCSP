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
        printf("Usage: ./substitution key");
        return 1;
    }

string key = argv[1];
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    int k;
    int c;
    int count;
    for (k = 0; k < 26; k++)
    {
        count = 0;
        if (isalpha(key[k]))
        {
            /*
            for (c = 0; c < 26; c++)
            {
                if (isupper(key[k]))
                {
                    if (key[k] == (65 + c))
                    {
                        count += 1;
                    }
                }

                if (islower(key[k]))
                {
                    if (key[k] == (97 + c))
                    {
                        count += 1;
                    }
                }
            }
            */
           for (c = 0; c < 26; c++)
           {
                if ((key[k] == islower(key[c])) || (key[k] == isupper(key[c])))
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
        else
        {
        printf("Key must contain 26 characters.");
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