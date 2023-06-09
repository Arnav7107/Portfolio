#include<stdio.h>
#include <string.h>
#include <stdbool.h>

bool isComment(char* str)
{
    if(str[0]=='/' && str[1] == '/' )
      return true;
    return false;
}

int main() {
    char str[100];
 scanf("%[^\n]s",str);
    int n = strlen(str);
    int s=0,k=0;
    char temp[100];
    for (int i=0;i<n;i++)
    {
        if (str[i]==' ' || i == n-1)
        {
           for(int l=0;l<100;l++)
           {
               temp[l]='\0';
           }
           k=0;
           if(i==n-1)
           i++;
            for(int j=s;j<i;j++){
                temp[k]=str[j];
                k++;
            }
            s=i+1;
            
            if(isComment(temp))
            {
                    printf("%s is a comment\n",temp);
                    break;
            }
            else
            {
                printf("%s is not a comment\n", temp);
            }
           
        }
    }
    return 0;
}