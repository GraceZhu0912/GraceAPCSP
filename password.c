// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool up = false;
    bool low = false;
    bool num = false;
    bool symbol = false;
    int i;

    for (i = 0; i < strlen(password); i++)
    {
        if isupper(password[i])
        {
            up = true;
        }
        else if islower(password[i])
        {
            low = true;
        }
        else if isalnum(password[i])
        {
            num = true;
        }
        else if (password[i]<'A')
        {
            symbol = true;
        }
    }

    if (up&&low&&num&&symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}