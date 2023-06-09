#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() 
{
    char string[100];
    printf("Enter the string: ");
    scanf("%s",string);

    int ind = 0;
    int n = strlen(string);
    int a_count = 0;
    int b_count = 0;
    
    while (ind < n) 
    {
        if (string[ind] == 'a') 
        {
            a_count++;
        } 
        else if (string[ind] == 'b') 
        {
            if (a_count == 0) 
            {
                printf("%s is not recognised\n", string);
                return 0;
            }
            b_count++;
        } 
        else 
        {
            printf("%s is not recognised\n", string);
            return 0;
        }
        ind++;
    }
    if (a_count == 1 && b_count == 2) 
    {
        printf("%s is accepted under rule abb\n", string);
    } 
    else if (a_count > 0 && a_count < 2 && b_count == 0) 
    {
        printf("%s is accepted under rule a*\n", string);
    } 
    else if (a_count >= 1 && b_count >= 1) 
    {
        printf("%s is accepted under rule a*b+\n", string);
    }
    return 0;
}