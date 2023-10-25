#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("enter the name of the program and the key of encryption");
        return 1;
    }

    string message = get_string("plaintext: ");
    int key = argc;
    int i;
    int ascii;

    for (i = 0; i<strlen(message); i++)
    {
        if ((message[i] > 'a') && (message[i] < 'z'))
        {
            ascii = message[i];
            ascii += key;
            if (ascii > 'z')
            {
                ascii = ascii%26;
            }
            message[i] = ascii;

        }
    }
    printf("ciphertext: %s \n", message);
}