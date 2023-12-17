#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

bool check_pair(int c1, int c2);
bool check_lock(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO


    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name,candidates[i]) == 0)
        {
                ranks[rank] = i; // the index of the candidate since ranks only accpet int

                //printf("hello");
                //printf("%i\n",i); //test
                return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // for every candidate, update their preference to all the ones after it
    int current;
    int next;
    for (int i = 0; i < candidate_count; i++)
    {
        current = ranks[i];
        for (int j = candidate_count - i - 1; j > 0; j--) // no. of candidadte after current
        {
            next = ranks[candidate_count - j];
            preferences[current][next] += 1;
            printf("preference[%i][%i] = %i\n", current, next, preferences[current][next]);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        // printf("\n\n%i\n",i);
        for (int j = 0; j < candidate_count; j++)
        {
            if (check_pair(i,j))
            {
                // printf("overall\n");
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    // printf("first condidtion\n");
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    // printf("second condidtion\n");
                }

                // printf("pairs %ith is: [%i][%i]\n", pair_count, pairs[pair_count].winner, pairs[pair_count].loser);
                pair_count += 1;
            }
        }
    }
    return;
}
bool check_pair(int c1, int c2) // function, getting candidate 1 and 2 from preference
{
    if (preferences[c1][c2] == preferences[c2][c1]) // check if there is a winner or not
    {
        // printf("no preference %i %i\n\n", c1, c2);
        return false;
    }

    for (int i = 0; i < pair_count; i++) // check for existing pairs
    {
        if (((pairs[i].winner == c1) && (pairs[i].loser == c2)) || ((pairs[i].loser == c1) && (pairs[i].winner == c2)))
        {
            // printf("exists %i %i\n\n", c1, c2);
            return false;
        }
    }

    return true; // add new pair
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair temp;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[i+1].winner][pairs[i+1].loser])
            {
                temp = pairs[i];
                pairs[i] = pairs[i+1];
                pairs[i+1] = temp;
            }
        }
    }

/*
    for (int c = 0; c < pair_count; c++)
    {
        printf("%i is %i,%i\n", c, pairs[c].winner, pairs[c].loser);
        printf("p = %i\n",preferences[pairs[c].winner][pairs[c].loser]);
    }
*/
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    int winner;
    int loser;
    for (int i = 0; i < pair_count; i++) //for every pair
    {
        winner = pairs[i].winner; //set the winner and loser
        loser = pairs[i].loser;

        if (check_lock(winner,loser))
        {
            locked[pairs[i].loser][pairs[i].winner] = true;
        }

        if (!check_lock(winner,loser))
        {
            printf("cycled, winner is %i, loser is %i",winner, loser);
        }
    }
    return;
}

bool check_lock(int winner, int loser)
{
    if (locked[winner][loser == true])
    {
        return false;
    }

    for (int i = 0; i < pair_count; i++) // for every 'loser' that goes into the loop
    {
        if (locked[i][loser] == true)
        {
            winner = loser;
            loser = i;
            check_lock(winner, loser);
        }
    }
    return true;
}


// Print the winner of the election
void print_winner(void)
{
    // TODO
    bool pointed[candidate_count];
    for (int set = 0; set < candidate_count; set++)
    {
        pointed[set] = false;
    }
    int winner;
    for (int i = 0; i < candidate_count; i++) // for every potential winner
    {
        winner = i;
        for (int j = 0; j < candidate_count; j++) // check if they are locked by another candidate
            if (locked[winner][j] == true)
            {
                pointed[i] = true;
            }
        printf("%s",candidates[winner]);
        return;
    }
}
