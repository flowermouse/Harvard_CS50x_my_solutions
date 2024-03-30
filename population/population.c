#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int num1 = 0;
    while (num1 <= 8)
    {
        num1 = get_int("set the start size:");
    }
    // TODO: Prompt for end size
    int num2 = -10000;
    while (num2 < num1)
    {
        num2 = get_int("set the end size:");
    }
    // TODO: Calculate number of years until we reach threshold
    int y = 0;
    while (num1 < num2)
    {
        num1 = num1 + num1 / 3 - num1 / 4;
        y++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", y);

    return 0;
}
