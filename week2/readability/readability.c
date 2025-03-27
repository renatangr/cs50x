#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
float Calculate_Avg_Letters(int letters, int words);
float Calculate_Avg_Sentences(int sentences, int words);
float Calculate_Index(float avg_letters, float avg_sentences);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Calculate the lenght of a string
    int lenght = strlen(text);

    // Initialize variables
    int letters = 0;
    int words = 0;
    int sentence = 0;

    // Count the number of letters, words, and sentences in the text
    for (int i = 0; i <= lenght; i++)
    {

        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]) || text[i] == '\0')
        {
            words++;
        }
        else if ((text[i] == '!' || text[i] == '?' || text[i] == '.') && text[i] != '-')
        {

            sentence++;
        }
    }

    printf("Letters: %i\nLenght: %i\nWords: %i\nSentences: %i\n", letters, lenght, words, sentence);

    // Compute the Coleman-Liau index

    float avg_letters = Calculate_Avg_Letters(letters, words);
    printf("Average of letters: %f\n", avg_letters);

    float avg_sentences = Calculate_Avg_Sentences(sentence, words);
    printf("Average of sentences: %f\n", avg_sentences);

    float index = Calculate_Index(avg_letters, avg_sentences);
    printf("Index: %f\n", index);

    // Print the grade level

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}

float Calculate_Avg_Letters(int letters, int words)
{
    // Calculate the average of letters per 100 words.
    float avg_letters = ((float) letters / (float) words) * 100;

    return avg_letters;
}

float Calculate_Avg_Sentences(int sentences, int words)
{
    // Calculate the average of sentences per 100 words.
    float avg_sentences = ((float) sentences / (float) words) * 100;

    return avg_sentences;
}

float Calculate_Index(float avg_letters, float avg_sentences)
{

    float index = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;

    return index;
}