#include <stdio.h>
#include <stdlib.h>

int clean_stdin()
{
    while (getchar()!='\n');
    return 1;
}

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
		printf("  ");
		for (int k=1; k<=row; k++)
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
    do
    {
        printf("Height: ");

    } while (((scanf("%d%c", &rows, &c)!=2 || c!='\n') && clean_stdin()) || rows<1 || rows>8);

    half_pyramid(rows);
}
