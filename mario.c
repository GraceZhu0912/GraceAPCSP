#include <cs50.h>
#include <stdio.h>

void repeat (char input , int count )
{
    for (int i=0; i != count; i++ )
    {
        printf("%c", input);
    }
}

int main(void){

    int height = 1;

    do {
        height = get_int("Height: ");
    } while (height <1 || height > 8);

    int line;
    int space;

    for (line = 1; line <= height; line++) {

        space = height - line;

        repeat (' ',space);
        repeat ('#',line);
        printf("  ");
        repeat ('#',line);
        printf("\n");

    }

}