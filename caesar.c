#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    int j;
    for (j=0; j < strlen(argv[1]); j++)
    {
        if ((argv[1][j] < 48) || (argv[1][j] > 57))
            {
                return 1;
            }
    }

    string message = get_string("plaintext: ");

    int i;
    int ascii;
    int key = atoi(argv[1]);
    for (i = 0; j < strlen(message); i++)
    {
        ascii = message[i];

        if (isalpha(message[i]))
        {
            ascii += key;
            if (isupper(message[i]))
            {
                ascii = ((ascii - 65) % 26) + 65;
            }
            else if (islower(message[i]))
            {
                ascii = ((ascii - 97) % 26) + 97;
            }
        }
        message[i] = ascii;
    }
    printf("ciphertext: %s", message);

}