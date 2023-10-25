#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("enter the name of the program and the key of encryption");
        return 1;
    }
    
    int j;
    for (j=0; j < strlen(argv[1]); j++)
    {
        if ((argv[1][j] < 48) || (argv[1][j] > 57))
            {
                return 2;
            }
    }

    string message = get_string("plaintext: ");
    int key = atoi(argv[1]);
    key = key%26;
    int i;
    char ascii;

    for (i = 0; i<strlen(message); i++)
    {
        if (isalpha(message[i]))
        {
            ascii = message[i]+key;
            if (islower(message[i]))
            {
                    ascii = ((ascii - 97) % 26) + 97;
            }
            else if (isupper(message[i]))
            {
                    ascii = ((ascii - 65) % 26) + 65;
            }
            message[i] = ascii;
        }
    }
    printf("ciphertext: %s\n", message);
}