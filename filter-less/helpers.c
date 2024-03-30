#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round (image[i][j].rgbtRed * .393 + image[i][j].rgbtGreen * .769 + image[i][j].rgbtBlue * .189);
            int green = round (image[i][j].rgbtRed * .349 + image[i][j].rgbtGreen * .686 + image[i][j].rgbtBlue * .168);
            int blue = round (image[i][j].rgbtRed * .272 + image[i][j].rgbtGreen * .534 + image[i][j].rgbtBlue * .131);
            image[i][j].rgbtRed = red < 255? red:255;
            image[i][j].rgbtGreen = green < 255? green:255;
            image[i][j].rgbtBlue = blue < 255? blue:255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-1-j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double red = 0, green = 0, blue = 0, num = 0;
            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }
                    if (j + col < 0 || j + col > width - 1)
                    {
                        continue;
                    }
                    num++;
                    red += image[i + row][j + col].rgbtRed;
                    green += image[i + row][j + col].rgbtGreen;
                    blue += image[i + row][j + col].rgbtBlue;
                }
            }
            tmp[i][j].rgbtRed = round(red / num);
            tmp[i][j].rgbtGreen = round(green / num);
            tmp[i][j].rgbtBlue = round(blue / num);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tmp[i][j];
        }
    }
    return;
}
