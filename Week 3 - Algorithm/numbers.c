#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int numbers[6] = {4, 8, 15, 16, 23, 42};

    for (int i=0; i<6; i++)
    //Linear Search
    {
        if (numbers[i] == 4)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Not Found");
    return 1;
}
