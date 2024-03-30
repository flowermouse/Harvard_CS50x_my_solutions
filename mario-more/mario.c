#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int h = -1;
   while (h < 1 || h > 8)
   {
    h = get_int("Height:");
   }
   for (int i = 1; i <= h; i++)
   {
    for (int j = 1; j <= 2 * h + 2; j++)
    {
        if (j < h - i + 1 || j == h + 1 || j == h + 2 )
        {
            printf(" ");
        }
        else if(j > h + i + 2)
        {
            printf("\n");
            break;
        }
        else
        {
            printf("#");
        }
    }
   }
   printf("\n");
}