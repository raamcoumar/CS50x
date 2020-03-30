// Import headers
#include<cs50.h>
#include<stdio.h>
#include<string.h>

typedef struct
// Defining a new data type
{
    string name;
    string number;
}
person; // Naming the new data type.

int main (void)
{
    person people[4];

    people[0].name = "Emma";
    people[0].number = "617-555-127";

    people[1].name = "Robert";
    people[1].number = "617-555-123";

    people[2].name = "David";
    people[2].number = "613-345-124";

    people[3].name = "Raam";
    people[3].name = "613-345-124";


    for (int i=0; i<5; i++)
    {
        if (strcmp(people[i].name, "Emma") == 0)
        {
            printf("%s's number is %s\n", people[i].name,people[i].number);
            return 0;
        }
    }
    printf("Name not found\n");
    return 1;
}
