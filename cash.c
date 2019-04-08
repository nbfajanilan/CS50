#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_float(string prompt);
int coin_counts(float f);
int main(void)
{
    float f = get_positive_float("Change owed: ");
    int coins = round(f * 100);
    int change =  coin_counts(coins);
    printf("%i\n", change);
}

float get_positive_float(string prompt)
{
    float f;
    do
    {
        f = get_float("%s", prompt);
    }
    while (f < 0);
    return f;
}

int coin_counts(float f)
{
    int balance = f;
    int count = 0;
    while (balance > 0)
    {
        if (balance >= 25)
        {
            count += balance/25;
            balance = balance%25;
        }
        else if (balance >= 10)
        {
            count += balance/10;
            balance = balance%10;
        }
        else if (balance >= 5)
        {
            count += balance/5;
            balance = balance%5;
        }
        else if (balance >= 1)
        {
            count += balance/1;
            balance = balance%1;
        }
        else
        {
            count += 0;
            balance = 0;
        }
    }
    return count;
}
