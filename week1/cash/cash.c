#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cash_owed;
    int coins_for_denomination = 0;
    int total_coins = 0;

    do
    {
        cash_owed = get_int("Cash owed: "); // Asks the cash owed
    }
    while (cash_owed <= 0); // Not 0 or negative numbers allowed

    if (cash_owed >= 25) // Calculate the number of 25-cent coins needed
    {

        coins_for_denomination = cash_owed / 25;
        total_coins = coins_for_denomination;
        cash_owed = cash_owed % 25;
    }

    if (cash_owed >= 10) // Calculate the number of 10-cent coins needed
    {
        coins_for_denomination = cash_owed / 10;
        total_coins = total_coins + coins_for_denomination;
        cash_owed = cash_owed % 10;
    }

    if (cash_owed >= 5) // Calculate the number of 5-cent coins needed
    {
        coins_for_denomination = cash_owed / 5;
        total_coins = total_coins + coins_for_denomination;
        cash_owed = cash_owed % 5;
    }

    if (cash_owed >= 1) // Calculate the number of 1-cent coins needed
    {
        coins_for_denomination = cash_owed / 1;
        total_coins = total_coins + coins_for_denomination;
        cash_owed = cash_owed % 1;
    }

    printf("Total coins: %d \n", total_coins);
}
