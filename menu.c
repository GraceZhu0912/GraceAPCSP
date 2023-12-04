#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE1 5000
#define SIZE2 10000
#define SIZE3 50000
int *readFile(string fileName, int size, int size2);  //pointer to return and int array
int linearSearch(int array[], int guess, int size);  //linear search
int binarySearch(int array[], int guess, int size);
void printArray(int array[], int size); // function to write the sorted array into a file
void Menu();
void writeArray(int array[], int size);

int main(void)
{
    // initiating global variables that may be used in different cases (sort, search, etc.)
    int choice = 0;
    string fileName;
    int size;
    int size2;
    int guess;
    char line[size];
    int array[size2][size];
    int temp;

    do
    {
    Menu();
    choice = get_int("Please enter your choice 1-5");
    switch (choice)
    {
        case 1: // read
            printf("option 1 choosen: read\n");

            fileName = get_string("file name: ");
            size = get_int("size: ");
            size2 = get_int("size2: ");
            readFile(fileName, size, size2);
            break;

        case 2: // sort
            printf("option 4 choosen: sort\n");

            fileName = get_string("file name: ");
            FILE *file = (fopen(fileName, "r"));
            if (!file)
            {
                printf("\n Unable to open : %s", fileName);
            }

            size = get_int("size: ");
            size2 = get_int("size2: ");

            for (int c = 0; c < size2; c++)
            {
                fscanf(file, "%d", array[c]);
            }
            fclose(file);

            int type_sort = get_int("\n1: bubble sort \n2: selection sort\n");
            switch (type_sort)
            {
            case 1: // bubble sort
                for (int j = 0; j < size; j++)
                {
                    for (int k = 0; k < size; k++)
                    {
                        if (array[j] > array[k])
                        {
                            temp = array[j];
                            array[j] = array[k]; //array type 'char[size]' is not assignable
                            array[k] = temp;
                        }
                    }
                }
                printArray(int array[], int size)
                break;

            case 2: // selection sort
                int indx = 0;
                for(int i = 0; i < size ; i++)
                {
                    int min = size + 1;
                    for(int j = i; j < size; j++)
                    {
                        if( array[j] < min)
                            {
                                min = array[j];
                                indx = j;
                            }
                    }
                        // make the swap
                        temp = array[i];
                        array[i] = min;
                        array[indx] = temp;
                }
                printArray(int array[], int size)
                break;
            }
            break;

        case 3: // search
            printf("option 3 choosen: search\n");

            fileName = get_string("file name: ");
            size = get_int("size: ");
            size2 = get_int("size2: ");
            FILE *file1 = (fopen(fileName, "r"));
            if (!file1)
            {
                printf("\n Unable to open : %s", fileName);
            }
            for (int d = 0; d < size2; d++)
            {
                fscanf(file, "%s", array[d]);
            }
            fclose(file1);

            guess = get_int("guess: ");

            int type_search = get_int("\n1: linear serach \n2: binary search\n");
            switch (type_search)
            {
            case 1: // linear search
                linearSearch(array[], guess,int size )
                break;

            case 2: // binary search
                int binarySearch(array[], guess, int size)
                break;
            }
            break;

        case 4: // create
            printf("option 4 choosen: create\n");
            size = get_int("size: ");
            sorted[] = array[];
            writeArray(int sorted[], int size)
            break;
    }
    } while(choice !=5);
}

int *readFile(string fileName, int size, int size2 )
    {
    FILE* file=(fopen(fileName, "r"));
    line[size2]; //how many characers per line
    options[size][size2];//array to put all the numbers from the file
    int  static numbers[SIZE2];  // file to be returned
    for (int i=0; i <size; i++)
    {
        fscanf(file, "%s", options[i]);
        // printf("%s \n", options[i]);
        numbers[i]= atoi(options[i]);
    }
    fclose(file);
    return numbers;
}

int linearSearch(int array[],int guess,int size )
{
    for(int i=0; i < size; i++)
    {
        if (array[i]== guess)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int array[], int guess, int size)
{
    bool found = false;
    int start = 0;
    int end = length;
    int middle = (start + end)/2;

    while (!found)
    {
        middle = (start + end)/2;
        printf("%i",middle);
        if (atoi(array[middle]) == guess)
        {
            printf("for binary search, the number is at %i", middle);
            found = true;
            return 0;
        }
        else if (atoi(array[middle]) > guess)
        {
            start = middle;
        }
        else
        {
            end = middle;
        }
    }
}

void Menu() //menu
{
 // This menu is just for reference. PLease create your own menu
 printf("=====================================\n");
 printf("#               MENU                #\n");
 printf("#              1.read               #\n");
 printf("#              2.create             #\n");
 printf("#              3.search             #\n");
 printf("#              4.sort               #\n");
 printf("#          enter 5 to exit          #\n");
 printf("=====================================\n");
}

void writeArray(int sorted[], int size) //create
{
    string name = get_string("How do you want to call your file? ");
    char filename[10];
    sprintf(filename, "%s.txt", name);
    FILE *file = fopen(filename, "w");

    for (int i=0; i < size; i++)
    {
        fprintf(file,"%d\n",sorted[i]);
    }
}

void printArray(int array[], int size) // print
{
    for (int i = 0; i < size; i++)
    {
        printf(" %i \n",array[i] );
    }
}
