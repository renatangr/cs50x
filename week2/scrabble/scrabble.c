#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Inicialize the letters and values
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                      'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Inicialize array of scores
    int scores[3];

    // Get words from players

    string word[2]; // Inicialize the array of words

    word[0] = get_string("Player's 1 word: ");
    word[1] = get_string("Player's 2 word: ");

    // Compute the score of players
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0, lenght = strlen(word[i]); j < lenght; j++)
        {
            for (int k = 0; k < sizeof(letters); k++)
            {
                if (toupper(word[i][j]) == letters[k])
                {
                    scores[2] = scores[2] + values[k];
                    break;
                }
            }
        }

        scores[i] = scores[2];
        scores[2] = 0;
    }

    // Print the winner

    if (scores[0] > scores[1])
    {
        printf("Player 1 wins!\n");
    }
    else if (scores[1] > scores[0])
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
