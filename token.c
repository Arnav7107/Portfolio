#include<stdio.h>
#include <string.h>
#include <stdbool.h>

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

bool isConstant(char *str)
{
    if (!strcmp(str, "0") || !strcmp(str, "1") || !strcmp(str, "2") ||
        !strcmp(str, "3") || !strcmp(str, "4") || !strcmp(str, "5") ||
        !strcmp(str, "6") || !strcmp(str, "7") || !strcmp(str, "8") ||
        !strcmp(str, "9"))
        {
            return (true);
        }
    return (false);
}

bool isOperator(char *str)
{
    if (!strcmp(str,"=") || !strcmp(str, "-") || !strcmp(str, "*")||
        !strcmp(str, "/")|| !strcmp(str, "<") || !strcmp(str, ">")
        || !strcmp(str, "+"))
        return (true);
    return (false);
}

bool isComment(char* str)
{
    if(str[0]=='/' && str[1] == '/' )
      return true;
    return false;
}

bool validIdentifier(char str)
{
    if (str == '0' || str == '1' || str == '2' ||
        str == '3' || str == '4' || str == '5' ||
        str == '6' || str== '7' || str == '8' ||
        str == '9'  || str == '&' || str == '!' || str == '%' || str == '@' || str == '#' || str == '^'  )
       
        return (false);
    return (true);
    
}

bool valid_identifier(char* str)
{
    int i;
    int len = strlen(str);
    for(i = 0; i<len;i++)
    {
        if(validIdentifier(str[i])==false)
        {
           return false;
        }
       
       
    }
    return true;
}


int main() {
    char a[100];
    printf("Enter Input: ");
 scanf("%[^\n]s",a);
    int n= strlen(a);
    int s=0,k=0;
    char temp[100];
    for (int i=0;i<n;i++)
    {
       
       
        if (a[i]==' ' || i == n-1){
           for(int l=0;l<100;l++){
               temp[l]='\0';
           }
           k=0;
           if(i==n-1)
           i++;
            for(int j=s;j<i;j++){
                temp[k]=a[j];
                k++;
            }
            s=i+1;
            if(isKeyword(temp))
                printf("%s is a Keyword\n",temp);
            else if(isOperator(temp))
                printf("%s is an Operator\n",temp);
            else if(isConstant(temp))
                printf("%s is a constant",temp);
            else if((*temp!='/') && valid_identifier(temp))
                printf("%s is an identifier\n",temp);
            else if ((*temp!='/') && valid_identifier(temp)==false)
            {
                printf("%s is not a valid Identifier\n",temp);
            }
            
           else if(isComment(temp))
            {
                    printf("%s is a comment",temp);
                    break;
            }
           
        }
    }
   
    return 0;
}

