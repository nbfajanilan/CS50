#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);
void hash(int n);
void space(int s);
int main(void)
{
    int i = get_positive_int("Enter an integer from 1 to 8: ");
    for (int num = 1; num <= i; num++)
    {
        space(i-num);
        hash(num);
        printf("\n");
    }
}

int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}

void hash(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }
}

void space(int n)
{
    for (int j = 0; j < n; j++)
    {
        printf(" ");
    }
}
