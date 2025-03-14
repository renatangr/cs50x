#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: "); // Get the height
    }
    while (height < 1 || height > 8); // Only accepts within the range 1 to 8.

    int spaces = height;

    for (int rows = 0; rows < height; rows++) // Creates the rows
    {
        for (int column = 0; column < spaces - 1; column++) // Print the spaces
        {
            printf(" ");
        }
        spaces--;

        for (int column = 0; column <= rows; column++) // Print the bricks
        {
            printf("#");
        }

        printf("\n");
    }
}
