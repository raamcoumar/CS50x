#include<cs50.h>
#include <stdio.h>

int main(void){
    string name = get_string("Hey! What's your name? ");
    printf("Hello %s\n", name);
}
