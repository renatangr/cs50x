#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2) // Check if the command-line has only one argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (only_digits(argv[1]) == false) // Check if command-line is only digits
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

        char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                             'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        string plaintext = get_string("plaintext: "); // Get plaintext
        string ciphertext = plaintext;                // Initialize the ciphertext variable
        int length = strlen(plaintext);               // Calculate the lenght of the string
        int key = atoi(argv[1]);                      // Get the key
        int cipherkey = 0;                            // Initialize the cipherkey

        // Encrypt message
        for (int i = 0; i < length; i++)
        {

            if (isalpha(plaintext[i]))
            {
                for (int j = 0; j < sizeof(alphabet); j++)
                {

                    if (plaintext[i] == alphabet[j])
                    {
                        cipherkey = (key + j) % 26;
                        ciphertext[i] = alphabet[cipherkey];
                        break;
                    }
                    else if (plaintext[i] == alphabet[j] + 32)
                    {
                        cipherkey = (key + j) % 26;
                        ciphertext[i] = alphabet[cipherkey] + 32;
                        break;
                    }
                    else
                    {
                        ciphertext[i] = plaintext[i];
                    }
                }
            }
        }
        // Print the ciphertext
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}

bool only_digits(string s)
{
    int lenght = strlen(s);

    for (int i = 0; i < lenght; i++)
    {

        if (isalpha(s[i]))
        {
            return false;
            break;
        }
    }

    return true;
}