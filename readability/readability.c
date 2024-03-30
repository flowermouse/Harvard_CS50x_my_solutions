#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
            words++;
    }
    return words;
}

int count_sentences(string text)
{
    int sentence = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            sentence++;
    }
    return sentence;
}

int main(void)
{
    string text = get_string("Text:");
    double L = count_letters(text) / (double)count_words(text) * 100;
    double S = count_sentences(text) / (double)count_words(text) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
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
        printf("Grade %i\n", index);
    }
}