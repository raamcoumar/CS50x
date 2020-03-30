#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

bool is_valid_key(string key); // A Function that returns true if all chars in key are alphabets
void vigenere (string key);  // The encrypting function

int main(int argc, string args[])
{
    if (argc != 2 || !is_valid_key(args[1]))
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    else
    {
        vigenere(args[1]);
    }
    printf("\n");
    return 0;
}


bool is_valid_key(string key)
// A Function that returns true if all chars in key are alphabets
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }

    return true;
}

void vigenere(string key)
{
    string plaintext = get_string("plaintext: ");
    int length = strlen(key);

    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;

        int pi = plaintext[i] - ascii_offset;
        int kj = toupper(key[j % length]) - 65;
        int ci = (pi + kj) % 26;
        j++;

        printf("%c", ci + ascii_offset);
    }
}