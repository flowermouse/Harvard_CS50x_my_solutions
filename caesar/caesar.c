#include <cs50.h>
#include <stdio.h>

int str_to_int(string str)
{
    if (str[0] == '\0')
        return 0;
    int n = str[0] - '0';
    for (int i = 1; str[i] != '\0'; i++)
        n = n * 10 + (str[i] - '0');
    return n;
}

string cipher(string text, int n)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] + n - 'A') % 26 + 'A';
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] + n - 'a') % 26 + 'a';
    }
    return text;
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int flag = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] > '9' || argv[1][i] < '0')
            flag++;
        if (flag != 0)
            break;
    }
    if (flag != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int n = str_to_int(argv[1]);
    string text = get_string("plaintext:  ");
    printf("ciphertext: %s\n", cipher(text, n));
    return 0;
}