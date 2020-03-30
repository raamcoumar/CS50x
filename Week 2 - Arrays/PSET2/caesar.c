#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt(int shift);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int shift = atoi(argv[1]);
        if (shift != 0)
        {
            encrypt(shift);
        }
        else
        {
            printf("Usage: ./caesar key\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

}

void encrypt(int shift)
{
    int k = shift % 26; // if k is > 26, store the division remainder instead
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + k) % 26;

        printf("%c", ci + ascii_offset);
    }
    printf("\n");
}

