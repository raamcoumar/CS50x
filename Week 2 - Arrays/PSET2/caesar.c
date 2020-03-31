#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void encrypt(int shift); //Decalring function prototype

int main(int argc, string argv[])
{
    int count = 0;
    if (argc == 2)
    {
        int n = atoi(argv[1]); //converting argv[1](a raw string) to integer
        while (n != 0)
        //counting the number of digits
        {
            n /= 10;
            ++count;
        }

        if (count == strlen(argv[1]))
        /*True if 'counts'(ie. number of digits converted from argv[1]
        and the string length of argv[1])
        ----------------------------------
        This step is done to avoid flaws like getting non-numeric input keys.
        the function atoi() converts string like '45x' to 45 which is an
        invalid input. So we compare the lenghts of the string and converted integer.*/
        {
            encrypt(atoi(argv[1]));
        }
        else
        {
            printf("Usage: ./caesar key\n");
            exit(1);
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
