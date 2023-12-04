#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
        //printf("%s", candidates[i].name);
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    /*
    sort the candidates in order of their votes
    take the highest
    if more than 1 has the same vote
        print all

    */
   candidate temp;
   int highest;

   for (int j = 0; j < candidate_count; j++)
   {
        for (int k = 0; k < candidate_count; k++)
        {
            if (candidates[k].votes < candidates[k+1].votes)
            {
                temp = candidates[k];
                candidates[k] = candidates[k+1];
                candidates[k+1] = temp;
            }
        }
   }

    highest = candidates[0].votes;
    printf("%s\n", candidates[0].name);
    for (int c = 1; c < candidate_count; c++)
    {
        if (candidates[c].votes == highest)
        {
            printf("%s\n",candidates[c].name);
            printf("%i\n",candidates[c].votes);

        }
    }

}