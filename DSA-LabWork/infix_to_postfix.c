#include <stdio.h>
#include <conio.h>
// #include <math.h>
#include <string.h>
// #include<ctype.h>
int precedency(char);
int alpha(char);
int main()
{
    int otos = -1, ptos = -1, length;
    char opstack[100], poststack[100], infix[100];
    printf("Enter the valid infix Expression:\n");
    gets(infix);
    length = strlen(infix);
    for (int i = 0; i < length; i++)
    {
        if (infix[i] == '(')
        {
            opstack[++otos] = infix[i];
        }
        else if (alpha(infix[i]))
        {
            poststack[++ptos] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (opstack[otos] != '(')
            {
                poststack[++ptos] = opstack[otos];
                otos--;
            }
            otos--;
        }
        else
        {
            if (precedency(opstack[otos]) >= precedency(infix[i]))
            {
                poststack[++ptos] = opstack[otos];
                // opstack[++otos] = infix[i];
                otos--;
            }
            opstack[++otos] = infix[i];
        }
    }
    while (otos != -1)
    {
        poststack[++ptos] = opstack[otos];
        otos--;
    }
    // poststack[++ptos] = '\0';
    // printf("%s\n",poststack);
    printf("The postfix expression is:\n");
    for (int i = 0; i <= ptos; i++)
    {
        printf("%c", poststack[i]);
    }
    printf("\n\n\tBy Krishna Aryal");
    return 0;
}
int precedency(char ch)
{
    switch (ch)
    {
    case '$':
    case '^':
        return (4);
        break;
    case '*':
    case '/':
        return (3);
    case '+':
    case '-':
        return (2);
    default:
        return (1);
        break;
    }
}
int alpha(char ch)
{
    int a = ch;
    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122))
    {
        return (1);
    }
    else
        return (0);
}