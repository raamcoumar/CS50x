#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

// Returns a pattern of half-pyramid with given 'rows'
void half_pyramid(int rows)
{
	for (int row=1; row<=rows; row++)
	{
		for (int i=1; i<=rows-row; i++)
		{
			printf(" ");
		}
		for (int j=1; j<=row; j++)
		{
			printf("#");
		}
	printf("\n");
	}
}

int main(void)
{
    int rows =0;
    char c;
    // Keep getting input untill the input is an int between 1 and 8
    do
    {
        printf("\nEnter an integer from 1 to 8: ");

    } while (((scanf("%d%c", &rows, &c)!=2 || c!='\n') && clean_stdin()) || rows<1 || rows>8);

    half_pyramid(rows);
}
