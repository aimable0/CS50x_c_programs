#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            float tot_val = (float)image[i][n].rgbtBlue +
                            (float)image[i][n].rgbtGreen + (float)image[i][n].rgbtRed;

            int avg_val = round(tot_val / 3.0);

            image[i][n].rgbtBlue = (BYTE)avg_val;
            image[i][n].rgbtGreen = (BYTE)avg_val;
            image[i][n].rgbtRed = (BYTE)avg_val;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width; n++)
        {
            int sepiaRed = round((.393 * image[i][n].rgbtRed) + (.769 * image[i][n].rgbtGreen) + (.189 * image[i][n].rgbtBlue));
            int sepiaGreen = round((.349 * image[i][n].rgbtRed) + (.686 * image[i][n].rgbtGreen) + (.168 * image[i][n].rgbtBlue));
            int sepiaBlue = round((.272 * image[i][n].rgbtRed) + (.534 * image[i][n].rgbtGreen) + (.131 * image[i][n].rgbtBlue));

            if (sepiaBlue <= 255)
                image[i][n].rgbtBlue = (BYTE)sepiaBlue;
            else
                image[i][n].rgbtBlue = 255;

            if (sepiaGreen <= 255)
                image[i][n].rgbtGreen = (BYTE)sepiaGreen;
            else
                image[i][n].rgbtGreen = 255;

            if (sepiaRed <= 255)
                image[i][n].rgbtRed = (BYTE)sepiaRed;
            else
                image[i][n].rgbtRed = 255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < width / 2; n++)
        {
            RGBTRIPLE *temp_pixel = malloc(sizeof(RGBTRIPLE));
            temp_pixel->rgbtBlue = image[i][width - 1 - n].rgbtBlue;
            temp_pixel->rgbtGreen = image[i][width - 1 - n].rgbtGreen;
            temp_pixel->rgbtRed = image[i][width - 1 - n].rgbtRed;

            image[i][width - 1 - n].rgbtBlue = image[i][n].rgbtBlue;
            image[i][width - 1 - n].rgbtGreen = image[i][n].rgbtGreen;
            image[i][width - 1 - n].rgbtRed = image[i][n].rgbtRed;

            image[i][n].rgbtBlue = temp_pixel->rgbtBlue;
            image[i][n].rgbtGreen = temp_pixel->rgbtGreen;
            image[i][n].rgbtRed = temp_pixel->rgbtRed;
        }
    }
    return;
}

// Blur image
// helper function
double avg(int height, int width, RGBTRIPLE image_og[height][width], char color, int i, int j)
{
    float sum = 0;
    float nbr = 0;

    for (int n = i - 1; n < i + 2; n++)
    {
        for (int m = j - 1; m < j + 2; m++)
        {
            if (n > -1 && n < height && m > -1 && m < width) // check bounds
            {
                // calculate avg excluding the current pixel;
                switch (color)
                {
                    case 'b': sum += image_og[n][m].rgbtBlue; break;
                    case 'g': sum += image_og[n][m].rgbtGreen; break;
                    case 'r': sum += image_og[n][m].rgbtRed; break;
                    default: break;
                }
                nbr++;
            }
        }
    }

    return round(sum / nbr);
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image first.
    RGBTRIPLE image_og[height][width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            image_og[i][j] = image[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = (BYTE) avg(height, width, image_og, 'b', i, j);
            image[i][j].rgbtGreen = (BYTE) avg(height, width, image_og, 'g', i, j);
            image[i][j].rgbtRed = (BYTE) avg(height, width, image_og, 'r', i, j);
        }

    return;
}